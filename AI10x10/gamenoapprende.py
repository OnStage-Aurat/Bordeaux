import numpy as np
import os
import random
import json

MAXR=10
MAXC=10
HAND=1
BALL=2
# dict dove registriamo i valori delle mosse, caricando dal file
qt={}
f = open('ai.json')
qt = json.load(f)
f.close()

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
while True:
    yh=random.randint(0,9)
    xh=random.randint(0,9)
    xb=random.randint(0,9)
    yb=random.randint(0,9)
    mosse=[]
    chiavi=[]

    t_game=np.zeros((MAXR,MAXC) ,dtype="int")
    t_game[yb,xb]=BALL
    t_game[yh,xh]=HAND
     
    while True:
        chiave=str(yb)+str(xb)+str(yh)+str(xh)
        os.system("cls")
        print(t_game)
        t_game[yh,xh]=0
        mossa,yh,xh=muovi(yh,xh,qt,chiave)
        t_game[yh,xh]=HAND
        input()
        if yh==yb and xh==xb:
            print("Presa!!!!!!!!!!!!")
            parola=input()
            break 
    if parola=='q':
        break