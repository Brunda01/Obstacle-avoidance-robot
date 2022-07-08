const int trigPin = 13;
const int echoPin = 12;
const int in1 = 2;
const int in2 = 3;
const int in3 = 4;
const int in4 = 5;


void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(9600);
}

long duration;
int distance;
void loop()
{
  digitalWrite(trigPin, LOW);
  delay(2);
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin, HIGH);
  distance = duration* 0.034/2;
  Serial.println(distance);
  
  if(distance<50){
    digitalWrite(in1, HIGH); // one pin HIGH and the other Pin LOW
    digitalWrite(in2, LOW);  // As to rotate in forward direction
    digitalWrite(in3, LOW); // If 3 are low and 1 is high then
    digitalWrite(in4, LOW);  // one motor works and the other doesn't
    }
  
  else {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delay(200);   
  }
}
