// #include "mbed.h"
// #include "platform/mbed_thread.h"

// Serial pc(SERIAL_TX, SERIAL_RX);
// //giallo (5V) bianco (gnd) blu (output)
// // Pin per A
// //A1 dir = D15(ok) pwm = D14(ok)
// //A2 dir = D2(ok)  pwm = D3(ok)  
// //A3 dir = D7(ok)  pwm = D6(ok)
// //A4 dir = D11(ok) pwm = D12(ok)
// // SENSORI PER A 
// //A2 = D6
// //A4 = PC_9
// //A3 = PA11
// //A1 = D4


// // Pin per P
// //P1 dir = D13(ok) pwm = D10(ok)
// //P2 dir = PC1(ok)  pwm = PB0(ok)
// //P3 dir = PA_0(ok)  pwm = A2(ok)
// //P4 dir = D8(ok)  pwm = D9(ok)

// //Pin per L
// //L1 dir = A0 pwm = PC3
// //L2 dir = D0 pwm = D1
// //L3 dir = PD_2 pwm = PC_11
// //L4 dir = PC_12   pwm = PC_10  

// PinName dA;
// PinName pA;
// PinName dL;
// PinName pL;
// PinName dP;
// PinName pP;
// DigitalIn ancaA2(D6);
// DigitalIn ancaA4(PC_9);
// DigitalIn ancaA3(PA_11); 
// DigitalIn ancaA1(D4);

// double read(AnalogIn feedback) {
//     return feedback.read();
// }

// void lettura(AnalogIn feedback){
//     while(true){
//        //pc.printf("valore normale:  %d\n",val);
//         //pc.printf("percentage: %3.3f%%\n",feedback.read()*100.0f);
//         wait_ms(200);
//         pc.printf("valore normale:  %d\n",feedback.read_u16());
//     }
// }




// 

// void goP(int numPin,int dirPin){
    
//     switch(numPin){
//         case 1:
//            dP = D13;
//            pP = D10;
//            break;
//         case 2:
//            dP = PC_1;
//            pP = PB_0;
//            break;
//         case 3:
//            dP = PA_0;
//            pP = A2;
//            break;
//         case 4:
//            dP = D8;
//            pP = D9;
//            break;
//         default :
//            exit(0);   
//     }
//     DigitalOut dir(dP);
//     DigitalOut pwm(pP);
//     switch(dirPin){
//     case 0:
//         pwm = 0;
//         break;
//     case 1:
//         pwm = 1;
//         dir = dirPin;
//         break;
//     case 2:
//         dir = 0;
//         pwm = 1;
//         break;
//     }
// }

// void goA (int numPin,int dirPin){
           
//     switch(numPin){
//         case 1:
//            dA = D15;
//            pA = D14;
//            break;
//         case 2:           
//            dA = D2;
//            pA = D3;

//            break;
//         case 3:
//            dA = D7;
//            pA = D6;
//            break;
//         case 4:
//            dA = D11;
//            pA = D12;
//            break;
//         default :
//             exit(0);        
//     }
    
//     DigitalOut dir(dA);
//     DigitalOut pwm(pA);
//     switch(dirPin){
//     case 0:
//         pwm = 0;
//         break;
//     case 1:
//         pwm = 1;
//         dir = dirPin;
//         break;
//     case 2:
//         dir = 0;
//         pwm = 1;
//         break;
//     }
        
// }


// void setMotorA(int mPin, DigitalIn pin){
//     int i=0;
//     bool controllo = true;
//     while(controllo){
//         if(pin == 0){
//             pc.printf("1");
//             if(mPin%2!=0) 
//                 goA(mPin, 2); 
//             else
//                 goA(mPin,2);
//             wait_ms(200);
//             goA(mPin, 0);
//             wait_ms(200);
//         }
//         else
//             controllo = false;
//         i++;
//         if(i==8)
//             break;
//     }
//     while(controllo){
//         if (pin == 0){
//             pc.printf("0");
//             if(mPin%2!=0) 
//                 goA(mPin, 1);
//             else
//                 goA(mPin,1);
//             wait_ms(200); 
//             goA(mPin, 0);
//             wait_ms(200);
//         }
//         else
//             controllo = false;  
//     }
//     goA(mPin,0);
// }


