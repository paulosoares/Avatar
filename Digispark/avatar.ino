#define USB_CFG_DEVICE_NAME     'D','i','g','i','B','l','i','n','k'
#define USB_CFG_DEVICE_NAME_LEN 9
#include <DigiUSB.h>

#define RED     2
#define GREEN   1
#define BLUE    0

int brightness = 0;
int fadeAmount = 5;

int cor;

boolean estado = false;
boolean stringComplete = false;

void fade(int cor);

void setup()  { 
  DigiUSB.begin();  
  DigiUSB.println("...Iniciado..."); 
  
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  digitalWrite(RED, HIGH);     
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);   
} 

void loop()  {  
  DigiUSB.refresh();

  if (DigiUSB.available() > 0) {
      char inChar = (char) DigiUSB.read(); 

      if (inChar == '1') { estado = true; DigiUSB.println("ON"); }
      if (inChar == '0') { estado = false; DigiUSB.println("OFF"); }
  }
  
    if (estado)
      cor = GREEN;
    else
      cor = RED;  
      
  fade(cor);  
}

void fade(int cor) {
  digitalWrite(RED, HIGH);     
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);  

analogWrite(cor, brightness);

  brightness += fadeAmount;

  if (brightness <= 0 || brightness >= 255) fadeAmount = -fadeAmount;          

  delay(30); 
}
