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
