/*all projects available
 * Auto handwash system using arduino
 * All code available in https://github.com/NirmalKnock/Auto_Hand_wash_system

 */
int pump =8;
int pump1 =9;

//sensor for water pump
const int trigPin = 7;
const int echoPin = 6;

//sensor for soup solution
const int trigPin1 = 4;
const int echoPin1 = 5;

float duration, distance,duration1, distance1;


void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(pump,OUTPUT);
  digitalWrite(pump,LOW);
  pinMode(echoPin, INPUT);

   pinMode(trigPin1, OUTPUT);
  pinMode(pump1,OUTPUT);
  digitalWrite(pump1,LOW);
  pinMode(echoPin1, INPUT);
  Serial.begin(9600);
 
}

void loop() {
  digitalWrite(trigPin, LOW);
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
   digitalWrite(trigPin1, LOW);

  duration = pulseIn(echoPin, HIGH);
    duration1 = pulseIn(echoPin1, HIGH);

  distance1 = (duration1*.0343)/2;
    distance = (duration*.0343)/2;

  Serial.print("Water Distance:  ");
  Serial.println(distance);
  Serial.print("Soap Distance:  ");
  Serial.println(distance1);
  delay(500);
if(distance<15){    //use can increase the distancen   
  /* Due to the TTL logic of relay and Arduino , I writen  digitalwrite as LOW, if after building your project ,if they works in opposite mode
  just change digitalWrite as Hign in (if condition ) and Low in else condition.
  Otherwise skip this comment*/
    digitalWrite(pump,HIGH);
    delay(7000);   //You can increase the water timing
    digitalWrite(pump,LOW);
  }
  if(distance1<10){    //use can increase the distancen   
  /* Due to the TTL logic of relay and Arduino , I writen  digitalwrite as LOW, if after building your project ,if they works in opposite mode
  just change digitalWrite as Hign in (if condition ) and Low in else condition.
  Otherwise skip this comment*/
    digitalWrite(pump1,HIGH);
    delay(3000);   //You can increase the water timing
    digitalWrite(pump1,LOW);
  }
  else{
    digitalWrite(pump,LOW);
    digitalWrite(pump1,LOW);
  }
}
