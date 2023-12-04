#include "Arduino.h"
//**************** PCA *********************************
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver servos = Adafruit_PWMServoDriver(0x40);
unsigned int pos0 = 172, pos180 = 565;

void setServo(uint8_t n_servo, int angulo) {
  int duty;
  duty=map(angulo,0,180,pos0, pos180);
  servos.setPWM(n_servo, 0, duty);  
}

//***************************************** Mov eyes ************************************************
void move_eyes(){
  int random1, random2;
  random1 = random(65,110), random2 = random(75,110);
  for(int i= random(65,110); i< random1; i++){
      setServo(8,i);
      delay(30);
    }
  for(int i= random(75,110); i< random2; i++){
    setServo(9,i);
    delay(30);
  }
}
//************************ Sleep ********************
void sleep(){

//****************** Eyebrows ******************************
  setServo(0,90);// eyebrow left****-> up 145*** down -> 90
  setServo(1,90);//eyebrow left***** ->up 154*** down -> 90
  setServo(2,50);//***** eyebrow right**-> up 15 ** down -> 50
  setServo(3,90);//**** eyebrow right** -> up 45 ** down -> 90
//************* eyelips ***************************************
  setServo(4, 110);//*****eyelip_up**->up 70**down -> 110
  setServo(5, 70);//*****eyelip_up**->up 110 **down ->70
  setServo(10, 70);//**** eyelip_down**->up 130 ** down-> 70
  setServo(11, 110);//**** eyelip_down** -> up 50** down ->100
//************************ Mouth ***********************************
  setServo(6,90);//********* mouth**->up 70**->down 90
  setServo(7,90);//******** mouth** ->up 110**->down 90
  //******************* eyes *************
  setServo(8, 65);//***********65 -> 110 **********************
  setServo(9, 110);//*********75 ->  110 ************
  //***************** Comusuras labios ***********************
  setServo(12, 90);//********** down->90 ********** up ->0
  setServo(13, 90);//********** down->90 ********** up ->120
  setServo(14, 90);//********** down->90 ********** up ->180
  setServo(15, 90);//********** down->90 ********** up ->80
  
}

//*************************** Normal *******************
void normal(){
  //************** Eyebrow /********************
  setServo(0,90);
  setServo(1,90);
  setServo(2,90);
  setServo(3,90);
  //************** Eyelip /********************
  setServo(4, 90);//*****eyelip_up**->up 90**down -> 130
  setServo(5, 140);//*****eyelip_up**->up 140 **down ->70
  setServo(10, 140);//**** eyelip_down**->up 140 ** down-> 80
  setServo(11, 30);//**** eyelip_down** -> up 30** down ->90
//************** Mouth /********************
  setServo(6,85);//********* mouth**->up 70**->down 90
  setServo(7,95);//******** mouth** ->up 110**->down 90
//***************** eyes **************
  setServo(8, 90);
  setServo(9, 90);
  //********************************
  setServo(12, 90);//******* comisuras labios up ** up-> 30 **** down -> 90 
  setServo(13,90);//******* comisuras labios up ** up-> 120 **** down -> 160
  setServo(14, 90);//******* comisuras labios down ** up-> 160 **** down -> 90 
  setServo(15,90);//******* comisuras labios down ** up-> 50 **** down -> 90
}
//*********************** wake up ******************
void wake_up_afer(){
  //************* open left eye ********
  for (int i=70; i<111; i++) {
    setServo(5, i);
    setServo(10, i+10);
    delay(21);
  }
  for (int k=110; k>71; k--) {
    setServo(4, k);
    setServo(11, k-20);
    delay(21);
  }
  delay(600);
  for (int i=0 ;i<6 ; i++) {
    move_eyes();
    delay(200);
  }
  sleep();
  delay(30);
  normal();
}

//************************* Eye gouge *********
void eye_gouge(){
  setServo(0,90);// eyebrow left
  setServo(1,90);//eyebrow left
  setServo(2,90);//****** eyebrow right
  setServo(3,90);//***** eyebrow right

  setServo(4, 100);//************ eyelip_up
  setServo(5, 80);//************ eyelip_up
  setServo(10, 90);//************ eyelip_down
  setServo(11, 40);//************ eyelip_down
  
  setServo(6,75);//********* mouth
  setServo(7,105);//******** mouth
  //******************* eyes *************
  setServo(8, 90);//***********60 -> 110 **********************
  setServo(9, 90);//*********75 ->  105 *
}

void surprise(){

  setServo(0,140);// eyebrow left
  setServo(1,140);//eyebrow left
  setServo(2,40);//****** eyebrow right
  setServo(3,40);//***** eyebrow right

  setServo(4, 90);
  setServo(5,140);
  setServo(10, 140);
  setServo(11, 30);

  setServo(6,70);//********* mouth
  setServo(7,100);//******** mouth

  setServo(12, 90);//******* comisuras labios up ** up-> 30 **** down -> 90 
  setServo(13,90);//******* comisuras labios up ** up-> 120 **** down -> 90
  setServo(14, 90);//******* comisuras labios down ** up-> 160 **** down -> 90 
  setServo(15,90);//******* comisuras labios down ** up-> 50 **** down -> 90


}

void angry(){
  setServo(0,90);// eyebrow left
  setServo(1,140);//eyebrow left
  setServo(2,40);//****** eyebrow right
  setServo(3,90);//***** eyebrow right

  setServo(4, 9);//************ eyelip_up
  setServo(5, 140);//************ eyelip_up
  setServo(10, 140);//************ eyelip_down
  setServo(11, 30);//************ eyelip_down

  setServo(6,85);//********* mouth
  setServo(7,95);//******** mouth

  setServo(8, 90);//****
  setServo(9, 90);//****

  setServo(12, 90);//******* comisuras labios up ** up-> 30 **** down -> 90 
  setServo(13,90);//******* comisuras labios up ** up-> 120 **** down -> 90
  setServo(14, 90);//******* comisuras labios down ** up-> 160 **** down -> 90 
  setServo(15,90);//******* comisuras labios down ** up-> 50 **** down -> 90

}

void smile(){
  setServo(0,90);
  setServo(1,90);
  setServo(2,90);
  setServo(3,90);

  setServo(4, 90);//************ eyelip_up
  setServo(5, 140);//************ eyelip_up
  setServo(10, 140);//************ eyelip_down
  setServo(11, 30);//************ eyelip_down

  setServo(6,90);//********* mouth
  setServo(7,90);//******** mouth

  setServo(8, 90);//**** Eye
  setServo(9, 90);//**** eye

  setServo(12, 30);//******* comisuras labios up ** up-> 30 **** down -> 90 
  setServo(13,120);//******* comisuras labios up ** up-> 120 **** down -> 90
  setServo(14, 160);//******* comisuras labios down ** up-> 160 **** down -> 90 
  setServo(15,50);//******* comisuras labios down ** up-> 50 **** down -> 90

}


void random_movs(int ran_mov){
  switch (ran_mov) {
    case 1:
      for (int i=0; i<3; i++) {
        move_eyes();
        delay(900);
      }
      break;
    case 2:
      normal();
      break;
    case 3:
      eye_gouge();
      break;
    case 4:
      surprise();
      break;
    case 5:
      angry();
      break;
    case 6:
      smile();
      break;
    default:
      normal();
      break;
  }
}