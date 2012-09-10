/*****************************************************************************

FileName: <yuv444packedtorgba.cpp>

Description:
	Modules for Converting YUV444 input to RGBA
	Contains functions for:
		yuv444ProgPackedToRGBA
		yuv444IntPackedToRGBA
		yvu444ProgPackedToRGBA
		yvu444IntPackedToRGBA
		uyv444ProgPackedToRGBA
		uyv444IntPackedToRGBA

*****************************************************************************/


#include "yuvconverter.h"
#include "videoout.h"


/*****************************************************************************

Routine: yuv444ProgPackedToRGBA

        returns        	: void
  Description			: Read yuv444ProgPacked Input frame 
  							and convert it into RGBA frame
*****************************************************************************/
void yuv444ProgPackedToRGBA(
				unsigned char *bufsrc, unsigned char *bufdest,
				int width, int height
				)
{

	bufdest += (texwidth)*(texheight-4)*4; /* Inverted buffer */


	#define YUV_444_PACKED_PROG
	#define SRC
	#include "yuv444offsets.h"
	#undef SRC
	#undef YUV_444_PACKED_PROG

	#define RGBA
	#define DEST
	#include "rgbaoffsets.h"
	#undef DEST
	#undef RGBA

	int i, j;

	int crv, cgu, cgv, cbu;
	int y, u, v;

	
	for(j=0; j<(height/4); j++)
	{
		for(i=0; i<(width); i++)
		{
			/* First Line */	
			u = (*ptrsrccb1);
			v = (*ptrsrccr1);
			crv = crv_tab[v];
			cgu = cgu_tab[u];
			cgv = cgv_tab[v];
			cbu = cbu_tab[u];
			y = tab_76309[(*ptrsrcy1)];	
			(*ptrdestr1) = clp[384+((y + crv)>>16)];  
			(*ptrdestg1) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb1) = clp[384+((y + cbu)>>16)];
			(*ptrdesta1) = 0xFF;

			ptrsrcy1 += 3;
			ptrsrccb1 += 3;
			ptrsrccr1 += 3;

			ptrdestr1 += 4;
			ptrdestg1 += 4;
			ptrdestb1 += 4;
			ptrdesta1 += 4;

			/* Second Line */	
			u = (*ptrsrccb2);
			v = (*ptrsrccr2);
			crv = crv_tab[v];
			cgu = cgu_tab[u];
			cgv = cgv_tab[v];
			cbu = cbu_tab[u];
			y = tab_76309[(*ptrsrcy2)];	
			(*ptrdestr2) = clp[384+((y + crv)>>16)];  
			(*ptrdestg2) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb2) = clp[384+((y + cbu)>>16)];
			(*ptrdesta2) = 0xFF;

			ptrsrcy2 += 3;
			ptrsrccb2 += 3;
			ptrsrccr2 += 3;

			ptrdestr2 += 4;
			ptrdestg2 += 4;
			ptrdestb2 += 4;
			ptrdesta2 += 4;

			/* Third Line */
			u = (*ptrsrccb3);
			v = (*ptrsrccr3);
			crv = crv_tab[v];
			cgu = cgu_tab[u];
			cgv = cgv_tab[v];
			cbu = cbu_tab[u];
			y = tab_76309[(*ptrsrcy3)];	
			(*ptrdestr3) = clp[384+((y + crv)>>16)];  
			(*ptrdestg3) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb3) = clp[384+((y + cbu)>>16)];
			(*ptrdesta3) = 0xFF;

			ptrsrcy3 += 3;
			ptrsrccb3 += 3;
			ptrsrccr3 += 3;

			ptrdestr3 += 4;
			ptrdestg3 += 4;
			ptrdestb3 += 4;
			ptrdesta3 += 4;

			/* Fourth Line */
			u = (*ptrsrccb4);
			v = (*ptrsrccr4);
			crv = crv_tab[v];
			cgu = cgu_tab[u];
			cgv = cgv_tab[v];
			cbu = cbu_tab[u];
			y = tab_76309[(*ptrsrcy4)];	
			(*ptrdestr4) = clp[384+((y + crv)>>16)];  
			(*ptrdestg4) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb4) = clp[384+((y + cbu)>>16)];
			(*ptrdesta4) = 0xFF;

			ptrsrcy4 += 3;
			ptrsrccb4 += 3;
			ptrsrccr4 += 3;

			ptrdestr4 += 4;
			ptrdestg4 += 4;
			ptrdestb4 += 4;
			ptrdesta4 += 4;

		}

		/* Update src pointers */
		ptrsrcy1  += srcystride;
		ptrsrcy2  += srcystride;
		ptrsrcy3  += srcystride;
		ptrsrcy4  += srcystride;
		
		ptrsrccb1 += srcccstride;
		ptrsrccb2 += srcccstride;
		ptrsrccb3 += srcccstride;
		ptrsrccb4 += srcccstride;
	
		ptrsrccr1 += srcccstride;
		ptrsrccr2 += srcccstride;
		ptrsrccr3 += srcccstride;
		ptrsrccr4 += srcccstride;

		/* Update dest pointers */
		ptrdestr1 += destrgbastride;
		ptrdestr2 += destrgbastride;
		ptrdestr3 += destrgbastride;
		ptrdestr4 += destrgbastride;

		ptrdestg1 += destrgbastride;
		ptrdestg2 += destrgbastride;
		ptrdestg3 += destrgbastride;
		ptrdestg4 += destrgbastride;

		ptrdestb1 += destrgbastride;
		ptrdestb2 += destrgbastride;
		ptrdestb3 += destrgbastride;
		ptrdestb4 += destrgbastride;

		ptrdesta1 += destrgbastride;
		ptrdesta2 += destrgbastride;
		ptrdesta3 += destrgbastride;
		ptrdesta4 += destrgbastride;

	}
}



