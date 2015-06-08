#ifndef MultiSevSegments_h
#define MultiSevSegments_h

#include "SevSegments.h"

/**
 * pin is the pin attached to the GND/v++ of the segment display
 * other attributes are the same of SevSegments
 */
class MultiSevSegments {
  public:
    MultiSevSegments(int pin, SevSegments *seg);
    int set(int n);
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

class SevSegmentsArray {
    public:
        SevSegmentsArray(int pins[], SevSegments *seg);
        int set(int pos, int n);
        void update();
    private:
        MultiSevSegments **_segments;
        int _size;
        int _current;
        unsigned long _previous;
        const int interval = 100;
};
#endif
