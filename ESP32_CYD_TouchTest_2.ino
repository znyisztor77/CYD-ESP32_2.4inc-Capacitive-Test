#include <TFT_eSPI.h>
#include "CST820.h"

#define I2C_SDA 33
#define I2C_SCL 32
#define TP_RST 25
#define TP_INT 21

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240
#define FONT_SIZE 2


int x, y, z;
int centerX = SCREEN_WIDTH / 2;
int centerY = SCREEN_HEIGHT / 2;

TFT_eSPI tft = TFT_eSPI();                      
CST820 touch(I2C_SDA, I2C_SCL, TP_RST, TP_INT);

void setup() {
  Serial.begin(115200);

  String CYD_ESP32 = "Touch Panel test";
  Serial.println(CYD_ESP32);
  
  
  
  //tft.begin();
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_WHITE);
  tft.setTextColor(TFT_BLACK, TFT_WHITE);

  tft.drawCentreString("Hello, world!", centerX, 30, FONT_SIZE);
  tft.drawCentreString("Touch screen to test", centerX, centerY, FONT_SIZE); 
  touch.begin(); 
  digitalWrite(27, HIGH);

}

void loop() {
  tft.setRotation(0);
  bool touched;
  uint8_t gesture;
  uint16_t touchX, touchY;
  touched = touch.getTouch(&touchX, &touchY, &gesture);

  if (!touched) {
  } else {
    Serial.println((String) "Touch Data x: " + touchX + (String) ", y: " + touchY + (String) ", gesture: " + gesture);
    //Drawing
    tft.fillCircle(touchX, touchY, 5, TFT_BLACK);
  }
}
