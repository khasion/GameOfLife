#include "scale.h"

int getWinHeight(){
	struct winsize w;
    	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	return w.ws_row;
}

int getWinWidth(){
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	return w.ws_col;
}
