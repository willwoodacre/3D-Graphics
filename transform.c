#include "transform.h"
#include <math.h>
#define PI 3.14159265

static void apply_transformation(polygon_t *poly, double transform[4][4]) {
  //TODO: do non niave matrix multiplication
  for(int i = 0; i < 4; i++) {
    for(int j = 0; j < poly->no_verts; j++) {
      int sum = 0;
      for(int k = 0; k < 4; k++) {
        //Go from double land to nice int land
        sum += (int)(transform[i][k] * poly->verts[k][j]);
      }
      poly->verts[i][j] = sum;
    }
  }
}

static double getRad(double deg) {
  double rad = PI / 180.0;
  rad *= deg;
  return rad;
}

// Adds the given co-ordinates to the polygons co-ordinates
void move(polygon_t *poly, int x, int y, int z) {
  double transform[4][4] = {{1,0,0,x},
                           {0,1,0,y},
                           {0,0,1,z},
                           {0,0,0,1}};
  apply_transformation(poly, transform);
}

// Scales the polygon linearly by the given x, y and z factors
void scale(polygon_t *poly, int x, int y, int z) {
  double transform[4][4] = {{x,0,0,0},
                           {0,y,0,0},
                           {0,0,z,0},
                           {0,0,0,1}};
  apply_transformation(poly, transform);
}

// Rotate the polygon on the x axis relative to the origin
void rotx(polygon_t *poly, double deg) {
  double rad = getRad(deg);
  double c = cos(rad);
  double s = sin(rad);
  double transform[4][4] = {{1,0,0,0},
                           {0,c,-s,0},
                           {0,s,c,0},
                           {0,0,0,1}};
  apply_transformation(poly, transform);
}

// Rotate the polygon on the y axis relative to the origin
void roty(polygon_t *poly, double deg) {
  double rad = getRad(deg);
  double c = cos(rad);
  double s = sin(rad);
  double transform[4][4] = {{c,0,s,0},
                           {0,1,0,0},
                           {-s,0,c,0},
                           {0,0,0,1}};
  apply_transformation(poly, transform);
}

// Rotate the polygon on the z axis relative to the origin
void rotz(polygon_t *poly, double deg) {
  double rad = getRad(deg);
  double c = cos(rad);
  double s = sin(rad);
  double transform[4][4] = {{c,-s,0,0},
                           {s,c,0,0},
                           {0,0,1,0},
                           {0,0,0,1}};
  apply_transformation(poly, transform);
}
