/////////////////////////////////////////////////////////////

// AUTHOR: FELICIA LIU
// DATE: FEBRUARY 15, 2025
// CODE IS FREE TO USE FOR HI-SKULE PURPOSES

const int xAxis = A0;  // Joystick X axis
const int yAxis = A1;  // Joystick Y axis

const int redPin = 9;    // PWM pin for Red LED
const int greenPin = 10; // PWM pin for Green LED
const int bluePin = 11;  // PWM pin for Blue LED
const int buzzer = 6;    // Buzzer pin

const int threshold = 200; // Dead zone threshold (adjust as needed)

void setup() {
  Serial.begin(9600); // Start serial communication
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  int xValue = analogRead(xAxis); // Read X axis
  int yValue = analogRead(yAxis); // Read Y axis

  if (xValue < (512 - threshold) && yValue < (512 - threshold)) {
    Serial.println("Top-Right");
    setColor(255, 165, 0); // Orange
    tone(buzzer, 587); // D5
  } 
  else if (xValue < (512 - threshold) && yValue > (512 + threshold)) {
    Serial.println("Bottom-Right");
    setColor(0, 255, 0); // Green
    tone(buzzer, 698); // F5
  } 
  else if (xValue > (512 + threshold) && yValue > (512 + threshold)) {
    Serial.println("Bottom-Left");
    setColor(75, 0, 130); // Indigo
    tone(buzzer, 880); // A5
  } 
  else if (xValue > (512 + threshold) && yValue < (512 - threshold)) {
    Serial.println("Top-Left");
    setColor(255, 0, 255); // Magenta
    tone(buzzer, 1046); // C6
  } 
  else if (yValue > (512 + threshold)) {
    Serial.println("Down");
    setColor(0, 0, 255); // Blue
    tone(buzzer, 784); // G5
  } 
  else if (yValue < (512 - threshold)) {
    Serial.println("Up");
    setColor(255, 0, 0); // Red
    tone(buzzer, 523); // C5
  }
  else if (xValue > (512 + threshold)) {
    Serial.println("Left");
    setColor(148, 0, 211); // Violet
    tone(buzzer, 988); // B5
  } 
  else if (xValue < (512 - threshold)) {
    Serial.println("Right");
    setColor(255, 255, 0); // Yellow
    tone(buzzer, 659); // E5
  } 
  else {
    Serial.println("Centered");
    setColor(0, 0, 0); // Off
    noTone(buzzer); // Stop sound
  }
  delay(100); 
}

// Set RGB color
void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

/////////////////////////////////////////////////////////////