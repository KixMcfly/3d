#include <glib.h>
#include <SDL.h>
#include <GL/gl.h>
#include "3d.h"

void drawTriangle()
{
    glClearColor(0.4, 0.4, 0.4, 0.4);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

        glBegin(GL_TRIANGLES);
                glVertex3f(-0.7, 0.7, 0);
                glVertex3f(0.7, 0.7, 0);
                glVertex3f(0, -1, 0);
        glEnd();

    glFlush();
}

gboolean
three_d_init (SDL_Window *win)
{
	gboolean success = true;
	
	if (SDL_Init (SDL) < 0)
	{
		g_print ("Error starting SDL video: %s\n", SDL_GetError ());
		success = FALSE;
	}
	else
	{
		SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3 );
		SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 1 );
		SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );

		win = SDL_CreateWindow ("3d",
								SDL_WINDOWPOS_UNDEFINED,
								SDL_WINDOWPOS_UNDEFINED,
								SCREEN_WIDTH,
								SCREEN_HEIGHT,
								SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
		if (win)
		{
			g_print ("Error creating window. SDL Error: %s\n", SDL_GetError());
			success = FALSE;
		}
		else
		{
			context = SDL_GL_CreateContext (win);
			if (!context)
			{
				g_print( "Couldn't create OpenGL context. SDL Error: %s\n", SDL_GetError() );
				success = FALSE;
			}
			else
			{
				if (SDL_GL_SetSwapInterval (1) < 0)
				{
					g_print ("VSync Error. SDL Error: %s\n", SDL_GetError() );
				}

				if (!initGL())
				{
					g_print ("Unable to initialize OpenGL!\n");
					success = FALSE;
				}
			}
		}
	}
	
	return success;
}

int main(int argc, char **argv)
{
    
    return 0;
}
