#include "render.h"
#include "objects.h"
#include "transform.h"

int main(int argc, char *argv[]) {
  frame_t *frame = createFrame(640, 480);
  colour_t col;
  col.red = 255;
  col.green = 0;
  col.blue = 0;
  polygon_t *poly = createCube();
  printVerts(poly);
  scale(poly, 100, 100, 100);
  printVerts(poly);
  move(poly, -50, -50, 200);
  printVerts(poly);
  renderPoly(poly, &col, frame);
  writeFrame(frame);
  return 1;
}
