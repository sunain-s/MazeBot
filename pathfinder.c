// robot pathfinding
#include <stdbool.h>
#include "robot.h"

void move_robot(Robot *r, int *map, int cols) {
    right(r);
    if (can_move_forward(r, map, cols)) {
        forward(r);
    }
    else {
        left(r);
        if (can_move_forward(r, map, cols)) {
            forward(r);
        }
        else {
            left(r);
            if (can_move_forward(r, map, cols)) {
                forward(r);
            }
            else {
                left(r);
                if (can_move_forward(r, map, cols)) {
                    forward(r);
                }
            }
        }
    }
}

// void depth_first_search(Robot *r, int *map, int cols, int num_markers) {
//     if (num_markers == get_marker_count(r)) {
//         return;
//     }
//     *((r->memory) + (r->y * cols) + r->x) = 1;
//     for (int i = 0; i < 4; i++) {
//         if (can_move_forward(r, map, cols)) {
//             forward(r);
//             if (*((r->memory) + (r->y * cols) + r->x) == 0) {
//                 return depth_first_search(r, map, cols, num_markers);
//             }
//             forward(r);
//         }
//         right(r);
//     //find_direction(r, map, cols);
//     }
//     *((r->memory) + (r->y * cols) + r->x) = 0;
//     // return depth_first_search(r, map, cols, num_markers);
// }