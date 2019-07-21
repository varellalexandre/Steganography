#include <stdio.h>
#include "leiturappm.h"
#include "leiturabmp.h"
int main(int argc,char * argv[]){
	if(argc != 7 && argc != 6){
		printf("A quantidade de argumentos está errada\n");
		return 0;
	}
	else{
		if((argc == 7 && !strcmp(argv[5],"ppm")) || (argc == 6 && !strcmp(argv[4],"ppm"))){
			readPXX(argv);	
		}else if ((argc == 7 && !strcmp(argv[5],"bmp")) || (argc == 6 && !strcmp(argv[4],"bmp"))){
			readDIB(argv);
		}
	}
	return 0;
}
