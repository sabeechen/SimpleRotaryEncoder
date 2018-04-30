Simple Incremental Rotary Encoder
==========

* Author: Stephen Beechen 
* Copyright (C) 2018 Stephen Beechen.
* Released under the MIT license.

Arduino IDE library for reading an incremental rotary encoder, with a push button, with or without using interrupts, on an ESP8266, Arduino, or other Arduino IDE compatible board.


Description
-----------
Supports reading information from [Incremental Rotary Encoders](https://en.wikipedia.org/wiki/Rotary_encoder#Incremental_rotary_encoder), for example https://www.adafruit.com/product/377 or http://a.co/0OrQ2Hm. Callbacks are used to handle events; one each for button up, button down, clockwise rotation and counter clockwise rotation.

How to Use
----------
The library provides the following methods:

```
    RotaryEncoder(int rotaryPin1, int rotaryPin2, int buttonPin)

    void setup(); // must be called
    void setupInterrupts(); //must be called if using interrupts
    void loop();  // Must be called in sketch loop() if you aren't using interrupts
    void setButtonDownCallback(Callback cb); 
    void setButtonUpCallback(Callback cb);
    void setRotateCWCallback(Callback cb);
    void setRotateCCWCallback(Callback cb);
```

The callbacks must be no argument methods returning void.  The example sketches show how to use the library if you're using interrupts or polling.  For polling to work the loop method must be called very often to catch the encoder transitions that indicate direction.  In my experience delays of more than 10ms will cause it to miss the transition.  The library attempts to detect this and make an educated guess about which direction the encoder was moving, but I'd really just recommend using a microcontroller that support interrupts.  Multiple encoders are supported, see the examples included with the library to see how.

Usage with Interrupts
---------------------
See the library examples for complete working code.
```
void setup() {
  encoder.setup();
  encoder.setupInterrupts();
  encoder.setButtonDownCallback(buttonDownCallback);
  encoder.setButtonUpCallback(buttonUpCallback);
  encoder.setRotateCWCallback(movedClockwiseCallback);
  encoder.setRotateCCWCallback(movedCounterClockwiseCallback);
}
```

Usage with Polling
---------------------
See the library examples for complete working code.
```
void setup() {
  encoder.setup();
  encoder.setButtonDownCallback(buttonDownCallback);
  encoder.setButtonUpCallback(buttonUpCallback);
  encoder.setRotateCWCallback(movedClockwiseCallback);
  encoder.setRotateCCWCallback(movedCounterClockwiseCallback);
}

void loop() {
  encoder.loop();
}
```

Installation
------------
Download the ZIP archive (https://github.com/sabeechen/SimpleRotaryEncoder/zipball/master) and choose "Sketch > Include Library > Add .ZIP Library..." and select the downloaded file.


License
-------

MIT License

Copyright (c) 2018 Stephen Beechen

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
