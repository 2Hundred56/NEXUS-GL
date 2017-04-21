/*
 * test_truism.cpp
 *
 *  Created on: Apr 21, 2017
 *      Author: sunlightiv
 */
#include "catch.hpp"
SCENARIO ("Truisms are true", "[true]") {
	GIVEN ("Two equal values") {
	int a = 2;
	int b= 2;
	THEN ("They are equal") {
	REQUIRE (a==b);
	}
	}
}




