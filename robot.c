// robot display and control

#include <stdlib.h>
#include <stdbool.h>
#include "graphics.h"
#include "robot.h"

Robot* create_robot(int x, int y, Dir direction, int markers) {
    Robot *r = malloc(sizeof(Robot));
    r -> x = x;
    r -> y = y;
    r -> direction = direction;
    r -> markers = markers;
    return r;
}

void draw_robot(Robot *r, int length) {
    setRGBColour(0, 0, 255);
    fillArc(r -> x * length, r -> y * length, length, length, 0, 360);
}

void forward() {

}

void left() {

}

void right() {

}

bool at_marker() {

}

bool can_move_forward() {

}

void pick_up_marker() {

}

void drop_marker() {

}

int get_marker_count() {

}