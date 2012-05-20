#include "cube.h"

void initialize_cube(Cube *c, int size) {
  array4d stickers;

  stickers = malloc(size*size*size*size*sizeof(color));
  c->size = size;
  c->stickers = stickers;
}
