/*****************************************************************************

FileName: <yuv420planartorgba.cpp>

Description:
	Modules for Converting YUV420 input to RGBA
	Contains functions for:
		yuv420ProgPlanarToRGBA
		yuv420IntPlanarToRGBA
		yvu420ProgPlanarToRGBA
		yvu420IntPlanarToRGBA

*****************************************************************************/


#include "yuvconverter.h"
#include "videoout.h"


/*****************************************************************************

Routine: yuv420ProgPlanarToRGBA

        returns        	: void
  Description			: Read yuv420ProgPlanar Input frame 
  							and convert it into RGBA frame
*****************************************************************************/
void yuv420ProgPlanarToRGBA(
				unsigned char *bufsrc, unsigned char *bufdest,
				int width, int height
				)
{


	bufdest += (texwidth)*(texheight-4)*4; /* Inverted buffer */

	#define YUV_420_PLANAR_PROG
	#define SRC
	#include "yuv420offsets.h"
	#undef SRC
	#undef YUV_420_PLANAR_PROG

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
		for(i=0; i<(width/2); i++)
		{
			/* First and Second Lines */	
			u = (*ptrsrccb1++);
			v = (*ptrsrccr1++);
			crv = crv_tab[v];
			cgu = cgu_tab[u];
			cgv = cgv_tab[v];
			cbu = cbu_tab[u];

			/* Top Left */
			y = tab_76309[(*ptrsrcy1++)];	
			(*ptrdestr1) = clp[384+((y + crv)>>16)];  
			(*ptrdestg1) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb1) = clp[384+((y + cbu)>>16)];
			(*ptrdesta1) = 0xFF;

			ptrdestr1 += 4;
			ptrdestg1 += 4;
			ptrdestb1 += 4;
			ptrdesta1 += 4;

			/* Top Right */
			y = tab_76309[(*ptrsrcy1++)];	
			(*ptrdestr1) = clp[384+((y + crv)>>16)];  
			(*ptrdestg1) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb1) = clp[384+((y + cbu)>>16)];
			(*ptrdesta1) = 0xFF;

			ptrdestr1 += 4;
			ptrdestg1 += 4;
			ptrdestb1 += 4;
			ptrdesta1 += 4;

			/* Bottom Left */
			y = tab_76309[(*ptrsrcy2++)];	
			(*ptrdestr2) = clp[384+((y + crv)>>16)];  
			(*ptrdestg2) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb2) = clp[384+((y + cbu)>>16)];
			(*ptrdesta2) = 0xFF;

			ptrdestr2 += 4;
			ptrdestg2 += 4;
			ptrdestb2 += 4;
			ptrdesta2 += 4;

			/* Bottom Right */
			y = tab_76309[(*ptrsrcy2++)];	
			(*ptrdestr2) = clp[384+((y + crv)>>16)];  
			(*ptrdestg2) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb2) = clp[384+((y + cbu)>>16)];
			(*ptrdesta2) = 0xFF;

			ptrdestr2 += 4;
			ptrdestg2 += 4;
			ptrdestb2 += 4;
			ptrdesta2 += 4;


			/* Third and Fourth Lines */
			u = (*ptrsrccb2++);
			v = (*ptrsrccr2++);
			crv = crv_tab[v];
			cgu = cgu_tab[u];
			cgv = cgv_tab[v];
			cbu = cbu_tab[u];

			/* Top Left */
			y = tab_76309[(*ptrsrcy3++)];	
			(*ptrdestr3) = clp[384+((y + crv)>>16)];  
			(*ptrdestg3) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb3) = clp[384+((y + cbu)>>16)];
			(*ptrdesta3) = 0xFF;

			ptrdestr3 += 4;
			ptrdestg3 += 4;
			ptrdestb3 += 4;
			ptrdesta3 += 4;

			/* Top Right */
			y = tab_76309[(*ptrsrcy3++)];	
			(*ptrdestr3) = clp[384+((y + crv)>>16)];  
			(*ptrdestg3) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb3) = clp[384+((y + cbu)>>16)];
			(*ptrdesta3) = 0xFF;

			ptrdestr3 += 4;
			ptrdestg3 += 4;
			ptrdestb3 += 4;
			ptrdesta3 += 4;

			/* Bottom Left */
			y = tab_76309[(*ptrsrcy4++)];	
			(*ptrdestr4) = clp[384+((y + crv)>>16)];  
			(*ptrdestg4) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb4) = clp[384+((y + cbu)>>16)];
			(*ptrdesta4) = 0xFF;

			ptrdestr4 += 4;
			ptrdestg4 += 4;
			ptrdestb4 += 4;
			ptrdesta4 += 4;

			/* Bottom Right */
			y = tab_76309[(*ptrsrcy4++)];	
			(*ptrdestr4) = clp[384+((y + crv)>>16)];  
			(*ptrdestg4) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb4) = clp[384+((y + cbu)>>16)];
			(*ptrdesta4) = 0xFF;

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
	
		ptrsrccr1 += srcccstride;
		ptrsrccr2 += srcccstride;

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

