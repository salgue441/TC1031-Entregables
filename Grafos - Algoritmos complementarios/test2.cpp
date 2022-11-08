#define CATCH_CONFIG_MAIN
#include <iostream>
#include <fstream>
#include "catch.h"
#include "activity.h"

using namespace std;

TEST_CASE("testing exercise 2", "[exercise2]") {
	int n, from, to;
	ifstream input;
	UListGraph<int> *graph;

	input.open("input2.txt");
	input >> n;
	graph = new UListGraph<int>(n);

	while (1) {
		input >> from >> to;
		if (!from && !to) {
			break;
		}
		graph->addEdge(from, to);
	}

	REQUIRE(topologicalSort(graph) == "[0 1 4 8 2 5 3 6 7 9 11 12 13 10 15 14 16 17]");
	REQUIRE(isBipartite(graph) == false);
	REQUIRE(isTree(graph) == false);

	delete graph;
}