/*****************************************************************************

Routine: yuv444IntPackedToRGBA

        returns        	: void
  Description			: Read yuv444IntPacked Input frame 
  							and convert it into RGBA frame
*****************************************************************************/
void yuv444IntPackedToRGBA(
				unsigned char *bufsrc, unsigned char *bufdest,
				int width, int height
				)
{

	bufdest += (texwidth)*(texheight-4)*4; /* Inverted buffer */


	#define YUV_444_PACKED_INT
	#define SRC
	#include "yuv444offsets.h"
	#undef SRC
	#undef YUV_444_PACKED_INT

	#define RGBA
	#define DEST
	#include "rgbaoffsets.h"
	#undef DEST
	#undef RGBA

	int i, j;

	int crv, cgu, cgv, cbu;
	int y, u, v;

	
	for(j=0; j<(height/4); j++)
	{
		for(i=0; i<(width); i++)
		{
			/* First Line */	
			u = (*ptrsrccb1);
			v = (*ptrsrccr1);
			crv = crv_tab[v];
			cgu = cgu_tab[u];
			cgv = cgv_tab[v];
			cbu = cbu_tab[u];
			y = tab_76309[(*ptrsrcy1)];	
			(*ptrdestr1) = clp[384+((y + crv)>>16)];  
			(*ptrdestg1) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb1) = clp[384+((y + cbu)>>16)];
			(*ptrdesta1) = 0xFF;

			ptrsrcy1 += 3;
			ptrsrccb1 += 3;
			ptrsrccr1 += 3;

			ptrdestr1 += 4;
			ptrdestg1 += 4;
			ptrdestb1 += 4;
			ptrdesta1 += 4;

			/* Second Line */	
			u = (*ptrsrccb3);
			v = (*ptrsrccr3);
			crv = crv_tab[v];
			cgu = cgu_tab[u];
			cgv = cgv_tab[v];
			cbu = cbu_tab[u];
			y = tab_76309[(*ptrsrcy3)];	
			(*ptrdestr2) = clp[384+((y + crv)>>16)];  
			(*ptrdestg2) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb2) = clp[384+((y + cbu)>>16)];
			(*ptrdesta2) = 0xFF;

			ptrsrcy3 += 3;
			ptrsrccb3 += 3;
			ptrsrccr3 += 3;

			ptrdestr2 += 4;
			ptrdestg2 += 4;
			ptrdestb2 += 4;
			ptrdesta2 += 4;

			/* Third Line */
			u = (*ptrsrccb2);
			v = (*ptrsrccr2);
			crv = crv_tab[v];
			cgu = cgu_tab[u];
			cgv = cgv_tab[v];
			cbu = cbu_tab[u];
			y = tab_76309[(*ptrsrcy2)];	
			(*ptrdestr3) = clp[384+((y + crv)>>16)];  
			(*ptrdestg3) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb3) = clp[384+((y + cbu)>>16)];
			(*ptrdesta3) = 0xFF;

			ptrsrcy2 += 3;
			ptrsrccb2 += 3;
			ptrsrccr2 += 3;

			ptrdestr3 += 4;
			ptrdestg3 += 4;
			ptrdestb3 += 4;
			ptrdesta3 += 4;

			/* Fourth Line */
			u = (*ptrsrccb4);
			v = (*ptrsrccr4);
			crv = crv_tab[v];
			cgu = cgu_tab[u];
			cgv = cgv_tab[v];
			cbu = cbu_tab[u];
			y = tab_76309[(*ptrsrcy4)];	
			(*ptrdestr4) = clp[384+((y + crv)>>16)];  
			(*ptrdestg4) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb4) = clp[384+((y + cbu)>>16)];
			(*ptrdesta4) = 0xFF;

			ptrsrcy4 += 3;
			ptrsrccb4 += 3;
			ptrsrccr4 += 3;

			ptrdestr4 += 4;
			ptrdestg4 += 4;
			ptrdestb4 += 4;
			ptrdesta4 += 4;

		}

		/* Update src pointers */
		ptrsrcy1  += srcystride;
		ptrsrcy2  += srcystride;
		ptrsrcy3  += srcystride;
		ptrsrcy4  += srcystride;
		
		ptrsrccb1 += srcccstride;
		ptrsrccb2 += srcccstride;
		ptrsrccb3 += srcccstride;
		ptrsrccb4 += srcccstride;
	
		ptrsrccr1 += srcccstride;
		ptrsrccr2 += srcccstride;
		ptrsrccr3 += srcccstride;
		ptrsrccr4 += srcccstride;

		/* Update dest pointers */
		ptrdestr1 += destrgbastride;
		ptrdestr2 += destrgbastride;
		ptrdestr3 += destrgbastride;
		ptrdestr4 += destrgbastride;

		ptrdestg1 += destrgbastride;
		ptrdestg2 += destrgbastride;
		ptrdestg3 += destrgbastride;
		ptrdestg4 += destrgbastride;

		ptrdestb1 += destrgbastride;
		ptrdestb2 += destrgbastride;
		ptrdestb3 += destrgbastride;
		ptrdestb4 += destrgbastride;

		ptrdesta1 += destrgbastride;
		ptrdesta2 += destrgbastride;
		ptrdesta3 += destrgbastride;
		ptrdesta4 += destrgbastride;

	}
}



