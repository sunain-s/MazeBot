// grid features and functions

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "graphics.h"
#include "grid.h"

//-----------------------------------------------------------------------------------------------
// Background

int set_screen_dimension(int cell_num, int cell_length) {
    return cell_num * cell_length;
}

Point* set_home(int *map, int cols, int rows) {
    Point *p = malloc(sizeof(Point));
    int i = 0;
    while (i < 1) {
        int c = rand() % (cols - 2) + 2;
        int r = rand() % (rows - 2) + 2;
        if (*((map + r * cols) + c) == 2) {
            *((map + r * cols) + c) = 4;
            p->x = c;
            p->y = r;
            i++;
        }
    }
    return p;
} 

void create_map(int *map, int cols, int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if ((i == 0 || j == 0 || i == rows - 1 || j == cols - 1)) { 
                *((map + i * cols) + j) = 0; // whitespace
            }
            else if ((i == 1 || j == 1 || i == rows - 2 || j == cols - 2)) { 
                *((map + i * cols) + j) = 1; // map boundary
            }
            else if (i % 2 == 0 && j % 2 == 0) {
                *((map + i * cols) + j) = 2; // grid cell
            } 
            else {
                *((map + i * cols) + j) = 3; // obstacle
            }
        }
    }
}

void sidewinder_maze(int *map, int cols, int rows) {
    // sidewinder maze generation algorithm, carves a route up or right randomly 
    for (int i = 2; i < rows - 1; i += 2) {
        int begin = 1;

        for (int j = 2; j < cols - 1; j += 2) {
            int carve_path_dir = (i == 2) ? 1 : rand() % 2;
            if (j == cols - 3) carve_path_dir = 0;
        
            if (carve_path_dir) {
                *((map + i * cols) + (j + 1)) = 2;
            } 
            else if (i != 2) {
                int up;
                do {
                    up = rand() % (j - begin + 1) + begin;
                } while (up % 2 == 1);
                *((map + (i - 1) * cols) + up) = 2;

            begin = j + 2;
            }
        }
    }
}

void draw_map(int *map, int cols, int rows, int length) {
    for (int i = 0; i < rows; i++) {    
        for (int j = 0; j < cols; j++) {
            if (*((map + i * cols) + j) != 0) {
                if (*((map + i * cols) + j) == 1) { // map boundary
                    setRGBColour(255, 69, 8);
                    fillRect(length * j, length * i, length, length);
                }
                else if (*((map + i * cols) + j) == 2 || *((map + i * cols) + j) ==  6) { // grid cell
                    setRGBColour(0, 0, 0);
                    drawRect(length * j, length * i, length, length);  
                }
                else if (*((map + i * cols) + j) == 3) { // obstacle
                    setRGBColour(0, 0, 0);
                    fillRect(length * j, length * i, length, length);    
                }
                else if (*((map + i * cols) + j) == 4) { // home cell
                    setRGBColour(23, 199, 4);
                    fillRect(length * j, length * i, length, length);
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
            *((map + r * cols) + c) = 6;
            i++;
        }
    }   
}

void draw_markers(int *map, int cols, int rows, int length) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (*((map + i * cols) + j) == 6) {
                setRGBColour(255, 231, 15);
                fillArc(length * j, length * i, length, length, 0, 360);
            }
        }
    }
}

void display_marker_count(int count, int length, int rows) {
    setRGBColour(0, 0, 0);
    char marker_str[30];
    sprintf(marker_str, "Markers: %d", count);
    drawString(marker_str, length, (rows + 0.8) * length);
}

// print map vals
// for (int i = 0; i < rows; i++) {
//     printf("\n%d: ", i);
//     for (int j = 0; j < cols; j++) {
//         printf(" %d ", *((robot_memory + i * cols) + j));
//     }
// }