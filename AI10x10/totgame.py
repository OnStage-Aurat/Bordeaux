import numpy as np
import os
import random
import json

MAXR=10
MAXC=10
HAND=1
BALL=2
ALFA=0.9
SIGMA=0.1
qt={}
f = open('ai.json')
qt = json.load(f)
f.close()
flag=0

def muovi(yh,xh,qt,chiave):
    
    while True:
        if chiave in qt and flag==0:
            massi=-1000000
            for i in range(4):
               
                if qt[chiave][i]>massi:
                    massi=qt[chiave][i]
                    mossa=i
                    #print("ai")   
        else:
            #input()
            #print("nai") 
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

yh=0
xh=0
xb=0
yb=0
lost=0
tot=0
for yb1 in range(10):
    for xb1 in range(10):
        for yh1 in range(10):
            for xh1 in range(10):
                tot+=1
                while True:
                    yb=yb1
                    xb=xb1
                    yh=yh1
                    xh=xh1                           
                    if xh==xb and yh==yb:
                        break
                    print("partita",yb,xb,yh,xh)
                    t_game=np.zeros((MAXR,MAXC) ,dtype="int")
                    t_game[yb,xb]=BALL
                    t_game[yh,xh]=HAND
                    passi=25
                    mosse=[]
                    chiavi=[]
                    
                    while True:
                        chiave=str(yb)+str(xb)+str(yh)+str(xh)
                        #stato vecchio e mossa da registrare
                        t_game[yh,xh]=0
                        #print(qt[chiave])
                        mossa,yh,xh=muovi(yh,xh,qt,chiave)
                        #print(mossa)
                        t_game[yh,xh]=HAND
                        if mossa not in mosse:
                            mosse.append(mossa)
                            chiavi.append(chiave)
                               
                        #print(t_game)
                        #input()
                        if yh==yb and xh==xb:
                            print("Presa!!!!!!!!!!!!")
                            #input()
                            reward=1*(passi+1)
                            flag=0
                            break
                        passi-=1
                        if passi==0:
                            lost+=1
                            print("Perso!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!")
                            #input()
                            flag=1
                            reward=-1
                            break
                    #fine partita
                    for k in range(len(chiavi)):
                            key=chiavi[k]
                            if key not in qt:
                                qt[key]=[-1000000,-1000000,-1000000,-1000000]
                            massimonextstate=0
                            if k+1<len(chiavi) and chiavi[k+1] in qt:
                                massimonextstate=max(qt[chiavi[k+1]])
                            qt[key][mosse[k]]+=ALFA*(reward+SIGMA*(massimonextstate)-qt[key][mosse[k]])
                    if passi!=0:
                        break
                        

with open("ai.json", "w") as fp:
    json.dump(qt,fp)
fp.close()
print(qt)
print(lost,tot,(lost/tot)*100)