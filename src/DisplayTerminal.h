#ifndef DISPLAY_TERMINAL_H
#define DISPLAY_TERMINAL_H

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>

class DisplayTerminal {
public:
    DisplayTerminal(int cs, int dc, int rst);
    void init();
    void print(const String& str);
    void clear();
private:
    Adafruit_ST7735 tft;
    String buffer[32];
    int buffer_size;
    int max_rows;
    int max_cols;
    int char_height;
    int char_width;
    void addWrapped(const String& line);
    void redraw();
};

#endif