// void alzata(int n){
//     switch(n){
//         case 1:
//             //alza piede 2 e 3
//             goP(2,2);
//             goP(3,2);
//             wait(3);
//             //pausa piede 2 e 3
//             goP(2,0);
//             goP(3,0);
//             wait(3);
//             break;
//         case 2:
//             //alza piede 4 e 1
//             goP(4,2);
//             goP(1,2);
//             wait(3);
//             //pausa piede 4 e 1
//             goP(4,0);
//             goP(1,0);
//             wait(3);
//             break;
//     }
// }
// void rialzoP(int n){
//     switch(n){
//         case 1:
//             //abbassa piede 2 e 3
//             goP(2,1);
//             goP(3,1);
//             wait(3);
//             //pausa piede 2 e 3
//             goP(2,0);
//             goP(3,0);
//             wait(3);
//             break;
//         case 2:
//             //abassa piede 4 e 1
//             goP(4,1);
//             goP(1,1);
//             wait(3);
//             //pausa piede 4 e 1
//             goP(4,0);
//             goP(1,0);
//             wait(3);
//             break;
//     }
// }
// void rialzoA(int n){
//     switch(n){
//         case 1:
//             //abbassa anca 2 e 3
//             goA(2,1);
//             goA(3,2);
//             wait(2);
//             //pausa anca 2 e 3
//             goA(2,0);
//             goA(3,0);
//             wait(2);
//             break;
//         case 2:
//             //va anca 4 e 1
//             goA(4,1);
//             goA(1,2);
//             wait(2);
//             //pausa anca 4 e 1
//             goA(4,0);
//             goA(1,0);
//             wait(2);
//             break;
//     }
// }
// void anca(int n){
//     switch(n){
//         case 1:
//             //va anca 2 e 3
//             goA(2,2);
//             goA(3,1);
//             wait(2);
//             //pausa anca 2 e 3
//             goA(2,0);
//             goA(3,0);
//             wait(2);
//             break;
//         case 2:
//             //alza anca 4 e 1 
//             goA(4,2);
//             goA(1,1);
//             wait(2);
//             //pausa anca 4 e 1
//             goA(4,0);
//             goA(1,0);
//             wait(2);
//             break;    
//     }
// }
// int main()
// {    
//     //uint16_t val;
//     // int i=1;
//     // alzata(1);
//     // while (true){
//     //     if(i==1){
//     //         anca(1);
//     //         rialzoP(1);
//     //         alzata(2);
//     //         rialzoA(1);         
//     //         i++;
//     //     }else{
//     //         anca(2);
//     //         rialzoP(2);
//     //         alzata(1);
//     //         rialzoA(2);
//     //         i--;
//     //     }
//     // }
    
//     // alzata(1);
//     //setMotorA(4, ancaA4);
//     // wait_ms(200);
//     //setMotorA(1,ancaA1);
//     // wait_ms(200);
//     // rialzoP(1);
//     // wait_ms(200);
//     // alzata(2);
//     setMotorA(3,ancaA3);
//     // wait_ms(200);
//     //setMotorA(2, ancaA2);
//     // wait_ms(200);
//     // rialzoP(2);
//     // wait_ms(200);
//     // while(true){
//     //     if(ancaA1 == 0)
//     //         pc.printf("0");
//     //     else
//     //         pc.printf("1");
//     // }        
// }

#include "mbed.h"
#include "platform/mbed_thread.h"

Serial pc(SERIAL_TX, SERIAL_RX);

/* #################.  PINOUT    ####################.

   Pin per P
       P1 dir = D13(ok) pwm = D10(ok)
       P2 dir = PC1(ok)  pwm = PB0(ok)
       P3 dir = PA_0(ok)  pwm = A2(ok)
       P4 dir = D8(ok)  pwm = D9(ok)

   Pin per L
       L1 dir = A0 pwm = PC3
       L2 dir = D0 pwm = D1
       L3 dir = PD_2 pwm = PC_11
       L4 dir = PC_12   pwm = PC_10  

####################.  PINOUT    ################. */


