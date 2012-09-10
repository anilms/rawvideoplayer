/*****************************************************************************

FileName: <rgbtorgba.cpp>

Description:
	Modules to convert RGB to RGBA format
	Contains functions for:
		rgbProgPlanarToRGBA
		rgbProgPackedToRGBA
		bgrProgPlanarToRGBA
		bgrProgPackedToRGBA
		
*****************************************************************************/


#include "videoout.h"


/*****************************************************************************

Routine: rgbProgPlanarToRGBA

        returns        	: void
  Description			: Read rgbProgPlanar Input frame 
  							and convert into RGBA frame
*****************************************************************************/
void rgbProgPlanarToRGBA(
				unsigned char *bufsrc, unsigned char *bufdest,
				int width, int height
				)
{

	bufdest += (texwidth)*(texheight-4)*4; /* Inverted buffer */

	#define RGB_PLANAR
	#define SRC
	#include "rgboffsets.h"
	#undef SRC
	#undef RGB_PLANAR

	#define RGBA
	#define DEST
	#include "rgbaoffsets.h"
	#undef DEST
	#undef RGBA

	int i, j;
	
	for(j=0; j<(height/4); j++)
	{
		for(i=0; i<(width); i++)
		{
			(*ptrdestr1) = (*ptrsrcr1++);
			(*ptrdestg1) = (*ptrsrcg1++);
			(*ptrdestb1) = (*ptrsrcb1++);
			(*ptrdesta1) = 0xff;

			ptrdestr1 += 4;
			ptrdestg1 += 4;
			ptrdestb1 += 4;
			ptrdesta1 += 4;

			(*ptrdestr2) = (*ptrsrcr2++);
			(*ptrdestg2) = (*ptrsrcg2++);
			(*ptrdestb2) = (*ptrsrcb2++);
			(*ptrdesta2) = 0xff;

			ptrdestr2 += 4;
			ptrdestg2 += 4;
			ptrdestb2 += 4;
			ptrdesta2 += 4;

			(*ptrdestr3) = (*ptrsrcr3++);
			(*ptrdestg3) = (*ptrsrcg3++);
			(*ptrdestb3) = (*ptrsrcb3++);
			(*ptrdesta3) = 0xff;

			ptrdestr3 += 4;
			ptrdestg3 += 4;
			ptrdestb3 += 4;
			ptrdesta3 += 4;


			(*ptrdestr4) = (*ptrsrcr4++);
			(*ptrdestg4) = (*ptrsrcg4++);
			(*ptrdestb4) = (*ptrsrcb4++);
			(*ptrdesta4) = 0xff;

			ptrdestr4 += 4;
			ptrdestg4 += 4;
			ptrdestb4 += 4;
			ptrdesta4 += 4;


		}

		/* Update src pointers */
		ptrsrcr1 += srcrgbstride;
		ptrsrcr2 += srcrgbstride;
		ptrsrcr3 += srcrgbstride;
		ptrsrcr4 += srcrgbstride;

		ptrsrcg1 += srcrgbstride;
		ptrsrcg2 += srcrgbstride;
		ptrsrcg3 += srcrgbstride;
		ptrsrcg4 += srcrgbstride;

		ptrsrcb1 += srcrgbstride;
		ptrsrcb2 += srcrgbstride;
		ptrsrcb3 += srcrgbstride;
		ptrsrcb4 += srcrgbstride;


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

Routine: rgbProgPackedToRGBA

        returns        	: void
  Description			: Read rgbProgPacked Input frame 
  							and convert it into RGBA frame
*****************************************************************************/
void rgbProgPackedToRGBA(
				unsigned char *bufsrc, unsigned char *bufdest,
				int width, int height
				)
{

	bufdest += (texwidth)*(texheight-4)*4; /* Inverted buffer */

	#define RGB_PACKED
	#define SRC
	#include "rgboffsets.h"
	#undef SRC
	#undef RGB_PACKED

	#define RGBA
	#define DEST
	#include "rgbaoffsets.h"
	#undef DEST
	#undef RGBA

	int i, j;
	
	for(j=0; j<(height/4); j++)
	{
		for(i=0; i<(width); i++)
		{
			(*ptrdestr1) = (*ptrsrcr1);
			(*ptrdestg1) = (*ptrsrcg1);
			(*ptrdestb1) = (*ptrsrcb1);
			(*ptrdesta1) = 0xff;

			ptrsrcr1 += 3;
			ptrsrcg1 += 3;
			ptrsrcb1 += 3;

			ptrdestr1 += 4;
			ptrdestg1 += 4;
			ptrdestb1 += 4;
			ptrdesta1 += 4;


			(*ptrdestr2) = (*ptrsrcr2);
			(*ptrdestg2) = (*ptrsrcg2);
			(*ptrdestb2) = (*ptrsrcb2);
			(*ptrdesta2) = 0xff;

			ptrsrcr2 += 3;
			ptrsrcg2 += 3;
			ptrsrcb2 += 3;

			ptrdestr2 += 4;
			ptrdestg2 += 4;
			ptrdestb2 += 4;
			ptrdesta2 += 4;


			(*ptrdestr3) = (*ptrsrcr3);
			(*ptrdestg3) = (*ptrsrcg3);
			(*ptrdestb3) = (*ptrsrcb3);
			(*ptrdesta3) = 0xff;

			ptrsrcr3 += 3;
			ptrsrcg3 += 3;
			ptrsrcb3 += 3;

			ptrdestr3 += 4;
			ptrdestg3 += 4;
			ptrdestb3 += 4;
			ptrdesta3 += 4;


			(*ptrdestr4) = (*ptrsrcr4);
			(*ptrdestg4) = (*ptrsrcg4);
			(*ptrdestb4) = (*ptrsrcb4);
			(*ptrdesta4) = 0xff;

			ptrsrcr4 += 3;
			ptrsrcg4 += 3;
			ptrsrcb4 += 3;

			ptrdestr4 += 4;
			ptrdestg4 += 4;
			ptrdestb4 += 4;
			ptrdesta4 += 4;


		}

		/* Update src pointers */
		ptrsrcr1 += srcrgbstride;
		ptrsrcr2 += srcrgbstride;
		ptrsrcr3 += srcrgbstride;
		ptrsrcr4 += srcrgbstride;

		ptrsrcg1 += srcrgbstride;
		ptrsrcg2 += srcrgbstride;
		ptrsrcg3 += srcrgbstride;
		ptrsrcg4 += srcrgbstride;

		ptrsrcb1 += srcrgbstride;
		ptrsrcb2 += srcrgbstride;
		ptrsrcb3 += srcrgbstride;
		ptrsrcb4 += srcrgbstride;


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

Routine: bgrProgPlanarToRGBA

        returns        	: void
  Description			: Read bgr_prog_planar Input frame 
  							and convert it into RGBA frame
*****************************************************************************/
void bgrProgPlanarToRGBA(
				unsigned char *bufsrc, unsigned char *bufdest,
				int width, int height
				)
{

	bufdest += (texwidth)*(texheight-4)*4; /* Inverted buffer */

	#define BGR_PLANAR
	#define SRC
	#include "rgboffsets.h"
	#undef SRC
	#undef BGR_PLANAR

	#define RGBA
	#define DEST
	#include "rgbaoffsets.h"
	#undef DEST
	#undef RGBA

	int i, j;
	
	for(j=0; j<(height/4); j++)
	{
		for(i=0; i<(width); i++)
		{
			(*ptrdestr1) = (*ptrsrcr1++);
			(*ptrdestg1) = (*ptrsrcg1++);
			(*ptrdestb1) = (*ptrsrcb1++);
			(*ptrdesta1) = 0xff;

			ptrdestr1 += 4;
			ptrdestg1 += 4;
			ptrdestb1 += 4;
			ptrdesta1 += 4;

			(*ptrdestr2) = (*ptrsrcr2++);
			(*ptrdestg2) = (*ptrsrcg2++);
			(*ptrdestb2) = (*ptrsrcb2++);
			(*ptrdesta2) = 0xff;

			ptrdestr2 += 4;
			ptrdestg2 += 4;
			ptrdestb2 += 4;
			ptrdesta2 += 4;

			(*ptrdestr3) = (*ptrsrcr3++);
			(*ptrdestg3) = (*ptrsrcg3++);
			(*ptrdestb3) = (*ptrsrcb3++);
			(*ptrdesta3) = 0xff;

			ptrdestr3 += 4;
			ptrdestg3 += 4;
			ptrdestb3 += 4;
			ptrdesta3 += 4;


			(*ptrdestr4) = (*ptrsrcr4++);
			(*ptrdestg4) = (*ptrsrcg4++);
			(*ptrdestb4) = (*ptrsrcb4++);
			(*ptrdesta4) = 0xff;

			ptrdestr4 += 4;
			ptrdestg4 += 4;
			ptrdestb4 += 4;
			ptrdesta4 += 4;


		}

		/* Update src pointers */
		ptrsrcr1 += srcrgbstride;
		ptrsrcr2 += srcrgbstride;
		ptrsrcr3 += srcrgbstride;
		ptrsrcr4 += srcrgbstride;

		ptrsrcg1 += srcrgbstride;
		ptrsrcg2 += srcrgbstride;
		ptrsrcg3 += srcrgbstride;
		ptrsrcg4 += srcrgbstride;

		ptrsrcb1 += srcrgbstride;
		ptrsrcb2 += srcrgbstride;
		ptrsrcb3 += srcrgbstride;
		ptrsrcb4 += srcrgbstride;


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

Routine: bgrProgPackedToRGBA

        returns        	: void
  Description			: Read bgrProgPacked Input frame 
  							and convert it into RGBA frame
*****************************************************************************/
void bgrProgPackedToRGBA(
				unsigned char *bufsrc, unsigned char *bufdest,
				int width, int height
				)
{

	bufdest += (texwidth)*(texheight-4)*4; /* Inverted buffer */

	#define BGR_PACKED
	#define SRC
	#include "rgboffsets.h"
	#undef SRC
	#undef BGR_PACKED

	#define RGBA
	#define DEST
	#include "rgbaoffsets.h"
	#undef DEST
	#undef RGBA

	int i, j;
	
	for(j=0; j<(height/4); j++)
	{
		for(i=0; i<(width); i++)
		{
			(*ptrdestr1) = (*ptrsrcr1);
			(*ptrdestg1) = (*ptrsrcg1);
			(*ptrdestb1) = (*ptrsrcb1);
			(*ptrdesta1) = 0xff;

			ptrsrcr1 += 3;
			ptrsrcg1 += 3;
			ptrsrcb1 += 3;

			ptrdestr1 += 4;
			ptrdestg1 += 4;
			ptrdestb1 += 4;
			ptrdesta1 += 4;


			(*ptrdestr2) = (*ptrsrcr2);
			(*ptrdestg2) = (*ptrsrcg2);
			(*ptrdestb2) = (*ptrsrcb2);
			(*ptrdesta2) = 0xff;

			ptrsrcr2 += 3;
			ptrsrcg2 += 3;
			ptrsrcb2 += 3;

			ptrdestr2 += 4;
			ptrdestg2 += 4;
			ptrdestb2 += 4;
			ptrdesta2 += 4;


			(*ptrdestr3) = (*ptrsrcr3);
			(*ptrdestg3) = (*ptrsrcg3);
			(*ptrdestb3) = (*ptrsrcb3);
			(*ptrdesta3) = 0xff;

			ptrsrcr3 += 3;
			ptrsrcg3 += 3;
			ptrsrcb3 += 3;

			ptrdestr3 += 4;
			ptrdestg3 += 4;
			ptrdestb3 += 4;
			ptrdesta3 += 4;


			(*ptrdestr4) = (*ptrsrcr4);
			(*ptrdestg4) = (*ptrsrcg4);
			(*ptrdestb4) = (*ptrsrcb4);
			(*ptrdesta4) = 0xff;

			ptrsrcr4 += 3;
			ptrsrcg4 += 3;
			ptrsrcb4 += 3;

			ptrdestr4 += 4;
			ptrdestg4 += 4;
			ptrdestb4 += 4;
			ptrdesta4 += 4;


		}

		/* Update src pointers */
		ptrsrcr1 += srcrgbstride;
		ptrsrcr2 += srcrgbstride;
		ptrsrcr3 += srcrgbstride;
		ptrsrcr4 += srcrgbstride;

		ptrsrcg1 += srcrgbstride;
		ptrsrcg2 += srcrgbstride;
		ptrsrcg3 += srcrgbstride;
		ptrsrcg4 += srcrgbstride;

		ptrsrcb1 += srcrgbstride;
		ptrsrcb2 += srcrgbstride;
		ptrsrcb3 += srcrgbstride;
		ptrsrcb4 += srcrgbstride;


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


