/*
 * nxsdebug.cpp
 *
 *  Created on: Apr 22, 2017
 *      Author: sunlightiv
 */
#include "nxsdebug.h"
#include <cstdio>
#include <cstdlib>
Severity KILLTHRESHOLD = FATAL;
Severity DISPLAYTHRESHOLD = INFO;

const inline char * to_string(Severity level) {
	switch (level) {
	case INFO: return "INFO";
	case DEBUG: return "DEBUG";
	case WARNING: return "WARNING";
	case ERROR: return "ERROR";
	case CRITICAL: return "CRITICAL";
	case FATAL: return "FATAL";
	default: return "MISC";
	}
}
namespace nxsdebug {
void error (Severity error_level, const char * error1, const char* error2) {
if (error_level>=DISPLAYTHRESHOLD) {
fprintf(stderr, "%s - %s: %s\n", to_string(error_level), error1, error2);
}
if (error_level>=KILLTHRESHOLD) {
	exit(2);
}
}
}


