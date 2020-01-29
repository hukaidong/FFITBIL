#include <cstddef>
#include <iostream>
#include "string.h"
#include "stdlib.h"
#include "tiff.h"
#include "tiffio.h"
#include "shade.c"
#include "pixcolor.h"

void ErrorExit(const char *msg, int ecode=1) {
  std::cerr << msg << std::endl;
  exit(ecode);
}

int main() {
  pixcolor pc;

  TIFF* tif = TIFFOpen("/tmp/new.tif", "w");
  if (!tif) ErrorExit("Can't open file");

  int ss = bpix * 8;
  int sp = 3;

  TIFFSetField(tif, TIFFTAG_IMAGEWIDTH, width);
  TIFFSetField(tif, TIFFTAG_IMAGELENGTH, height);
  TIFFSetField(tif, TIFFTAG_BITSPERSAMPLE, ss, ss, ss);
  TIFFSetField(tif, TIFFTAG_COMPRESSION, 1);
  TIFFSetField(tif, TIFFTAG_PHOTOMETRIC, 2); 
  TIFFSetField(tif, TIFFTAG_SAMPLESPERPIXEL, sp);
  TIFFSetField(tif, TIFFTAG_PLANARCONFIG, 2);
  TIFFSetField(tif, TIFFTAG_ROWSPERSTRIP, 1);
  TIFFSetField(tif, TIFFTAG_ROWSPERSTRIP, 1);


  B* channels[3];
  channels[0] = (B*) _TIFFmalloc(width * bpix);
  channels[1] = (B*) _TIFFmalloc(width * bpix);
  channels[2] = (B*) _TIFFmalloc(width * bpix);


   for(int row=0; row < height; row++) {
     int rp = 0;
     for (int col=0; col < width; col++) {
       pc.col = col;
       pc.row = row;
       fragpix(pc);
       channels[0][rp] = (B)pc.r;
       channels[1][rp] = (B)pc.g;
       channels[2][rp] = (B)pc.b;
       rp ++ ;
     }
     for (int cnl=0; cnl < sp; cnl++)
       if (TIFFWriteScanline(tif, channels[cnl], row, cnl) < 0)
         ErrorExit("Write scanline failed");
   }

  TIFFClose(tif);
  _TIFFfree(channels[0]);
  _TIFFfree(channels[1]);
  _TIFFfree(channels[2]);

  system("zsh -lc 'xdg-open /tmp/new.tif'");
}
