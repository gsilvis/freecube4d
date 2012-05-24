#include <stdio.h>
#include <stdlib.h>
#include "cube.h"
#define DONE printf("Done\n")

int main(int argc, char** argv) {
  printf("Starting ... ");
  Cube *c = malloc(sizeof(Cube));
  DONE;
  printf("Making default cube ... ");
  initialize_cube(c,3);
  DONE;
  print_cube(c);
  free_cube(c);
  free(c);
  printf("Exiting ...\n");
  return 0;
}
