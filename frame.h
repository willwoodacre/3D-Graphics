#ifndef FRAME_H
#define FRAME_H

#include <stdint.h>

typedef struct colour {
  uint8_t red;
  uint8_t green;
  uint8_t blue;
} colour_t;

typedef struct frame {
  colour_t ***colour;
  int width;
  int height;
} frame_t;

void writeFrame(frame_t *);
frame_t *createFrame(int, int);

#endif
