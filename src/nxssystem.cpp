/*
 * nxssystem.cpp
 *
 *  Created on: Apr 23, 2017
 *      Author: sunlightiv
 */
#include "nxssystem.h"
#include "nxsdebug.h"
#include "SDL2/SDL.h"
#include "glad/glad.h"
bool FULLSCREEN = false;
int WIDTH = 720;
int HEIGHT = 720;
const char * CAPTION = "NEXUS";
int GLMAJORVERSION = 2;
int GLMINORVERSION = 2;
int GLDEPTHSIZE = 24;
namespace nxssystem {
SDL_Window* window = NULL;
SDL_GLContext context;
void flip() {
	SDL_GL_SwapWindow(window);
}
void init() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		die("Couldn't initialize SDL");
	atexit(quit);
	SDL_GL_LoadLibrary(NULL);
	SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, GLMAJORVERSION);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, GLMINORVERSION);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, GLDEPTHSIZE);
	if (FULLSCREEN) {
	  window = SDL_CreateWindow(
	    CAPTION,
	    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
	    0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_OPENGL
	  );
	} else {
	  window = SDL_CreateWindow(
	    CAPTION,
	    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
	    WIDTH, HEIGHT, SDL_WINDOW_OPENGL
	  );
	}
	if (window == NULL) die("Couldn't set video mode");
	context = SDL_GL_CreateContext(window);
	if (context == NULL)
	  die("Failed to create OpenGL context");
	nxsdebug::error(INFO, "OpenGL loaded", "");
	gladLoadGLLoader(SDL_GL_GetProcAddress);
	nxsdebug::error(INFO, "Vendor", (const char *) glGetString(GL_VENDOR));
	nxsdebug::error(INFO, "Renderer", (const char *) glGetString(GL_RENDERER));
	nxsdebug::error(INFO, "Version", (const char *) glGetString(GL_VERSION));
	SDL_GL_SetSwapInterval(1);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);
	int w,h;
	SDL_GetWindowSize(window, &w, &h);
	glViewport(0, 0, w, h);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}
void quit() {
	SDL_Quit();
}

void die(const char* err) {
	nxsdebug::error(FATAL, err, SDL_GetError());
}

}

double nxssystem::time() {
	return ((double) SDL_GetTicks())/1000.0;
}
