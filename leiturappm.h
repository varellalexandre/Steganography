#ifndef LEITURAPPM_H
	#define LEITURAPPM_H
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "pxx.h"
	#include "leituramsg.h"
	void readPXX(char * argv[]);
	PPM readP6(PXX aux,FILE * arquivo);
	void savePPM(PPM ppm,char * arquivo);
#endif