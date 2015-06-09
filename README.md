# arduino-L293D
Arduino library for using a L293D motor controller chip

## Usage
Download the source:

  ```git clone https://github.com/tysweat/arduino-L293D.git```
  
and manually install the library. (http://www.arduino.cc/en/Guide/Libraries#toc5)


#### Setting motor speed
```
motor.set(255); // Full on forward
motor.set(1); // Also full on forward

motor.set(-255); // Full on reverse
motor.set(-1); // Also full on reverse
```

#### Wiring
For controlling motor speed more than 100% on or off, you must use a PWM enabled pin on the Arduino for the L293D enable pin (ie: pins 3, 5, 6, 9, 10, and 11 on Arduino Uno).

See the L293D datasheet for more information on connecting to the Arduino and to the motor. (http://www.ti.com/lit/ds/symlink/l293.pdf)

### Example Arduino sketch

```
#include <L293D.h>

L293D motor(9,8,7);

setup()
{
}

loop()
{
  // Set motor speed and direction with a double value between -1 and 1
  motor.set(.75); // 75% power forward
  delay(2500);
  motor.set(-.3); // 30% power reverse
  delay(2500);
  // Set motor speed and direction with an int value between -255 and 255
  motor.set(200);
  delay(2500);
  motor.set(-150);
  delay(2500);
  
  // Use motor.get() to get current speed and then update it from that
  motor.set(-255);
  while(motor.get() != 255)
  {
    motor.set(motor.get() + 5); // Increment motor speed from previous speed
    delay(100); // Delay 100ms to see the speed changing
  }
}
```
