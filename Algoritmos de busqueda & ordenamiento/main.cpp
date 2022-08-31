/**
 * @file main.cpp
 * @author Carlos Salguero
 * @brief  Main file of the program.
 * @version 0.1
 * @date 2022-08-29
 * @copyright Copyright (c) 2022
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

#include "header.h"
#include "search.h"
#include "bubble.h"
#include "selection.h"
#include "insertion.h"

// function prototypes
void show_data(const std::vector<int> &);
void write_data(const std::fstream &output_file);

template <typename T>
int timing_algorithms(std::vector<T> &,
					  T (*sort_func)(std::vector<T> &));

template <typename T>
int timing_algorithms(T (*sort_func)(std::vector<T> &),
					  std::vector<T> &);

int main(int argc, char **argv)
{
	int num_datos, num_busqueda,
		steps_bubble, steps_selection, steps_insertion;
	std::vector<int> data_vec, search_data_vec;
	std::string data, data_searched;

	std::ifstream input_file(argv[1], std::ios::in);
	std::ofstream output_file(argv[2], std::ios::out);

	if (argc != 3)
	{
		std::cout << "Uso: " << argv[0] << "input.txt output.txt";
		return -1;
	}
	else if (input_file.fail())
	{
		std::cout << "No se pudo abrir el archivo";
		return -1;
	}
	else if (output_file.fail())
	{
		std::cout << "No se pudo abrir el archivo";
		return -1;
	}

	input_file >> num_datos;

	// lectura de los datos
	for (size_t i{}; i < num_datos; ++i)
	{
		std::getline(input_file, data, ' ');
		data_vec.push_back(std::stoi(data));
	}

	// ordenando el vector
	steps_bubble = timing_algorithms(data_vec, &bubbleSort);
	steps_selection = timing_algorithms(data_vec, &selectionSort);
	steps_insertion = timing_algorithms(&insertionSort, data_vec);

	output_file << steps_bubble << " "
				<< steps_selection << " "
				<< steps_insertion << std::endl
				<< std::endl;

	// filtrando por los datos
	input_file >> num_busqueda;

	std::pair<int, int> results{};

	for (size_t i{}; i < num_busqueda; ++i)
	{
		std::getline(input_file, data_searched, ' ');
		search_data_vec.push_back(std::stoi(data_searched));

		results = sequentialSearch(data_vec, search_data_vec[i]);
		output_file << results.first << " " << results.second << " ";

		results = binarySearch(data_vec, search_data_vec[i]);
		output_file << results.second << "\n";
	}

	input_file.close();
	output_file.close();
}

/**
 * @brief
 * Funcion auxiliar. Usada para mostrar los contenidos del vector.
 * @param data_vec         Vector con los datos de los input files.
 */
void show_data(const std::vector<int> &data_vec)
{
	for (const auto &elem : data_vec)
		std::cout << elem << " ";

	std::cout << std::endl;
}

/**
 * @brief
 * Se encarga de contar los pasos que toma cada algoritmo en ordenar
 * los datos.
 * @tparam T               Usado para el tipo de dato del vector.
 * @param data_vec         Vector con los datos del input file
 * @param sort_func        Algoritmo a utilizar
 * @return int             Tiempo tomado por el algoritmo
 */
template <typename T>
int timing_algorithms(std::vector<T> &data_vec,
					  T (*sort_func)(std::vector<T> &))
{
	std::vector<T> copy_vec = data_vec;
	int steps = sort_func(copy_vec);

	copy_vec.clear();

	return steps;
}

/**
 * @brief
 * Se encarga de contar los pasos que toma cada algoritmo en ordenar
 * los datos. La unica diferencia con la otra implementacion, es que
 * esta ordena el vector original.
 * @tparam T                Usado para el tipo de dato del vector.
 * @param sort_func         Algoritmo a utilizar.
 * @param data_vec          Vector con los datos.
 * @return int              Tiempo tomado con el algoritmo
 */
template <typename T>
int timing_algorithms(T (*sort_func)(std::vector<T> &),
					  std::vector<T> &data_vec)
{
	int steps = sort_func(data_vec);
	return steps;
}