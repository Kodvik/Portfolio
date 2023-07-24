/*--------------- Inclusão de bibliotecas ---------------*/
#include <ESP32Time.h> //biblioteca gratuita para utilização do RTC
#include <BluetoothSerial.h> // Biblioteca de bluetooth
#include <ESP32Servo.h> //biblioteca para utilização de servo motores com ESP32
#include <math.h>
/*--------------- Fim de Inclusão de bibliotecas ---------------*/

/*--------------- Definição de pinos ---------------*/
#define   botaoAlarme       12  //botão para interromper o alarme e sair do loop de alarme
#define   LED_SLOT1         14  //LED do slot 1 do dispenser para alarme no GPIO4 (pin 24)
#define   LED_SLOT2         27  //LED do slot 2 do dispenser para alarme no GPIO16 (pin 25)
#define   LED_SLOT3         26  //LED do slot 3 do dispenser para alarme no GPIO17 (pin 27)
#define   LED_SLOT4         25  //LED do slot 4 do dispenser para alarme no GPIO5 (pin 34)
#define   BUZZER            33  //BUZZER do alarme no GPIO18 (pin 33)
#define   PINO_SERVO_TAMPA  2   //Pino PWM utilizado para controlar o servo no GPIO13 (pin 20) 
#define   tempoAntiBounce   50  //Limitador de tempo em milisegundos que vai ser utilizado
/*--------------- Fim da definição de pinos ---------------*/


/*--------------- Declaração de variaveis, constantes e estruturas utilizadas ---------------*/
int segundos;
bool condicaoDeParada = false;            //utilizado para o alarme
int ESTADO=1;                             //utilizado para alternar estado, fazendo LEDs piscar e o buzzer alternar
int temporizadorDePrevencaoDeBounce = 50; //utilizado na função de parada do alarme (medido em milisegundos)
Servo servoTampa;                         //definição de nome do servo para ''tampa''
BluetoothSerial ESP_BT;                   //definição de nome do bluetooth ''ESP_BT''
double coletaDadosSerialBT;               //utiliado para recebimento da informação no serial
double IDrecebido;
String cmd = "";
String manipula = "";
char recebe;
int cont = 0;
struct ALARMES{
  int SLOTID;
  int minutos;
  int horas;
  int dia;
  int mes;
};
/*--------------- Fim da declaração de variaveis e constantes utilizadas ---------------*/

ESP32Time rtc(0); //Inicialização do RTC

