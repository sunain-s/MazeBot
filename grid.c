// grid features
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "graphics.h"
#include "grid.h"
#include "pathfinder.h"

//-----------------------------------------------------------------------------------------------
// Background

int num_cells(int screen_length, int cell_length) {
    return screen_length / cell_length;
}

Point* set_home(int *map, int cols, int rows) {
    Point *p = malloc(sizeof(Point));
    int i = 0;
    while (i < 1) {
        int c = rand() % (cols - 2) + 2;
        int r = rand() % (rows - 2) + 2;
        if (*((map + r * cols) + c) == 2) {
            *((map + r * cols) + c) = -2;
            p->x = c;
            p->y = r;
            i++;
        }
    }
    return p;
} 

void add_obstacles(int *map, int cols, int rows, int n) {
    int i = 0;
    while (i < n) {
        int c = rand() % (cols - 2) + 2;
        int r = rand() % (rows - 2) + 2;
        if (*((map + r * cols) + c) == 2) {
            *((map + r * cols) + c) = 3;
            i++;
        }
    }
}

// print map vals
// for (int i = 0; i < cols; i++) {
    //     printf("\n%d: ", i);
    //     for (int j = 0; j < rows; j++) {
    //         printf(" %d ", *((map + j * cols) + i));
    //     }
    // }
    // printf("\n\n\n");

void create_map(int *map, int cols, int rows) {
    for (int i = 0; i < rows ; i++) {
        for (int j = 0; j < cols; j++) {
            if ((i == 0 || j == 0 || i == rows - 1 || j == cols - 1)) { 
                *((map + i * cols) + j) = 0; // whitespace
            }
            else if ((i == 1 || j == 1 || i == rows - 2 || j == cols - 2)) { 
                *((map + i * cols) + j) = 1; // map boundary
            }
            else { 
                *((map + i * cols) + j) = 2; // grid cell
            } 
        }
    }
}


void draw_map(int *map, int cols, int rows, int length) {
    for (int i = 0; i < rows; i++) {    
        for (int j = 0; j < cols; j++) {
            if (*((map + i * cols) + j) != 0) {
                if (*((map + i * cols) + j) == -1) {
                    setRGBColour(23, 199, 4);
                    fillRect(length * j, length * i, length, length);
                }
                else if (*((map + i * cols) + j) == 1) {
                    setRGBColour(255, 69, 8);
                    fillRect(length * j, length * i, length, length);
                }
                else if (*((map + i * cols) + j) == 3) { 
                    setRGBColour(0, 0, 0);
                    fillRect(length * j, length * i, length, length);    
                }
                else {
                    setRGBColour(0, 0, 0);
                    drawRect(length * j, length * i, length, length);  
                }
            }
        }
    }
}

//-----------------------------------------------------------------------------------------------
// Foreground

void add_markers(int *map, int cols, int rows, int n) {
    int i = 0;
    while (i < n) {
        int c = rand() % (cols - 2) + 2;
        int r = rand() % (rows - 2) + 2;
        if (*((map + r * cols) + c) == 2) {
            *((map + r * cols) + c) = 4;
            i++;
        }
    }   
}

void draw_markers(int *map, int cols, int rows, int length) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (*((map + i * cols) + j) == 4) {
                setRGBColour(255, 231, 15);
                fillArc(length * j, length * i, length, length, 0, 360);
            }
        }
    }
}


// check pointer arithmetic for this
bool check_coord(int *map, int cols, int rows, int x, int y, int type_val) {
    if (*((map + y * cols) + x) == type_val) {
        return true;
    }
    return false;
}