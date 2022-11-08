#define CATCH_CONFIG_MAIN
#include <iostream>
#include <fstream>
#include "catch.h"
#include "activity.h"

using namespace std;

TEST_CASE("testing exercise 3", "[exercise3]") {
	int n, from, to;
	ifstream input;
	UListGraph<int> *graph;

	input.open("input4.txt");
	input >> n;
	graph = new UListGraph<int>(n);

	while (1) {
		input >> from >> to;
		if (!from && !to) {
			break;
		}
		graph->addEdge(from, to);
	}

	REQUIRE(topologicalSort(graph) == "[1 4 3 2]");
	REQUIRE(isBipartite(graph) == true);
	REQUIRE(isTree(graph) == true);

	delete graph;
}
