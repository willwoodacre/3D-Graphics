#include "render.h"
#include "objects.h"
#include "transform.h"
#include "perspective.h"

int main(int argc, char *argv[]) {
  frame_t *frame = createFrame(640, 480);
  colour_t col;
  col.red = 255;
  col.green = 0;
  col.blue = 0;
  perspective_t *pers = createPerspective();
  movePerspective(pers, 0, 400, 0);
  polygon_t *cube1 = createCube();
  scale(cube1, 200, 200, 200);
  rotx(cube1, 20.0);
  printVerts(cube1);
  move(cube1, -100, -100, 800);
  printVerts(cube1);
  renderPoly(cube1, pers, &col, frame);
  move(cube1, 400, 400, 0);
  printVerts(cube1);
  renderPoly(cube1, pers, &col, frame);
  move(cube1, -800, 0, 0);
  printVerts(cube1);
  renderPoly(cube1, pers, &col, frame);
  move(cube1, 0, -800, 0);
  printVerts(cube1);
  renderPoly(cube1, pers, &col, frame);
  move(cube1, 800, 0, 0);
  printVerts(cube1);
  renderPoly(cube1, pers, &col, frame);
  writeFrame(frame);
  return 1;
}
