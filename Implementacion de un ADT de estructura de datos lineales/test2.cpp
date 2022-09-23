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

TEST_CASE("testing insert_at", "[List]") {
	List<int> b1;
	b1.push_front(7); b1.push_front(6); b1.push_front(5);
	b1.push_front(4); b1.push_front(3); b1.push_front(2);

	SECTION ( "b1.insert_at(100, 0)" ) {
		b1.insert_at(100, 0);
		REQUIRE(b1.length() == 7);
		REQUIRE(b1.toString() == "[100, 2, 3, 4, 5, 6, 7]");
	}

	SECTION ( "b1.insert_at(100, 3)" ) {
		b1.insert_at(100, 3);
		REQUIRE(b1.length() == 7);
		REQUIRE(b1.toString() == "[2, 3, 4, 100, 5, 6, 7]");
	}

	SECTION ( "b1.insert_at(100, 6)" ) {
		b1.insert_at(100, 6);
		REQUIRE(b1.length() == 7);
		REQUIRE(b1.toString() == "[2, 3, 4, 5, 6, 7, 100]");
	}

	SECTION ( "b1.insert_at(100, 7)" ) {
		REQUIRE_THROWS_AS(b1.insert_at(100, 1000), IndexOutOfBounds);
	}
}
