#include "frame.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Saves a bmp image with name filename to the current dir
// corresponding to the given frame struct
void writeFrame(frame_t *frame, char *filename) {
  FILE *f;
  unsigned char *img = NULL;
  int filesize = 54 + 3 * frame->height * frame->width;
  if( img )
    free( img );
  img = (unsigned char *)malloc(3* frame->height * frame->width);
  memset(img,0,sizeof(img));
  
  for(int i = 0; i < frame->width; i++) {
    for(int j = 0; j < frame->height; j++) {
      int x = i; 
      int y = (frame->height - 1) - j;
      uint8_t r = frame->colour[i][j]->red;
      uint8_t g = frame->colour[i][j]->green;
      uint8_t b = frame->colour[i][j]->blue;
      img[(x+y * frame->width)*3+2] = (unsigned char)(r);
      img[(x+y * frame->width)*3+1] = (unsigned char)(g);
      img[(x+y * frame->width)*3+0] = (unsigned char)(b);
    }
  }
  
  unsigned char bmpfileheader[14] = {'B','M', 0,0,0,0, 0,0, 0,0, 54,0,0,0};
  unsigned char bmpinfoheader[40] = {40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0, 24,0};
  unsigned char bmppad[3] = {0,0,0};
  
  bmpfileheader[ 2] = (unsigned char)(filesize);
  bmpfileheader[ 3] = (unsigned char)(filesize >> 8);
  bmpfileheader[ 4] = (unsigned char)(filesize >>16);
  bmpfileheader[ 5] = (unsigned char)(filesize >>24);
  
  bmpinfoheader[ 4] = (unsigned char)(frame->width);
  bmpinfoheader[ 5] = (unsigned char)(frame->width >> 8);
  bmpinfoheader[ 6] = (unsigned char)(frame->width >>16);
  bmpinfoheader[ 7] = (unsigned char)(frame->width >>24);
  bmpinfoheader[ 8] = (unsigned char)(frame->height);
  bmpinfoheader[ 9] = (unsigned char)(frame->height >> 8);
  bmpinfoheader[10] = (unsigned char)(frame->height >>16);
  bmpinfoheader[11] = (unsigned char)(frame->height >>24);
  
  f = fopen(filename,"wb");
  fwrite(bmpfileheader,1,14,f);
  fwrite(bmpinfoheader,1,40,f);
  for(int i = 0; i < frame->height; i++) {
    fwrite(img+(frame->width*(frame->height-i-1)*3),3,frame->width,f);
    fwrite(bmppad,1,(4-(frame->width*3)%4)%4,f);
  }
  fclose(f);
  free(img);
}

// Allocates and returns a blank frame structure
// of the given width and height
frame_t *createFrame(int width, int height) {
  frame_t *frame = malloc(sizeof(frame_t));
  colour_t ***colour = malloc(width * sizeof(colour_t **));

  for(int i = 0; i < width; i++) {
    colour_t **colour_col = malloc(height * sizeof(colour_t *));
    for(int j = 0; j < height; j++) {
      colour_t *colour_entry = malloc(sizeof(colour_t));
      colour_entry->red = 255;
      colour_entry->green = 255;
      colour_entry->blue = 255;
      colour_col[j] = colour_entry;
    }
    colour[i] = colour_col;
  }

  frame->width = width;
  frame->height = height;
  frame->colour = colour;

  return frame;
}

// Frees the memory used by the given frame ptr
void destroyFrame(frame_t *frame) {
  for(int i = 0; i < frame->width; i++) {
    for(int j = 0; j < frame->height; j++) {
      colour_t **col = frame->colour[i];
      free(col[j]);
    }
    if (frame->colour[i]) {
      free(frame->colour[i]);
    }
  }
  free(frame->colour);
  free(frame);
}
