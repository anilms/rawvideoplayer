/*****************************************************************************

FileName: <ytorgba.cpp>

Description:
	Modules for Converting Y input to RGBA
	Contains functions for:
		yToRGBA

*****************************************************************************/


#include "yuvconverter.h"
#include "videoout.h"


/*****************************************************************************

Routine: yToRGBA

        returns        	: void
  Description			: Read y Input frame 
  							and convert it into RGBA frame
*****************************************************************************/
void yToRGBA(
				unsigned char *bufsrc, unsigned char *bufdest,
				int width, int height
				)
{


	bufdest += (texwidth)*(texheight-4)*4; /* Inverted buffer */

	#define Y_ONLY
	#define SRC
	#include "yoffsets.h"
	#undef SRC
	#undef Y_ONLY

	#define RGBA
	#define DEST
	#include "rgbaoffsets.h"
	#undef DEST
	#undef RGBA


	int i, j;
	int y;


	for(j=0; j<(height/4); j++)
	{
		for(i=0; i<(width/2); i++)
		{
			/* First and Second Lines */	
			/* Top Left */
			y = *ptrsrcy1++;	
			(*ptrdestr1) = y;  
			(*ptrdestg1) = y;
            (*ptrdestb1) = y;

			ptrdestr1 += 4;
			ptrdestg1 += 4;
			ptrdestb1 += 4;

			/* Top Right */
			y = *ptrsrcy1++;	
			(*ptrdestr1) = y;  
			(*ptrdestg1) = y;
            (*ptrdestb1) = y;

			ptrdestr1 += 4;
			ptrdestg1 += 4;
			ptrdestb1 += 4;

			/* Bottom Left */
			y = *ptrsrcy2++;	
			(*ptrdestr2) = y;  
			(*ptrdestg2) = y;
            (*ptrdestb2) = y;

			ptrdestr2 += 4;
			ptrdestg2 += 4;
			ptrdestb2 += 4;

			/* Bottom Right */
			y = *ptrsrcy2++;	
			(*ptrdestr2) = y;  
			(*ptrdestg2) = y;
            (*ptrdestb2) = y;

			ptrdestr2 += 4;
			ptrdestg2 += 4;
			ptrdestb2 += 4;


			/* Third and Fourth Lines */
			/* Top Left */
			y = (*ptrsrcy3++);	
			(*ptrdestr3) = y;  
			(*ptrdestg3) = y;
            (*ptrdestb3) = y;

			ptrdestr3 += 4;
			ptrdestg3 += 4;
			ptrdestb3 += 4;

			/* Top Right */
			y = (*ptrsrcy3++);	
			(*ptrdestr3) = y;  
			(*ptrdestg3) = y;
            (*ptrdestb3) = y;

			ptrdestr3 += 4;
			ptrdestg3 += 4;
			ptrdestb3 += 4;

			/* Bottom Left */
			y = (*ptrsrcy4++);	
			(*ptrdestr4) = y;  
			(*ptrdestg4) = y;
            (*ptrdestb4) = y;

			ptrdestr4 += 4;
			ptrdestg4 += 4;
			ptrdestb4 += 4;

			/* Bottom Right */
			y = (*ptrsrcy4++);	
			(*ptrdestr4) = y;  
			(*ptrdestg4) = y;
            (*ptrdestb4) = y;

			ptrdestr4 += 4;
			ptrdestg4 += 4;
			ptrdestb4 += 4;

		}

		/* Update src pointers */
		ptrsrcy1  += srcystride;
		ptrsrcy2  += srcystride;
		ptrsrcy3  += srcystride;
		ptrsrcy4  += srcystride;
		
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


	}
}



