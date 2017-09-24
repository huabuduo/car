#include "U8glib.h"

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);  // I2C / TWI

void oledInit(void)
{
  // assign default color value
  if ( u8g.getMode() == U8G_MODE_R3G3B2 ) {
    u8g.setColorIndex(255);     // white
  }
  else if ( u8g.getMode() == U8G_MODE_GRAY2BIT ) {
    u8g.setColorIndex(3);         // max intensity
  }
  else if ( u8g.getMode() == U8G_MODE_BW ) {
    u8g.setColorIndex(1);         // pixel on
  }
  else if ( u8g.getMode() == U8G_MODE_HICOLOR ) {
    u8g.setHiColorByRGB(255, 255, 255);
  }
}

/**
   绘图
*/
void draw(void) {
  u8g.setFont(u8g_font_unifont);
  //u8g.setFont(u8g_font_osb21);
  u8g.setPrintPos(0, 10);
  u8g.print("V-bat:");
  u8g.print(powerGetVBat());
  //  Serial.print("V-bat:");
  //  Serial.print(powerGetVBat());
  u8g.setPrintPos(0, 22);
  u8g.print("V-boost:");
  u8g.print(powerGetVBoost());
  u8g.setPrintPos(0, 34);
  u8g.print("I-charge:");
  u8g.print(powerGetChargeCurrent());
  //  Serial.print("  Vboost: ");
  //  Serial.println(powerGetVBoost());
}


void oledHandle()
{
  static long int lastTime = 0;
  if (millis() - lastTime >= 300) // 2fps
  {
    lastTime = millis();
    u8g.firstPage();
    do {
      draw();
    } while (u8g.nextPage());
  }
}
