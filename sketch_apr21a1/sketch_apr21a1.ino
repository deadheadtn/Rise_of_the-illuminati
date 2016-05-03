int xPin = A1;
int yPin = A0;
int button1 =8;
int button2 =9;
int led1=12;
int led2=13;
int xPosition = 0;
int yPosition = 0;
int calibration=2;  
int buttonState=0;
char data;

void setup() {
  Serial.begin(9600); 
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(calibration,LOW);
}

void loop() {
  buttonState = digitalRead(button1);
  xPosition = analogRead(xPin);
  yPosition = analogRead(yPin);
  if(xPosition>230 && xPosition<240 && yPosition==760 || yPosition==761)
     Serial.print("i\n");
   else if(xPosition>340 && yPosition>1016)
     Serial.print("l\n");
   else if(yPosition>950 && yPosition<1000&& xPosition>330 && xPosition<850)
      Serial.print("d\n");
   else if(xPosition==0  && yPosition>950)
     Serial.print("u\n");
   else if(xPosition<500 && xPosition>100 && yPosition>1016)
    Serial.print("r\n");
   delay(150);
   if(Serial.available() >0)
   {
     char data = (char) Serial.read();
     delay (5);
   }
     if((char)Serial.read()=='1')
     {
       digitalWrite(led1, HIGH);
       digitalWrite(led2, HIGH);
     }
     else if((char)Serial.read()=='0')
     {
       digitalWrite(led1, LOW);
       digitalWrite(led2, LOW);
     }
   
}
