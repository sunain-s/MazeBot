// main file

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "graphics.h"
#include "grid.h"
#include "robot.h"

//-----------------------------------------------------------------------------------------------

int main() {
    // setup
    srand((unsigned) time(NULL));
    int cell_length = 5 + rand() % 20;
    int cols = 10 + rand() % ((1900 - 10 * cell_length) / cell_length);
    int rows = 10 + rand() % ((900 - 10 * cell_length) / cell_length);
    if (cols % 2 == 0) cols--;
    if (rows % 2 == 0) rows--; // set odd dimensions for maze generation
    int SCREEN_W = set_screen_dimension(cols, cell_length);
    int SCREEN_H = set_screen_dimension(rows + 1, cell_length);
    setWindowSize(SCREEN_W, SCREEN_H);

    // background
    int *map = malloc(rows * cols * sizeof(int));
    int num_markers = 3 + rand() % (int)(rows * cols / 75);
    background();
    create_map(map, cols, rows);
    sidewinder_maze(map, cols, rows);
    Point *home = set_home(map, cols, rows);
    Dir direction;
    Robot *robot = create_robot((int)home->x, (int)home->y, EAST, 0);
    add_markers(map, cols, rows, num_markers);
    draw_map(map, cols, rows, cell_length);

    // main loop
    foreground();
    bool searching = true;
    while (searching) {    
        clear();
        display_marker_count(get_marker_count(robot), cell_length, rows);
        if (is_at_home(robot, map, cols) && get_marker_count(robot) == num_markers) {
            drop_marker(robot, map, cols);
            draw_markers(map, cols, rows, cell_length);
            searching = false;
        }
        draw_markers(map, cols, rows, cell_length);
        draw_robot(robot, cell_length);
        pick_up_marker(robot, map, cols);
        move_robot(robot, map, cols);
        sleep(50);
    }

    free(robot);
    free(home);
    free(map);
    return 0;
}