PinName dA, pA, dL, pL, dP, pP;
DigitalIn ancaA1(D4), ancaA2(D5), ancaA3(PA_11), ancaA4(PC_9); // Pin sensori

/* #######################
FUNZIONI MOVIMENTO MOTORI
####################### */

void goL (int numPin, int dirPin){
    switch(numPin){
        case 1:     dL = A0;    pL = PC_3;  break; 
        case 2:     dL = D0;    pL = D1;    break;
        case 3:     dL = PD_2;  pL = PC_11; break; 
        case 4:     dL = PC_12; pL = PC_10; break;
        default : exit(0);    
    }
    DigitalOut dir(dL);
    DigitalOut pwm(pL);
    switch(dirPin){
        case 0:     pwm = 0;                break;
        case 1:     pwm = 1;    dir = 1;    break;
        case 2:     pwm = 1;    dir = 0;    break;
    }
}

void goP (int numPin, int dirPin){
    
    switch(numPin){
        case 1:     dP = D13;   pP = D10;   break;
        case 2:     dP = PC_1;  pP = PB_0;  break;
        case 3:     dP = PA_0;  pP = A2;    break;
        case 4:     dP = D8;    pP = D9;    break;
        default :   exit(0);   
    }
    DigitalOut dir(dP);
    DigitalOut pwm(pP);
    switch(dirPin){
        case 0:     pwm = 0;                    break;
        case 1:     pwm = 1;    dir = 1;        break;
        case 2:     pwm = 1;    dir = 0;        break;
    }
}


void goA (int numPin, int dirPin){
    switch(numPin){
        case 1:     dA = D15;   pA = D14;   break;
        case 2:     dA = D2;    pA = D3;    break;
        case 3:     dA = D7;    pA = D6;    break;
        case 4:     dA = D11;   pA = D12;   break;
        default :   exit(0);        
    }
    DigitalOut dir(dA);
    DigitalOut pwm(pA);
    switch(dirPin){
        case 0:     pwm = 0;                    break;
        case 1:     pwm = 1;    dir = 1;        break;
        case 2:     pwm = 1;    dir = 0;        break;
    }
}

/* ###############################
  END_ FUNZIONI MOVIMENTO MOTORI
############################### */

#define PISTONE_PIEDE       0
#define PISTONE_ANCA        1
#define PISTONE_LATERALE    2

#define APRI                1   // apre il pistone
#define CHIUDI              2   // chiude il pistone

void logSensoriAnca() {
    pc.printf("\n ##########  LOG SENSORI ANCA  ##########\n");
    pc.printf("\t 1 = led acceso; 0 = led spento\n\r");
    pc.printf("\tAnca 1: %d \n\r", (int)ancaA1);    // 1 = led spento ; 0 = led acceso
    pc.printf("\tAnca 2: %d \n\r", (int)ancaA2);
    pc.printf("\tAnca 3: %d \n\r", (int)ancaA3);
    pc.printf("\tAnca 4: %d \n\r", (int)ancaA4);
}

int leggiSensoreAnca(int n_gamba){
    switch (n_gamba) {
        case 1: return (int)ancaA1;
        case 2: return (int)ancaA2;
        case 3: return (int)ancaA3;
        case 4: return (int)ancaA4;
    }
    return -1;
}

