#ifndef GRID_H
#define GRID_H

#include <stdbool.h>

typedef struct coord {
    int x;
    int y;
} Point;

int screen_dimension(int, int);

Point * set_home(int *, int, int);

// void add_obstacles(int *, int, int, int);

void create_map(int *, int, int);

void sidewinder_maze(int *, int, int);

void draw_map(int *, int, int, int);

void add_markers(int *, int, int, int);

void draw_markers(int *, int, int, int);

// bool check_coord(int *, int, int, int, int);

#endif 