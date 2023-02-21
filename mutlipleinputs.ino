int pin = 2; 
int pin2 = 3;
//declare the pin 2 for the interrupt

volatile int state = LOW; 
//initialse it as low
//Declare them as volatile 

void setup() 
{
   Serial. begin(9600);
   pinMode(13, OUTPUT); 
   //set the pinmode as output for 13 pin
   pinMode(2, INPUT);
   pinMode(3, INPUT);
   //set the pinmode as input for pin 2 and 3
   attachInterrupt(digitalPinToInterrupt(pin), flash, CHANGE);
   //interrupt at pin 2 blink when pin to change the value,
   //change value means when the motion is detected
   
   attachInterrupt(digitalPinToInterrupt(pin2), light, CHANGE);
   //interrupt at pin 3 blink when pin to change the value,
   //change value means when the motion is detected
} 
void loop() { 
 
} 

void flash() { 
   state = !state; //toggle the state when the interrupt occurs
  digitalWrite(13, state); //pin 13 have the new value of state
  Serial.println("Blink from first sensor");
  delay(1000);
}
void light() { 
   state = !state; //toggle the state when the interrupt occurs
  digitalWrite(13, state); //pin 13 have the new value of state
  Serial.println("Blink from second sensor");
  delay(1000);
}
