import pandas as pd
import numpy as np
from keras.regularizers import l2
from keras.utils import np_utils
from keras.models import Sequential
from keras.layers.core import Flatten, Dense, Dropout
from keras.layers import Conv2D, MaxPooling2D, AveragePooling2D,BatchNormalization
import cv2


emotion_data = pd.read_csv('data/fer2013.csv')
num_classes=7
X_train = []
Y_train = []
X_test = []
Y_test = []
for index, row in emotion_data.iterrows():
    k = row['pixels'].split(" ")
    k=np.array(k,'float32')
    k/=255
    y=row['emotion']
    if row['Usage'] == 'Training':
        X_train.append(k)
        Y_train.append(y)
    elif row['Usage'] == 'PublicTest':
        X_test.append(k)
        Y_test.append(y)
        
X_train = np.array(X_train)
Y_train = np.array(Y_train)
X_test = np.array(X_test)
Y_test = np.array(Y_test)

X_train = X_train.reshape(X_train.shape[0], 48, 48, 1)
X_test = X_test.reshape(X_test.shape[0], 48, 48, 1)

Y_train= np_utils.to_categorical(Y_train, num_classes=7)
Y_test = np_utils.to_categorical(Y_test, num_classes=7)

model = Sequential()
 
#1st convolution layer
model.add(Conv2D(64, (3, 3), activation='relu',padding='same', input_shape=(48,48,1)))
model.add(MaxPooling2D(pool_size=(2,2)))
model.add(Dropout(0.25))
 
#2nd convolution layer
model.add(Conv2D(128, (3, 3), activation='relu',padding='same'))
model.add(MaxPooling2D(pool_size=(2,2)))
model.add(Dropout(0.25))
 
#3rd convolution layer
model.add(Conv2D(256, (3, 3), activation='relu',padding='same'))
model.add(MaxPooling2D(pool_size=(2,2)))
model.add(Dropout(0.25))

model.add(Conv2D(512, (3, 3), activation='relu',padding='same'))
model.add(MaxPooling2D(pool_size=(2,2)))
model.add(Dropout(0.25))
model.add(Flatten())
 
#fully connected neural networks
model.add(Dense(4096, activation='relu'))
model.add(Dropout(0.25))

model.add(Dense(4096, activation='relu'))
model.add(Dropout(0.25))
 
model.add(Dense(num_classes, activation='softmax'))
 


model.compile(optimizer="nadam",loss='categorical_crossentropy',metrics=['accuracy'])

model.fit(X_train,Y_train,batch_size=64,epochs=7,verbose=1)

loss_and_metrics = model.evaluate(X_train,Y_train,verbose=0)
print("loss e metrics train",loss_and_metrics)
loss_and_metrics = model.evaluate(X_test,Y_test,verbose=0)
print("loss e metrics test",loss_and_metrics)

from sklearn.metrics import classification_report, confusion_matrix
 
pred_list = []; actual_list = []
predictions = model.predict(X_test)
for i in predictions:
    pred_list.append(np.argmax(i))
 
for i in Y_test:
    actual_list.append(np.argmax(i))
 
print(confusion_matrix(actual_list, pred_list))

model_json = model.to_json()
with open("model.json", "w") as json_file:
    json_file.write(model_json)
    model.save_weights("model.h5")
print("Saved model to disk")