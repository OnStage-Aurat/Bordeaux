#https://www.kaggle.com/astraszab/facial-expression-dataset-image-folders-fer2013/version/1
import os
import cv2
import numpy as np
from keras.models import model_from_json
from keras.preprocessing import image

model = model_from_json(open("model.json", "r").read())
model.load_weights('model.h5')



faceCascade = cv2.CascadeClassifier("haarcascade_frontalface_alt.xml")

video_capture = cv2.VideoCapture(0)

while True:
    # Capture frame-by-frame
    ret, frame = video_capture.read()

    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    faces = faceCascade.detectMultiScale(
        gray,
        scaleFactor=1.1,
        minNeighbors=5,
        minSize=(30, 30)
    )

    # Draw a rectangle around the faces
    for (x, y, w, h) in faces:
        cv2.rectangle(frame, (x, y), (x+w, y+h), (0, 255, 0), 2)
        roi_gray=gray[y:y+w,x:x+h]
        roi_gray=cv2.resize(roi_gray,(48,48))
        x = image.img_to_array(roi_gray)
        x = np.expand_dims(x, axis = 0)
        x/=255
        custom = model.predict(x)
        objects = ('angry','disgust', 'fear', 'happy', 'sad', 'surprise', 'neutral')
        max=0
        pos=0
        for i in range(7):
            if max<custom[0][i]:
                max=custom[0][i]
                pos=i
        print("oggi sei "+objects[pos])        
    cv2.imshow('Emotion',frame)
    

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# When everything is done, release the capture
video_capture.release()
cv2.destroyAllWindows()