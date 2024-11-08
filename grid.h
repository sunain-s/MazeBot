#ifndef GRID_H
#define GRID_H

#include <stdbool.h>

typedef struct coord {
    int x;
    int y;
} Point;

int screen_dimension(int, int);

Point * set_home(int *, int *, int, int);

void create_map(int *, int, int);

void sidewinder_maze(int *, int, int);

void draw_map(int *, int, int, int);

void add_markers(int *, int, int, int);

void draw_markers(int *, int, int, int);

void display_marker_count(int, int, int);

#endif 