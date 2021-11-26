const int ledPin =13;
const int alarm=2;
const int buzzer=11;
const int trigPin = 9;
const int echoPin = 10;
int pirstate = 0;
int maxRange = 200;
int minRange =100;
long duration;
int distance;


void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(buzzer, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(alarm, INPUT); 
  Serial.begin(9600);
}


void loop() {
  
  if(digitalRead(alarm) == HIGH)
  {

    // Clears the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);

    // Calculating the distance
    distance= duration/29 /2;

    if (distance >= minRange && distance <= maxRange){
      //digitalWrite(buzzer, HIGH);
      Serial.println("-1");
      digitalWrite(ledPin, HIGH);
    }
    else if (distance <= minRange){
      Serial.println("-1");
      digitalWrite(buzzer, HIGH);
      digitalWrite(ledPin, HIGH);
    }

    else{
      Serial.println(distance);
      digitalWrite(buzzer, LOW);
      digitalWrite(ledPin, LOW);
    }
    
    if(pirstate = 0) {

      // Prints the distance on the Serial Monitor
      Serial.println("Motion Detected!");
      pirstate=0;
    }
      Serial.print("Distance: ");
      Serial.println(distance);

  }
  else {

    if(pirstate == 1){
    Serial.println("Motion Ended!");
    pirstate=0;
  }


  }
  //delay(1000);
}
