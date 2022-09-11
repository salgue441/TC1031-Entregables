/**
 * @file main.cpp
 * @author Carlos Salguero
 * @author Daniel Hurtado
 * @brief  Main file of the program.
 * @version 0.1
 * @date 2022-09-06
 * @copyright Copyright (c) 2022
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <string_view>
#include <algorithm>
#include <iomanip>
#include <ctime>

#include "selection.h"

typedef struct Bitacora
{
	std::string fecha, hora,
		entrada, identificador;
	long long date;

} Registros;

// function prototypes
template <typename T>
void write_data(std::vector<T> &, std::string_view,
				std::fstream &);

template <typename T>
std::pair<int, std::string> read_file(std::fstream &,
									  std::vector<T> &);

long long date_format(const std::string_view);

int main(int argc, char **argv)
{
	std::vector<Bitacora> data_vec;

	std::fstream input_file(argv[1], std::ios::in);
	std::fstream output_file(argv[2], std::ios::out);

	if (argc != 3)
	{
		std::cout << "Numero de argumentos no cumple con el requerido. "
				  << "\nFormato: executable input_file output_file"
				  << std::endl;
		return -1;
	}
	else if (input_file.fail() || output_file.fail())
	{
		std::cout << "ERROR: no se pudo abrir el archivo."
				  << std::endl;
		return -1;
	}

	std::pair<int, std::string> primera_linea =
		read_file(input_file, data_vec);

	// filtrando el vector de acuerdo con las fechas
	selection_sort(data_vec);

	// guardado los datos
	write_data(data_vec, primera_linea.second, output_file);

	input_file.close();
	output_file.close();
}

/**
 * @brief
 * Se encarga de leer los datos de los input files y guardarlos en el vector
 * correspondiente.
 * @tparam T                Tipo de dato del vector
 * @param data_file         Archivo con los datos de entrada.
 * @param data_vec          Vector para guardar los datos del input file.
 * @return num_barcos       Numero de lineas leidas del archivo
 * @return prefix_ubi       Prefijo a encontrar en los identificadores
 */
template <typename T>
std::pair<int, std::string> read_file(std::fstream &data_file,
									  std::vector<T> &data_vec)
{
	Registros bitacora;
	std::string linea{}, prefix_ubi{};
	int num_barcos{};
	time_t formato_fecha{};

	data_file >> num_barcos >> prefix_ubi;

	for (size_t i{}; i < num_barcos; ++i)
	{
		std::getline(data_file, bitacora.fecha, ' ');
		std::getline(data_file, bitacora.hora, ' ');
		std::getline(data_file, bitacora.entrada, ' ');
		std::getline(data_file, bitacora.identificador);

		bitacora.date = date_format(bitacora.fecha);
		data_vec.push_back(bitacora);
	}

	return std::pair<int, std::string>(num_barcos, prefix_ubi);
}

/**
 * @brief
 * Usada para guardar los contenidos del vector en los archivos de
 * salida.
 * @tparam T               Tipo de dato del vector
 * @param data_vec         Vector con los datos de los input files.
 */
template <typename T>
void write_data(std::vector<T> &data_vec, std::string_view prefijo,
				std::fstream &output_file)
{
	std::string prefix(prefijo.data(), prefijo.size());

	for (size_t i{0}; i < data_vec.size(); ++i)
	{
		if (data_vec[i].identificador.rfind(prefix, 0) == 0)
		{
			// guardando los datos en el archivo
			output_file
				<< data_vec[i].fecha << " "
				<< data_vec[i].hora << " "
				<< data_vec[i].entrada << " "
				<< data_vec[i].identificador
				<< std::endl;
		}
	}
}

/**
 * @brief
 * Se encarga de convertir las fechas leidas como strings de los
 * input files a un timestamp.
 * @param input_string         String solo de lectura
 * @return Timestamp
 */
long long date_format(const std::string_view input_string)
{
	struct std::tm tm = {0};
	std::string date_string(input_string.data(), input_string.size());

	date_string.erase(remove(date_string.begin(),
							 date_string.end(), '\n'),
					  date_string.cend());

	std::istringstream ss(date_string);

	ss >> std::get_time(&tm, "%d-%m-%y");
	std::time_t time = std::mktime(&tm);

	return time;
}