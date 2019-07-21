#ifndef PXX_H
	#define PXX_H
	#define lastbitmask 254
	typedef enum{
		P1 = 1,
		P2 = 2,
		P3 = 3,
		P4 = 4,
		P5 = 5,
		P6 = 6
	}PX;
	typedef struct{
		int linhas,colunas;
		PX px;
	}PXX;
	typedef struct {
		unsigned char val;
	}GREY;
	typedef struct {
		unsigned char r;
		unsigned char g;
		unsigned char b;
	}RGB;
	typedef struct{
		PXX super;
		GREY ** bits;
	}PBM;
	typedef struct{
		PXX super;
		GREY ** bits;
		unsigned char maxVal;
	}PGM;
	typedef struct{
		PXX super;
		RGB ** bits;
		unsigned char maxVal;
	}PPM;
#endif