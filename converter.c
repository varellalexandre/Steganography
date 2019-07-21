#include "converter.h"
int strParseInt(char * str){
	int num = 0;
	for(int i = 0 ; i<strlen(str) ; ++i){
		num += (((int) str[strlen(str)-1-i])-48)*potencia(10,i);
	}
	return num;
}
char * intParseStr(int n){
	char * retorno;
	int size = getSize(n);
	if(size<=8)
		size = 8;
	retorno = (char *) malloc((size+1)*sizeof(char));
	for(int i = 0;i<size;++i){
		retorno[size-1-i] = (char) (48+(n%10));
		n = n/10;
	}
	retorno[size]='\0';
	return retorno;
}
char * decToBin(char * dec){
	char * retorno;
	int num=0;
	int bin = 0;
	num = strParseInt(dec);
	int aux = 0;
	while(num>=1){
		bin = bin+(num%2)*potencia(10,aux);
		num = num/2;
		++aux;
	}
	retorno = intParseStr(bin);
	return retorno;
}
char * binToDec(char * bin){
	char * retorno;
	int num=0;
	int saida = 0;
	saida = strParseInt(bin);
	int aux = 0;
	while(saida>=1){
		num+=(saida%10)*potencia(2,aux);
		saida = saida/10;
		++aux;
	}
	retorno = intParseStr(num);
	return retorno;
}
int getSize(int n){
	int i = 0;
	while(n>=1){
		n = n/10;
		++i;
	}
	return i;
}
int potencia(int base,int exp){
	int retorno = 1;
	for(int i = 0;i<exp;++i)
		retorno = retorno*base;
	return retorno;
}