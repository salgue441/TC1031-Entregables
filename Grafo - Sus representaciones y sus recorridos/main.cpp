/**
 * @file main.cpp
 * @author Carlos Salguero
 * @brief Main file of the program
 * @version 0.1
 * @date 2022-11-04
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>

#include "UMatrix_graph.cpp"

int main()
{
    UMatrix_graph<int> graph(5);

    graph.add_edge(0, 1);
    graph.add_edge(0, 2);
    graph.add_edge(1, 2);
    graph.add_edge(2, 0);
    graph.add_edge(2, 3);
    graph.add_edge(3, 3);
    graph.add_edge(4, 4);

    std::cout << graph;
}