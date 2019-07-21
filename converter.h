#ifndef CONVERTER_H
	#define CONVERTER_H
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	char * decToBin(char * dec);
	char * binToDec(char * bin);
	int getSize(int n);
	int strParseInt(char * str);
	char * intParseStr(int n);
	int potencia(int base,int exp);
#endif