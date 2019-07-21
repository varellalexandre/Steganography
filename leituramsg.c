#include "leituramsg.h"
char * getMessage(char * name){
	FILE * arquivo = fopen(name,"r");
	if(arquivo !=NULL){
		int i = 0;
		char c;
		char * message;
		while((c = fgetc(arquivo))!=EOF){
			++i;
		}
		rewind(arquivo);
		message = (char *) malloc(sizeof(char)*i+1);
		fgets(message,i+1,arquivo);
		return message;
	}else{
		exit(0);
	}
}
void encript(RGB ** val,char * mensagem,int largura,int altura){
	if((long long int) strlen(mensagem)*9 <= (long long int) altura*largura*3){
		int i = 0,linha = 0,coluna = 0;
		do{
			char * digit = decToBin(intParseStr((int) mensagem[i]));
			for(int j = 0;j<8;++j){
				if(j%3 == 0)
					val[linha][coluna].r = (val[linha][coluna].r&lastbitmask) + digit[j]-48;
				else if(j%3 == 1)
					val[linha][coluna].g = (val[linha][coluna].r&lastbitmask) + digit[j]-48;
				else if(j%3 == 2)
					val[linha][coluna].b = (val[linha][coluna].r&lastbitmask) + digit[j]-48;
				if(coluna == largura-1){
					coluna = 0;
					++linha;
				}
				else
					++coluna;
			}
			++i;
			free(digit);
		}while(i<=strlen(mensagem));
	}else{
		printf("TAMANHO DA IMAGEM INSUFICIENTE");
	}
}
void decript(RGB ** val,FILE * local,int largura,int altura){
	char aux = 'a';
	int linha = 0,coluna = 0;
	while(aux != 0){
		aux = 0;
		for(int i = 7;i>=0;--i){
			if(i%3 == 1)
				aux+=val[linha][coluna].r%2*potencia(2,i);
			else if(i%3 == 0)
				aux+=val[linha][coluna].g%2*potencia(2,i);
			else if(i%3 == 2)
				aux+=val[linha][coluna].b%2*potencia(2,i);
			if(coluna == largura-1){
				coluna = 0;
				++linha;
			}
			else
				++coluna;
		}
		if(aux != 0)
			fprintf(local,"%c",aux);
	}
	return;	
}
char veracidade(char * argv[]){
	if(!strcmp(argv[1],"-d")){
		if(!strcmp(argv[2],"-s") && (!strcmp(argv[4],"ppm") || !strcmp(argv[4],"bmp"))){
			return 1;
		}else if(!strcmp(argv[2],"-o") && (!strcmp(argv[5],"ppm") || !strcmp(argv[5],"bmp"))){
			return 1;
		}
	}else if(!strcmp(argv[1],"-e") && !strcmp(argv[2],"-i")){
		if(!strcmp(argv[5],"ppm") || !strcmp(argv[5],"bmp")){
			return 1;
		}
	}
	return 0;

}