Routine: yuv420IntPlanarToRGBA

        returns        	: void
  Description			: Read yuv420IntPlanar Input frame 
  							and convert it into RGBA frame
*****************************************************************************/
void yuv420IntPlanarToRGBA(
				unsigned char *bufsrc, unsigned char *bufdest,
				int width, int height
				)
{


	bufdest += (texwidth)*(texheight-4)*4; /* Inverted buffer */

	#define YUV_420_PLANAR_INT
	#define SRC
	#include "yuv420offsets.h"
	#undef SRC
	#undef YUV_420_PLANAR_INT

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
		for(i=0; i<(width/2); i++)
		{
			/* First and Second Lines */	
			u = (*ptrsrccb1++);
			v = (*ptrsrccr1++);
			crv = crv_tab[v];
			cgu = cgu_tab[u];
			cgv = cgv_tab[v];
			cbu = cbu_tab[u];

			/* Top Left */
			y = tab_76309[(*ptrsrcy1++)];	
			(*ptrdestr1) = clp[384+((y + crv)>>16)];  
			(*ptrdestg1) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb1) = clp[384+((y + cbu)>>16)];
			(*ptrdesta1) = 0xFF;

			ptrdestr1 += 4;
			ptrdestg1 += 4;
			ptrdestb1 += 4;
			ptrdesta1 += 4;

			/* Top Right */
			y = tab_76309[(*ptrsrcy1++)];	
			(*ptrdestr1) = clp[384+((y + crv)>>16)];  
			(*ptrdestg1) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb1) = clp[384+((y + cbu)>>16)];
			(*ptrdesta1) = 0xFF;

			ptrdestr1 += 4;
			ptrdestg1 += 4;
			ptrdestb1 += 4;
			ptrdesta1 += 4;

			/* Bottom Left */
			y = tab_76309[(*ptrsrcy3++)];	
			(*ptrdestr2) = clp[384+((y + crv)>>16)];  
			(*ptrdestg2) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb2) = clp[384+((y + cbu)>>16)];
			(*ptrdesta2) = 0xFF;

			ptrdestr2 += 4;
			ptrdestg2 += 4;
			ptrdestb2 += 4;
			ptrdesta2 += 4;

			/* Bottom Right */
			y = tab_76309[(*ptrsrcy3++)];	
			(*ptrdestr2) = clp[384+((y + crv)>>16)];  
			(*ptrdestg2) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb2) = clp[384+((y + cbu)>>16)];
			(*ptrdesta2) = 0xFF;

			ptrdestr2 += 4;
			ptrdestg2 += 4;
			ptrdestb2 += 4;
			ptrdesta2 += 4;


			/* Third and Fourth Lines */
			u = (*ptrsrccb2++);
			v = (*ptrsrccr2++);
			crv = crv_tab[v];
			cgu = cgu_tab[u];
			cgv = cgv_tab[v];
			cbu = cbu_tab[u];

			/* Top Left */
			y = tab_76309[(*ptrsrcy2++)];	
			(*ptrdestr3) = clp[384+((y + crv)>>16)];  
			(*ptrdestg3) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb3) = clp[384+((y + cbu)>>16)];
			(*ptrdesta3) = 0xFF;

			ptrdestr3 += 4;
			ptrdestg3 += 4;
			ptrdestb3 += 4;
			ptrdesta3 += 4;

			/* Top Right */
			y = tab_76309[(*ptrsrcy2++)];	
			(*ptrdestr3) = clp[384+((y + crv)>>16)];  
			(*ptrdestg3) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb3) = clp[384+((y + cbu)>>16)];
			(*ptrdesta3) = 0xFF;

			ptrdestr3 += 4;
			ptrdestg3 += 4;
			ptrdestb3 += 4;
			ptrdesta3 += 4;

			/* Bottom Left */
			y = tab_76309[(*ptrsrcy4++)];	
			(*ptrdestr4) = clp[384+((y + crv)>>16)];  
			(*ptrdestg4) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb4) = clp[384+((y + cbu)>>16)];
			(*ptrdesta4) = 0xFF;

			ptrdestr4 += 4;
			ptrdestg4 += 4;
			ptrdestb4 += 4;
			ptrdesta4 += 4;

			/* Bottom Right */
			y = tab_76309[(*ptrsrcy4++)];	
			(*ptrdestr4) = clp[384+((y + crv)>>16)];  
			(*ptrdestg4) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb4) = clp[384+((y + cbu)>>16)];
			(*ptrdesta4) = 0xFF;

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
	
		ptrsrccr1 += srcccstride;
		ptrsrccr2 += srcccstride;

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

