#ifndef BMP_H
	#define BMP_H
	#include "pxx.h"
	typedef  struct {
		unsigned short bfType;
		unsigned int bfSize;
		short bfReserved1;
		short bfReserved2;
		unsigned int bfOffBits;
	}BITMAPFILEHEADER;
	typedef struct {
		unsigned int biSize;
		int biWidth;
		int biHeight;
		unsigned short biPlanes;
		unsigned short biBitCount;
		unsigned int biCompression;
		unsigned int biSizeImage;
		unsigned int biXPelsPerMeter;
		unsigned int biYPelsPerMeter;
		unsigned int biClrUsed;
		unsigned int biClrImportant;
	}BITMAPINFOHEADER;
	typedef struct{
		BITMAPFILEHEADER fheader;
		BITMAPINFOHEADER iheader;
		int altura;
		int largura;
		RGB ** rgb;
	}BMP;
#endif