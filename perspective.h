#ifndef PERSPECTIVE_H
#define PERSPECTIVE_H

typedef struct perspective {
  double **trans; // The transformation matrix for the perspective
  int *pos; // A vector showing the displacement from the 0 coordinate
} perspective_t;

perspective_t *createPerspective(void);
void movePerspective(perspective_t *, int x, int y, int z);

#endif
