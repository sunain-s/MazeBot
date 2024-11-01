#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "graphics.h"
#include "grid.h"
#include "robot.h"
#include "pathfinder.h"

// void move_robot(Robot *r, int *map, int cols) {
//     if (can_move_forward(r, map, cols)) {
//             forward(r);
//     }
//     else {
//         right(r);
//         if (!can_move_forward(r, map, cols)) {
//             left(r);
//             left(r);
//         }
//     }
// }


int main() {
    srand((unsigned) time(NULL));
    int SCREEN_W = 200; //+ 100 * (rand() % 18);
    int SCREEN_H = 200; //+ 100 * (rand() % 8);
    // printf("w: %d, h: %d\n", SCREEN_W, SCREEN_H);
    setWindowSize(SCREEN_W, SCREEN_H);
    int cell_length = 20;
    int cols = num_cells(SCREEN_W, cell_length);
    int rows = num_cells(SCREEN_H, cell_length);
    // printf("rows: %d, cols: %d\n", rows, cols);
    int *map = malloc(rows * cols * sizeof(int));

    background();
    create_map(map, cols, rows);
    add_obstacles(map, cols, rows, (int)((rows - 4) * (cols - 4) * 0.4));

    Point *home = set_home(map, cols, rows);
    Dir direction;
    Robot *robot = create_robot((int)home->x, (int)home->y, EAST, 0);
    add_markers(map, cols, rows, 3);
    draw_map(map, cols, rows, cell_length);

    foreground();
    while (true) {
        clear();
        draw_markers(map, cols, rows, cell_length);
        pick_up_marker(robot, map, cols);
        draw_robot(robot, cell_length);
        move_robot(robot, map, cols); 
        sleep(1000);
    }
    
    free(robot);
    free(map);
    free(home);
    return 0;
}