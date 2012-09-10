/*****************************************************************************

FileName: <yoffsets.h>

Description:
	This file contains the offset definitions for Y only format.
	This can be included in different files with proper macros defined
	to replace huge codes in different source files.

*****************************************************************************/


#ifdef Y_ONLY
#ifdef SRC
	unsigned char *ptrsrcy1, *ptrsrcy2;
	unsigned char *ptrsrcy3, *ptrsrcy4;
	int srcystride;

	ptrsrcy1 = bufsrc;
	ptrsrcy2 = bufsrc + width;
	ptrsrcy3 = bufsrc + width*2;
	ptrsrcy4 = bufsrc + width*3;
	
	srcystride  = (width)*3;
#endif
#endif



