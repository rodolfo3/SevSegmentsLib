#include "Arduino.h"
#include "SevSegments.h"

#include "SevSegmentsArray.h"

MultiSevSegments::MultiSevSegments(int pin, SevSegments *seg) {
    this->_pin = pin;
    this->_seg = seg;
    this->_n = 0;
}

void MultiSevSegments::setCathode() {
  this->_seg->setCathode();
  this->on = LOW;
  this->off = HIGH;
}

int MultiSevSegments::set(int n) {
  this->_n = n;
  return n;
}

void MultiSevSegments::turnOn() {
  digitalWrite(this->_pin, this->on);
  this->_seg->set(this->_n);
}

void MultiSevSegments::turnOff() {
  this->_seg->turnOff();
  digitalWrite(this->_pin, this->off);
}

SevSegmentsArray::SevSegmentsArray(int pins[], SevSegments *seg) {
    int size = sizeof(pins)/sizeof(int);
    this->_size = size;

    MultiSevSegments *segments[size];
    for(int i=0; i<size; i++) {
        segments[i] = new MultiSevSegments(pins[i], seg);
        segments[i]->turnOff();
    }
    this->_segments = segments;

    this->_previous = millis();
    this->_current = 0;
}

int SevSegmentsArray::set(int pos, int n) {
    return this->_segments[pos]->set(n);
}

void SevSegmentsArray::update() {
    if (millis() - this->_previous >= interval) {
        int prev = this->_current;
        if (prev < 0) {
            prev = this->_size - 1;
        }
        this->_segments[prev]->turnOff();
        this->_segments[this->_current]->turnOn();

        this->_current += 1;
        if (this->_current > this->_size) {
            this->_current = 0;
        }
        this->_previous = millis();
    }

}
