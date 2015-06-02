# arduino-L293D
Arduino library for using a L293D motor controller chip

## Usage
Download the source:

  ```git clone https://github.com/tysweat/arduino-L293D.git```
  
and move ```L293D.h``` and ```L293D.cpp``` into your sketch folder.

```
#include "L293D.h"
// Order of pins: enable, a, b
L293D motor(9, 8, 7);
```
#### Setting motor speed
```
motor.set(255); // Full on forward
motor.set(-255); // Full on reverse

motor(1); // Also full on forward
motor(-1); // Also full on reverse
```


### Example Arduino sketch

```
#include "L293D.h"

L293D motor(9,8,7);

setup()
{
}

loop()
{
  // Set motor speed and direction with a double value between -1 and 1
  motor.set(.75);
  delay(5000);
  motor.set(-.75);
  delay(5000);
  // Set motor speed and direction with an int value between -255 and 255
  motor.set(200);
  delay(5000);
  motor.set(-200);
  delay(5000);
}
```
