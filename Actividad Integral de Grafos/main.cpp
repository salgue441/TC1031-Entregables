/**
 * @file main.cpp
 * @author Carlos Salguero
 * @brief Main file for the project
 * @version 0.1
 * @date 2022-11-12
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <fstream>
#include <string>

#include "UGraph.cpp"

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        std::cout << "Usage: " << argv[0] << " <input_file> <output_file>"
                  << std::endl;
        return 1;
    }

    std::fstream input_file(argv[1], std::ios::in);
    if (!input_file.is_open())
    {
        std::cout << "Error opening input file" << std::endl;
        return 1;
    }

    std::fstream output_file(argv[2], std::ios::out);
    if (!output_file.is_open())
    {
        std::cout << "Error opening output file" << std::endl;
        return 1;
    }

    int size{};
    input_file >> size;

    std::string port_1{}, port_2{};
    UGraph<std::string> graph;

    for (int i = 0; i < size; i++)
    {
        input_file >> port_1 >> port_2;
        graph.add_edge(port_1, port_2);
    }

    int num_queries{};
    input_file >> num_queries;

    int count{}, query_mnp{};
    std::string mnp_port{};

    for (int i = 0; i < num_queries; i++)
    {
        input_file >> mnp_port >> query_mnp;
        graph.get_mnp()[mnp_port] = query_mnp;
        graph.bfs(mnp_port);

        for (auto &port : graph.get_distance())
            if (port.second > query_mnp)
                count++;

        output_file << "Case " << i + 1 << ": "
                    << count << " ports not reachable from port "
                    << mnp_port << " with MNP = " << query_mnp
                    << "." << std::endl;

        // reset
        count = 0;
        graph.reset();
    }
}