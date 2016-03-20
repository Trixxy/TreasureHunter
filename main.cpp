/***********************************************************
export LD_LIBRARY_PATH=/opt/gcc/4.8.1/lib64/
export LD_PRELOAD=/opt/gcc/4.8.1/lib64/libstdc++.so.6
***********************************************************/

#include "game.hpp"

int main(){
	using namespace cprogame;
	Game g;
	g.run();
	return 0;
}

