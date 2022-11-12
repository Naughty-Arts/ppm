#ifndef _PPM_H_
#define _PPM_H_

#include <canvas.h>

void ppm3_write(FILE* out, Canvas *canvas);
Canvas* ppm3_read(FILE* in);

#endif
