/*****************************************************************************

FileName: <videoout.cpp>

Description:
	Modules for displaying video

*****************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "rawvideoplayer.h"
#include "videoout.h"

unsigned char *rgba_buffer;
int texwidth=0, texheight=0;
float relwidth, relheight;
int textureid = 1;
int running = 1;
int framenum = 0;
float framerate = 25;
int frameinterval = 40;
int nTime, nLastTime;

extern FILE *infile1;
extern char *infile1_name;
extern FILE *infile2;
extern char *infile2_name;
extern int inframesize;
extern int bTwoFiles;

/*****************************************************************************
  Routine:  void GenTexture()

        returns        	: void
  Description          	: Generate Texture Object
*****************************************************************************/
void GenTexture()
{
	GenOutputBuf();

	glEnable(GL_TEXTURE_2D);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	glBindTexture(GL_TEXTURE_2D, textureid);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexImage2D(GL_TEXTURE_2D, 0, COMPONENTS, texwidth, texheight, 0, GL_RGBA,
				GL_UNSIGNED_BYTE, rgba_buffer);
}



/*****************************************************************************
  Routine:  void event_display()

        returns        	: void
  Description          	: CallBack function for display
*****************************************************************************/
void event_display(void) 
{

	if(running)
	{
		nTime = glutGet(GLUT_ELAPSED_TIME);
		if((nTime-nLastTime) >= frameinterval)
		{
			GenTexture();
			nLastTime = nTime;
		}
	}

	
	glClear(GL_COLOR_BUFFER_BIT);
    glBindTexture(GL_TEXTURE_2D, textureid);
    glPushMatrix();
    glBegin(GL_POLYGON);
	glTexCoord2f(0.0, (1-relheight));
	glVertex2f(-1.0, -1.0);					// left top
	glTexCoord2f(relwidth, (1-relheight));
	glVertex2f(1.0, -1.0);					// right top
	glTexCoord2f(relwidth, 1.0);
	glVertex2f(1.0, 1.0);					// right bottom
	glTexCoord2f(0.0, 1.0);
	glVertex2f(-1.0, 1.0);					// left bottom
    glEnd();
    glPopMatrix();
    glutSwapBuffers();

	glBindTexture(GL_TEXTURE_2D, 0);

}



/*****************************************************************************
  Routine:  void event_key(unsigned char key, int x, int y)

        returns        	: void
  Description          	: CallBack function for KeyHit
*****************************************************************************/
void event_key(unsigned char key, int x, int y)
{
    switch(key) {
    case '\033'	: exit(0);		break;
    case ' '	: running ^= 1; break;
    default: break;
    }
    glutPostRedisplay();
}



