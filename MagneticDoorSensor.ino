//Declare Pins for Magnetic Sensor and Buzzer/LED
const int magSwitch = 8;
const int buzz = 9;
const int trig = 11;
const int echo = 12;

long duration;
float distance;

void setup() {
  // Set sensor as input and buzzer/LED as output
  pinMode(magSwitch,INPUT);
  pinMode(buzz,OUTPUT);
  // Set sensor pin to high
  digitalWrite(magSwitch,HIGH);
  // Set trig as output and echo as input
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);
}

void loop() {
  // Clears trig pin
  digitalWrite(trig,LOW);
  delayMicroseconds(2);

  // Set trig to HIGH for 10 microseconds
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);

  // find duration and distance
  duration = pulseIn(echo,HIGH);
  distance = duration*0.034/2;

  // Prints duration and distance
  Serial.print("Duration: ");
  Serial.println(duration);
  //Serial.print("Distance: ");
  //Serial.println(distance);
  
  if (digitalRead(magSwitch) == LOW)
  {
    digitalWrite(buzz,LOW);
  }
  else if ((digitalRead(magSwitch) == HIGH) && (distance <= 100))
  {
    digitalWrite(buzz,HIGH);
  }
  else
  {
    digitalWrite(buzz,HIGH);
    delay(100);
    digitalWrite(buzz,LOW);
    delay(100);
  }

}
