#ifndef SevSegments_h
#define SevSegments_h

/**
 * Segments Map
 *  -- A --
 * |       |
 * F       B
 * |       |
 *  -- G --
 * |       |
 * E       C
 * |       |
 *  -- D --
 */

class SevSegments
{
  public:
    SevSegments(int a, int b, int c, int d, int e, int f, int g);
    int set(int n);
    int setHex(int hex);
    int turnOff();
    void setAnode();
    void setCathode();
  private:
    int _pins[7];
    int on;
    int off;
    void segOn(int);
    void segOff(int);
    const int segments[16] = {
      // abcdef (pin segments)
      0b1111110, // 0
      0b0110000, // 1
      0b1101101,
      0b1111001,
      0b0110011,
      0b1011011,
      0b1011111,
      0b1110010,
      0b1111111,
      0b1111011,
      0b1110111, // A
      0b0011111,
      0b1001110,
      0b0111101,
      0b1001111,
      0b1000111
    };
};

#endif
