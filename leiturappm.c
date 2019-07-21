#include "leiturappm.h"
#include "leituramsg.h"
void readPXX(char * argv[]){
	FILE * arquivo;
	arquivo = ((!strcmp(argv[2],"-o") ||(!strcmp(argv[2],"-i"))) && veracidade(argv) ? fopen(argv[6],"r") : fopen(argv[5],"r"));
	if(arquivo!=NULL){
		char linha[500];
		char tipo[10];
		PXX aux;
		fgets(linha,500,arquivo);
		sscanf(linha,"%s",tipo);
		fgets(linha,500,arquivo);
		while(linha[0] == '#'){
			fgets(linha,500,arquivo);
		}
		sscanf(linha,"%d %d",&aux.linhas,&aux.colunas);
		if(strcmp(tipo,"P6") == 0){
			PPM ppm = readP6(aux,arquivo);
			if(!strcmp(argv[1],"-e")){
				char * menssagem = getMessage(argv[3]);
				encript(ppm.bits,menssagem,ppm.super.colunas,ppm.super.linhas);
				free(menssagem);
				fclose(arquivo);
				savePPM(ppm,argv[6]);
			}else if(!strcmp(argv[1],"-d")){
				if(!strcmp(argv[2],"-s")){
					decript(ppm.bits,stdout,ppm.super.colunas,ppm.super.linhas);
				}else if(!strcmp(argv[2],"-o")){
					FILE * texto = fopen(argv[3],"w");
					decript(ppm.bits,texto,ppm.super.colunas,ppm.super.linhas);
					fclose(texto);
				}else{
					printf("Instrução incorreta\n");
					return;
				}
			}
		}else{
			printf("TIPO ERRADO!\n");
			return;
		}
		return ;
	}else{
		printf("ARQUIVO INEXISTENTE!\n");
		return;
	}
}
PPM readP6(PXX aux,FILE * arquivo){
	int max;
	aux.px = P6;
	PPM ppm;
	ppm.super = aux;
	fscanf(arquivo,"%d",&max);
	ppm.maxVal = (unsigned char) max;
	ppm.bits = (RGB **) malloc(sizeof(RGB *)*ppm.super.linhas);
	for(int i = 0;i<ppm.super.linhas;++i){
		ppm.bits[i] = (RGB *) malloc(sizeof(RGB)*ppm.super.colunas);
	}
	fgetc(arquivo);
	for(int i = 0;i<ppm.super.linhas;++i){
		for(int j = 0;j<ppm.super.colunas;++j){
			ppm.bits[i][j].r = fgetc(arquivo);
			ppm.bits[i][j].g = fgetc(arquivo);
			ppm.bits[i][j].b = fgetc(arquivo);
		}
	}
	return ppm;
}
void savePPM(PPM ppm,char * nome){
	FILE * arquivo = fopen(nome,"w+");
	if(ppm.super.px == P6){
		fprintf(arquivo,"P6\n");
		fprintf(arquivo,"%d %d\n",ppm.super.linhas,ppm.super.colunas);
		fprintf(arquivo,"%hhu\n",ppm.maxVal);
		for(int i = 0;i<ppm.super.linhas;++i){
			for(int j = 0;j<ppm.super.colunas;++j){
				fprintf(arquivo,"%c",ppm.bits[i][j].r);
				fprintf(arquivo,"%c",ppm.bits[i][j].g);
				fprintf(arquivo,"%c",ppm.bits[i][j].b);
			}
		}
	}
	fclose(arquivo);
	return;
}
