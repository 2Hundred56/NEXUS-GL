/*
 * nxssystem.h
 *
 *  Created on: Apr 23, 2017
 *      Author: sunlightiv
 */
#ifndef NXSSYSTEM_H_
#define NXSSYSTEM_H_
namespace nxssystem {
void init();
void quit();
void die(const char * err);
double time();
void flip();
}
#endif /* NXSSYSTEM_H_ */
