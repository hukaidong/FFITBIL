#include "pixcolor.h"

void fragshader(float x, float y, float &r, float &g, float &b) {
/*   0 <= r, g, b <= 1
 *
 *          ^ y=1
 *     x=-1 |
 *     ----------> x=1
 *          |
 *          | y=-1
 *
 */
//  if (x*x + y*y < 1) {
    r = 0.5, g = 0.5, b = 0.5;
  //}
}

void normalizedpos(pixcolor &c, float &x, float &y) {

  x = float(c.col) / float(width) * 2.f - 1.f ;
  y = 1.f - float(c.row) / float(height) * 2.f ;
}

void setcolor(pixcolor &c, float r, float g, float b) {
  c.r = 0xFFFF;
  c.g = 0xFFFF;
  c.b = 0xFFFF;
}
// void setcolor(pixcolor &c, float r, float g, float b) {
//   c.r = (unsigned short) (r*-1);
//   c.g = (unsigned short) (g*-1);
//   c.b = (unsigned short) (b*-1);
// }


void fragpix(pixcolor& c) {
  float x, y, r, g, b;
  normalizedpos(c, x, y);
  fragshader(x, y, r, g, b);
  setcolor(c, r, g, b);
}
