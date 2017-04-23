/*
 * nxsdebug.h
 *
 *  Created on: Apr 22, 2017
 *      Author: sunlightiv
 */

#ifndef NXSDEBUG_H_
#define NXSDEBUG_H_
enum Severity {INFO=0, DEBUG=1, WARNING=2, ERROR=3, CRITICAL=4, FATAL=5};
namespace nxsdebug {
void error(Severity error_level, const char * errortype, const char * error);
}



#endif /* NXSDEBUG_H_ */
