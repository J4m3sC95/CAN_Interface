#include "CAN.h"

uint16_t test_buffer[4] = {0x1F0, 0x1F0, 0x1F0};
uint16_t test_buffer1[4] = {0x0145, 0x00, 0x0145};
uint16_t blank_buffer[4] = {0,0,0};

// need to add a better way of setting the delay and loop parameters
uint16_t loop_buffer[4] = {0x020A,0,0};
uint16_t delay_buffer[4] = {0x3E8, 0, 0};

void setup() {
  uint8_t n;
  
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  delay(2000);
  CAN_setup();

  digitalWrite(LED_BUILTIN, HIGH);

  led_cube(EEPROM_WRITE_BEGIN, 0, 0, blank_buffer);
  delay(1000);

  led_cube(LOAD, 0,0, test_buffer);
  delay(1000);
  
  led_cube(ROTATE, ZAXIS, NEGATIVE, blank_buffer);
  delay(1000);
  led_cube(DELAY, 0, 0, delay_buffer);
  delay(1000);
  led_cube(LOOP,0,0,loop_buffer);
  delay(1000);
  
  led_cube(MIRROR, YZPLANE, 0, blank_buffer);
  delay(1000);
  led_cube(DELAY, 0, 0, delay_buffer);
  delay(1000);
  led_cube(LOOP,0,0,loop_buffer);
  delay(1000);
  
  led_cube(TRANSLATE_CLEAR, 0, 0, blank_buffer);
  delay(1000);
  led_cube(TRANSLATE, XAXIS, POSITIVE, test_buffer1);
  delay(1000);
  led_cube(DELAY, 0, 0, delay_buffer);
  delay(1000);
  led_cube(LOOP,0,0,loop_buffer);
  delay(1000);



  
  led_cube(EEPROM_WRITE_END, 0, 0, blank_buffer);
  delay(1000);

  digitalWrite(LED_BUILTIN, LOW);
  
  while(1); 
  
}

void loop() {
  uint8_t n;
  led_cube(LOAD, 0,0, test_buffer);
  delay(1000);
  for(n = 0; n < 10; n++){
    led_cube(ROTATE, ZAXIS, NEGATIVE, blank_buffer);
    delay(100);
  }
  delay(2000);
  for(n = 0; n < 10; n++){
    led_cube(MIRROR, YZPLANE, 0, blank_buffer);
    delay(100);
  }
  delay(2000);
  led_cube(TRANSLATE_CLEAR, 0, 0, blank_buffer);
  for(n = 0; n < 4; n++){
    led_cube(TRANSLATE, XAXIS, POSITIVE, test_buffer1);
    delay(1000);
  }
  delay(2000);
}