/*****************************************************************************

Routine: yvu444ProgPackedToRGBA

        returns        	: void
  Description			: Read yvu444ProgPacked Input frame 
  							and convert it into RGBA frame
*****************************************************************************/
void yvu444ProgPackedToRGBA(
				unsigned char *bufsrc, unsigned char *bufdest,
				int width, int height
				)
{

	bufdest += (texwidth)*(texheight-4)*4; /* Inverted buffer */


	#define YVU_444_PACKED_PROG
	#define SRC
	#include "yuv444offsets.h"
	#undef SRC
	#undef YVU_444_PACKED_PROG

	#define RGBA
	#define DEST
	#include "rgbaoffsets.h"
	#undef DEST
	#undef RGBA

	int i, j;

	int crv, cgu, cgv, cbu;
	int y, u, v;

	
	for(j=0; j<(height/4); j++)
	{
		for(i=0; i<(width); i++)
		{
			/* First Line */	
			u = (*ptrsrccb1);
			v = (*ptrsrccr1);
			crv = crv_tab[v];
			cgu = cgu_tab[u];
			cgv = cgv_tab[v];
			cbu = cbu_tab[u];
			y = tab_76309[(*ptrsrcy1)];	
			(*ptrdestr1) = clp[384+((y + crv)>>16)];  
			(*ptrdestg1) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb1) = clp[384+((y + cbu)>>16)];
			(*ptrdesta1) = 0xFF;

			ptrsrcy1 += 3;
			ptrsrccb1 += 3;
			ptrsrccr1 += 3;

			ptrdestr1 += 4;
			ptrdestg1 += 4;
			ptrdestb1 += 4;
			ptrdesta1 += 4;

			/* Second Line */	
			u = (*ptrsrccb2);
			v = (*ptrsrccr2);
			crv = crv_tab[v];
			cgu = cgu_tab[u];
			cgv = cgv_tab[v];
			cbu = cbu_tab[u];
			y = tab_76309[(*ptrsrcy2)];	
			(*ptrdestr2) = clp[384+((y + crv)>>16)];  
			(*ptrdestg2) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb2) = clp[384+((y + cbu)>>16)];
			(*ptrdesta2) = 0xFF;

			ptrsrcy2 += 3;
			ptrsrccb2 += 3;
			ptrsrccr2 += 3;

			ptrdestr2 += 4;
			ptrdestg2 += 4;
			ptrdestb2 += 4;
			ptrdesta2 += 4;

			/* Third Line */
			u = (*ptrsrccb3);
			v = (*ptrsrccr3);
			crv = crv_tab[v];
			cgu = cgu_tab[u];
			cgv = cgv_tab[v];
			cbu = cbu_tab[u];
			y = tab_76309[(*ptrsrcy3)];	
			(*ptrdestr3) = clp[384+((y + crv)>>16)];  
			(*ptrdestg3) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb3) = clp[384+((y + cbu)>>16)];
			(*ptrdesta3) = 0xFF;

			ptrsrcy3 += 3;
			ptrsrccb3 += 3;
			ptrsrccr3 += 3;

			ptrdestr3 += 4;
			ptrdestg3 += 4;
			ptrdestb3 += 4;
			ptrdesta3 += 4;

			/* Fourth Line */
			u = (*ptrsrccb4);
			v = (*ptrsrccr4);
			crv = crv_tab[v];
			cgu = cgu_tab[u];
			cgv = cgv_tab[v];
			cbu = cbu_tab[u];
			y = tab_76309[(*ptrsrcy4)];	
			(*ptrdestr4) = clp[384+((y + crv)>>16)];  
			(*ptrdestg4) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb4) = clp[384+((y + cbu)>>16)];
			(*ptrdesta4) = 0xFF;

			ptrsrcy4 += 3;
			ptrsrccb4 += 3;
			ptrsrccr4 += 3;

			ptrdestr4 += 4;
			ptrdestg4 += 4;
			ptrdestb4 += 4;
			ptrdesta4 += 4;

		}

		/* Update src pointers */
		ptrsrcy1  += srcystride;
		ptrsrcy2  += srcystride;
		ptrsrcy3  += srcystride;
		ptrsrcy4  += srcystride;
		
		ptrsrccb1 += srcccstride;
		ptrsrccb2 += srcccstride;
		ptrsrccb3 += srcccstride;
		ptrsrccb4 += srcccstride;
	
		ptrsrccr1 += srcccstride;
		ptrsrccr2 += srcccstride;
		ptrsrccr3 += srcccstride;
		ptrsrccr4 += srcccstride;

		/* Update dest pointers */
		ptrdestr1 += destrgbastride;
		ptrdestr2 += destrgbastride;
		ptrdestr3 += destrgbastride;
		ptrdestr4 += destrgbastride;

		ptrdestg1 += destrgbastride;
		ptrdestg2 += destrgbastride;
		ptrdestg3 += destrgbastride;
		ptrdestg4 += destrgbastride;

		ptrdestb1 += destrgbastride;
		ptrdestb2 += destrgbastride;
		ptrdestb3 += destrgbastride;
		ptrdestb4 += destrgbastride;

		ptrdesta1 += destrgbastride;
		ptrdesta2 += destrgbastride;
		ptrdesta3 += destrgbastride;
		ptrdesta4 += destrgbastride;

	}
}



