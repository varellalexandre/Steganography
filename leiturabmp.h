#ifndef LEITURABMP_H
	#define LEITURABMP_H
	#include "bmp.h"
	#include "leiturappm.h"
	#include <stdio.h>
	#include <stdlib.h>
	void readDIB(char * argv[]);
	void saveBMP(BMP bmp,char * arquivo);
	void encriptBMP(BMP * bmp,char * menssagem);
	void decriptBMP(BMP bmp,FILE * local);
	int contrarioInt(FILE * arquivo);
	BMP readBMP(FILE * arquivo);
#endif