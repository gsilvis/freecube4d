#ifndef __CUBE
#define __CUBE
enum _color { 
  BLUE,   // right 
  YELLOW, // front
  PURPLE, // top
	RED,    // center
  GREEN,  // left
  WHITE,  // back
  PINK,   // bottom
  ORANGE, // outer
  NOCOLOR   // special: no sticker
};
typedef enum _color color;

enum _side {
  RIGHT,
  FRONT,
  TOP,
  CENTER,
  LEFT,
  BACK,
  BOTTOM,
  OUTER,
  NOSIDE
};
typedef enum _side side;

// sticker postions on face
enum _pos {
  CORNER_STICKER,
  EDGE_STICKER,
  CENTER_STICKER,
  FACE_CENTER_STICKER,
  NONSTICKER // interior of hypercube
};   
typedef enum _pos position;

// total sticker location in the hypercube as displayed
struct _loc {
  side sticker_side;
  position sticker_position;
};
typedef struct _loc location;

typedef color**** array4d;
typedef color***  Face;

struct _cube {
  array4d stickers; 
  unsigned char size;
};
typedef struct _cube Cube;

struct _coord {
  int x,
  int y,
  int z,
  int w
};
typedef coordinate _coord;

// returns faces in the order defined in _side
Face get_faces(Cube*);
// determines where a sticker is
location get_location(coordinate); 
// rotate a cube
void rotate(Cube*, Cube*, coordinate);
// initializes a 4d cube, given its size
void initialize_cube(Cube *, int);
#endif