/*****************************************************************************

Routine: yvu444IntPackedToRGBA

        returns        	: void
  Description			: Read yvu444IntPacked Input frame 
  							and convert it into RGBA frame
*****************************************************************************/
void yvu444IntPackedToRGBA(
				unsigned char *bufsrc, unsigned char *bufdest,
				int width, int height
				)
{

	bufdest += (texwidth)*(texheight-4)*4; /* Inverted buffer */


	#define YVU_444_PACKED_INT
	#define SRC
	#include "yuv444offsets.h"
	#undef SRC
	#undef YVU_444_PACKED_INT

	#define RGBA
	#define DEST
	#include "rgbaoffsets.h"
	#undef DEST
	#undef RGBA

	int i, j;

	int crv, cgu, cgv, cbu;
	int y, u, v;

	
	for(j=0; j<(height/4); j++)
	{
		for(i=0; i<(width); i++)
		{
			/* First Line */	
			u = (*ptrsrccb1);
			v = (*ptrsrccr1);
			crv = crv_tab[v];
			cgu = cgu_tab[u];
			cgv = cgv_tab[v];
			cbu = cbu_tab[u];
			y = tab_76309[(*ptrsrcy1)];	
			(*ptrdestr1) = clp[384+((y + crv)>>16)];  
			(*ptrdestg1) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb1) = clp[384+((y + cbu)>>16)];
			(*ptrdesta1) = 0xFF;

			ptrsrcy1 += 3;
			ptrsrccb1 += 3;
			ptrsrccr1 += 3;

			ptrdestr1 += 4;
			ptrdestg1 += 4;
			ptrdestb1 += 4;
			ptrdesta1 += 4;

			/* Second Line */	
			u = (*ptrsrccb3);
			v = (*ptrsrccr3);
			crv = crv_tab[v];
			cgu = cgu_tab[u];
			cgv = cgv_tab[v];
			cbu = cbu_tab[u];
			y = tab_76309[(*ptrsrcy3)];	
			(*ptrdestr2) = clp[384+((y + crv)>>16)];  
			(*ptrdestg2) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb2) = clp[384+((y + cbu)>>16)];
			(*ptrdesta2) = 0xFF;

			ptrsrcy3 += 3;
			ptrsrccb3 += 3;
			ptrsrccr3 += 3;

			ptrdestr2 += 4;
			ptrdestg2 += 4;
			ptrdestb2 += 4;
			ptrdesta2 += 4;

			/* Third Line */
			u = (*ptrsrccb2);
			v = (*ptrsrccr2);
			crv = crv_tab[v];
			cgu = cgu_tab[u];
			cgv = cgv_tab[v];
			cbu = cbu_tab[u];
			y = tab_76309[(*ptrsrcy2)];	
			(*ptrdestr3) = clp[384+((y + crv)>>16)];  
			(*ptrdestg3) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb3) = clp[384+((y + cbu)>>16)];
			(*ptrdesta3) = 0xFF;

			ptrsrcy2 += 3;
			ptrsrccb2 += 3;
			ptrsrccr2 += 3;

			ptrdestr3 += 4;
			ptrdestg3 += 4;
			ptrdestb3 += 4;
			ptrdesta3 += 4;

			/* Fourth Line */
			u = (*ptrsrccb4);
			v = (*ptrsrccr4);
			crv = crv_tab[v];
			cgu = cgu_tab[u];
			cgv = cgv_tab[v];
			cbu = cbu_tab[u];
			y = tab_76309[(*ptrsrcy4)];	
			(*ptrdestr4) = clp[384+((y + crv)>>16)];  
			(*ptrdestg4) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb4) = clp[384+((y + cbu)>>16)];
			(*ptrdesta4) = 0xFF;

			ptrsrcy4 += 3;
			ptrsrccb4 += 3;
			ptrsrccr4 += 3;

			ptrdestr4 += 4;
			ptrdestg4 += 4;
			ptrdestb4 += 4;
			ptrdesta4 += 4;

		}

		/* Update src pointers */
		ptrsrcy1  += srcystride;
		ptrsrcy2  += srcystride;
		ptrsrcy3  += srcystride;
		ptrsrcy4  += srcystride;
		
		ptrsrccb1 += srcccstride;
		ptrsrccb2 += srcccstride;
		ptrsrccb3 += srcccstride;
		ptrsrccb4 += srcccstride;
	
		ptrsrccr1 += srcccstride;
		ptrsrccr2 += srcccstride;
		ptrsrccr3 += srcccstride;
		ptrsrccr4 += srcccstride;

		/* Update dest pointers */
		ptrdestr1 += destrgbastride;
		ptrdestr2 += destrgbastride;
		ptrdestr3 += destrgbastride;
		ptrdestr4 += destrgbastride;

		ptrdestg1 += destrgbastride;
		ptrdestg2 += destrgbastride;
		ptrdestg3 += destrgbastride;
		ptrdestg4 += destrgbastride;

		ptrdestb1 += destrgbastride;
		ptrdestb2 += destrgbastride;
		ptrdestb3 += destrgbastride;
		ptrdestb4 += destrgbastride;

		ptrdesta1 += destrgbastride;
		ptrdesta2 += destrgbastride;
		ptrdesta3 += destrgbastride;
		ptrdesta4 += destrgbastride;

	}
}




