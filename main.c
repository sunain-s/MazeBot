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
    int cell_length = 20;
    int cols = 10 + rand() % 85;
    int rows = 10 + rand() % 35;
    if (cols % 2 == 0) cols--;
    if (rows % 2 == 0) rows--;
    int SCREEN_W = screen_dimension(cols, cell_length);
    int SCREEN_H = screen_dimension(rows, cell_length);
    setWindowSize(SCREEN_W, SCREEN_H);
    // printf("w: %d, h: %d\n", SCREEN_W, SCREEN_H);
    // printf("rows: %d, cols: %d\n", rows, cols);
    int *map = malloc(rows * cols * sizeof(int));
    int *robot_memory = malloc(rows * cols * sizeof(int));
    setup_memory(robot_memory, cols, rows);

    background();
    create_map(map, cols, rows);
    sidewinder_maze(map, cols, rows);
    // add_obstacles(map, cols, rows, (int)((rows - 4) * (cols - 4) * 0.4));

    Point *home = set_home(map, cols, rows);
    Dir direction;
    Robot *robot = create_robot((int)home->x, (int)home->y, EAST, 0, robot_memory);
    int num_markers = 3;
    add_markers(map, cols, rows, num_markers);
    draw_map(map, cols, rows, cell_length);

    foreground();
    while (true) {
        clear();
        if (is_at_home(robot, map, cols) && get_marker_count(robot) == num_markers) {
            for (int i = 0; i < num_markers; i++) {
                drop_marker(robot, map, cols);
            }
            draw_markers(map, cols, rows, cell_length);
            break;
        }
        draw_markers(map, cols, rows, cell_length);
        draw_robot(robot, cell_length);
        pick_up_marker(robot, map, cols);
        move_robot(robot, map, cols);
        
        sleep(50);
    }
    
    free(robot);
    free(map); // need to delete row by row - this isnt complete
    free(home);
    return 0;
}