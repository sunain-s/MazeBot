#include <stdlib.h>
#include <time.h>
#include "graphics.h"
#include "grid.h"
#include "robot.h"

#define SCREEN_W 800
#define SCREEN_H 800

int main() { 
    srand((unsigned) time(NULL));
    setWindowSize(SCREEN_W, SCREEN_H);
    int cell_length = 30;
    int rows = num_cells(SCREEN_H, cell_length);
    int cols = num_cells(SCREEN_W, cell_length);
    int *map = malloc(rows * cols * sizeof(int));

    
    background();
    create_map(map, rows, cols);
    add_obstacles(map, rows, cols, 200);
    draw_map(map, rows, cols, cell_length);

    foreground();
    add_markers(map, rows, cols, 3);
    draw_markers(map, rows, cols, cell_length);
    Robot *robot = create_robot(4, 5, 0, 0);
    draw_robot(robot, cell_length);
    

    free(robot);
    free(map);
    return 0;
}