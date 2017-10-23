#include "perspective.h"

// Recalculates the perspective structure after being transformed
// by recalculating its co-ordinates from the transform
static void recalculatePerspective(perspective_t *pers) {
  for (int i = 0; i < 3; i++) {
    int sum = 0;
    for (int j = 0; j < 3; j++) {
      sum += pers->trans[i][j] * pers->pos[j];
    }   
    pers->trans[i][3] = -1 * sum;
  }
}

// Allocates and returns and perspective structure
// Perspective given at co-ordinates (0,0,0)
perspective_t *createPerspective() {
  perspective_t *pers = malloc(sizeof(perspective_t));
  pers->trans = malloc(4 * sizeof(double *));
  pers->pos = malloc(3 * sizeof(int));

  for (int i = 0; i < 4; i++) {
    pers->trans[i] = malloc(4 * sizeof(double));
    for (int j = 0; j < 4; j++) {
      if (i == j) {
        pers->trans[i][j] = 1.0;
      } else {
        pers->trans[i][j] = 0;
      }
    }
  }

  pers->pos[0] = 0;
  pers->pos[1] = 0;
  pers->pos[2] = 0;

  return pers;
}

// Frees the given perspective structure
void destroyPerspective(perspective_t *pers) {
  for (int i = 0; i < 4; i++) {
    free(pers->trans[i]);
  }
  free(pers->trans);
  free(pers->pos);
  free(pers);
}

// Adds the given x, y and z to the co-ordinates of the given perspective
void movePerspective(perspective_t *pers, int x, int y, int z) {
  pers->pos[0] += x;
  pers->pos[1] += y;
  pers->pos[2] += z;
  recalculatePerspective(pers);
}              
