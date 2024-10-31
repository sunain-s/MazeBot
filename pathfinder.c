// robot pathfinding
#include <stdbool.h>
#include "robot.h"

void move_robot(Robot *r, int *map, int cols) {
    if (can_move_forward(r, map, cols)) {
            forward(r);
    }
    else {
        right(r);
        if (!can_move_forward(r, map, cols)) {
            left(r);
            left(r);
        }
    }
}