/*****************************************************************************

Routine: uyv444ProgPackedToRGBA

        returns        	: void
  Description			: Read uyv444ProgPacked Input frame 
  							and convert it into RGBA frame
*****************************************************************************/
void uyv444ProgPackedToRGBA(
				unsigned char *bufsrc, unsigned char *bufdest,
				int width, int height
				)
{

	bufdest += (texwidth)*(texheight-4)*4; /* Inverted buffer */


	#define UYV_444_PACKED_PROG
	#define SRC
	#include "yuv444offsets.h"
	#undef SRC
	#undef UYV_444_PACKED_PROG

	#define RGBA
	#define DEST
	#include "rgbaoffsets.h"
	#undef DEST
	#undef RGBA

	int i, j;

	int crv, cgu, cgv, cbu;
	int y, u, v;

	
	for(j=0; j<(height/4); j++)
	{
		for(i=0; i<(width); i++)
		{
			/* First Line */	
			u = (*ptrsrccb1);
			v = (*ptrsrccr1);
			crv = crv_tab[v];
			cgu = cgu_tab[u];
			cgv = cgv_tab[v];
			cbu = cbu_tab[u];
			y = tab_76309[(*ptrsrcy1)];	
			(*ptrdestr1) = clp[384+((y + crv)>>16)];  
			(*ptrdestg1) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb1) = clp[384+((y + cbu)>>16)];
			(*ptrdesta1) = 0xFF;

			ptrsrcy1 += 3;
			ptrsrccb1 += 3;
			ptrsrccr1 += 3;

			ptrdestr1 += 4;
			ptrdestg1 += 4;
			ptrdestb1 += 4;
			ptrdesta1 += 4;

			/* Second Line */	
			u = (*ptrsrccb2);
			v = (*ptrsrccr2);
			crv = crv_tab[v];
			cgu = cgu_tab[u];
			cgv = cgv_tab[v];
			cbu = cbu_tab[u];
			y = tab_76309[(*ptrsrcy2)];	
			(*ptrdestr2) = clp[384+((y + crv)>>16)];  
			(*ptrdestg2) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb2) = clp[384+((y + cbu)>>16)];
			(*ptrdesta2) = 0xFF;

			ptrsrcy2 += 3;
			ptrsrccb2 += 3;
			ptrsrccr2 += 3;

			ptrdestr2 += 4;
			ptrdestg2 += 4;
			ptrdestb2 += 4;
			ptrdesta2 += 4;

			/* Third Line */
			u = (*ptrsrccb3);
			v = (*ptrsrccr3);
			crv = crv_tab[v];
			cgu = cgu_tab[u];
			cgv = cgv_tab[v];
			cbu = cbu_tab[u];
			y = tab_76309[(*ptrsrcy3)];	
			(*ptrdestr3) = clp[384+((y + crv)>>16)];  
			(*ptrdestg3) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb3) = clp[384+((y + cbu)>>16)];
			(*ptrdesta3) = 0xFF;

			ptrsrcy3 += 3;
			ptrsrccb3 += 3;
			ptrsrccr3 += 3;

			ptrdestr3 += 4;
			ptrdestg3 += 4;
			ptrdestb3 += 4;
			ptrdesta3 += 4;

			/* Fourth Line */
			u = (*ptrsrccb4);
			v = (*ptrsrccr4);
			crv = crv_tab[v];
			cgu = cgu_tab[u];
			cgv = cgv_tab[v];
			cbu = cbu_tab[u];
			y = tab_76309[(*ptrsrcy4)];	
			(*ptrdestr4) = clp[384+((y + crv)>>16)];  
			(*ptrdestg4) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb4) = clp[384+((y + cbu)>>16)];
			(*ptrdesta4) = 0xFF;

			ptrsrcy4 += 3;
			ptrsrccb4 += 3;
			ptrsrccr4 += 3;

			ptrdestr4 += 4;
			ptrdestg4 += 4;
			ptrdestb4 += 4;
			ptrdesta4 += 4;

		}

		/* Update src pointers */
		ptrsrcy1  += srcystride;
		ptrsrcy2  += srcystride;
		ptrsrcy3  += srcystride;
		ptrsrcy4  += srcystride;
		
		ptrsrccb1 += srcccstride;
		ptrsrccb2 += srcccstride;
		ptrsrccb3 += srcccstride;
		ptrsrccb4 += srcccstride;
	
		ptrsrccr1 += srcccstride;
		ptrsrccr2 += srcccstride;
		ptrsrccr3 += srcccstride;
		ptrsrccr4 += srcccstride;

		/* Update dest pointers */
		ptrdestr1 += destrgbastride;
		ptrdestr2 += destrgbastride;
		ptrdestr3 += destrgbastride;
		ptrdestr4 += destrgbastride;

		ptrdestg1 += destrgbastride;
		ptrdestg2 += destrgbastride;
		ptrdestg3 += destrgbastride;
		ptrdestg4 += destrgbastride;

		ptrdestb1 += destrgbastride;
		ptrdestb2 += destrgbastride;
		ptrdestb3 += destrgbastride;
		ptrdestb4 += destrgbastride;

		ptrdesta1 += destrgbastride;
		ptrdesta2 += destrgbastride;
		ptrdesta3 += destrgbastride;
		ptrdesta4 += destrgbastride;

	}
}



