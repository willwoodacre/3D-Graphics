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
    int framey = y * yMult;
    int framex = x * xMult;
    if (octant == 2 || octant == 6) {
      framex *= -1;
      framey *= -1;
    }
    if (swap) {
      int temp = framey;
      framey = framex;
      framex = temp;
    }

    if (framex >= 0 && framex < frame->width && framey >= 0 && framey < frame->height) {
      drawPixel(framex, framey, colour, frame);
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

void renderPoly(polygon_t *poly, perspective_t *pers, colour_t *colour, frame_t *frame) {
  //calculate the x and y coords of verts after perspective projection
  co_ord_t coords[poly->no_verts];
  int midx = frame->width / 2;
  int midy = frame->height / 2;
  for (int i = 0; i < poly->no_verts; i++) {
    int vert[3];
    for (int j = 0; j < 3; j++) {
      int sum = 0;
      for (int k = 0; k < 4; k++) {
        sum += poly->verts[k][i] * pers->trans[j][k];
      }
      vert[j] = sum;
    }
    coords[i].x = midx + (F * vert[0] / vert[2]);
    coords[i].y = midy + (F * vert[1] / vert[2]);
  }

  for (int i = 0; i < poly->no_verts; i++) {
    for (int j = (i + 1); j < poly->no_verts; j++) {
      if (poly->adj[i][j]) {
        drawLine(&coords[i], &coords[j], colour, frame);
      }
    }
  }
}