void raddrizzaGambe(int n1_gamba,int n2_gamba){
    int INTERVALLO_CONTROLLO = 75;   // controlla la posizione ogni 100 ms
    pc.printf("MOVIMENTO - Raddrizzo la gamba %d \n\r", n1_gamba);
    pc.printf("MOVIMENTO - Raddrizzo la gamba %d \n\r", n2_gamba);
    pc.printf("sensori: %d - %d \n",leggiSensoreAnca(n1_gamba),leggiSensoreAnca(n2_gamba));
    if((leggiSensoreAnca(n1_gamba) == 1) && (leggiSensoreAnca(n2_gamba) == 0)){
        while(true){
            pc.printf("dentro1\n");
            goA(n1_gamba,1);
            goA(n2_gamba,2);
            thread_sleep_for(INTERVALLO_CONTROLLO);
            if(leggiSensoreAnca(n1_gamba) == 0  && (leggiSensoreAnca(n2_gamba) == 1)) { 
                goA(n1_gamba, 0); 
                goA(n2_gamba, 0);  
                break; 
            }
        }
        pc.printf("fine dentro1 sensori: %d - %d \n",leggiSensoreAnca(n1_gamba),leggiSensoreAnca(n2_gamba));
    }else if((leggiSensoreAnca(n1_gamba) == 1) && (leggiSensoreAnca(n2_gamba) == 1)){
        while(true){
            pc.printf("dentro2\n");
            goA(n1_gamba, 2);
            goA(n2_gamba, 1);
            thread_sleep_for(INTERVALLO_CONTROLLO);
            if((leggiSensoreAnca(n1_gamba) == 0) && (leggiSensoreAnca(n2_gamba) == 0)) { 
                goA(n1_gamba, 0); goA(n2_gamba, 0); 
                break; 
            }
        }
        pc.printf("fine dentro2 sensori: %d - %d \n",leggiSensoreAnca(n1_gamba),leggiSensoreAnca(n2_gamba));
    }
}


void raddrizzaGamba(int n_gamba){
    int INTERVALLO_CONTROLLO = 50;   // controlla la posizione ogni 100 ms
    pc.printf("MOVIMENTO - Raddrizzo la gamba %d \n\r", n_gamba);
    if(leggiSensoreAnca(n_gamba) == 0){
        while(true){
            pc.printf("dentro1\n");
            goA(n_gamba, 2);
            thread_sleep_for(INTERVALLO_CONTROLLO);
            if(leggiSensoreAnca(n_gamba) == 1) { goA(n_gamba, 0);  break; }
        }
    }else{
        while(true){
            pc.printf("dentro2\n");
            goA(n_gamba, 1);
            thread_sleep_for(INTERVALLO_CONTROLLO);
            if(leggiSensoreAnca(n_gamba) == 0) { goA(n_gamba, 0); break; }
        }
    }
}

void muoviPistone(int n_gamba_A, int tipo_pistone, int time, int movimentoA){
    switch (tipo_pistone) {
    case PISTONE_PIEDE:
        //pc.printf("\t(PISTONE PIEDE)\n\r");
        goP(n_gamba_A, movimentoA);
        thread_sleep_for(time);
        goP(n_gamba_A, 0);    // 0 = stop
        break;
    case PISTONE_ANCA:
        //pc.printf("\t(PISTONE ANCA)\n\r");
        goA(n_gamba_A, movimentoA);
        thread_sleep_for(time);
        goA(n_gamba_A, 0); 
        break;
    case PISTONE_LATERALE:
        pc.printf("\t(PISTONE LATERALE)\n\r");
        goL(n_gamba_A, movimentoA);
        thread_sleep_for(time);
        goL(n_gamba_A, 0);
        break;
    }
}

void resetPistoni(){
    pc.printf("\n ##########  RESET PISTONI  ##########\n");
    muoviPistone(1, PISTONE_PIEDE, 1000, APRI);
    raddrizzaGamba(1);
    muoviPistone(1, PISTONE_PIEDE, 1000, CHIUDI);

    muoviPistone(2, PISTONE_PIEDE, 1000, APRI);
    raddrizzaGamba(2);
    muoviPistone(2, PISTONE_PIEDE, 1000, CHIUDI);

    muoviPistone(3, PISTONE_PIEDE, 1000, APRI);
    raddrizzaGamba(3);
    muoviPistone(3, PISTONE_PIEDE, 1000, CHIUDI);

    muoviPistone(4, PISTONE_PIEDE, 1000, APRI);
    raddrizzaGamba(4);
    muoviPistone(4, PISTONE_PIEDE, 1000, CHIUDI);

    muoviPistone(1, PISTONE_PIEDE, 1000, APRI);
    muoviPistone(2, PISTONE_PIEDE, 1000, APRI);
    muoviPistone(3, PISTONE_PIEDE, 1000, APRI);
    muoviPistone(4, PISTONE_PIEDE, 1000, APRI);
}

