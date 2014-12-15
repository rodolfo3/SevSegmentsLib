#include "Arduino.h"
#include "MultiSevSegments.h"


MultiSevSegment::MultiSevSegment(int pin, int a, int b, int c, int d, int e, int f, int g) {
  this->_seg = new SevSegments(a, b, c, d, e, f, g);

  this->_pin = pin;

  pinMode(pin, OUTPUT);

  this->setCathode();
  this->turnOff();
}

void MultiSevSegment::setCathode() {
  this->_seg->setCathode();
  this->on = LOW;
  this->off = HIGH;
}

int MultiSevSegment::set(int n) {
  this->_n = n;
  return n;
}

void MultiSevSegment::update() {
  int hex = this->_seg->getHex();
  this->_seg->turnOff();
  this->turnOn();

  // the pin in the middle is less brighter
  // TODO identify why and remove this shit
  if (hex & 1) {
    _seg->setHex(0b0000001);
    delay(_delay);
  }
  this->_seg->set(_n);
  delay(_delay );
  this->turnOff();
}

void MultiSevSegment::turnOff() {
  digitalWrite(this->_pin, this->off);
}

void MultiSevSegment::turnOn() {
  digitalWrite(this->_pin, this->on);
}
