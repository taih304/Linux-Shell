### Sending data with UART from Linux comnputer to Arduino

Send ``9``, ``8`` from Terminal Linux to turn ON/OFF LED on Arduino.

**On Arduino**

```c
#include <Arduino.h>

char received;
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {

  if (Serial.available()) {
    received = Serial.read() - 48;
    Serial.println(received);
    if (received == 9)
    {
      digitalWrite(13, HIGH);
    }
    else if (received == 8)
    {
      digitalWrite(13, LOW);
    }
  }
}
```

**Using screen**

The screen package is pre-installed on most Linux distros nowadays. Install: ``sudo apt install screen``

Enter screen: ``screen /dev/ttyUSB0``. Then starts sending value.

To end screen: ``Ctr+A+D``

**Using echo**

Arduinos have auto-reset circuit to reset the board if new connection is initiated on USB. It is good for convenient upload or to reset for debugging at Serial Monitor open. But it causes troubles if you want to communicate with MCU from computer over USB from command line tools, scripts, python, C++, C#, Java.

To disable this feature: ``stty -F /dev/ttyACM0 -hupcl``

``hupcl`` is equal to ``hupc``: Send a hangup signal when the last process closes the tty.

Then:

``echo 9 > /dev/ttyUSB0``: Turn ON

``echo 8 > /dev/ttyUSB0``: Turn OFF

### Read serial port data

**Arduino**

```c
Serial.println("Hello, World");
delay(1000);
```

**Using cat to read**: ``cat /dev/ttyUSB0``
