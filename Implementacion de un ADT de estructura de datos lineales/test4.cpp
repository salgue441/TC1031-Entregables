/*
 * main.cpp
 *
 *  Created on: 05/08/2015
 *      Author: pperezm
 */
#define CATCH_CONFIG_MAIN
#include <string>
#include "catch.h"
#include "list.h"

TEST_CASE("testing indexOf", "[List]") {
	List<int> b1;
	b1.push_front(7); b1.push_front(6); b1.push_front(5);
	b1.push_front(4); b1.push_front(3); b1.push_front(2);

	SECTION ( "b1.indexOf(2)" ) {
		REQUIRE(b1.indexOf(2) == 0);
	}

	SECTION ( "b1.indexOf(7)" ) {
		REQUIRE(b1.indexOf(7) == 5);
	}

	SECTION ( "b1.indexOf(5)" ) {
		REQUIRE(b1.indexOf(5) == 3);
	}

	SECTION ( "b1.indexOf(100)" ) {
		REQUIRE(b1.indexOf(100) == -1);
	}
}
