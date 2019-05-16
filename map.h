#include "cell.h"
#include <stdio.h>
#include <unistd.h>
#include <time.h>

void game(int h, int w);
void evolve(int h, int w, Cell m[h][w]);
void show(int h, int w, Cell m[h][w]);

