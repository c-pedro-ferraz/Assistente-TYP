/*				Assistente TYP
				Facens 2021 - ADS
				Fabrica de Projetos I
				Pedro Ferraz - 210047		
                Projeto dedicado a minha mãe Vanda <3 */

//Declaro a biblioteca do LCD e definindo as portas

#include <LiquidCrystal.h>

#define D4 5
#define D5 4
#define D6 3
#define D7 2
#define E 6
#define RS 7
#define intervalo 10

//Declaro as Variaveis

int led1 = 11;
int led2 = 12;
int led3 = 13;
int alarme = 0;
int buzzer = 8;
LiquidCrystal LCD(7, 6, 5, 4, 3, 2);

// Inicio o Void SETUP
void setup()
{
  //Variaveis de Saida  
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
  pinMode (led3, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  //Defino a quantidade de colunas e linhas do LCD  
  LCD.begin(16, 2);
}

//Inicio o loop
void loop()
{
  //Mensagem após o reset
  LCD.setCursor(2, 0);
  LCD.print("NOS VEMOS");
  LCD.setCursor(2, 1);
  LCD.print("EM 24HRS");
  delay(4000);
  
  //Mensagem fixa até que de o tempo de 24hrs
  LCD.setCursor(2, 0);
  LCD.print("TYP AO SEU");
  LCD.setCursor(2, 1);
  LCD.print("DISPOR VANDA");
  
  //Bip para confirmar o reset
  tone(buzzer,500,800);
  
  //Piscar das leds para confirmar o reset
   digitalWrite(led1, HIGH);  
    delay(100);
    digitalWrite(led1,LOW);  
    delay(100);
  
   digitalWrite(led2, HIGH);  
    delay(100);
    digitalWrite(led2,LOW);  
    delay(100);
  
   digitalWrite(led3, HIGH);  
    delay(100);
    digitalWrite(led3,LOW);  
    delay(100);
  
  /* Define o intervalo de tempo que irá acionar o assistente
  (O coração do código)  */
  
  delay(15000);
  
/* Conversão Horas em Milissegundos
  24Hrs = 86400000
  12Hrs = 43200000
  8Hrs 	= 28800000
  4Hrs	= 14400000
  2Hrs	= 7200000
  1Hr	= 3600000
  15s	= 15000 (Para demonstração) */ 
 
  //Após o tempo determinado vai para a chamada do buzzer
  goto buzzer;

  //Inicia o estado do buzzer
  buzzer:  
  {
    
  //Primeira mensagem
  LCD.setCursor(2, 0);
  LCD.print("SENHORA VANDA!");
  LCD.setCursor(2, 1);
  LCD.print("SENHORA VANDA!");
  
    //Primeira sequencia de LEDs
    digitalWrite(led1, HIGH);  
    delay(100);
    digitalWrite(led1,LOW);  
    delay(100);
  
   digitalWrite(led2, HIGH);  
    delay(100);
    digitalWrite(led2,LOW);  
    delay(100);
  
   digitalWrite(led3, HIGH);  
    delay(100);
    digitalWrite(led3,LOW);  
    delay(100);   
   
    //Primeiro alarme
  for (alarme = 150; alarme < 1800; alarme += 1) 
  {   
    tone(buzzer, alarme, intervalo); 
    delay(1);       
  }
    
  for (alarme = 1800; alarme > 150; alarme -= 1) 
  {
    tone(buzzer, alarme, intervalo); 
    delay(1);
  }
    
    //Segunda sequencia de LEDs
    digitalWrite(led1, HIGH);  
    delay(100);
    digitalWrite(led1,LOW);  
    delay(100);
  
   digitalWrite(led2, HIGH);  
    delay(100);
    digitalWrite(led2,LOW);  
    delay(100);
  
   digitalWrite(led3, HIGH);  
    delay(100);
    digitalWrite(led3,LOW);  
    delay(100);  
  
    //Segunda mensagem
  LCD.clear();
  delay(1000);
  LCD.setCursor(2, 0);
  LCD.print("HORA DE TOMAR");
  LCD.setCursor(2, 1);
  LCD.print("LOSARTANA !!!");
    
    //Terceira sequencia de LEDs
   digitalWrite(led1, HIGH);  
    delay(100);
    digitalWrite(led1,LOW);  
    delay(100);
  
   digitalWrite(led2, HIGH);  
    delay(100);
    digitalWrite(led2,LOW);  
    delay(100);
  
   digitalWrite(led3, HIGH);  
    delay(100);
    digitalWrite(led3,LOW);  
    delay(100); 
    
   //Segundo alarme
   for (alarme = 150; alarme < 1800; alarme += 1) 
  {
    tone(buzzer, alarme, intervalo); 
    delay(1);
  }
  for (alarme = 1800; alarme > 150; alarme -= 1) 
  {
    tone(buzzer, alarme, intervalo); 
    delay(1);
  }
    
    //Quarta sequencia de LEDS
  digitalWrite(led1, HIGH);  
    delay(100);
    digitalWrite(led1,LOW);  
    delay(100);
  
   digitalWrite(led2, HIGH);  
    delay(100);
    digitalWrite(led2,LOW);  
    delay(100);
  
   digitalWrite(led3, HIGH);  
    delay(100);
    digitalWrite(led3,LOW);  
    delay(100); 
 
  delay(1000);
    
    //Repete a chamada do buzzer    
    goto buzzer;
    //Até que o reset seja acionado e inicia a contagem novamente
  }
}