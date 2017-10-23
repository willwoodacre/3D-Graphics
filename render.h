#ifndef RENDER_H
#define RENDER_H

#include "frame.h"
#include "objects.h"
#include "perspective.h"

#define drawPixel(x, y, col, frame) \
  frame->colour[x][y]->red   = col->red; \
  frame->colour[x][y]->blue  = col->blue; \
  frame->colour[x][y]->green = col->green;
#define F 200

void drawLine(co_ord_t *, co_ord_t *, colour_t *, frame_t *); 
void renderPoly(polygon_t *, perspective_t *, colour_t *, frame_t *);

#endif