Routine: yvu420ProgPlanarToRGBA

        returns        	: void
  Description			: Read yvu420ProgPlanar Input frame 
  							and convert it into RGBA frame
*****************************************************************************/
void yvu420ProgPlanarToRGBA(
				unsigned char *bufsrc, unsigned char *bufdest,
				int width, int height
				)
{


	bufdest += (texwidth)*(texheight-4)*4; /* Inverted buffer */

	#define YVU_420_PLANAR_PROG
	#define SRC
	#include "yuv420offsets.h"
	#undef SRC
	#undef YVU_420_PLANAR_PROG

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
		for(i=0; i<(width/2); i++)
		{
			/* First and Second Lines */	
			u = (*ptrsrccb1++);
			v = (*ptrsrccr1++);
			crv = crv_tab[v];
			cgu = cgu_tab[u];
			cgv = cgv_tab[v];
			cbu = cbu_tab[u];

			/* Top Left */
			y = tab_76309[(*ptrsrcy1++)];	
			(*ptrdestr1) = clp[384+((y + crv)>>16)];  
			(*ptrdestg1) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb1) = clp[384+((y + cbu)>>16)];
			(*ptrdesta1) = 0xFF;

			ptrdestr1 += 4;
			ptrdestg1 += 4;
			ptrdestb1 += 4;
			ptrdesta1 += 4;

			/* Top Right */
			y = tab_76309[(*ptrsrcy1++)];	
			(*ptrdestr1) = clp[384+((y + crv)>>16)];  
			(*ptrdestg1) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb1) = clp[384+((y + cbu)>>16)];
			(*ptrdesta1) = 0xFF;

			ptrdestr1 += 4;
			ptrdestg1 += 4;
			ptrdestb1 += 4;
			ptrdesta1 += 4;

			/* Bottom Left */
			y = tab_76309[(*ptrsrcy2++)];	
			(*ptrdestr2) = clp[384+((y + crv)>>16)];  
			(*ptrdestg2) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb2) = clp[384+((y + cbu)>>16)];
			(*ptrdesta2) = 0xFF;

			ptrdestr2 += 4;
			ptrdestg2 += 4;
			ptrdestb2 += 4;
			ptrdesta2 += 4;

			/* Bottom Right */
			y = tab_76309[(*ptrsrcy2++)];	
			(*ptrdestr2) = clp[384+((y + crv)>>16)];  
			(*ptrdestg2) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb2) = clp[384+((y + cbu)>>16)];
			(*ptrdesta2) = 0xFF;

			ptrdestr2 += 4;
			ptrdestg2 += 4;
			ptrdestb2 += 4;
			ptrdesta2 += 4;


			/* Third and Fourth Lines */
			u = (*ptrsrccb2++);
			v = (*ptrsrccr2++);
			crv = crv_tab[v];
			cgu = cgu_tab[u];
			cgv = cgv_tab[v];
			cbu = cbu_tab[u];

			/* Top Left */
			y = tab_76309[(*ptrsrcy3++)];	
			(*ptrdestr3) = clp[384+((y + crv)>>16)];  
			(*ptrdestg3) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb3) = clp[384+((y + cbu)>>16)];
			(*ptrdesta3) = 0xFF;

			ptrdestr3 += 4;
			ptrdestg3 += 4;
			ptrdestb3 += 4;
			ptrdesta3 += 4;

			/* Top Right */
			y = tab_76309[(*ptrsrcy3++)];	
			(*ptrdestr3) = clp[384+((y + crv)>>16)];  
			(*ptrdestg3) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb3) = clp[384+((y + cbu)>>16)];
			(*ptrdesta3) = 0xFF;

			ptrdestr3 += 4;
			ptrdestg3 += 4;
			ptrdestb3 += 4;
			ptrdesta3 += 4;

			/* Bottom Left */
			y = tab_76309[(*ptrsrcy4++)];	
			(*ptrdestr4) = clp[384+((y + crv)>>16)];  
			(*ptrdestg4) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb4) = clp[384+((y + cbu)>>16)];
			(*ptrdesta4) = 0xFF;

			ptrdestr4 += 4;
			ptrdestg4 += 4;
			ptrdestb4 += 4;
			ptrdesta4 += 4;

			/* Bottom Right */
			y = tab_76309[(*ptrsrcy4++)];	
			(*ptrdestr4) = clp[384+((y + crv)>>16)];  
			(*ptrdestg4) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb4) = clp[384+((y + cbu)>>16)];
			(*ptrdesta4) = 0xFF;

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
	
		ptrsrccr1 += srcccstride;
		ptrsrccr2 += srcccstride;

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