void muoviPistoni(int n_gamba_A, int n_gamba_B, int tipo_pistone, int time, int movimentoA, int movimentoB){
    pc.printf(
        "MOVIMENTO - %s il pistone %d\t %s il pistone %d\t per %d milliseondi", 
        movimentoA == 1 ? "Apro":"Chiudo",
        n_gamba_A,
        movimentoB == 1 ? "Apro":"Chiudo",
        n_gamba_B,
        time
    );

    switch (tipo_pistone) {
    case PISTONE_PIEDE:
        pc.printf("\t(PISTONE PIEDE)\n\r");
        goP(n_gamba_A, movimentoA);
        goP(n_gamba_B, movimentoB);
        thread_sleep_for(time);
        goP(n_gamba_A, 0);   // 0 = stop
        goP(n_gamba_B, 0);
        break;
    case PISTONE_ANCA:
        pc.printf("\t(PISTONE ANCA)\n\r");
        goA(n_gamba_A, movimentoA);
        goA(n_gamba_B, movimentoB);
        thread_sleep_for(time);
        goA(n_gamba_A, 0); 
        goA(n_gamba_B, 0);
        break;
    case PISTONE_LATERALE:
        pc.printf("\t(PISTONE LATERALE)\n\r");
        goL(n_gamba_A, movimentoA);
        goL(n_gamba_B, movimentoB);
        thread_sleep_for(time);
        goL(n_gamba_A, 0);  
        goL(n_gamba_B, 0);
        break;
    }

}

/*
############.  Utilizzo muoviPistone().  ##################

muoviPistone( 2,    3,      PISTONE_PIEDE,      2000,       APRI ,      APRI);
-> alza i pistoni dei piedi 2 e 3 per 2 secondi

############.  Utilizzo muoviPistone().  ##################
*/


int TEMPO_ALLUNGO_GAMBA = 1200;    // 5 secondi
int TEMPO_ALLUNGO_ANCA = 2000;

