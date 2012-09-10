/*****************************************************************************

FileName: <videoout.h>

Description:
	Header File for videoout.cpp

*****************************************************************************/


#define COMPONENTS 				4
#define TRICK_MODE_MOVE 		5
#define TRICK_MODE_FAST_MOVE 	25
#define TRICK_MODE_FAST_FWD 	2
#define TRICK_MODE_MAXFRAMERATE	128
#define TRICK_MODE_MINFRAMERATE	1
#define INITTIME				-1000

extern int texwidth;
extern int texheight;
extern int framewidth;
extern int frameheight;

void GenTexture();
void VideoOutInit(char *name, int argc, char **argv, int width, int height, int displaywidth, int displayheight);

