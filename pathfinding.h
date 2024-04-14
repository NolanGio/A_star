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

int min_index(struct cell *open, int open_size)
{
    int index = 0;

    for (int i; i < open_size; i++)
    {
        if (open[i].f < open[index].f)
        {
            index = i;
        }
    }

    return index;
}

int IsValid(int x, int y)
{
    // Check for out of range values
    return (0 <= x) && (x < 10) && (0 <= y) && (y < 9);
};

int IsUnblocked(int x, int y)
{
    // 1 means unblocked and 0 means blocked
    return grid[y][x];
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
    if (cell.g)
    {
        return cell.g + h(cell, dst);
    } else {
        return g(cell) + h(cell, dst);
    }
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

    printf("(%i, %i)", path[0].x, path[0].y);
    for (int i = 1; i < cells; i++)
    {
        printf("->(%i, %i)", path[i].x, path[i].y);
    }

    printf("\n");
};

int check_dst(struct cell *open, int open_size, struct cell dst)
{
    // Check if the dst cell is in the open list
    int index = -1;

    for (int i; i < open_size; i++)
    {
        if (open[i].x == dst.x & open[i].y == dst.y)
        {
            index = i;
        }
    }

    return index;
}

void search(struct cell *open, struct cell dst)
{}
    // Calculate f values of neighbors of a cell and removes the cell from the open list

void A_star(struct cell src, struct cell dst)
{
    struct cell open[90] = {};
    int open_size = 0;
    struct cell map[9][10] = {};
    int directions[8][2] = {
        {-1, -1}, {0, -1}, {1, -1},
        {-1, 0},           {1, 0},
        {-1, 1},  {0, 1},  {1, 1},    
    };

    map[src.y][src.x] = src;
    
    // Loop through all neighbors
    for (int i = 0; i < 8; i++)
    {
        int x, y;
        struct cell cell = {src.x+directions[i][0], src.y+directions[i][1], &src, src.g+1, 0};
        cell.f = f(cell, dst);
        map[cell.y][cell.x] = cell;
        open[open_size] = cell;
        open_size++;
    }

    // Until the dst cell is in the open list and while there are still cells to explore in the open list
    while (check_dst(open, open_size, dst) < 0 & 0 < open_size)
    {
        
    }

    int index = check_dst(open, open_size, dst);

    if (index < 0)
    {
        printf("%s", "Could not find the path to destination\n");
    } else {
        trace_path(open[index]);
    }

};

#endif