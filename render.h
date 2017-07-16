#include "frame.h"
#include "objects.h"

#define drawPixel(x, y, col, frame) \
  (frame->colour[x][y] = col)

void drawLine(co_ord_t *, co_ord_t *, colour_t *, frame_t *); 
