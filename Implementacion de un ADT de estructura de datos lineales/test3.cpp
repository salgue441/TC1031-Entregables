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

TEST_CASE("testing remove_at", "[List]") {
	List<int> b1;
	b1.push_front(7); b1.push_front(6); b1.push_front(5);
	b1.push_front(4); b1.push_front(3); b1.push_front(2);

	SECTION ( "b1.remove_at(0)" ) {
		int result = b1.remove_at(0);
		REQUIRE(result == 2);
		REQUIRE(b1.length() == 5);
		REQUIRE(b1.toString() == "[3, 4, 5, 6, 7]");
	}

	SECTION ( "b1.remove_at(5)" ) {
		int result = b1.remove_at(5);
		REQUIRE(result == 7);
		REQUIRE(b1.length() == 5);
		REQUIRE(b1.toString() == "[2, 3, 4, 5, 6]");
	}

	SECTION ( "b1.remove_at(3)" ) {
		int result = b1.remove_at(3);
		REQUIRE(result == 5);
		REQUIRE(b1.length() == 5);
		REQUIRE(b1.toString() == "[2, 3, 4, 6, 7]");
	}

	SECTION ( "b1.remove_at(6)" ) {
		REQUIRE_THROWS_AS(b1.remove_at(1000), IndexOutOfBounds);
	}
}
