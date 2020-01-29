#ifndef PIXC_H
#define PIXC_H

#include <cstddef>

using B = unsigned int;
struct pixcolor{
  unsigned short col, row, r, g, b;
};

void fragpix(pixcolor&);

const int height = 48;
const int width = 64;
const int bpix = sizeof(B);

#endif
