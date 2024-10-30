#include <stdbool.h>

typedef struct coord{
    int x;
    int y;
} Point;

int num_cells(int, int);

void create_map(int *, int, int);

void add_obstacles(int *, int, int, int);

void draw_map(int *, int, int, int);

void add_markers(int *, int, int, int);

void draw_markers(int *, int, int, int);

bool check_coord(int *, int, int, int, int);