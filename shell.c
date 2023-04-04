#include "lmvs.h"

int main(int argc, char **argv)
{
    if(argc == 2 ){
		batch(argv);
        kill(0, 9); 
    }else if(argc == 1){
		interative();
	}

}



