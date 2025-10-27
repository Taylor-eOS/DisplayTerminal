#include "DisplayTerminal.h"
#include <SPI.h>

DisplayTerminal::DisplayTerminal(int cs, int dc, int rst) : tft(cs, dc, rst) {}

void DisplayTerminal::init() {
    tft.initR(INITR_BLACKTAB);
    tft.setRotation(1);
    tft.fillScreen(ST7735_BLACK);
    tft.setTextColor(ST7735_WHITE);
    tft.setTextSize(1);
    tft.setTextWrap(false);
    char_height = 8;
    char_width = 6;
    max_rows = tft.height() / char_height;
    max_cols = tft.width() / char_width;
    buffer_size = 0;
}

void DisplayTerminal::print(const String& str) {
    String remaining = str;
    while (remaining.length() > 0) {
        int nl_pos = remaining.indexOf('\n');
        String line;
        if (nl_pos == -1) {
            line = remaining;
            remaining = "";
        } else {
            line = remaining.substring(0, nl_pos);
            remaining = remaining.substring(nl_pos + 1);
        }
        addWrapped(line);
    }
    redraw();
}

void DisplayTerminal::clear() {
    buffer_size = 0;
    tft.fillScreen(ST7735_BLACK);
}

void DisplayTerminal::addWrapped(const String& line) {
    String l = line;
    while (l.length() > 0) {
        int len = min(max_cols, (int)l.length());
        String sub = l.substring(0, len);
        if (buffer_size >= max_rows) {
            for (int i = 0; i < buffer_size - 1; i++) {
                buffer[i] = buffer[i + 1];
            }
            buffer_size--;
        }
        buffer[buffer_size++] = sub;
        l = l.substring(len);
    }
}

void DisplayTerminal::redraw() {
    tft.fillScreen(ST7735_BLACK);
    for (int i = 0; i < buffer_size; i++) {
        tft.setCursor(0, i * char_height);
        tft.print(buffer[i]);
    }
}

