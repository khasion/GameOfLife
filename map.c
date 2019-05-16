#include "map.h"

void game(int h, int w){
	Cell m[h][w];
	int r, i, j;
	srand(time(0));
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			r = rand()%10;
			if (r==0) m[i][j] = *cellInit(1);
			else m[i][j] = *cellInit(0);	
		}
	}
	while(1){
		show(h, w, m);
		evolve(h, w, m);
		usleep(100000);
	}
}

void evolve(int h, int w, Cell m[h][w]){
	int i, j, i1, j1, n;
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			n = 0;
			for(i1=i-1;i1<=i+1;i1++){
				for(j1=j-1;j1<=j+1;j1++){
					if( isAlive( m[(i1+h)%h][(j1+w)%w] ) == 1 ){
						n++;
					}
				}
			}
			if ( isAlive(m[i][j]) == 1){
				 n--;
			}
			setNeighbors( &m[i][j], n);
		}
	}
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			update(&m[i][j]);
		}
	}	
}

void show(int h, int w, Cell m[h][w]){
	int i, j;
	printf("\033[H");
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			if (isAlive(m[i][j])){
				 printf("\033[07m \033[m");
			}
			else{
				 printf(" ");
			}
		}
		printf("\033[E");
	}	
	fflush(stdout);
}
