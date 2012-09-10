/*****************************************************************************

FileName: 	<inittab.cpp>

Description:
Contains Modules to initialize the LUTs for YUVtoRGB conversion

*****************************************************************************/

#include "yuvconverter.h"
#include "inittab.h"


/*****************************************************************************
  Routine:  void InitTab()

        returns        	: void
  Description          	: Initializes the LUTs for yuvtorgb conversion
*****************************************************************************/

void InitTab() {
   long int crv,cbu,cgu,cgv;
   int i,ind;   
     
   crv = SCALECrv; cbu = SCALECbu;
   cgu = SCALECgu; cgv = SCALECgv;
  
   for (i = 0; i < 256; i++) {
        crv_tab[i] = (i-SHIFTCrv) * crv;
        cbu_tab[i] = (i-SHIFTCbu) * cbu;
        cgu_tab[i] = (i-SHIFTCgu) * cgu;
        cgv_tab[i] = (i-SHIFTCgv) * cgv;
        tab_76309[i] = SCALEY*(i-SHIFTY);
  
   }
	 
   for (i=0; i<384; i++)
	  clp[i] =0;
   ind=384;
   for (i=0;i<256; i++)
	   clp[ind++]=i;
   ind=640;
   for (i=0;i<384;i++)
	   clp[ind++]=255;
}




