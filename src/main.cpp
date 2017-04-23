/*
 * main.cpp
 *
 *  Created on: Apr 21, 2017
 *      Author: sunlightiv
 */
#include "nxssystem.h"
#include "GameThread.h"
int main() {
	nxssystem::init();
	nxssystem::GameThread* game = new nxssystem::GameThread();
	double dt, time, last = 0;
	do {
		time = nxssystem::time();
		dt = time-last;
		last = time;

	} while (game->update(dt));
	delete game;
	return 0;
}