void camminataSemplice(){

    muoviPistoni(3, 2, PISTONE_PIEDE, 1000, CHIUDI, CHIUDI);
    for(int j = 0; j < 1; j++){    // inizio loop
            thread_sleep_for(1000);
            //goA(2, CHIUDI);    // muovo le anche per fare il passo
            //goA(3, APRI);
        //movimento delle anche della gambe 2 e 3 verso l'indoetro di 
            muoviPistoni(3, 2, PISTONE_ANCA, 1250, APRI, CHIUDI);
            goP(1, 0); 
            goP(4, 0);
            muoviPistoni(4, 1, PISTONE_PIEDE, 1000, CHIUDI, CHIUDI);
            //raddrizzaGambe(2,3);
            muoviPistoni(3, 2, PISTONE_PIEDE, 1000, APRI, APRI);
            muoviPistoni(3, 2, PISTONE_ANCA, 1250, CHIUDI, APRI);
            thread_sleep_for(1000);
            
            muoviPistoni(1, 4, PISTONE_ANCA, 1250, APRI, CHIUDI);
            thread_sleep_for(1000);
            muoviPistoni(3, 2, PISTONE_PIEDE, 1000, CHIUDI, CHIUDI);
            //raddrizzaGambe(1,4);
            muoviPistoni(1 ,4, PISTONE_PIEDE, 1000, APRI, APRI);
            muoviPistoni(1, 4, PISTONE_ANCA, 1250, CHIUDI, APRI);
            thread_sleep_for(1000);
            //thread_sleep_for(1000);
            //goP(2, APRI);   // inizio ad alzare i piedi
            // goP(3, APRI);
            // thread_sleep_for(5000);
//             //raddrizzaGambe(2,3);
//             // raddrizzaGamba(2);
//             // raddrizzaGamba(3);

//             thread_sleep_for(5000);

//             goA(1, APRI);   //  muovo le anche per fare il passo
//             thread_sleep_for(1000);
//             goA(1, 0);
//             goA(4, CHIUDI);
//             thread_sleep_for(1000);
//             goA(4, 0);
//             thread_sleep_for(5000);

//             goP(2, 0);  
//             goP(3, 0);
            
//             muoviPistoni(3, 2, PISTONE_PIEDE, 2000, CHIUDI, CHIUDI);
//             thread_sleep_for(5000);
//             muoviPistoni(1, 4, PISTONE_PIEDE, 2000, APRI, APRI);
//             thread_sleep_for(5000);
         }
//           //  fine loop
        muoviPistone(1, PISTONE_PIEDE, 5000, APRI);
        muoviPistone(2, PISTONE_PIEDE, 5000, APRI);
        muoviPistone(3, PISTONE_PIEDE, 5000, APRI);
        muoviPistone(4, PISTONE_PIEDE, 5000, APRI);

//         thread_sleep_for(1000);
}
//}
//     //abbasso piede 2 e 1 
//     // muoviPistoni(1, 2, PISTONE_PIEDE,3500, APRI, APRI);
//     //  for(int j = 0; j < 1; j++){
//     //     thread_sleep_for(1000);
//     //     muoviPistone(3, PISTONE_PIEDE, 2000, APRI);
    //     thread_sleep_for(1000);
    //     goA(3, CHIUDI);    // muovo le anche per fare il passo
    //     thread_sleep_for(1500);
    //     goA(3, 0);
    //     muoviPistone(3, PISTONE_PIEDE, 2000, CHIUDI);
    //     thread_sleep_for(1000);  
    //     muoviPistoni(3, 4, PISTONE_PIEDE,2000, APRI, APRI);
    //     muoviPistone(2, PISTONE_PIEDE, 2000, APRI);
    //     thread_sleep_for(1000);
    //     goA(2, APRI);
    //     thread_sleep_for(1500);
    //     goA(2,0);
    //     muoviPistone(2, PISTONE_PIEDE, 2000, CHIUDI);
    //     thread_sleep_for(1000);
    //     muoviPistoni(3, 4, PISTONE_PIEDE,2000, CHIUDI, CHIUDI);
    //     thread_sleep_for(1000);
    //     muoviPistoni(1, 2, PISTONE_PIEDE,2000, APRI, APRI);
    //     thread_sleep_for(1000);
    //     muoviPistone(4, PISTONE_PIEDE, 3500, APRI);
    //     thread_sleep_for(1000);
    //     goA(4, APRI);
    //     thread_sleep_for(1500);
    //     goA(4,0);
    //     muoviPistone(4, PISTONE_PIEDE, 3500, CHIUDI);
    //     thread_sleep_for(1000);
    //     muoviPistoni(1, 2, PISTONE_PIEDE,2000, APRI, APRI);
    //     thread_sleep_for(1000);
    //     muoviPistoni(3, 4, PISTONE_PIEDE,2000, CHIUDI, CHIUDI);
    //     thread_sleep_for(1000);
    //     muoviPistone(1, PISTONE_PIEDE, 3500, APRI);
    //     thread_sleep_for(1000);
    //     goA(1, CHIUDI);
    //     thread_sleep_for(1500);
    //     goA(1,0);
    //     thread_sleep_for(1000);
    //     muoviPistone(1, PISTONE_PIEDE, 3500, CHIUDI);
    //     thread_sleep_for(1000);
    //     muoviPistoni(1, 2, PISTONE_PIEDE,2000, APRI, APRI);
    //     thread_sleep_for(1000);
    //     goA(1, APRI);
    //     thread_sleep_for(1000);
    //     goA(1,0);
    //     thread_sleep_for(1000);
    //     goA(2, CHIUDI);
    //     thread_sleep_for(1000);
    //     goA(2,0);
    //     thread_sleep_for(1000);
    //     goA(3, APRI);    // muovo le anche per fare il passo
    //     thread_sleep_for(1000);
    //     goA(3, 0);
    //     thread_sleep_for(1000);
    //     goA(4, CHIUDI);
    //     thread_sleep_for(1000);
    //     goA(4,0);
        // //  muoviPistoni(3, 2, PISTONE_PIEDE, TEMPO_ALLUNGO_GAMBA+500, APRI, CHIUDI);
        //  muoviPistoni(3, 4, PISTONE_PIEDE, TEMPO_ALLUNGO_GAMBA+500, APRI, APRI);
        //  thread_sleep_for(5000);
        // //  muoviPistoni(4, 1, PISTONE_PIEDE, TEMPO_ALLUNGO_GAMBA+500, APRI, CHIUDI);
        //  muoviPistoni(2, 1, PISTONE_PIEDE, TEMPO_ALLUNGO_GAMBA+500, CHIUDI, CHIUDI);
         
        // thread_sleep_for(5000);
        // muoviPistone(1, PISTONE_PIEDE, 1000, APRI);
        // thread_sleep_for(5000);
        // goA(1, CHIUDI);    // muovo le anche per fare il passo
        // thread_sleep_for(5000);
        // muoviPistone(1, PISTONE_PIEDE, 1000, CHIUDI);
        // thread_sleep_for(5000);
        // goA(1,0);
        // muoviPistone(2, PISTONE_PIEDE, 750, APRI);
        // thread_sleep_for(5000);
        // goA(2, APRI);
        // thread_sleep_for(5000);
        // muoviPistone(2, PISTONE_PIEDE, 1000, CHIUDI);
        // goA(2,0);
        // thread_sleep_for(5000);
        // muoviPistoni(3, 4, PISTONE_PIEDE, TEMPO_ALLUNGO_GAMBA, APRI, APRI);
        // thread_sleep_for(5000);
        // raddrizzaGambe(3,4);
        // thread_sleep_for(5000);

        //  muoviPistone(1, PISTONE_PIEDE, 1000, APRI);
        //  muoviPistone(2, PISTONE_PIEDE, 1000, APRI);
        //  muoviPistone(3, PISTONE_PIEDE, 1000, APRI);
        //  muoviPistone(4, PISTONE_PIEDE, 1000, APRI);



