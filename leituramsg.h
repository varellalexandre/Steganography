#ifndef LEITURAMSG_H
	#define LEITURAMSG_H
	#include <stdio.h>
	#include <stdlib.h>
	#include "converter.h"
	#include "pxx.h"
	char * getMessage(char * name);
	void encript(RGB ** val,char * mensagem,int largura,int altura);
	void decript(RGB ** val,FILE * local,int largura,int altura);
	char veracidade(char * argv[]);
#endif