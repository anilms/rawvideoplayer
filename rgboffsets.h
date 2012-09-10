/*****************************************************************************

FileName: <rgboffsets.h>

Description:
	This file contains the offset definitions for different rgb formats.
	This will can be included in different files with proper macros defined
	to replace huge codes in different source files.

*****************************************************************************/


#ifdef RGB_PLANAR
#ifdef SRC
	unsigned char *ptrsrcr1, *ptrsrcr2;
	unsigned char *ptrsrcr3, *ptrsrcr4;
	unsigned char *ptrsrcg1, *ptrsrcg2;
	unsigned char *ptrsrcg3, *ptrsrcg4;
	unsigned char *ptrsrcb1, *ptrsrcb2;
	unsigned char *ptrsrcb3, *ptrsrcb4;
	int srcrgbstride;

	ptrsrcr1  = bufsrc;
	ptrsrcr2  = bufsrc + width;
	ptrsrcr3  = bufsrc + width*2;
	ptrsrcr4  = bufsrc + width*3;

	ptrsrcg1 = bufsrc + width*height;
	ptrsrcg2 = bufsrc + width*height + width;
	ptrsrcg3 = bufsrc + width*height + width*2;
	ptrsrcg4 = bufsrc + width*height + width*3;
	
	ptrsrcb1 = bufsrc + ((width*height)<<1);
	ptrsrcb2 = bufsrc + ((width*height)<<1) + width;
	ptrsrcb3 = bufsrc + ((width*height)<<1) + width*2;
	ptrsrcb4 = bufsrc + ((width*height)<<1) + width*3;

	srcrgbstride  = width*3;
#endif
#endif


#ifdef BGR_PLANAR
#ifdef SRC
	unsigned char *ptrsrcr1, *ptrsrcr2;
	unsigned char *ptrsrcr3, *ptrsrcr4;
	unsigned char *ptrsrcg1, *ptrsrcg2;
	unsigned char *ptrsrcg3, *ptrsrcg4;
	unsigned char *ptrsrcb1, *ptrsrcb2;
	unsigned char *ptrsrcb3, *ptrsrcb4;
	int srcrgbstride;

	ptrsrcb1  = bufsrc;
	ptrsrcb2  = bufsrc + width;
	ptrsrcb3  = bufsrc + width*2;
	ptrsrcb4  = bufsrc + width*3;

	ptrsrcg1 = bufsrc + width*height;
	ptrsrcg2 = bufsrc + width*height + width;
	ptrsrcg3 = bufsrc + width*height + width*2;
	ptrsrcg4 = bufsrc + width*height + width*3;
	
	ptrsrcr1 = bufsrc + ((width*height)<<1);
	ptrsrcr2 = bufsrc + ((width*height)<<1) + width;
	ptrsrcr3 = bufsrc + ((width*height)<<1) + width*2;
	ptrsrcr4 = bufsrc + ((width*height)<<1) + width*3;

	srcrgbstride  = width*3;
#endif
#endif


/* Packed Formats */
#ifdef RGB_PACKED
#ifdef SRC
	unsigned char *ptrsrcr1, *ptrsrcr2;
	unsigned char *ptrsrcr3, *ptrsrcr4;
	unsigned char *ptrsrcg1, *ptrsrcg2;
	unsigned char *ptrsrcg3, *ptrsrcg4;
	unsigned char *ptrsrcb1, *ptrsrcb2;
	unsigned char *ptrsrcb3, *ptrsrcb4;
	int srcrgbstride;

	ptrsrcr1  = bufsrc;
	ptrsrcr2  = bufsrc + width*3;
	ptrsrcr3  = bufsrc + width*3*2;
	ptrsrcr4  = bufsrc + width*3*3;

	ptrsrcg1 = bufsrc + 1;
	ptrsrcg2 = bufsrc + width*3 + 1;
	ptrsrcg3 = bufsrc + width*3*2 + 1;
	ptrsrcg4 = bufsrc + width*3*3 + 1;
	
	ptrsrcb1 = bufsrc + 2;
	ptrsrcb2 = bufsrc + width*3 + 2;
	ptrsrcb3 = bufsrc + width*3*2 + 2;
	ptrsrcb4 = bufsrc + width*3*3 + 2;

	srcrgbstride  = width*3*3;
#endif
#endif


#ifdef BGR_PACKED
#ifdef SRC
	unsigned char *ptrsrcr1, *ptrsrcr2;
	unsigned char *ptrsrcr3, *ptrsrcr4;
	unsigned char *ptrsrcg1, *ptrsrcg2;
	unsigned char *ptrsrcg3, *ptrsrcg4;
	unsigned char *ptrsrcb1, *ptrsrcb2;
	unsigned char *ptrsrcb3, *ptrsrcb4;
	int srcrgbstride;

	ptrsrcr1  = bufsrc + 2;
	ptrsrcr2  = bufsrc + width*3 + 2;
	ptrsrcr3  = bufsrc + width*3*2 + 2;
	ptrsrcr4  = bufsrc + width*3*3 + 2;

	ptrsrcg1 = bufsrc + 1;
	ptrsrcg2 = bufsrc + width*3 + 1;
	ptrsrcg3 = bufsrc + width*3*2 + 1;
	ptrsrcg4 = bufsrc + width*3*3 + 1;
	
	ptrsrcb1 = bufsrc;
	ptrsrcb2 = bufsrc + width*3;
	ptrsrcb3 = bufsrc + width*3*2;
	ptrsrcb4 = bufsrc + width*3*3;

	srcrgbstride  = width*3*3;
#endif
#endif





