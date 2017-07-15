#include <stdint.h>

typedef struct frame {
  uint8_t **red;
  uint8_t **green;
  uint8_t **blue;
  int width;
  int height;
} frame_t;

void writeFrame(frame_t *);
frame_t *createFrame(int, int);
