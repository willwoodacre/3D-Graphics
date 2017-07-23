#include "render.h"
#include "objects.h"
#include "transform.h"

int main(int argc, char *argv[]) {
  frame_t *frame = createFrame(640, 480);
  colour_t col;
  col.red = 255;
  col.green = 0;
  col.blue = 0;
  polygon_t *cube1 = createCube();
  scale(cube1, 200, 200, 200);
  printVerts(cube1);
  move(cube1, -100, -100, 400);
  printVerts(cube1);
  renderPoly(cube1, &col, frame);
  move(cube1, 400, 400, 400);
  printVerts(cube1);
  renderPoly(cube1, &col, frame);
  writeFrame(frame);
  move(cube1, -800, 0, 0);
  printVerts(cube1);
  renderPoly(cube1, &col, frame);
  writeFrame(frame);
  move(cube1, 0, -800, 0);
  printVerts(cube1);
  renderPoly(cube1, &col, frame);
  writeFrame(frame);
  move(cube1, 800, 0, 0);
  printVerts(cube1);
  renderPoly(cube1, &col, frame);
  writeFrame(frame);
  return 1;
}
