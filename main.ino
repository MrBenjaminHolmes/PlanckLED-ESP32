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

  for (int step = 0; step <= 160; step++) {
    float current_mA = step * 0.1;

    for (int i = 0; i < 10; i++) {
      float voltage = readAnalog(A1, 5);

      Serial.print(current_mA, 1);a
      Serial.print(",");
      Serial.println(voltage, 4);

      delay(100);
    }

    Serial.println("-------------------");

    delay(4000); // time adjust generator
  }

  while (true); // stop after one full sweep
}