#ifndef MultiSevSegments_h
#define MultiSevSegments_h

#include "SevSegments.h"

/**
 * pin is the pin attached to the GND/v++ of the segment display
 * other attributes are the same of SevSegments
 */
class MultiSevSegment
{
  public:
    MultiSevSegment(int pin, int a, int b, int c, int d, int e, int f, int g);
    int set(int n);
    void update();
    void turnOn();
    void turnOff();
    void setCathode();
  private:
    SevSegments *_seg;
    int _pin;
    int _n;
    const int _delay = 1;
    int on;
    int off;
};

#endif