void setup() {
  Serial.begin(115200);
  ESP_BT.begin("Dispenser_Remedios");
  
  Serial.println("/*---------- Iniciando configurações ----------*/");
  
  /*--------------- Setup de pinos ---------------*/
  pinMode(botaoAlarme,INPUT_PULLUP);
  pinMode(LED_SLOT1, OUTPUT);
  pinMode(LED_SLOT2, OUTPUT);
  pinMode(LED_SLOT3, OUTPUT);
  pinMode(LED_SLOT4, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(PINO_SERVO_TAMPA, OUTPUT);
  /*--------------- Fim setup de pinos ---------------*/
  
  /*--------------- teste de LEDs e buzzer ---------------*/
  Serial.println("teste de LEDs e Buzzer");
  for(int i=0 ; i<4 ; i++){
    digitalWrite(LED_SLOT1,ESTADO);
    digitalWrite(LED_SLOT2,ESTADO);
    digitalWrite(LED_SLOT3,ESTADO);
    digitalWrite(LED_SLOT4,ESTADO);
    digitalWrite(BUZZER,ESTADO);
    delay(1000);
    if(ESTADO == 1){
      ESTADO = 0;
    }
    else if(ESTADO == 0){
      ESTADO =1;
    }
  }
  Serial.println("fim do teste de LEDs e buzzer");
  /*--------------- fim teste de LEDs e buzzer ---------------*/

  /*--------------- setup e teste do servo motor ---------------*/
  Serial.println("Iniciando teste do servo motor");
  
  servoTampa.attach(PINO_SERVO_TAMPA);
  
  servoTampa.write(0);
  delay(2000);
  servoTampa.write(45);
  delay(2000);
  servoTampa.write(90);
  delay(2000);
  servoTampa.write(135);
  delay(2000);
  servoTampa.write(180);
  delay(2000);
  servoTampa.write(90);
  delay(200);

  Serial.println("fim do teste do servo motor");
  /*--------------- fim do setup e teste o servo motor ---------------*/
  Serial.println("/*---------- Finalizado inicialização e configurações ----------*/");
}

void atualizaAlarme(int ID, int dados){
  
  Serial.println("Atualiando SLOT: ");
  Serial.print(ID);
  Serial.println(" ");
  if(ID == 8){
    ATUAL.minutos = (dados)%100;
    dados = dados/100;
    ATUAL.horas = (dados)%100;
    dados = dados/100;
    ATUAL.mes =(dados)%100;
    dados = dados/100;
    ATUAL.dia = (dados)%100;
    rtc.setTime(00, ATUAL.minutos, ATUAL.horas, ATUAL.dia, ATUAL.mes, 2023);
  }
  else{
    SLOTS[ID].minutos   =  (dados)%100;
    dados = dados/100;
    SLOTS[ID].horas = (dados)%100;
    dados = dados/100;
    SLOTS[ID].mes   = (dados)%100;
    dados = dados/100;
    SLOTS[ID].dia   = (dados)%100;
  }

}

void disparaAlarme(int ID){
  Serial.println(ID);
  servoTampa.write(0); // move o servo para a posição de slot 1 (POSIÇÃO TEORICA NO MOMENTO, PRECISO MEDIR PARA TER PRECISÃO)
  delay(500);
  while(condicaoDeParada != true){
    if(ID == 0){
      Serial.println("Alarme ativado:");
      Serial.print(ID);
      Serial.println(" ");
      digitalWrite(LED_SLOT1,ESTADO); 
      digitalWrite(BUZZER,ESTADO);
      servoTampa.write(0);
    }else if(ID ==1){
      digitalWrite(LED_SLOT2,0);
      digitalWrite(BUZZER,ESTADO);
      servoTampa.write(45);
    }else if(ID ==2){ 
      digitalWrite(LED_SLOT3,0);
      digitalWrite(BUZZER,ESTADO);
      servoTampa.write(135);
    }else if(ID ==3){ 
      digitalWrite(LED_SLOT4,0);
      digitalWrite(BUZZER,ESTADO);
      servoTampa.write(180);
    }
    delay(1000);
    paraAlarme();
    if(ESTADO == 1){
      ESTADO = 0;
    }
    else if(ESTADO == 0){
      ESTADO =1;
    }
  }

}

void paraAlarme (){
  
  if ( digitalRead(botaoAlarme) == LOW ) {
    
    delay(temporizadorDePrevencaoDeBounce); // anti bounce simples 

    if( digitalRead(botaoAlarme) == LOW){
      Serial.println("parando alarme");
      Serial.println(" ");
      condicaoDeParada = true;
      digitalWrite(LED_SLOT1,0);
      digitalWrite(LED_SLOT2,0); 
      digitalWrite(LED_SLOT3,0); 
      digitalWrite(LED_SLOT4,0);
      digitalWrite(BUZZER,0);
      servoTampa.write(90); // retorna o servo para a posição de fechado
    }
 
  }

}

void loop() {
  ATUAL.SLOTID=9;
  SLOTS[0].SLOTID=1;
  SLOTS[1].SLOTID=2;
  SLOTS[2].SLOTID=3;
  SLOTS[3].SLOTID=4;

  if(ESP_BT.available()){
    
    recebe = ESP_BT.read();
    cmd+= recebe;

    if(recebe == '\n'){
      //Serial.println(cmd);
      coletaDadosSerialBT = cmd.toDouble();
      Serial.println(coletaDadosSerialBT);
      /*tratamento dos dados recebidos*/
      IDrecebido = coletaDadosSerialBT/100000000;
      atualizaAlarme(IDrecebido-1,coletaDadosSerialBT);
      cmd="";
      Serial.println(rtc.getTime("%A, %B %d %Y %H:%M:%S")); // print hora para debug
      /*--------------- fim do tratamento dos dados recebidos ---------------*/    
    }
    ///coletaDadosSerialBT = ESP_BT.read(); //como o nome da variavel onde foi salvo diz, informações que estavam no buffer do serial foram coletadas.
    //Serial.println(coletaDadosSerialBT);   
  }

  int aux=segundos;
  segundos=rtc.getSecond();
  ATUAL.minutos = rtc.getMinute();
  ATUAL.horas = rtc.getHour(true);
  ATUAL.dia = rtc.getDay();
  ATUAL.mes = (rtc.getMonth())+1;
  if(segundos!=aux){
    Serial.println(rtc.getTime("%A, %B %d %Y %H:%M:%S")); // print hora para debug
  }


  for(int i=0 ; i <4 ; i++){
    if((SLOTS[i].mes) == ATUAL.mes){
      if((SLOTS[i].dia) == ATUAL.dia){
        if((SLOTS[i].horas) == ATUAL.horas){
          if((SLOTS[i].minutos) == ATUAL.minutos){
            disparaAlarme(i);
          }
        }
      }
    }
  }
    
  if(condicaoDeParada){
    for(int i=0; i < 4 ; i++){
      if((ATUAL.mes) == SLOTS[i].mes){
        if((ATUAL.dia) == SLOTS[i].dia){
          if((ATUAL.horas) == SLOTS[i].horas){
            if((ATUAL.minutos) == (SLOTS[i].minutos)+1){
              condicaoDeParada = false;
            }
          }
        }
      }
    }
  }
}