Arduino SevSegmentsLib
======================


Assemble (pinout):

```
  -- A --
 |       |
 F       B
 |       |
  -- G --
 |       |
 E       C
 |       |
  -- D --
```

Code:
```
seg = new SevSegments(a, b, c, d, e, f, g);
```


Usage sample:

``` c
#include <SevSegments.h>

SevSegments *seg;

void setup() {
  seg = new SevSegments(7, 8, 2, 3, 4, 6, 5);
  seg->setCathode();
}

void loop() {
  for(int i=0; i<16; i++) {
    seg->set(i);
    delay(500);
  }
  seg->turnOff();
  delay(500);
}
```

To use multiple segments with less IO pins, it can be done connecting the GND pin in some IO pins and use it as a "selector".
The code looks like:

``` c
#include <SevSegmentsArray.h>

SevSegmentsArray *seg;
void _initSegment() {
  int pins[] = {11, 12};
  seg = new SevSegmentsArray(
    pins,
    new SevSegments(2, 3, 4, 5, 6, 7, 8)
  );
}

void setup() {
   _initSegment();
   seg->set(0, 3);
   seg->set(1, 9);
}

void loop() {
  seg->update();
}
```

With GND of seven segment connected to pins 11 and 12.
