#include "Functions.h"

unsigned long previues_1, current_1;
int random_mov;
const int  time = 1200;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servos.begin();
  servos.setPWMFreq(60);
  //sleep();
  //delay(1500);
  //wake_up_afer();

}

void loop() {
   //put your main code here, to run repeatedly:
  current_1 = millis();
  if ((current_1 - previues_1)>= time) {
    previues_1 = current_1;
    random_mov = random(1,9);
    random_movs(random_mov);
    //Serial.println(random_mov);
  }
  
 
  
  
}
