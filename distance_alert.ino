const int trigPin = 9;
const int echoPin = 10;
const int buzzerPin = 8;
const int ledPin = 7;

long duration;
float distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 30000); 
  distance = duration * 0.034 / 2;

  if (duration == 0 || distance > 300) {
    Serial.println("No object detected");
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, LOW);
  } else {
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    if (distance < 20) {
      digitalWrite(buzzerPin, HIGH);
      digitalWrite(ledPin, HIGH);
    } else {
      digitalWrite(buzzerPin, LOW);
      digitalWrite(ledPin, LOW);
    }
  }

  delay(500); 
}