Routine: yvu420IntPlanarToRGBA

        returns        	: void
  Description			: Read yvu420IntPlanar Input frame 
  							and convert it into RGBA frame
*****************************************************************************/
void yvu420IntPlanarToRGBA(
				unsigned char *bufsrc, unsigned char *bufdest,
				int width, int height
				)
{


	bufdest += (texwidth)*(texheight-4)*4; /* Inverted buffer */

	#define YVU_420_PLANAR_INT
	#define SRC
	#include "yuv420offsets.h"
	#undef SRC
	#undef YVU_420_PLANAR_INT

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
		for(i=0; i<(width/2); i++)
		{
			/* First and Second Lines */	
			u = (*ptrsrccb1++);
			v = (*ptrsrccr1++);
			crv = crv_tab[v];
			cgu = cgu_tab[u];
			cgv = cgv_tab[v];
			cbu = cbu_tab[u];

			/* Top Left */
			y = tab_76309[(*ptrsrcy1++)];	
			(*ptrdestr1) = clp[384+((y + crv)>>16)];  
			(*ptrdestg1) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb1) = clp[384+((y + cbu)>>16)];
			(*ptrdesta1) = 0xFF;

			ptrdestr1 += 4;
			ptrdestg1 += 4;
			ptrdestb1 += 4;
			ptrdesta1 += 4;

			/* Top Right */
			y = tab_76309[(*ptrsrcy1++)];	
			(*ptrdestr1) = clp[384+((y + crv)>>16)];  
			(*ptrdestg1) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb1) = clp[384+((y + cbu)>>16)];
			(*ptrdesta1) = 0xFF;

			ptrdestr1 += 4;
			ptrdestg1 += 4;
			ptrdestb1 += 4;
			ptrdesta1 += 4;

			/* Bottom Left */
			y = tab_76309[(*ptrsrcy3++)];	
			(*ptrdestr2) = clp[384+((y + crv)>>16)];  
			(*ptrdestg2) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb2) = clp[384+((y + cbu)>>16)];
			(*ptrdesta2) = 0xFF;

			ptrdestr2 += 4;
			ptrdestg2 += 4;
			ptrdestb2 += 4;
			ptrdesta2 += 4;

			/* Bottom Right */
			y = tab_76309[(*ptrsrcy3++)];	
			(*ptrdestr2) = clp[384+((y + crv)>>16)];  
			(*ptrdestg2) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb2) = clp[384+((y + cbu)>>16)];
			(*ptrdesta2) = 0xFF;

			ptrdestr2 += 4;
			ptrdestg2 += 4;
			ptrdestb2 += 4;
			ptrdesta2 += 4;


			/* Third and Fourth Lines */
			u = (*ptrsrccb2++);
			v = (*ptrsrccr2++);
			crv = crv_tab[v];
			cgu = cgu_tab[u];
			cgv = cgv_tab[v];
			cbu = cbu_tab[u];

			/* Top Left */
			y = tab_76309[(*ptrsrcy2++)];	
			(*ptrdestr3) = clp[384+((y + crv)>>16)];  
			(*ptrdestg3) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb3) = clp[384+((y + cbu)>>16)];
			(*ptrdesta3) = 0xFF;

			ptrdestr3 += 4;
			ptrdestg3 += 4;
			ptrdestb3 += 4;
			ptrdesta3 += 4;

			/* Top Right */
			y = tab_76309[(*ptrsrcy2++)];	
			(*ptrdestr3) = clp[384+((y + crv)>>16)];  
			(*ptrdestg3) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb3) = clp[384+((y + cbu)>>16)];
			(*ptrdesta3) = 0xFF;

			ptrdestr3 += 4;
			ptrdestg3 += 4;
			ptrdestb3 += 4;
			ptrdesta3 += 4;

			/* Bottom Left */
			y = tab_76309[(*ptrsrcy4++)];	
			(*ptrdestr4) = clp[384+((y + crv)>>16)];  
			(*ptrdestg4) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb4) = clp[384+((y + cbu)>>16)];
			(*ptrdesta4) = 0xFF;

			ptrdestr4 += 4;
			ptrdestg4 += 4;
			ptrdestb4 += 4;
			ptrdesta4 += 4;

			/* Bottom Right */
			y = tab_76309[(*ptrsrcy4++)];	
			(*ptrdestr4) = clp[384+((y + crv)>>16)];  
			(*ptrdestg4) = clp[384+((y - cgu - cgv)>>16)];
            (*ptrdestb4) = clp[384+((y + cbu)>>16)];
			(*ptrdesta4) = 0xFF;

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
	
		ptrsrccr1 += srcccstride;
		ptrsrccr2 += srcccstride;

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



