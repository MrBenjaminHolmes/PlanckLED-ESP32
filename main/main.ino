void setup() {
  Serial.begin(9600);
}

float readAnalog(int pin, int samples) {
  long sum = 0;
  for (int i = 0; i < samples; i++) {
    sum += analogRead(pin);
    delay(2);
  }
  float avg = sum / float(samples);
  return avg * (3.3 / 4095.0);
}

void loop() {

  delay(5000);
  Serial.println("Press any key to start");

  while (Serial.available() == 0) {}

  while (Serial.available() > 0) Serial.read();

  Serial.println("Starting in 5 seconds...");
  delay(5000);

  while (true) {
    float Vin = readAnalog(A0, 10);   // resistor
    float Vled = readAnalog(A1, 10);  // across LED

    float current_mA = ((Vin - Vled) / 220.0) * 1000.0;

    Serial.print(current_mA, 4);
    Serial.print(",");
    Serial.println(Vled, 4);

    delay(100);
  }
}