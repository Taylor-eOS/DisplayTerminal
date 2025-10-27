# DisplayTerminal
DisplayTerminal is a simple scrolling terminal emulator for ST7735 TFT displays using the Adafruit GFX and ST7735 libraries. It provides an easy way to print text line by line to a small display, automatically wrapping and scrolling when the screen is full.

### Features
* Works with ST7735 displays via Adafruit GFX
* Handles line wrapping and automatic scrolling
* Simple interface for printing and clearing text

### Import
Add this to your `platformio.ini`:
```
lib_deps = https://github.com/Taylor-eOS/DisplayTerminal.git
```

### Example
```cpp
#include <Arduino.h>
#include <DisplayTerminal.h>

DisplayTerminal terminal(5, 17, 16);

void setup() {
    terminal.init();
    terminal.print("Hello World");
}
```
