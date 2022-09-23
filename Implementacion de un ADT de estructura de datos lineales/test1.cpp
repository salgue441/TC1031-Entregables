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

TEST_CASE("testing get", "[List]") {
	List<int> b1;
	b1.push_front(7); b1.push_front(6); b1.push_front(5);
	b1.push_front(4); b1.push_front(3); b1.push_front(2);

	REQUIRE(b1.get(0) == 2);
	REQUIRE(b1.get(5) == 7);
	REQUIRE_THROWS_AS(b1.get(6), IndexOutOfBounds);
}
