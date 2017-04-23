/*
 * GameThread.cpp
 *
 *  Created on: Apr 23, 2017
 *      Author: sunlightiv
 */

#include "GameThread.h"
#include "SDL2/SDL.h"
#include "nxssystem.h"
namespace nxssystem {

GameThread::GameThread() {
}

GameThread::~GameThread() {
}

bool GameThread::update(double dt) {
	bool quit = false;
	SDL_Event event;
	flip();
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			quit = true;
		}
	}
	return !quit;
}

} /* namespace nxssystem */
