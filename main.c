#include "render.h"

int main(int argc, char *argv[]) {
  frame_t *frame = createFrame(640, 480);
  co_ord_t a, b;
  a.x = 10;
  b.x = 100;
  a.y = 10;
  b.y = 10;
  colour_t col;
  col.red = 255;
  col.green = 0;
  col.blue = 0;
  drawLine(&b, &a, &col, frame);
  writeFrame(frame);
  return 1;
}
