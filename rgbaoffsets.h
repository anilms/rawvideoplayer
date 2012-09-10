/*****************************************************************************

FileName: <rgbaoffsets.h>

Description:
	This file contains the offset definitions for rgba format.
	This can be included in different files with proper macros defined
	to replace huge codes in different source files.

*****************************************************************************/


#ifdef RGBA
#ifdef DEST
	unsigned char *ptrdestr1, *ptrdestr2;
	unsigned char *ptrdestr3, *ptrdestr4;
	unsigned char *ptrdestg1, *ptrdestg2;
	unsigned char *ptrdestg3, *ptrdestg4;
	unsigned char *ptrdestb1, *ptrdestb2;
	unsigned char *ptrdestb3, *ptrdestb4;
	unsigned char *ptrdesta1, *ptrdesta2;
	unsigned char *ptrdesta3, *ptrdesta4;
	int destrgbastride;

	ptrdestr4  = bufdest;
	ptrdestr3  = bufdest + texwidth*4;
	ptrdestr2  = bufdest + texwidth*4*2;
	ptrdestr1  = bufdest + texwidth*4*3;

	ptrdestg4 = bufdest + 1;
	ptrdestg3 = bufdest + texwidth*4 + 1;
	ptrdestg2 = bufdest + texwidth*4*2 + 1;
	ptrdestg1 = bufdest + texwidth*4*3 + 1;
	
	ptrdestb4 = bufdest + 2;
	ptrdestb3 = bufdest + texwidth*4 + 2;
	ptrdestb2 = bufdest + texwidth*4*2 + 2;
	ptrdestb1 = bufdest + texwidth*4*3 + 2;
	
	ptrdesta4 = bufdest + 3;
	ptrdesta3 = bufdest + texwidth*4 + 3;
	ptrdesta2 = bufdest + texwidth*4*2 + 3;
	ptrdesta1 = bufdest + texwidth*4*3 + 3;

	destrgbastride = -(texwidth*4*4+framewidth*4);
#endif
#endif

