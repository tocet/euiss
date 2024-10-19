#define BAUDRATE 115200
// hardware resources - analog
#define VAR_RES A0
#define LM35 A2
// hardware resources - digital
#define RGB_R 9
#define RGB_G 10
#define RGB_B 11
#define LED_R 12
#define LED_B 13

#define MAINLOOP 1000

bool led_state = false;
int led_color[5] = {RGB_R, RGB_G, RGB_B, LED_R, LED_B};

long p_millis = 0;

void setup() {
Serial.begin(BAUDRATE);
}

double measure_temp(int channel) {
 return double(analogRead(channel))*5*100/1024;
}

void loop() {
if(millis()-p_millis>=MAINLOOP) {
  Serial.println("Pot value = " + String(analogRead(VAR_RES)));
  Serial.println("Temperature = " + String(measure_temp(LM35)));
  digitalWrite(led_color[random(0,5)],led_state);
  led_state ^= true;
  p_millis = millis();
}
}
