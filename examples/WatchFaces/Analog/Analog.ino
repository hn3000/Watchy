#include <Watchy.h>

class AnalogWatchy: public Watchy {
  void drawWatchFace();
};

void drawHand(
  GxEPD2_BW<GxEPD2_154_D67, GxEPD2_154_D67::HEIGHT> &display,
  int16_t len, float angle
);

void AnalogWatchy::drawWatchFace() {
    display.setFullWindow();
    display.fillScreen(GxEPD_BLACK);
    //display.setFont(&FreeMonoBold9pt7b);
    //display.setLineColor(GxEPD_WHITE);

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

  //display.drawLine(xc, yc, xe, ye, GxEPD_WHITE);
  display.fillTriangle(xc-xb, yc-yb, xc+xb, yc+yb, xe+xb, ye+yb, GxEPD_WHITE);
  display.fillTriangle(xc-xb, yc-yb, xe+xb, ye+yb, xe-xb, ye-yb, GxEPD_WHITE);

}

AnalogWatchy watchy;

void setup() {
  watchy.init();
}

void loop(){}