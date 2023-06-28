#Imports
import cv2
import imutils
import numpy as np
import os
import random
import json
import serial
import time

def muovi(yh,xh,qt,chiave):
    while True:
        if chiave in qt:
            massi=-1000000
            for i in range(4):
                if qt[chiave][i]>massi:
                    massi=qt[chiave][i]
                    mossa=i
        #caso in cui non conosce mossa e va a caso
        else:
            mossa=random.randint(0,3)
        if mossa==0 and xh!=0:
            xh-=1
            break
        elif mossa==1 and xh!=MAXC-1:
            xh+=1
            break
        elif mossa==2 and yh!=0:
            yh-=1
            break
        elif mossa==3 and yh!=MAXR-1:
            yh+=1
            break
    return mossa,yh,xh

def trova_colore(immagine,colore):
    cx=0
    cy=0
    cz=-1
    if colore==0:
        low=GL
        high=GH
    if colore==1:
        low=BL
        high=BH
    hsv = cv2.cvtColor(immagine, cv2.COLOR_BGR2HSV)
    mask = cv2.inRange(hsv, low, high)
    cv2.imshow("Canvas0", mask)
    cnts = cv2.findContours(mask, cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)
    cnts = imutils.grab_contours(cnts)#problemi di compatibilità
    if len(cnts)!=0:
        c = max(cnts, key = cv2.contourArea)
        x,y,w,h = cv2.boundingRect(c)
        area=w*h
        if area>200:
            cx=(x+(w//2))
            cy=(y+(h//2))
            cz=area
            
    return cx,cy,cz


MAXR=10
MAXC=10
HAND=1
BALL=2
GL = np.array([36,50,50])
GH = np.array([85,255,255])
BL = np.array([(91,88,92)])
BH =np.array([(116, 255, 255)])
    
qt={}
f = open('ai.json')
qt = json.load(f)
f.close()

yh=0
xh=0
xb=0
yb=0
  
#Main
def prendi(img,ser):
    
    #mosse=[]
    #chiavi=[]
    t_game=np.zeros((MAXR,MAXC) ,dtype="int")

    chx,chy,chz=trova_colore(img,0)
    cbx,cby,cbz=trova_colore(img,1)
    
    yh=chy//48
    xh=chx//64
    yb=cby//48+1
    xb=cbx//64
    if yh>9:
        yh=9
    if xh>9:
        xh=9
    if yb>9:
        yb=9
    if xb>9:
        xb=9    
    t_game[yh,xh]=HAND
    t_game[yb,xb]=BALL

    chiave=str(yb)+str(xb)+str(yh)+str(xh)
    os.system("cls")
    print(t_game)
    conta = 0
    if yh==yb and xh==xb:
        print("Presa!!!!!!!!!!!!")
        if chx>cbx:
            ser.write(b'D')
            conta = 1
        else:    
            ser.write(b'S')
            conta = 2
            
        if conta == 1:
            ser.write(b'D')
        else:
            ser.write(b'S')
            
        time.sleep(0.2)
        ser.write(b'a')
  
        return 1 
    
    t_game[yh,xh]=0
    t_game[yb,xb]=0
    mossa,yh,xh=muovi(yh,xh,qt,chiave)
    print(mossa)#qui muove motore
    if chz==-1:#senza verde 
        print("pos inizio")
        ser.write(b'0')#posizione iniziale
    
    ser.flush()    
    if mossa==0:
        ser.write(b'd')
    if mossa==1:
        ser.write(b's')
    if mossa==2:
        ser.write(b'i')
    if mossa==3:
        ser.write(b'k')
    
    cv2.waitKey(100)
     
    
    cv2.circle(img, (chx,chy), 5, (0,0,255))
    cv2.circle(img, (cbx,cby), 5, (255,255,255))

def prendinoai(img,ser):
    
    chx,chy,chz=trova_colore(img,0)
    cbx,cby,cbz=trova_colore(img,1)   
    if cbz==-1: #senza verde o blu
        print("pos inizio")
        ser.write(b'0') #posizione iniziale
        ser.write(b'a')
    time.sleep(0.2)
    if cbx-chx>3:
        mossa = 1
    elif chx-cbx>3:
        mossa = 0  
    elif cby-chy>0:
        mossa = 3
    elif chy-cby>85:
        mossa = 2
    else:
        return 1
    print("mossa",mossa,cbx,cby,chx,chy)
    
    ser.flush()    
    if mossa==0:
        ser.write(b'd')
    if mossa==1:
        ser.write(b's')
    if mossa==2:
        ser.write(b'i')
    if mossa==3:
        ser.write(b'k')
    
    cv2.circle(img, (chx,chy), 5, (0,0,255))
    cv2.circle(img, (cbx,cby), 5, (255,255,255))
    