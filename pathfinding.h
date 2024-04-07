#ifndef PATHFINDING
#define PATHFINDING
#include "math.h"



struct cell {
    /* data */
    int x; 
    int y;
    struct cell *parent;
    int g;
    float f;
};

// 1 means unblocked and 0 means blocked
int grid[9][10] = {
    { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
    { 1, 1, 1, 0, 1, 1, 1, 0, 1, 1 },
    { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
    { 0, 0, 1, 0, 1, 0, 0, 0, 0, 1 },
    { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
    { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
    { 1, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
    { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
    { 1, 1, 1, 0, 0, 0, 1, 0, 0, 1 }
};

int IsValid(struct cell cell)
{
    // Check for out of range values
    return (0 <= cell.x) && (cell.x < 10) && (0 <= cell.y) && (cell.y < 9);
};

int IsUnblocked(struct cell cell)
{
    // 1 means unblocked and 0 means blocked
    return grid[cell.y][cell.x];
};

int g(struct cell cell)
{
    // Number of parents to cell
    return cell.parent->g + 1;
};

float h(struct cell cell, struct cell dst)
{
    int i;
    // Euclidian distance
    return sqrt(pow(dst.x-cell.x, 2) + pow(dst.y-cell.y, 2));
};

float f(struct cell cell, struct cell dst)
{
    // Value of cell
    return g(cell) + h(cell, dst);
};

struct cell *trace_path(struct cell cell)
{
    // Trace the path from destination to source through parents
    struct cell *parentcell = &cell;
    struct cell reversepath[54];
    reversepath[0] = cell;
    int cells = 1;

    while (parentcell != 0)
    {
        parentcell = parentcell->parent;
        reversepath[cells] = *(parentcell);
        cells++;
    }

    struct cell *path = (struct cell*)calloc(sizeof(struct cell), cells);
    
    for (int i = 0; i < cells; i++)
    {
        path[i] = reversepath[cells-i-1];
        i++;
    }

    return path;

};

void search(struct cell *open, struct cell *closed, struct cell src, struct cell dst)
{
    // Calculate f values of neighbours and adds the cell to the closed list
};

int A_star(struct cell src, struct cell dst)
{
    struct cell open[54] = {};
    int open_iterator = 0;
    int closed[9][10];
    struct cell map[9][10] = {};
};

#endif