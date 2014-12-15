/*
*/

#include "Arduino.h"
#include "SevSegments.h"

SevSegments::SevSegments(int a, int b, int c, int d, int e, int f, int g) {
  _pins[0] = a;
  _pins[1] = b;
  _pins[2] = c;
  _pins[3] = d;
  _pins[4] = e;
  _pins[5] = f;
  _pins[6] = g;
  for (int i=0; i<7; i++) {
    pinMode(_pins[i], OUTPUT);
  }
  setCathode();

}

int SevSegments::turnOff() {
  return setHex(0);
}

void SevSegments::setAnode() {
  on = HIGH;
  off = LOW;
}

void SevSegments::setCathode() {
  on = HIGH;
  off = LOW;
}

int SevSegments::getHex() {
    return _current;
}

int SevSegments::set(int n) {
  // turn the number "n" on (hex digit supported)
  if (n>15) {
    return -1;
  }
  return setHex(segments[n]);
}

int SevSegments::setHex(int hex) {
  _current = hex;
  for (int i=0; i<7; i++) {
    if (hex & (1 << i)) {
      segOn(6 - i);
    } else {
      segOff(6 - i);
    }
  }
}

void SevSegments::segOn(int i) {
  // turn segment on
  digitalWrite(_pins[i], on);
}

void SevSegments::segOff(int i) {
  // turn segment off
  digitalWrite(_pins[i], off);
}
