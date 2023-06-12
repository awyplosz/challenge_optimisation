#define MAX_GRID_SIZE 100

typedef struct {
    int row;
    int col;
} Cell;

typedef struct {
    int rows;
    int cols;
    Cell targets[MAX_GRID_SIZE];
    Cell obstacles[MAX_GRID_SIZE];
    int numTargets;
    int numObstacles;
} Instance;

typedef struct {
    char teamName[50];
    int instanceNum;
    Cell guards[MAX_GRID_SIZE];
    int numGuards;
} Solution;