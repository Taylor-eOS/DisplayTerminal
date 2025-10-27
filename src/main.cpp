#include <Arduino.h>
#include "DisplayTerminal.h"

DisplayTerminal terminal(5, 17, 16);

void setup() {
    terminal.init();
    terminal.print("Starting");
}

void loop() {
    static int count = 1;
    delay(1000);
    int cycle = (count - 1) % 3;
    uint32_t free_heap = ESP.getFreeHeap();
    uint32_t uptime_ms = millis();
    if (cycle == 0) {
        terminal.print("System status OK");
    }
    else if (cycle == 1) {
        terminal.print(String(free_heap) + " bytes free heap");
    }
    else {
        terminal.print("Uptime " + String(uptime_ms) + "ms");
    }
    count++;
}
