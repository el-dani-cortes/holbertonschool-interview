#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdlib.h>
#include <stdio.h>

/*Function that computes the sum of two sandpiles*/
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);

/*Copy a grid from another*/
void copy_grip(int grid_result[3][3], int grid_sum[3][3]);

/*Recursive toppling sandpiles round*/
void toppling_round(int grid1[3][3]);

#endif /* SANDPILES_H */
