#define RED     9
#define GREEN  10
#define BLUE   11
#define COMMON 12

int brightness = 0;
int fadeAmount = 5;

int cor;

boolean estado = false;
boolean stringComplete = false;

void fade(int cor);

void setup()  { 
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(COMMON, OUTPUT);
 
  digitalWrite(COMMON, HIGH); 
  
  Serial.begin(9600);
  Serial.println("...Iniciado...");  
} 

void loop()  {  
  
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
  
    if (brightness == 0 || brightness == 255) fadeAmount = -fadeAmount;          
  
    delay(30); 
}

void serialEvent() {
    while (Serial.available()) {
      char inChar = (char) Serial.read(); 

      if (inChar == '1') { estado = true; Serial.println("ON"); }
      if (inChar == '0') { estado = false; Serial.println("OFF"); }
    }
}