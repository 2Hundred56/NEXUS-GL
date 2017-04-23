/*
 * GameThread.h
 *
 *  Created on: Apr 23, 2017
 *      Author: sunlightiv
 */

#ifndef GAMETHREAD_H_
#define GAMETHREAD_H_

namespace nxssystem {

class GameThread {
public:
	GameThread();
	virtual ~GameThread();

	bool update(double dt);
};

} /* namespace nxssystem */

#endif /* GAMETHREAD_H_ */
