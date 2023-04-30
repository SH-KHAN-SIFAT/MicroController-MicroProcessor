#include <Servo.h>
#include<Wire.h>
#include <LiquidCrystal_I2C.h>;

int sensorPin = A0;
int outputValue ;
const int RELAY_PIN = 3;
int pos = 0,pos2=0; 

int flag=1;
Servo myservo,servo;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {

  pinMode(RELAY_PIN, OUTPUT);
  myservo.attach(10);
  servo.attach(9);

  lcd.init();
  lcd.backlight();
  lcd.print("Reading Data From the Sensor ...");
  delay(2000);
  
}

void loop() {

if(flag=1){
  pos2 = 0;
    servo.write(pos2);              // tell servo to go to position in variable 'pos'                    
    delay(1000);                    // waits 1m for the servo to reach the position
    pos2 = 180;
    servo.write(pos2);              // tell servo to go to position in variable 'pos'
    delay(10);                      // waits 10ms for the servo to reach the position
    flag=0;
}            

func();
  
}
void func(){
  for (pos = 30; pos <= 60; pos += 1) {       // goes from 30 degrees to 60 degrees in steps of 1 degree
    myservo.write(pos);                       // tell servo to go to position in variable 'pos'
    delay(10);                                // waits 10ms for the servo to reach the position
  }
  for (pos = 60; pos >= 30; pos -= 1) {       // goes from 60 degrees to 30 degrees
    myservo.write(pos);                       // tell servo to go to position in variable 'pos'
    delay(10);                                // waits 10ms for the servo to reach the position
}

  outputValue= analogRead(sensorPin);
  outputValue=constrain(outputValue,485,1023);
  outputValue=map(outputValue,485,1023,100,0);

  lcd.setCursor(0,0);
  lcd.print("Moisture: ");
  lcd.print(outputValue);
  lcd.print("%");
  if(outputValue<40)  {
    digitalWrite(RELAY_PIN, LOW);
    delay(500);
  }else{
    digitalWrite(RELAY_PIN, HIGH);
    delay(500);
  }
  delay(1000);
  lcd.clear();
}
