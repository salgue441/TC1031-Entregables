/**
 * @file main.cpp
 * @author Carlos Salguero
 * @brief
 * @version 0.1
 * @date 2022-11-16
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <fstream>

#include "heap.cpp"

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		std::cout << "Usage: " << argv[0] << " <size> <file>" << std::endl;
		return 1;
	}

	std::fstream input_file(argv[1], std::ios::in);
	if (!input_file.is_open())
	{
		std::cout << "Error: Could not open file " << argv[1] << std::endl;
		return 1;
	}

	std::fstream output_file(argv[2], std::ios::out);
	if (!output_file.is_open())
	{
		std::cout << "Error: Could not open file " << argv[2] << std::endl;
		return 1;
	}

	int heap_size;
	input_file >> heap_size;

	Heap<int> heap;

	int value;
	for (int i = 0; i < heap_size; i++)
	{
		input_file >> value;
		heap.push(value);
	}

	int comparison{}, sum{};

	while (heap.get_size() > 1)
	{
		sum = heap.pop_front() + heap.pop_front();
		heap.push(sum);
		comparison += sum - 1;
	}

	output_file << comparison << std::endl;
}