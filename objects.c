#include "objects.h"
#include <stdlib.h>
#include <stdio.h>

int cube_verts[4][8] = {{0,0,0,0,1,1,1,1},
                        {0,0,1,1,0,0,1,1},
                        {0,1,0,1,0,1,0,1},
                        {1,1,1,1,1,1,1,1}};

bool cube_adj[8][8] =  {{0,1,1,0,1,0,0,0},
                        {1,0,0,1,0,1,0,0},
                        {1,0,0,1,0,1,0,0},
                        {0,1,1,0,0,0,0,1},
                        {1,0,0,0,0,1,1,0},
                        {0,1,0,0,1,0,0,1},
                        {0,0,1,0,1,0,0,1},
                        {0,0,0,1,0,1,1,0}};

const int cube_no_verts = 8;

polygon_t *createCube() {
  return createPoly(cube_no_verts, cube_verts, &cube_adj);
}

polygon_t *createPoly(int no_verts, int verts[][no_verts], bool adj[][no_verts]) {
  polygon_t *poly = malloc(sizeof(polygon_t));
  poly->verts = malloc(4 * sizeof(int *)); 
  poly->no_verts = no_verts;
  poly->adj = malloc(no_verts * sizeof(bool *));

  for(int i = 0; i < 4; i++) {
    poly->verts[i] = malloc(no_verts * sizeof(int));
    memcpy(poly->verts[i], &verts[i], no_verts * sizeof(int));
  }

  for(int i = 0; i < no_verts; i++) {
    poly->adj[i] = malloc(no_verts * sizeof(bool));
    memcpy(poly->adj[i], &adj[i], no_verts * sizeof(bool));
  }

  return poly;
}
