// Hello World sketch for Arduino Mega 2560 R3
// Blinks the onboard LED (pin 13), beeps a buzzer (pin 8) for 100ms, and prints "Hello, World!" over Serial

const int LED_PIN = 13;
const int BUZZER_PIN = 8;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  Serial.println("Hello, World!");

  tone(BUZZER_PIN, 1000, 100);
  delay(1000);

  digitalWrite(LED_PIN, LOW);
  delay(1000);
}
