#include <Stepper.h> //INCLUSÃO DE BIBLIOTECA
#define potPin 0 // pino do potenciometro
        const int stepsPerRevolution = 64; //NÚMERO DE PASSOS POR VOLTA
        int stepCount = 0;  
        int valPot = 0;

    Stepper myStepper(stepsPerRevolution, 8,10,9,11); //INICIALIZA O MOTOR UTILIZANDO OS PINOS DIGITAIS

void setup(){
  
  }//end setup
 
void loop(){
 
         valPot = analogRead(potPin);
         if (valPot < 470){
            int motorSpeed = map(valPot,500,0,0,100);
         
         if (motorSpeed > 0){
          myStepper.setSpeed(motorSpeed);
          myStepper.step(stepsPerRevolution);
          
          }//end if2
         }//end if1
           
           
          if (valPot > 530) {
           int motorSpeed = map(valPot,515,1024,0,100);
          
          if (motorSpeed > 0){
            myStepper.setSpeed(motorSpeed);
            myStepper.step(-stepsPerRevolution); 
            
            }//end if4 
          }//end if3

          
          /* float velocidade = valorPot * (20.0 / 1023.0);
           myStepper.setSpeed(300); //VELOCIDADE DO MOTOR
           myStepper.step(stepsPerRevolution); //GIRA O MOTOR NO SENTIDO ANTI-HORÁRIO
          delay (500);
  
 
          myStepper.step(-stepsPerRevolution); //GIRA O MOTOR NO SENTIDO HORÁRIO
          delay (500);
 */
}//end loop
