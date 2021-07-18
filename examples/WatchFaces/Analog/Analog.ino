#include <Watchy.h>

#if 1  /* 0 for white on black*/
#define FG_COLOR GxEPD_BLACK
#define BG_COLOR GxEPD_WHITE
#else
#define FG_COLOR GxEPD_WHITE
#define BG_COLOR GxEPD_BLACK
#endif

class AnalogWatchy: public Watchy {
  void drawWatchFace();
};

void drawHand(
  GxEPD2_BW<GxEPD2_154_D67, GxEPD2_154_D67::HEIGHT> &display,
  int16_t len, float angle
);

void AnalogWatchy::drawWatchFace() {
    display.setFullWindow();
    display.fillScreen(BG_COLOR);
    //display.setFont(&FreeMonoBold9pt7b);
    //display.setLineColor(FG_COLOR);

  int16_t minute = currentTime.Minute;
  int16_t hour = currentTime.Hour;

  drawHand(display, 90, minute / 60.0 * -3.1415926 * 2);
  drawHand(display, 60, (hour + minute / 60.0) / 12.0 * -3.1415926 * 2);

}

const int16_t xc = 100;
const int16_t yc = 100;

void drawHand(
  GxEPD2_BW<GxEPD2_154_D67, GxEPD2_154_D67::HEIGHT> &display,
  int16_t len, float angle
) {
  int16_t xe = floor(-len * sin(angle));
  int16_t ye = floor(-len * cos(angle));

  int16_t xb = round(-ye / (len / 3.0));
  int16_t yb = round(xe / (len / 3.0));

  xe+=xc;
  ye+=yc;

  //display.drawLine(xc, yc, xe, ye, FG_COLOR);
  display.fillTriangle(xc-xb, yc-yb, xc+xb, yc+yb, xe+xb, ye+yb, FG_COLOR);
  display.fillTriangle(xc-xb, yc-yb, xe+xb, ye+yb, xe-xb, ye-yb, FG_COLOR);

}

AnalogWatchy watchy;

void setup() {
  //watchy.init(__DATE__ " " __TIME__);
}

void loop(){}