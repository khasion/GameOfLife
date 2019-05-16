#include <stdlib.h>

typedef struct cell{
	int alive;
	int neighs;
	int gen;
}Cell;

Cell *cellInit(int alive);

int isAlive(Cell c);
int getNeighbors(Cell c);
int getGen(Cell c);

int setNeighbors(Cell *c, int n);
int setGen(Cell *c, int n);

void kill(Cell *c);
void rez(Cell *c);
int willLive(Cell c);
void update(Cell *c);
