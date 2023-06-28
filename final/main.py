import cv2 as cv
import serial
import yolo2
import visual
import dlib
import time

file_name = 'ManoSinistra.svm'
detector = dlib.simple_object_detector(file_name)
scale_factor = 1.0
size, center_x = 0,0
#qui la seconda seriale per la camminata
ser = serial.Serial(port='COM8',baudrate=9600)
ser2 = serial.Serial(port='COM7',baudrate=9600)
cap = cv.VideoCapture(1)

cap.set(3, 640)
cap.set(4, 480) 
if not cap.isOpened():
    cap.open(0)
    
(net,ln,classes)=yolo2.settaggio()

forbici=0
spazzolino=0
cup=0
scena=0
tempo=1
while True:
        
    ret, img = cap.read(0)
    cv.waitKey(1)
    #qui aspetta un blu nella scena
    if scena==0:
        print("scena 0")
        frame = cv.flip( img, 1 )
        copy = frame.copy()
        new_width = int(frame.shape[1]/scale_factor)
        new_height = int(frame.shape[0]/scale_factor)
        resized_frame = cv.resize(copy, (new_width, new_height))
        detections = detector(resized_frame)
        if len(detections)!=0:
            print("ho visto gesto")
            ser.write(b'p')
        cbx,cby,cbz=visual.trova_colore(img,1)
        if cbz!=-1:
            print("qui invio carattere per la camminata")
            ser2.write(b'c')
            #carattere proboscide
            ser.write(b'p')
            time.sleep(0.2)
            scena=1
    #scena riconoscimento
    if scena==1:
        if spazzolino!=2:
            print("scena 1")
            oggetto=yolo2.riconosce(img,net,ln,classes)
        else:
            tempo=100
            if visual.prendi(img,ser):
                spazzolino=1
                tempo=1
        if oggetto==1 and forbici==0:
            print("forbici")
            ser.write(b'2')
            forbici=1
            time.sleep(5)
        if oggetto==2 and spazzolino==0:
            print("spazzolino")
            ser.write(b'0')
            time.sleep(0.2)
            ser.write(b'a') 
            time.sleep(5)
            ser.write(b'c')
            time.sleep(3)
            ser.write(b'1')
            time.sleep(5)
            spazzolino=2
            ser.write(b'0')
            time.sleep(0.2)
        if oggetto==4 and cup==0:
            print("bottle")
            cup=1
            scena=2
            ser.write(b'0')
            time.sleep(0.2)
            ser.write(b'a')
            time.sleep(0.2)
            tempo=100
    if scena==2:
    #o in modo differente prende il bicchiere
        if visual.prendinoai(img,ser):
            #avanza chiude la pinza fa scena di bere e buttare bicchiere
            scena=3
            print("beve")
            #ser.write(b'i')
            #time.sleep(0.2)
            ser.write(b'i')
            time.sleep(0.2)
            ser.write(b'i')
            time.sleep(0.2)
            ser.write(b'i')
            time.sleep(0.2)
            ser.write(b't')
            time.sleep(5)
            ser.write(b'p')
            time.sleep(0.2)
            time.sleep(0.9)
            ser.write(b'a')
            time.sleep(0.2)
    if scena==3:
        break
        
    cv.imshow('window',img)
    cv.waitKey(tempo)

cv.destroyAllWindows()
