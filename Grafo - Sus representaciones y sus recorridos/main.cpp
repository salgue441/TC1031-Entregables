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

    std::shared_ptr<UMatrix_graph<int>> graph =
        std::make_shared<UMatrix_graph<int>>(first_line);

    graph->load_graph(first_line, input_file);

    graph->dfs(1);
    graph->bfs(1);

    std::cout << graph << std::endl;
}