void keyControl(){
    while(true){
    while(pc.readable()){
        char newc = pc.getc();
        switch(newc){

            case 'l':   // Log sensori anca
                logSensoriAnca();
                break;
            case 'r':   // Reset pistoni (allunga tutti i piedi, raddrizza le anche)
                resetPistoni();
                break;
            case 'c': // Camminata continuata semplice
                camminataSemplice();
                break;
            case '1':
                muoviPistone(1, PISTONE_PIEDE, 1000, APRI);
                //thread_sleep_for(TEMPO_ALLUNGO_GAMBA);
                muoviPistone(1, PISTONE_PIEDE, 1000, CHIUDI);
                break;
            case '2':
                muoviPistone(2, PISTONE_PIEDE, 1000, APRI);
                //thread_sleep_for(TEMPO_ALLUNGO_GAMBA);
                muoviPistone(2, PISTONE_PIEDE, 1000, CHIUDI);
                break;
            case '3':
                muoviPistone(3, PISTONE_PIEDE, 1000, APRI);
                //thread_sleep_for(TEMPO_ALLUNGO_GAMBA);
                muoviPistone(3, PISTONE_PIEDE, 1000, CHIUDI);
                break;
            case '4':
                muoviPistone(4, PISTONE_PIEDE, 1000, APRI);
                //thread_sleep_for(TEMPO_ALLUNGO_GAMBA);
                muoviPistone(4, PISTONE_PIEDE, 1000, CHIUDI);
                break;
            default:
                pc.printf("inserisci un comando valido");
        }
    }
    }     
}





int main(){
    pc.printf("\n\n\r #################.  ELEFANTE START.  #################.\n\n\r");
    keyControl();
}
