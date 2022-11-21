/**
 * @file main.cpp
 * @author Carlos Salguero
 * @brief Main file
 * @version 0.1
 * @date 2022-11-09
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <fstream>
#include <memory>

#include "UMatrix_graph.cpp"

int main()
{
    std::fstream input_file("graph.txt", std::ios::in);

    if (!input_file)
    {
        std::cout << "Error opening file" << std::endl;
        return 1;
    }

    int first_line;
    input_file >> first_line;

    std::shared_ptr<UMatrix_graph<std::string>> graph =
        std::make_shared<UMatrix_graph<std::string>>(first_line);

    graph->add_edge("A", "B");
    graph->add_edge("A", "C");
    graph->add_edge("A", "D");
    graph->add_edge("A", "E");
    graph->add_edge("B", "C");
    graph->add_edge("B", "E");
    graph->add_edge("C", "D");
    graph->add_edge("C", "E");
    graph->add_edge("C", "A");
    graph->add_edge("D", "A");
    graph->add_edge("D", "F");
    graph->add_edge("D", "C");
    graph->add_edge("D", "B");
    graph->add_edge("E", "A");
    graph->add_edge("E", "B");
    graph->add_edge("E", "C");
    graph->add_edge("E", "D");
    graph->add_edge("E", "F");
    graph->add_edge("F", "D");
    graph->add_edge("F", "E");

    std::cout << graph << std::endl;
}