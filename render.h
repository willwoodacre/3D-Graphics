#ifndef RENDER_H
#define RENDER_H

#include "frame.h"
#include "objects.h"

#define drawPixel(x, y, col, frame) \
  (frame->colour[x][y] = col) 
#define F 100

void drawLine(co_ord_t *, co_ord_t *, colour_t *, frame_t *); 
void renderPoly(polygon_t *, colour_t *, frame_t *);

#endif
