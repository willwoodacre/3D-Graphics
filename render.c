#include "render.h"
#include <stdbool.h>

// gets the value of the octant the line between a and b is in
static int getOctant(co_ord_t *a, co_ord_t *b) {
  int dx = b->x - a->x;
  int dy = b->y - a->y;
  int octant = 0;

  if (dy < 0) {
    dx = -dx;
    dy = -dy;
    octant += 4;
  } 
  if (dx < 0) {
    int temp = dx;
    dx = dy;
    dy = -temp;
    octant += 2;
  }
  if (dx < dy) {
    octant += 1;
  }

  return octant;
}

static int getXMult(int octant) {
  return (octant > 1 && octant < 6) ? -1 : 1;
}

static int getYMult(int octant) {
  return (octant > 3) ? -1 : 1;
}

static bool getSwap(int octant) {
  return (octant == 1 || octant == 2 || octant == 5 || octant == 6);
}

// Draws a line between a and b on the given frame
// Uses the Bresenham line drawing algorithm
void drawLine(co_ord_t *a, co_ord_t *b, colour_t *colour, frame_t *frame) {
  int octant = getOctant(a, b);
  int xMult = getXMult(octant);
  int yMult = getYMult(octant);
  bool swap = getSwap(octant);
  // transform the coordinates based on the octant the line is in
  int ax = a->x * xMult;
  int ay = a->y * yMult;
  int bx = b->x * xMult;
  int by = b->y * yMult;
  if (swap) {
    int temp = ax;
    ax = ay;
    ay = temp;
    temp = bx;
    bx = by;
    by = temp;
  }

  int x = ax;
  int y = ay;
  int dx = bx - ax;
  int dy = by - ay;

  int p = 2 * dy - dx;
  while (x < bx) {
    // undo the transform applied to the coords
    if (swap) {
      drawPixel(y * yMult, x * xMult, colour, frame);
    } else {
      drawPixel(x * xMult, y * yMult, colour, frame);
    }

    if (p >= 0) {
      y += 1;
      p = p + 2 * dy - 2 * dx;
    } else {
      p = p + 2 * dy;
    }

    x += 1;
  }
}
