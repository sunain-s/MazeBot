typedef enum dir{
    EAST,
    SOUTH,
    WEST,
    NORTH
} Dir;

typedef struct Robot {
    int x;
    int y;
    Dir direction;
    int markers;
} Robot;

Robot * create_robot(int, int, int, int);

void draw_robot(Robot *, int);

void forward();

void left();

void right();

bool at_marker();

bool can_move_forward();

void pick_up_marker();

void drop_marker();

int get_marker_count();