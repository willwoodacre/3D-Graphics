#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "objects.h"

void move(polygon_t *, int x, int y, int z);
void scale(polygon_t *, int x, int y, int z);
void rotx(polygon_t *, double deg);
void roty(polygon_t *, double deg);
void rotz(polygon_t *, double deg);

#endif
