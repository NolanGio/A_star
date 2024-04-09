#include <stdlib.h>
#include <stdio.h>
#include "pathfinding.h"



int main(int argc, char **argv)
{
    struct cell A = {1, 2};
    struct cell B = {2, 2, &A, 1, 0};
    struct cell C = {2, 3, &B};

    struct cell src = {8, 0};
    struct cell dst = {0, 0};

    struct cell *path[3] ={&A, &B, &C};
    path[0] = &A;
    path[1] = &B;
    path[2] = &C;

    int pathsize = sizeof(path)/sizeof(path[0]);
    printf("path size: %i\n", pathsize);
    for (int i = 0; i < pathsize; i++)
    {
        printf("cell: %c, x: %i, y: %i, parent's address: %i\n", 65+i, path[i]->x, path[i]->y, path[i]->parent);
    }
    printf("g(C) = %i\n", g(C));
    printf("h(C) = %f\n", h(C, dst));
    printf("f(C) = %f\n", f(C, dst));
}