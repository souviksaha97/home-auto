#include <SoftwareSerial.h>

SoftwareSerial bluetooth(3, 2);

int greenLED = 8;
int redLED = 13;
int blueLED = 12;
int fanMotor = 7;
int servoMotor = 9;
int pumpMotor = 4;
int socketMotor = 2;

boolean state[7];
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bluetooth.begin(9600);
  pinMode(blueLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(fanMotor, OUTPUT);
  pinMode(servoMotor, OUTPUT);
  pinMode(pumpMotor, OUTPUT);
  pinMode(socketMotor, OUTPUT);
}



void green()
{
  Serial.println("Green Lights ON?OFF");
  state[0] = !state[0];
  digitalWrite(greenLED, state[0]);
}
void blue()
{
  Serial.println("Blue Lights ON?OFF");
  state[1] = !state[1];
  digitalWrite(blueLED, state[1]);
}
void red()
{
  Serial.println("Red Lights ON?OFF");
  state[2] = !state[2];
  digitalWrite(redLED, state[2]);
}
void fan()
{
  Serial.println("Motor ON?OFF");
  state[3] = !state[3];
  digitalWrite(fanMotor, state[3]);
}
void servo()
{
  Serial.println("Servo ON?OFF");
  state[4] = !state[4];
  digitalWrite(servoMotor, state[4]);
}
void pump()
{
  Serial.println("Pump ON?OFF");
  state[5] = !state[5];
  digitalWrite(pumpMotor, state[5]);
}

void socket()
{
  Serial.println("Socket Lights ON?OFF");
  state[6] = !state[6];
  digitalWrite(socketMotor, state[6]);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (bluetooth.available())
  {
    String str = bluetooth.readString();
    Serial.println(str);
    if (str.equalsIgnoreCase("*green#"))
      green();
    else if (str.equalsIgnoreCase("*red#"))
      red();
    else if (str.equalsIgnoreCase("*blue#"))
      blue();
    else if (str.equalsIgnoreCase("*fan#"))
      fan();
    else if (str.equalsIgnoreCase("*servo#"))
      servo();
    else if (str.equalsIgnoreCase("*pump#"))
      pump();
    else if (str.equalsIgnoreCase("*socket#"))
      socket();
    else
      Serial.println("Imroper Input!");
  }
}
