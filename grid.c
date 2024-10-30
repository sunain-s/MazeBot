// grid features

#include <stdlib.h>
#include <stdbool.h>
#include "graphics.h"

//-----------------------------------------------------------------------------------------------
// Background

int num_cells(int screen_length, int cell_length) {
    return screen_length / cell_length;
}

 set_home(int *map, int rows, int cols) {
    int r = rand() % (rows - 2) + 2;
    int c = rand() % (cols - 2) + 2;
    *((map + c * cols) + r) = -1;
} 

void add_obstacles(int *map, int rows, int cols, int n) {
    int i = 0;
    while (i < n) {
        int r = rand() % (rows - 2) + 2;
        int c = rand() % (cols - 2) + 2;
        if (*((map + c * cols) + r) == 2) {
            *((map + c * cols) + r) = 3;
            i++;
        }
    }
}

void create_map(int *map, int rows, int cols) {
    set_home(map, rows, cols);
    for (int i = 0; i < cols ; i++) {
        for (int j = 0; j < rows; j++) {
            if (*((map + i * cols) + j) != -1) {

                if ((i == 0 || j == 0 || i == cols - 1 || j == rows - 1)) { 
                *((map + i * cols) + j) = 0; // whitespace
                }
                else if ((i == 1 || j == 1 || i == cols - 2 || j == rows - 2)) { 
                    *((map + i * cols) + j) = 1; // map boundary
                }
                else { 
                    *((map + i * cols) + j) = 2; // grid cell
                }
            }
        }
    }
}

void draw_map(int *map, int rows, int cols, int length) {
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            if (*((map + i * cols) + j) == -1) {
                setRGBColour(23, 199, 4);
                //fillArc(length * i, length * j, length, length, 0, 360);
                fillRect(length * i, length * j, length, length);
            } 
            else if (*((map + i * cols) + j) == 0) {
                continue;
            }
            else if (*((map + i * cols) + j) == 1) {
                setRGBColour(255, 69, 8);
                fillRect(length * i, length * j, length, length);
            }
            else if (*((map + i * cols) + j) == 3) { 
                setRGBColour(0, 0, 0);
                fillRect(length * i, length * j, length, length);    
            }
            else {
                setRGBColour(0, 0, 0);
                drawRect(length * i, length * j, length, length);  
            }
        }
    }
}

//-----------------------------------------------------------------------------------------------
// Foreground

void add_markers(int *map, int rows, int cols, int n) {
    int i = 0;
    while (i < n) {
        int r = rand() % (rows - 2) + 2;
        int c = rand() % (cols - 2) + 2;
        if (*((map + c * cols) + r) == 2) {
            *((map + c * cols) + r) = 4;
            i++;
        }
    }
}

void draw_markers(int *map, int rows, int cols, int length) {
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            if (*((map + i * cols) + j) == 4) {
                setRGBColour(255, 231, 15);
                fillArc(length * i, length * j, length, length, 0, 360);
            }
        }
    }
}

bool check_coord(int *map, int rows, int cols, int x, int y, int type_val) {
    if (*((map + x * cols) + y) == type_val) {
        return true;
    }
    return false;
}