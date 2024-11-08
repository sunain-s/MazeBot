// robot display and control

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "graphics.h"
#include "grid.h"
#include "robot.h"

Robot* create_robot(int x, int y, int direction, int markers, int *robot_memory) {
    Robot *r = malloc(sizeof(Robot));
    r->x = x;
    r->y = y;
    r->direction = direction;
    r->markers = markers;
    r->memory = robot_memory;
    return r;
}

void draw_robot(Robot *r, int length) {
    setRGBColour(0, 0, 255);
    // fillArc(r->x * length, r->y * length, length, length, 0, 360);
    if (r->direction == EAST) {
        fillPolygon(3, (int[]){r->x * length + length / 10, r->x * length + length / 10, r->x * length + length}, (int[]){r->y * length + length / 10, r->y * length + 9 * length / 10, r->y * length + length / 2});
    }
    else if (r->direction == SOUTH) {
        fillPolygon(3, (int[]){r->x * length + length / 2, r->x * length + length / 10, r->x * length + 9 * length / 10}, (int[]){r->y * length + length, r->y * length + length / 10, r->y * length + length / 10});
    }
    else if (r->direction == WEST) {
        fillPolygon(3, (int[]){r->x * length, r->x * length + 9 * length / 10, r->x * length + 9 * length / 10}, (int[]){r->y * length + length / 2, r->y * length + length / 10, r->y * length + 9 * length / 10});
    }
    else if (r->direction == NORTH) {
        fillPolygon(3, (int[]){r->x * length + length / 2, r->x * length + length / 10, r->x * length + 9 * length / 10}, (int[]){r->y * length, r->y * length + 9 * length / 10, r->y * length + 9 * length / 10});
    }
}

void forward(Robot *r) {
    if (r->direction == EAST) {
        r->x += 1;
    }
    else if (r->direction == SOUTH) {
        r->y += 1;
    }
    else if (r->direction == WEST) {
        r->x -= 1;
    }
    else {
        r->y -= 1;
    }
}

void left(Robot *r) {
    r->direction = (r->direction - 1) % 4;
}   

void right(Robot *r) {
    r->direction = (r->direction + 1) % 4;
}

bool at_marker(Robot *r, int *map, int cols) {
    if (*((map + r->y * cols) + r->x) == 6) {
        return true;
    }
    return false;
}

bool can_move_forward(Robot *r, int *map, int cols) {
    if (r->direction == EAST) {
        if (*((map + r->y * cols) + (r->x + 1)) % 2 == 0) {
            return true;
        }
    }
    else if (r->direction == SOUTH) {
        if (*((map + (r->y + 1) * cols) + r->x) % 2 == 0) {
            return true;
        }
    }
    else if (r->direction == WEST) {
        if (*((map + r->y * cols) + (r->x - 1)) % 2 == 0) {
            return true;
        }
    }
    else {
        if (*((map + (r->y - 1) * cols) + r->x) % 2 == 0) {
            return true;
        }
    }
    return false;
}

void pick_up_marker(Robot *r, int *map, int cols) {
    if (at_marker(r, map, cols)) {
        r->markers += 1;
        *((map + r->y * cols) + r->x) = 2;
    }
}

void drop_marker(Robot *r, int *map, int cols) {
    if (r->markers > 0) {
        r->markers -= 1;
        *((map + r->y * cols) + r->x) = 6;
    }
}

int get_marker_count(Robot *r) {
    return r->markers;
}

bool is_at_home(Robot *r, int *map, int cols) {
    if (*((map + r->y * cols) + r->x) == 4) {
        return true;
    }
    return false;
}

void setup_memory(int *memory, int cols, int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            *((memory) + (i * cols) + j) = 0;
        }
    }
}