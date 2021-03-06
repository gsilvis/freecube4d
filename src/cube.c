#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "cube.h"


// determines where a sticker is
#define EVIL() if (s != NOSIDE) return (location){NOSIDE,{0,0,0}}
location get_location(const Cube *c, coord4d co) {
  side s = NOSIDE;
  if (co.x == 0) {
    s = RIGHT;
  }
  if (co.x == c->size+1) {
    EVIL(); // macro: expands to 'if side has been defined, then exit'
            // if something seems to be on two sides, it is not on any side.
    s = LEFT;
  }
  if (co.y == 0) {
    EVIL();
    s = FRONT;
  }
  if (co.y == c->size+1) {
    EVIL();
    s = BACK;
  }
  if (co.z == 0) {
    EVIL();
    s = TOP;
  }
  if (co.z == c->size+1) {
    EVIL();
    s = BOTTOM;
  }
  if (co.w == 0) {
    EVIL();
    s = CENTER;
  }
  if (co.w == c->size+1) {
    EVIL();
    s = OUTER;
  }
 
  if (s == RIGHT  || s == LEFT   ) return (location){s,{co.y,co.z,co.w}};
  if (s == FRONT  || s == BACK   ) return (location){s,{co.x,co.z,co.w}};
  if (s == TOP    || s == BOTTOM ) return (location){s,{co.x,co.y,co.w}};
  if (s == CENTER || s == OUTER  ) return (location){s,{co.x,co.y,co.z}};
  // if a sticker is not on any side, don't bother returning any x,y,z coordinates
  return (location){NOSIDE,{0,0,0}};
}
// for the good of all mankind : |
#undef EVIL
// rotate src into dst, around the sticker at pivot.
void rotate(const Cube *src, Cube *dst, coord4d pivot) {
  //TODO: implement
}
// initializes a 4d cube, given its size
void initialize_cube(Cube *c, int size) {
  location L;

  assert(size >= 1);
  c->size = size;
  c->stickers = malloc((POW4(size+2)*sizeof(color)));

  for (int x=0; x < size+2; x++) {
    for (int y=0; y < size+2; y++) {
      for (int z=0; z < size+2; z++) {
        for (int w=0; w < size+2; w++) {
          L = get_location(c, (coord4d) {x,y,z,w});
          AT4D(c,x,y,z,w) = (color)L.sticker_side;
        }
      }
    }
  }
}

// free a cube's memory
void free_cube(Cube *c) {
  free(c->stickers);
}

// print out a cube for  debug purposes in ascii
void print_cube(const Cube *c) {
  for (int x=0; x < c->size+2; x++) {
    for (int y=0; y < c->size+2; y++) {
      for (int z=0; z < c->size+2; z++) {
        for (int w=0; w < c->size+2; w++) {
          printf("%d ",(int)AT4D(c,x,y,z,w));
        }
        printf("\n");
      }
      printf("\n");
    }
    printf("\n");
  }
}
