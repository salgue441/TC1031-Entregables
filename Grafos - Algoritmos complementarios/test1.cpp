#define CATCH_CONFIG_MAIN
#include <iostream>
#include <fstream>
#include "catch.h"
#include "activity.h"

using namespace std;

TEST_CASE("testing exercise 1", "[exercise1]") {
	int n, from, to;
	ifstream input;
	UListGraph<int> *graph;

	input.open("input1.txt");
	input >> n;
	graph = new UListGraph<int>(n);

	while (1) {
		input >> from >> to;
		if (!from && !to) {
			break;
		}
		graph->addEdge(from, to);
	}

	REQUIRE(topologicalSort(graph) == "[1 2 3 4 5 12 8 6 10 7 9 13 11 15 16 14 19 17 20 18]");
	REQUIRE(isBipartite(graph) == false);
	REQUIRE(isTree(graph) == false);

	delete graph;
}
