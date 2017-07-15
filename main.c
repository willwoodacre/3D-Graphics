#include "frame.h"

int main(int argc, char *argv[]) {
  frame_t *frame = createFrame(640, 480);
  writeFrame(frame);
  return 1;
}
