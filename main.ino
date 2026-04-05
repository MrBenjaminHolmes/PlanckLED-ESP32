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
  for(int pwm = 0; pwm <= 255; pwm++) {
    ledcWrite(pwmChannel, pwm);
    delay(20);
    unsigned long start = millis();
    while(millis() - start < 1000){
      //read sensor code
      Serial.print(pwm);
      Serial.print(",");
      Serial.println(pwm);//this will be sensor reading
    }
    while(true);
  }
}