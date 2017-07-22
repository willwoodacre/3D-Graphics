#ifndef OBJECTS_H
#define OBJECTS_H

#include <stdbool.h>

typedef struct co_ord {
  int x;
  int y;
} co_ord_t;

typedef struct polygon {
  int no_verts; // the number of vertices in the polygon
  int **verts; // a matrix of the polygons vertices (with scale factors)
  bool **adj; // the adjanency matrix of the vertices
} polygon_t;

polygon_t *createPoly(int no_verts, int verts[][no_verts], bool adj[][no_verts]);
polygon_t *createCube(void);
void printVerts(polygon_t *);

#endif
