#define BAUDRATE 115200

unsigned long p_millis = 0;

void setup() {
Serial.begin(BAUDRATE); }

#define SERIAL_DELAY 1000

void loop() {
if(millis() - p_millis > SERIAL_DELAY) {
  Serial.println(int(random(1,9)));
  p_millis = millis(); }
}
