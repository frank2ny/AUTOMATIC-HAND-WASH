
#define trigPin1 A0
#define echoPin1 A1
#define trigPin2 A2
#define echoPin2 A3
int soapled=10;
int waterled=11;
int ALARM = 8;
int pump = 9;
long duration, distance, FIRSTSensor,SECONDSensor;
void setup()
{

Serial.begin (9600);
pinMode(soapled,OUTPUT);
pinMode(waterled,OUTPUT);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);

pinMode(ALARM, OUTPUT);pinMode(pump,OUTPUT);
digitalWrite(ALARM, LOW);digitalWrite(pump,LOW);
 
}

void loop() 
{
/////////////////////////////////////////////////////// 
SonarSensor(trigPin1, echoPin1);
FIRSTSensor = distance;
SonarSensor(trigPin2, echoPin2);
SECONDSensor = distance;
digitalWrite(ALARM, LOW);
digitalWrite(pump,LOW);
Serial.print("S1:");Serial.println(FIRSTSensor); delayMicroseconds(10);
Serial.print("S2:");Serial.println(SECONDSensor);delayMicroseconds(10);
delay(1000);
if((FIRSTSensor >= 5) & (FIRSTSensor <= 12)) 
{digitalWrite(waterled, HIGH);
  digitalWrite(ALARM, HIGH);
delay(5500);
Serial.println("water pump is on");
digitalWrite(ALARM,LOW);digitalWrite(waterled,LOW);}
if((SECONDSensor >= 5) & (SECONDSensor <= 12)) 
{digitalWrite(soapled,HIGH);digitalWrite(pump, HIGH);
Serial.println("Soap pump is on");
delay(2000);
digitalWrite(pump, LOW);digitalWrite(soapled,LOW);}
}
void SonarSensor(int trigPin,int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
}
