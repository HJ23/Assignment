#ifndef SOLVER
#define SOLVER

#include <stdio.h>
#include <stdlib.h>

void print();
int loop(char **content,int** lenghtMatrix ,int a, int b,int row,int col);
int32_t solve(char** content,int r,int c);
void display(char** content,int r,int c);
#endif
