#include <Watchy.h>

class AnalogWatchy: public Watchy {
  
  void drawWatchFace();
};

void drawHand(
  GxEPD2_BW<GxEPD2_154_D67, GxEPD2_154_D67::HEIGHT> &display,
  int16_t len, float angle
);

void AnalogWatchy::drawWatchFace() {
    display.init(0, false); //_initial_refresh to false to prevent full update on init
    display.setFullWindow();
    display.fillScreen(GxEPD_BLACK);
    //display.setFont(&FreeMonoBold9pt7b);
    //display.setLineColor(GxEPD_WHITE);

  int16_t minute = currentTime.Minute;
  int16_t hour = currentTime.Hour;

  drawHand(display, 90, minute / 60.0 * -3.1415926 * 2);
  drawHand(display, 60, (hour + minute / 60.0) / 12.0 * -3.1415926 * 2);

  /*
  float a = minute / 60.0 * -3.1415926 * 2;
  int16_t xe = floor(xc + -90 * sin(a));
  int16_t ye = floor(yc + -90 * cos(a));

  int16_t xb = round(-(ye-yc) / 45.0);
  int16_t yb = round((xe-xc) / 45.0);

  //display.drawLine(xc, yc, xe, ye, GxEPD_WHITE);
  display.fillTriangle(xc-xb, yc-yb, xc+xb, yc+yb, xe+xb, ye+yb, GxEPD_WHITE);
  display.fillTriangle(xc-xb, yc-yb, xe+xb, ye+yb, xe-xb, ye-yb, GxEPD_WHITE);

  a = (hour + minute / 60.0) / 12.0 * -3.1415926 * 2;
  xe = floor(xc + -60 * sin(a));
  ye = floor(yc + -60 * cos(a));

  xb = round(-(ye-yc) / 30.0);
  yb = round((xe-xc) / 30.0);

  //display.drawLine(xc, yc, xe, ye, GxEPD_WHITE);
  display.fillTriangle(xc-xb, yc-yb, xc+xb, yc+yb, xe+xb, ye+yb, GxEPD_WHITE);
  display.fillTriangle(xc-xb, yc-yb, xe+xb, ye+yb, xe-xb, ye-yb, GxEPD_WHITE);
  */
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