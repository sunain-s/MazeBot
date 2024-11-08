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
    if (*((r->memory) + (r->y * cols) + r->x) == 0) {
        *((r->memory) + (r->y * cols) + r->x) = 1;
    }
}