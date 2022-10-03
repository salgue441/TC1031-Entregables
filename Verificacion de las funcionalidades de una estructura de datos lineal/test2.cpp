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

TEST_CASE("testing after", "[DoubleLinkedList]")
{
	DoubleLinkedList<int> b1;
	b1.push_front(7);
	b1.push_front(6);
	b1.push_front(5);
	b1.push_front(4);
	b1.push_front(3);
	b1.push_front(2);

	REQUIRE(b1.after(2) == 3);
	REQUIRE(b1.after(4) == 5);
	REQUIRE_THROWS_AS(b1.after(7), NoSuchElement);
	REQUIRE_THROWS_AS(b1.after(10), NoSuchElement);
}
