/*****************************************************************************

FileName: <yuv444packedtorgba.cpp>

Description:
	Modules for Converting Raw input to RGBA
*****************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "yuvconverter.h"

extern int inframesize;


/* LUTs for YUV to RGB conversion */
long int crv_tab[256];
long int cbu_tab[256];
long int cgu_tab[256];
long int cgv_tab[256];
long int tab_76309[256];
unsigned char clp[1024];
void (*GetRGBAFrame)(unsigned char *bufsrc, unsigned char *bufdest, int width, int height);


void InitConverter(int width, int height, int mode)
{
	switch(mode)
	{
		/* Y only */
		case -1:	GetRGBAFrame = yToRGBA;
					inframesize = (width * height);
					break;

		/* YUV 420 to RGBA */
		case 0:		GetRGBAFrame = yuv420ProgPlanarToRGBA;
					inframesize = (width * height * 3)>>1;
					break;

		case 1:		GetRGBAFrame = yuv420IntPlanarToRGBA;
					inframesize = (width * height * 3)>>1;
					break;

		case 2:		GetRGBAFrame = yvu420ProgPlanarToRGBA;
					inframesize = (width * height * 3)>>1;
					break;

		case 3:		GetRGBAFrame = yvu420IntPlanarToRGBA;
					inframesize = (width * height * 3)>>1;
					break;

		case 4:		GetRGBAFrame = yuv420YCbCrPlanarToRGBA;
					inframesize = (width * height * 3)>>1;
					break;




		/* YUV 422 to RGBA */
		/* Planar */
		case 10:	GetRGBAFrame = yuv422ProgPlanarToRGBA;
					inframesize = width * height * 2;
					break;

		case 11:	GetRGBAFrame = yuv422IntPlanarToRGBA;
					inframesize = width * height * 2;
					break;

		case 12:	GetRGBAFrame = yvu422ProgPlanarToRGBA;
					inframesize = width * height * 2;
					break;

		case 13:	GetRGBAFrame = yvu422IntPlanarToRGBA;
					inframesize = width * height * 2;
					break;

		/* Packed */
		case 20:	GetRGBAFrame = uyvyProgPackedToRGBA;
					inframesize = width * height * 2;
					break;

		case 21:	GetRGBAFrame = uyvyIntPackedToRGBA;
					inframesize = width * height * 2;
					break;

		case 22:	GetRGBAFrame = yuyvProgPackedToRGBA;
					inframesize = width * height * 2;
					break;

		case 23:	GetRGBAFrame = yuyvIntPackedToRGBA;
					inframesize = width * height * 2;
					break;

		case 24:	GetRGBAFrame = yvyuProgPackedToRGBA;
					inframesize = width * height * 2;
					break;

		case 25:	GetRGBAFrame = yvyuIntPackedToRGBA;
					inframesize = width * height * 2;
					break;



		/* YUV 444 to RGBA */
		/* Planar */					
		case 30:	GetRGBAFrame = yuv444ProgPlanarToRGBA;
					inframesize = width * height * 3;
					break;

		case 31:	GetRGBAFrame = yuv444IntPlanarToRGBA;
					inframesize = width * height * 3;
					break;

		case 32:	GetRGBAFrame = yvu444ProgPlanarToRGBA;
					inframesize = width * height * 3;
					break;

		case 33:	GetRGBAFrame = yvu444IntPlanarToRGBA;
					inframesize = width * height * 3;
					break;

		case 34:	GetRGBAFrame = uyv444ProgPlanarToRGBA;
					inframesize = width * height * 3;
					break;

		case 35:	GetRGBAFrame = uyv444IntPlanarToRGBA;
					inframesize = width * height * 3;
					break;

		/* Packed */					
		case 40:	GetRGBAFrame = yuv444ProgPackedToRGBA;
					inframesize = width * height * 3;
					break;

		case 41:	GetRGBAFrame = yuv444IntPackedToRGBA;
					inframesize = width * height * 3;
					break;

		case 42:	GetRGBAFrame = yvu444ProgPackedToRGBA;
					inframesize = width * height * 3;
					break;

		case 43:	GetRGBAFrame = yvu444IntPackedToRGBA;
					inframesize = width * height * 3;
					break;


		case 44:	GetRGBAFrame = uyv444ProgPackedToRGBA;
					inframesize = width * height * 3;
					break;

		case 45:	GetRGBAFrame = uyv444IntPackedToRGBA;
					inframesize = width * height * 3;
					break;



		/* RGB to RGBA */
		case 50:	GetRGBAFrame = rgbProgPlanarToRGBA;
					inframesize = width * height * 3;
					break;

		case 51:	GetRGBAFrame = rgbProgPackedToRGBA;
					inframesize = width * height * 3;
					break;

		case 52:	GetRGBAFrame = bgrProgPlanarToRGBA;
					inframesize = width * height * 3;
					break;

		case 53:	GetRGBAFrame = bgrProgPackedToRGBA;
					inframesize = width * height * 3;
					break;



		default:
					printf("\n\nUnrecognised Input Format.");
					printf("\nExiting !!!");
					exit(3);
	}

	InitTab();

}



