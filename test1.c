#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool isCovered[MAX_GRID_SIZE][MAX_GRID_SIZE];

void initializeCoveredCells(int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            isCovered[i][j] = false;
        }
    }
}

bool isValidPosition(int row, int col, Instance instance) {
    if (row < 0 || row >= instance.rows || col < 0 || col >= instance.cols) {
        return false;
    }
    for (int i = 0; i < instance.numObstacles; i++) {
        if (row == instance.obstacles[i].row && col == instance.obstacles[i].col) {
            return false;
        }
    }
    return true;
}

void updateCoveredCells(int row, int col, Instance instance) {
    for (int i = 0; i < instance.rows; i++) {
        if (isValidPosition(i, col, instance)) {
            isCovered[i][col] = true;
        }
    }
    for (int j = 0; j < instance.cols; j++) {
        if (isValidPosition(row, j, instance)) {
            isCovered[row][j] = true;
        }
    }
}

void solveInstance(Instance instance, Solution* solution) {
    initializeCoveredCells(instance.rows, instance.cols);
    solution->numGuards = 0;

    for (int i = 0; i < instance.rows; i++) {
        for (int j = 0; j < instance.cols; j++) {
            if (isValidPosition(i, j, instance)) {
                bool coversTarget = false;
                for (int k = 0; k < instance.numTargets; k++) {
                    if (instance.targets[k].row == i && instance.targets[k].col == j && !isCovered[i][j]) {
                        coversTarget = true;
                        break;
                    }
                }
                if (coversTarget) {
                    solution->guards[solution->numGuards].row = i;
                    solution->guards[solution->numGuards].col = j;
                    solution->numGuards++;
                    updateCoveredCells(i, j, instance);
                }
            }
        }
    }
}

void readInstance(FILE* file, Instance* instance) {
    char type[10];
    int row, col;
    instance->numTargets = 0;
    instance->numObstacles = 0;

    while (fscanf(file, "%s", type) != EOF) {
        if (strcmp(type, "LIGNES") == 0) {
            fscanf(file, "%d", &instance->rows);
        } else if (strcmp(type, "COLONNES") == 0) {
            fscanf(file, "%d", &instance->cols);
        } else if (strcmp(type, "CIBLE") == 0) {
            fscanf(file, "%d %d", &row, &col);
            instance->targets[instance->numTargets].row = row;
            instance->targets[instance->numTargets].col = col;
            instance->numTargets++;
        } else if (strcmp(type, "OBSTACLE") == 0) {
            fscanf(file, "%d %d", &row, &col);
            instance->obstacles[instance->numObstacles].row = row;
            instance->obstacles[instance->numObstacles].col = col;
            instance->numObstacles++;
        }
    }
}

void writeSolution(FILE* file, Solution solution) {
    fprintf(file, "EQUIPE OpenAI\n");
    fprintf(file, "INSTANCE %d\n", solution.instanceNum);
    for (int i = 0; i < solution.numGuards; i++) {
        fprintf(file, "%d %d\n", solution.guards[i].row, solution.guards[i].col);
    }
}

int main() {
    int numInstances = 16;
    char inputFileName[10];
    char outputFileName[10];
    Instance instance;
    Solution solution;

    for (int i = 0; i < numInstances; i++) {
        sprintf(inputFileName, "gr%d.txt", i);
        FILE* inputFile = fopen(inputFileName, "r");
        if (inputFile == NULL) {
            printf("Cannot open input file: %s\n", inputFileName);
            continue;
        }

        readInstance(inputFile, &instance);
        fclose(inputFile);

        solution.instanceNum = i;
        solveInstance(instance, &solution);

        sprintf(outputFileName, "res_%d.txt", i);
        FILE* outputFile = fopen(outputFileName, "w");
        if (outputFile == NULL) {
            printf("Cannot open output file: %s\n", outputFileName);
            continue;
        }

        writeSolution(outputFile, solution);
        fclose(outputFile);
    }

    return 0;
}
