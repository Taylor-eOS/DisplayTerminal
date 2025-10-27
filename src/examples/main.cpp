#include <Arduino.h>
#include "DisplayTerminal.h"

DisplayTerminal terminal(5, 17, 16);

void setup() {
    terminal.init();
    terminal.print("Starting");
}

void loop() {
    static int count = 1;
    static int prints_before_clear = 0;
    delay(1400);
    int cycle = (count - 1) % 3;
    uint32_t free_heap = ESP.getFreeHeap();
    uint32_t uptime_ms = millis();
    if (cycle == 0) {
        terminal.print("System status ok");
    }
    else if (cycle == 1) {
        terminal.print("Free heap: " + String(free_heap) + " bytes");
    }
    else {
        terminal.print("Uptime: " + String(uptime_ms) + "ms");
    }
    count++;
    prints_before_clear++;
    if (prints_before_clear >= 20) {
        terminal.clear();
        prints_before_clear = 0;
    }
}

