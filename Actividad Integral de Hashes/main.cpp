/**
 * @file main.cpp
 * @author Carlos Salguero
 * @author Sergio Garnica
 * @author Sven Chavez
 * @brief Main file for the project
 * @version 0.1
 * @date 2022-11-22
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <map>

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		std::cout << "Usage: " << argv[0] << " <input file> <output file>"
				  << std::endl;
		return -1;
	}

	std::ifstream input(argv[1], std::ios::in);
	if (!input.is_open())
	{
		std::cout << "Error opening input file" << std::endl;
		return -1;
	}

	std::ofstream output(argv[2], std::ios::out);
	if (!output.is_open())
	{
		std::cout << "Error opening output file" << std::endl;
		return -1;
	}

	int num_lines, num_jobs;
	input >> num_lines >> num_jobs;

	std::map<std::string, int> jobs;

	for (int i = 0; i < num_lines; i++)
	{
		std::string job;
		int time;

		input >> job >> time;
		jobs[job] = time;
	}

	for (int i = 0; i < num_jobs; i++)
	{
		std::string job;
		int weight = 0;

		while (input >> job)
		{
			if (job == ".")
				break;

			weight += jobs[job];
		}

		output << weight << std::endl;
	}

	input.close();
	output.close();
}