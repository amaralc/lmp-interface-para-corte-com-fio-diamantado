#include <Stepper.h> //INCLUSÃO DE BIBLIOTECA
#define potPin1 0 // pino do potenciometro de velocidade
#define potPin2 1 // pino do potenciometro de avanço       
const int stepsPerRevolution = 64; //NÚMERO DE PASSOS POR VOLTA
int stepCount = 0;  
int valPot1 = 0;
int valPot2 = 0;
const int botao = 2;

// Variaveis de entrada

int numVoltas = 0;
int velocidade = 0;
int sentido = 0;
int sentidoRotacao = LOW; // LOW = Anti-horário e HIGH = horário
int estadoBotao = 0;      // Estado do botão, HIGH = apertado e LOW = solto
Stepper myStepper(stepsPerRevolution, 8,10,9,11); //INICIALIZA O MOTOR UTILIZANDO OS PINOS DIGITAIS

void setup(){ 
  pinMode(botao, INPUT_PULLUP);
   Serial.begin(9600);
  
}//end setup
 
void loop(){
  Serial.println(valPot1);
  delay (500);
 estadoBotao = digitalRead(botao);               // Lê a entrada  do botão
  if (estadoBotao == LOW) {                      // Se o botão for apertado
    delay(50);                                    // Espera 50 ms (necessário para o debouncing)
    estadoBotao = digitalRead(botao);             // Lê a entrada  do botão novamente
    while (!digitalRead(botao))                    // Só libera o programa após soltar o botão
    {
      //delay(30);
    }
    if (estadoBotao == LOW) {                    // Se o botão realmente for apertado faz a sequência normal
      if (sentidoRotacao == HIGH) {               // O sentido de rotação é horário?
        sentidoRotacao = LOW;                     // Muda para anti-horário
      }
      else {                                      // O sentido de rotação é anti-horário?
        sentidoRotacao = HIGH;                    // Muda para horário
      }
    }
  }
  if (sentidoRotacao == HIGH)  {
    // Configura o sentido de rotação como horário
    sentido = 1;
  }
  else  {
    // Configura o sentido de rotação como anti-horário
    sentido = -1;
  }

  /* avanço */
  
   
   valPot2 = analogRead(potPin2);
  if (valPot2 < 1024){
      
    int motorSpet = map(valPot1,0,1023,10,100);

    /*2*/ 
    if (motorSpet > 0){

      myStepper.step(motorSpet);

    }//end if2

  }//end if1  
  

        /* velocidade*/
  
 
  valPot1 = analogRead(potPin1);
  if (valPot1 < 1024){
      
    int motorSpeed = map(valPot1,0,1023,10,100);

    /*2*/ 
    if (motorSpeed > 0){

      myStepper.setSpeed(motorSpeed);
      myStepper.step(sentido*stepsPerRevolution); 

    }//end if2

  }//end if1    

       
 /* if (valPot > 530)/*3(*)/ {

    int motorSpeed = map(valPot,515,1024,0,100);  
    if (motorSpeed > 0)/*4(*)/{  

      myStepper.setSpeed(motorSpeed);
      myStepper.step(sentido*stepsPerRevolution);  

    }//end if4 
  }//end if3
*/
  
  /* float velocidade = valorPot * (20.0 / 1023.0);
    myStepper.setSpeed(300); //VELOCIDADE DO MOTOR
    myStepper.step(stepsPerRevolution); //GIRA O MOTOR NO SENTIDO ANTI-HORÁRIO
  delay (500);


  myStepper.step(-stepsPerRevolution); //GIRA O MOTOR NO SENTIDO HORÁRIO
  delay (500);
 */
}//end loop