/*****************************************************************************
  Routine:  void event_specialkey(int key, int x, int y)

        returns        	: void
  Description          	: CallBack function for KeyHit
*****************************************************************************/
void event_specialkey(int key, int x, int y)
{
    switch(key) {

	case GLUT_KEY_PAGE_UP :
						framerate = framerate*TRICK_MODE_FAST_FWD;
						if (framerate > TRICK_MODE_MAXFRAMERATE)
							framerate = TRICK_MODE_MAXFRAMERATE;
						frameinterval = (int)((float)1000*(framenum)/framerate)-(int)((float)1000*(framenum-1)/framerate);
						nLastTime = -frameinterval;
						nTime = 0;
						break;

    case GLUT_KEY_PAGE_DOWN :
						framerate = framerate/TRICK_MODE_FAST_FWD;
						if (framerate< TRICK_MODE_MINFRAMERATE)
							framerate = TRICK_MODE_MINFRAMERATE;
						frameinterval = (int)((float)1000*(framenum)/framerate)-(int)((float)1000*(framenum-1)/framerate);
						nLastTime = -frameinterval;
						nTime = 0;
						break;


	case GLUT_KEY_RIGHT :
						framerate = framerate*TRICK_MODE_FAST_FWD;
						if (framerate > TRICK_MODE_MAXFRAMERATE)
							framerate = TRICK_MODE_MAXFRAMERATE;
						frameinterval = (int)((float)1000*(framenum)/framerate)-(int)((float)1000*(framenum-1)/framerate);
						nLastTime = -frameinterval;
						nTime = 0;
						break;

    case GLUT_KEY_LEFT :
						framerate = framerate/TRICK_MODE_FAST_FWD;
						if (framerate< TRICK_MODE_MINFRAMERATE)
							framerate = TRICK_MODE_MINFRAMERATE;
						frameinterval = (int)((float)1000*(framenum)/framerate)-(int)((float)1000*(framenum-1)/framerate);
						nLastTime = -frameinterval;
						nTime = 0;
						break;


    case GLUT_KEY_HOME :
						if(!feof(infile1))
		   					fseek(infile1, 0, SEEK_SET);
						else
						{
							fclose(infile1);
							fopen(infile1_name, "rb");
							fseek(infile1, 0, SEEK_SET);
						}
						if(bTwoFiles)
						{
							if(!feof(infile2))
								fseek(infile2, 0, SEEK_SET);
							else
							{
								fclose(infile2);
								fopen(infile2_name, "rb");
								fseek(infile2, 0, SEEK_SET);
							}
						}
						framenum = 0;
						running = 0;
						GenTexture();
						nLastTime = -frameinterval;
						nTime = 0;
						break;

    default: break;
    }
	event_display();
    glutPostRedisplay();
}



/*****************************************************************************
  Routine:  void event_animate()

        returns        	: void
  Description          	: Animation
*****************************************************************************/
void event_animate(void) 
{
	glutPostRedisplay();
	printf("\rFrame: %d", framenum);
}



/*****************************************************************************
  Routine:  event_reshape(int w, int h)

        returns        	: void
  Description          	: CallBack function for Reshape
*****************************************************************************/
void event_reshape(int w, int h) 
{
    glViewport(0, 0, w, h);
}




/*****************************************************************************
  Routine:  VideoOutInit(
  						char *name, int argc, char **argv, 
						int width, int height, 
						int displaywidth, int displayheight
						)

        returns        	: void
  Description          	: Initializes the display process. Display process
  						  will there after call the necessary functions
						  through callback functions to generate the output.

*****************************************************************************/
void VideoOutInit(
					char *name, int argc, char *argv[], 
					int width, int height, 
					int displaywidth, int displayheight
					)
{

	int i, size;

	/* Initialize texture width to nearest power of 2 */
	size = 1;
	while(size<width)
		size = (size << 1);
	texwidth = size;
	/* Initialize texture height to nearest power of 2 */
	size = 1;
	while(size<height)
		size = (size << 1);
	texheight = size;

	relwidth = (float)width/(float)texwidth;
	relheight = (float)height/(float)texheight;

	rgba_buffer = (unsigned char *)malloc(texwidth*texheight*4);
	if(rgba_buffer != NULL)
	{
		memset(rgba_buffer, 0, texwidth*texheight*4);
		for(i=3; i<texwidth*texheight*4; i+=4)
			rgba_buffer[i]=0xFF;	// set alpha values to 0xFF
	}
	else
	{
		printf("\nAllocating Buffers failed! Not Enough Memory.");
		printf("\nExiting !!!");
		exit(4);
	}
		
	nTime = 0;
	nLastTime = -frameinterval;

	/* Create Window */
	glutInitWindowSize(displaywidth, displayheight);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE);
    (void)glutCreateWindow(name);

	/* Map GLUT callback functions */
    glutDisplayFunc(event_display);
    glutKeyboardFunc(event_key);
    glutSpecialFunc(event_specialkey);
    glutReshapeFunc(event_reshape);
    glutIdleFunc(event_animate);

	/* Run Callback Loop */
    glutMainLoop();

}

