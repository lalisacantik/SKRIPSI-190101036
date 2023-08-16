int lowerThreshold = 360;
int upperThreshold = 430;


#define sensorPower 8
#define sensorPin A0
#define R1 12


int val = 0;


int blueLED = 2;
int redLED = 4;


void setup() {
  Serial.begin(9600);
  pinMode(sensorPower, OUTPUT);
  digitalWrite(sensorPower, LOW);
  
  
  pinMode(blueLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode (R1, OUTPUT);

  digitalWrite(blueLED, LOW);
  digitalWrite(redLED, LOW);
  digitalWrite (R1, LOW);
}

void loop() {
  int level = readSensor();

  if (level == 0) {
    Serial.println("Water Level: Empty");
    digitalWrite(blueLED, LOW);
    digitalWrite(redLED, LOW);
    digitalWrite (R1, LOW);
 
    
  }
  else if (level > 0 && level <= lowerThreshold) {
    Serial.println("Water Level: Low");
    digitalWrite(blueLED, HIGH);
    digitalWrite(redLED, LOW);
    digitalWrite (R1, LOW);

  }
  else if (level > upperThreshold) {
    Serial.println("Water Level: High");
    digitalWrite(blueLED, LOW);
    digitalWrite(redLED, HIGH);
    digitalWrite (R1, HIGH);
    
  }
  delay(500);
}

//This is a function used to get the reading
int readSensor() {
  digitalWrite(sensorPower, HIGH);
  delay(10);
  val = analogRead(sensorPin);
  digitalWrite(sensorPower, LOW);
  return val;
}
