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
  NOCOLOR,   // special: no sticker
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
  NOSIDE,
};
typedef enum _side side;

// sticker postions on face
enum _pos {
  CORNER_STICKER,
  EDGE_STICKER,
  CENTER_STICKER,
  FACE_CENTER_STICKER,
  NONSTICKER, // interior of hypercube
};   
typedef enum _pos position;

// sticker coord4d in face
struct _coord3d {
  int x;
  int y;
  int z;
};
typedef struct _coord3d coord3d;

// total sticker location in the hypercube as displayed
struct _loc {
  side sticker_side;
  coord3d coord;
};
typedef struct _loc location;

typedef color* array4d;
typedef color* array3d;

struct _cube {
  array4d stickers; 
  int size;
};
typedef struct _cube Cube;

struct _face {
  array3d stickers;
  int size;
};
typedef struct _face Face;

struct _coord4d {
  int x;
  int y;
  int z;
  int w;
};
typedef struct _coord4d coord4d;

// returns faces in the order defined in _side
//Face get_faces(Cube*);
location get_location(const Cube *, coord4d); 
// rotate a cube
void rotate(const Cube*, Cube*, coord4d);
// initializes a 4d cube, given its size
void initialize_cube(Cube *, int);
// frees the memory allocated by a cube
void free_cube(Cube *);
// displays a cube in text form - debug only
void print_cube(const Cube *);

// Power macros
#define POW4(A) (A)*POW3(A)
#define POW3(A) (A)*POW2(A)
#define POW2(A) (A)*(A)
// 4d array access macro. Takes a Cube*, and 4 ints, or a Cube and a coord4d.
#define AT4D(C,X,Y,Z,W) (C)->stickers[(X) + ((C)->size+2)*(Y) + \
                        (POW2((C)->size+2))*(Z) + \
                        (POW3((C)->size+2))*(W)]
#define AT3D(F,X,Y,Z) (F)->stickers[(X) + ((F)->size+2)*(Y) + \
                       (POW2((F)->size+2))*(Z)]
#define AT4DC(C,L) AT((C),(L).x,(L).y,(L).z,(L).w)

#endif
