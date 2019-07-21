#include "leiturabmp.h"
void readDIB(char * argv[]){
	FILE * arquivo;
	BMP bmp;
	arquivo = ((!strcmp(argv[2],"-o") ||(!strcmp(argv[2],"-i"))) && veracidade(argv) ? fopen(argv[6],"r") : fopen(argv[5],"r"));
	if(arquivo!=NULL){
		bmp = readBMP(arquivo);
		if(!strcmp(argv[1],"-e")){
			char * menssagem = getMessage(argv[3]);
			encript(bmp.rgb,menssagem,bmp.largura,bmp.altura);
			free(menssagem);
			fclose(arquivo);
			saveBMP(bmp,argv[6]);
		}else if(!strcmp(argv[1],"-d")){
			if(!strcmp(argv[2],"-s")){
				decript(bmp.rgb,stdout,bmp.largura,bmp.altura);
			}else if(!strcmp(argv[2],"-o")){
				FILE * texto = fopen(argv[3],"w");
				decript(bmp.rgb,texto,bmp.largura,bmp.altura);
				fclose(texto);
			}else{
				printf("Instrução incorreta\n");
				return;
			}
		}
		for(int i = 0;i<bmp.altura;++i){
			free(bmp.rgb[i]);
		}
		free(bmp.rgb);
	}else{
		printf("Arquivo inexistente!\n");
	}
}
void saveBMP(BMP bmp,char * arquivo){
	FILE * ptr = fopen(arquivo,"w");
	fwrite(&bmp.fheader,sizeof(BITMAPFILEHEADER),1,ptr);
	fwrite(&bmp.iheader,sizeof(BITMAPINFOHEADER),1,ptr);
	bmp.altura = (bmp.altura<0 ? -1 : 1)*bmp.altura;
	for(int i = 0;i<bmp.altura;++i){
		fwrite(bmp.rgb[i],sizeof(RGB),bmp.largura,ptr);
	}
	fclose(ptr);
}
int contrarioInt(FILE * arquivo){
	unsigned char val[4];
	fread(val,1,4,arquivo);
	return val[3]<<24 | val[2]<<16 | val[1]<<8 | val[0];
}
short contrarioShort(FILE * arquivo){
	unsigned char val[2];
	fread(val,1,2,arquivo);
	return val[1]<<8 | val[0];
}
BMP readBMP(FILE * arquivo){
	BMP bmp;
	fread(&bmp.fheader,sizeof(BITMAPFILEHEADER),1,arquivo);
	if(bmp.fheader.bfType == 19778){
		fread(&bmp.iheader,sizeof(BITMAPINFOHEADER),1,arquivo);
		fseek(arquivo,18,SEEK_SET);
		bmp.largura = contrarioInt(arquivo);
		bmp.altura = contrarioInt(arquivo);
		bmp.altura = (bmp.altura<0 ? -1 : 1)*bmp.altura;
		fseek(arquivo,56,SEEK_SET);
		bmp.rgb = (RGB **) malloc(bmp.altura*sizeof(RGB*));
		for(int i = 0;i<bmp.altura;++i){
			bmp.rgb[i] = (RGB *) malloc(bmp.largura*sizeof(RGB));
		}
		for(int i = 0;i<bmp.altura;++i){
			fread(bmp.rgb[i],sizeof(RGB),bmp.largura,arquivo);
		}
	}else{
			printf("Formato incorreto!\n");
	}	
	return bmp;
}
