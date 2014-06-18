/*****************************************************************************

FileName: <yuvconverter.h>

Description:
	Header File for yuvconverter modules

*****************************************************************************/


/* LUTs for YUV to RGB conversion */
extern long int crv_tab[256];
extern long int cbu_tab[256];
extern long int cgu_tab[256];
extern long int cgv_tab[256];
extern long int tab_76309[256];
extern unsigned char clp[1024];
extern void (*GetRGBAFrame)(unsigned char *bufsrc, unsigned char *bufdest, int width, int height);

void InitConverter(int width, int height, int mode);
void InitTab();


/* Y to RGBA */
void yToRGBA(unsigned char *bufsrc, unsigned char *bufdest,int width, int height);


/* YUV 420 to RGBA */
void yuv420ProgPlanarToRGBA(unsigned char *bufsrc, unsigned char *bufdest,int width, int height);
void yuv420IntPlanarToRGBA(unsigned char *bufsrc, unsigned char *bufdest,int width, int height);
void yvu420ProgPlanarToRGBA(unsigned char *bufsrc, unsigned char *bufdest,int width, int height);
void yvu420IntPlanarToRGBA(unsigned char *bufsrc, unsigned char *bufdest,int width, int height);
void yuv420YCbCrPlanarToRGBA(unsigned char *bufsrc, unsigned char *bufdest,int width, int height);


/* YUV 422 to RGBA */
void yuv422ProgPlanarToRGBA(unsigned char *bufsrc, unsigned char *bufdest,int width, int height);
void yuv422IntPlanarToRGBA(unsigned char *bufsrc, unsigned char *bufdest,int width, int height);
void yvu422ProgPlanarToRGBA(unsigned char *bufsrc, unsigned char *bufdest,int width, int height);
void yvu422IntPlanarToRGBA(unsigned char *bufsrc, unsigned char *bufdest,int width, int height);

void uyvyProgPackedToRGBA(unsigned char *bufsrc, unsigned char *bufdest,int width, int height);
void uyvyIntPackedToRGBA(unsigned char *bufsrc, unsigned char *bufdest,int width, int height);
void yuyvProgPackedToRGBA(unsigned char *bufsrc, unsigned char *bufdest,int width, int height);
void yuyvIntPackedToRGBA(unsigned char *bufsrc, unsigned char *bufdest,int width, int height);
void yvyuProgPackedToRGBA(unsigned char *bufsrc, unsigned char *bufdest,int width, int height);
void yvyuIntPackedToRGBA(unsigned char *bufsrc, unsigned char *bufdest,int width, int height);


/* YUV 444 to RGBA */
void yuv444ProgPlanarToRGBA(unsigned char *bufsrc, unsigned char *bufdest,int width, int height);
void yuv444IntPlanarToRGBA(unsigned char *bufsrc, unsigned char *bufdest,int width, int height);
void yvu444ProgPlanarToRGBA(unsigned char *bufsrc, unsigned char *bufdest,int width, int height);
void yvu444IntPlanarToRGBA(unsigned char *bufsrc, unsigned char *bufdest,int width, int height);
void uyv444ProgPlanarToRGBA(unsigned char *bufsrc, unsigned char *bufdest,int width, int height);
void uyv444IntPlanarToRGBA(unsigned char *bufsrc, unsigned char *bufdest,int width, int height);

void yuv444ProgPackedToRGBA(unsigned char *bufsrc, unsigned char *bufdest,int width, int height);
void yuv444IntPackedToRGBA(unsigned char *bufsrc, unsigned char *bufdest,int width, int height);
void yvu444ProgPackedToRGBA(unsigned char *bufsrc, unsigned char *bufdest,int width, int height);
void yvu444IntPackedToRGBA(unsigned char *bufsrc, unsigned char *bufdest,int width, int height);
void uyv444ProgPackedToRGBA(unsigned char *bufsrc, unsigned char *bufdest,int width, int height);
void uyv444IntPackedToRGBA(unsigned char *bufsrc, unsigned char *bufdest,int width, int height);


/* RGB to RGBA */
void rgbProgPlanarToRGBA(unsigned char *bufsrc, unsigned char *bufdest,int width, int height);
void rgbProgPackedToRGBA(unsigned char *bufsrc, unsigned char *bufdest,int width, int height);
void bgrProgPlanarToRGBA(unsigned char *bufsrc, unsigned char *bufdest,int width, int height);
void bgrProgPackedToRGBA(unsigned char *bufsrc, unsigned char *bufdest,int width, int height);



