Simple Rotary Encoder
==========

* Author: Stephen Beechen 
* Copyright (C) 2018 Stephen Beechen.
* Released under the MIT license.

Arduino library for reading a rotary encoder with a button on an ESP8266.


Description
-----------

Callbacks are used to handle events; one each for button up, button down, clockwise rotation and counter clockwise rotation.

How to Use
----------

The library provides the following methods:

```
    RotaryEncoder(int rotaryPin1, int rotaryPin2, int buttonPin)

    void setup();
    void setButtonDownCallback(Callback cb);
    void setButtonUpCallback(Callback cb);
    void setRotateCWCallback(Callback cb);
    void setRotateCCWCallback(Callback cb);
```

The callbacks must be no argument methods returning void.

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