/*****************************************************************************

Routine: uyv444IntPackedToRGBA

        returns        	: void
  Description			: Read uyv444IntPacked Input frame 
  							and convert it into RGBA frame
*****************************************************************************/
void uyv444IntPackedToRGBA(
				unsigned char *bufsrc, unsigned char *bufdest,
				int width, int height
				)
{

	bufdest += (texwidth)*(texheight-4)*4; /* Inverted buffer */


	#define UYV_444_PACKED_INT
	#define SRC
	#include "yuv444offsets.h"
	#undef SRC
	#undef UYV_444_PACKED_INT

	#define RGBA
	#define DEST
	#include "rgbaoffsets.h"
	#undef DEST
	#undef RGBA

	int i, j;

	int crv, cgu, cgv, cbu;
	int y, u, v;

	
	for(j=0; j<(height/4); j++)
	{
		for(i=0; i<(width); i++)
		{
			/* First Line */	
			u = (*ptrsrccb1);
			v = (*ptrsrccr1);
			crv = crv_tab[v];
			cgu = cgu_tab[u];
			cgv = cgv_tab[v];
			cbu = cbu_tab[u];
			y = tab_76309[(*ptrsrcy1)];	
			(*ptrdestr1) = clp[384+((y + crv)>>16)];  
			(*ptrdestg1) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb1) = clp[384+((y + cbu)>>16)];
			(*ptrdesta1) = 0xFF;

			ptrsrcy1 += 3;
			ptrsrccb1 += 3;
			ptrsrccr1 += 3;

			ptrdestr1 += 4;
			ptrdestg1 += 4;
			ptrdestb1 += 4;
			ptrdesta1 += 4;

			/* Second Line */	
			u = (*ptrsrccb3);
			v = (*ptrsrccr3);
			crv = crv_tab[v];
			cgu = cgu_tab[u];
			cgv = cgv_tab[v];
			cbu = cbu_tab[u];
			y = tab_76309[(*ptrsrcy3)];	
			(*ptrdestr2) = clp[384+((y + crv)>>16)];  
			(*ptrdestg2) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb2) = clp[384+((y + cbu)>>16)];
			(*ptrdesta2) = 0xFF;

			ptrsrcy3 += 3;
			ptrsrccb3 += 3;
			ptrsrccr3 += 3;

			ptrdestr2 += 4;
			ptrdestg2 += 4;
			ptrdestb2 += 4;
			ptrdesta2 += 4;

			/* Third Line */
			u = (*ptrsrccb2);
			v = (*ptrsrccr2);
			crv = crv_tab[v];
			cgu = cgu_tab[u];
			cgv = cgv_tab[v];
			cbu = cbu_tab[u];
			y = tab_76309[(*ptrsrcy2)];	
			(*ptrdestr3) = clp[384+((y + crv)>>16)];  
			(*ptrdestg3) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb3) = clp[384+((y + cbu)>>16)];
			(*ptrdesta3) = 0xFF;

			ptrsrcy2 += 3;
			ptrsrccb2 += 3;
			ptrsrccr2 += 3;

			ptrdestr3 += 4;
			ptrdestg3 += 4;
			ptrdestb3 += 4;
			ptrdesta3 += 4;

			/* Fourth Line */
			u = (*ptrsrccb4);
			v = (*ptrsrccr4);
			crv = crv_tab[v];
			cgu = cgu_tab[u];
			cgv = cgv_tab[v];
			cbu = cbu_tab[u];
			y = tab_76309[(*ptrsrcy4)];	
			(*ptrdestr4) = clp[384+((y + crv)>>16)];  
			(*ptrdestg4) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb4) = clp[384+((y + cbu)>>16)];
			(*ptrdesta4) = 0xFF;

			ptrsrcy4 += 3;
			ptrsrccb4 += 3;
			ptrsrccr4 += 3;

			ptrdestr4 += 4;
			ptrdestg4 += 4;
			ptrdestb4 += 4;
			ptrdesta4 += 4;

		}

		/* Update src pointers */
		ptrsrcy1  += srcystride;
		ptrsrcy2  += srcystride;
		ptrsrcy3  += srcystride;
		ptrsrcy4  += srcystride;
		
		ptrsrccb1 += srcccstride;
		ptrsrccb2 += srcccstride;
		ptrsrccb3 += srcccstride;
		ptrsrccb4 += srcccstride;
	
		ptrsrccr1 += srcccstride;
		ptrsrccr2 += srcccstride;
		ptrsrccr3 += srcccstride;
		ptrsrccr4 += srcccstride;

		/* Update dest pointers */
		ptrdestr1 += destrgbastride;
		ptrdestr2 += destrgbastride;
		ptrdestr3 += destrgbastride;
		ptrdestr4 += destrgbastride;

		ptrdestg1 += destrgbastride;
		ptrdestg2 += destrgbastride;
		ptrdestg3 += destrgbastride;
		ptrdestg4 += destrgbastride;

		ptrdestb1 += destrgbastride;
		ptrdestb2 += destrgbastride;
		ptrdestb3 += destrgbastride;
		ptrdestb4 += destrgbastride;

		ptrdesta1 += destrgbastride;
		ptrdesta2 += destrgbastride;
		ptrdesta3 += destrgbastride;
		ptrdesta4 += destrgbastride;

	}
}



