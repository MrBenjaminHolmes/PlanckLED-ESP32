const int ledPin = 5;
const int pwmChannel = 0;
const int freq = 5000;
const int resolution = 8;


void setup() {
  Serial.begin(115200);        // start serial communication
  ledcSetup(pwmChannel, freq, resolution);
  ledcAttachPin(ledPin, pwmChannel);
}

void loop() {
  ledcWrite(pwmChannel, 0);
  delay(10000); //Allow for time to turn off monitor
  for(int pwm = 0; pwm <= 255; pwm++) {
    ledcWrite(pwmChannel, pwm);
    delay(20);
    unsigned long start = millis();
    while(millis() - start < 100){
      //read sensor code
      Serial.print(pwm);
      Serial.print(",");
      Serial.println(random(500));//this will be sensor reading
    }
  }
  ledcWrite(pwmChannel, 0);
  while(true);
}