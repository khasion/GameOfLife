#include "cell.h"

Cell *cellInit(int alive){
	Cell *c;
	c = (Cell*) malloc(sizeof(Cell));
	c->alive = alive;
	setNeighbors(c, 0);
	c->gen = 0;
	return c;
}

int isAlive(Cell c){
	return c.alive;
}

int getNeighbors(Cell c){
	return c.neighs;
}

int getGen(Cell c){
	return c.gen;
}

int setNeighbors(Cell *c, int n){
	c->neighs = n;
}

int setGen(Cell *c, int n){
	c->gen = n;
}

void kill(Cell *c){
	c->alive = 0;
	setGen(c, 0);
}

void rez(Cell *c){
	c->alive = 1;
	setGen(c, 0);
}

int willLive(Cell c){
	if (isAlive(c) && c.neighs < 2 ){
	 	 return 0;
	}
	else if (isAlive(c) && (c.neighs == 3 || c.neighs == 2)){
		 return 1;
	} 
	else if (isAlive(c) && c.neighs > 3){
		 return 0;
	}
	else if (!isAlive(c) && c.neighs == 3){
		 return 1;
	}
}

void update(Cell *c){
	if (isAlive(*c) && c->neighs < 2 ){
		 kill(c);
	 	 return;
	}
	else if (isAlive(*c) && (c->neighs == 3 || c->neighs == 2)){
		 setGen(c, getGen(*c)+1);
		 return;
	} 
	else if (isAlive(*c) && c->neighs > 3){
		 kill(c);
		 return;
	}
	else if (!isAlive(*c) && c->neighs == 3){
		 rez(c);
		 return;
	}
}
