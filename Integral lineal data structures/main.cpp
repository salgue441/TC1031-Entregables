/**
 * @file main.cpp
 * @author Carlos Salguero
 * @author Daniel Hurtado
 * @brief Driver code of the program
 * @version 0.1
 * @date 2022-10-16
 *
 * @copyright Copyright (c) 2022
 */

#include <iostream>
#include <fstream>
#include <vector>

#include "boat.cpp"
#include "header.h"

// function prototypes
std::string read_file(std::fstream &, std::vector<Boat *> &);
void write_data(std::fstream &, std::vector<Boat *> &);
void selection_sort(std::vector<Boat *> &);

// Driver code
int main(int argc, char **argv)
{
    if (argc != 3)
    {
        std::cout << "Argument number is not the required."
                  << std::endl;
        return -1;
    }

    std::fstream input_file(argv[1], std::ios::in),
        output_file(argv[2], std::ios::out);

    if (input_file.fail() || output_file.fail())
    {
        std::cout << "Error processing file."
                  << std::endl;
        return -1;
    }

    std::vector<Boat *> boats_data;
    std::string prefix = read_file(input_file, boats_data);

    // sorting the data
    selection_sort(boats_data);

    // writing into output files
    write_data(output_file, boats_data);

    input_file.close();
    output_file.close();
}

/**
 * @brief
 * Reads the input data from the file and saves them in a vector.
 * @param input_file         File containing the inputs.
 * @param boats_data         Vector where data is going to be saved.
 * @return prefix            Prefix used when sorting.
 */
std::string read_file(std::fstream &input_file,
                      std::vector<Boat *> &boats_data)
{
    int boat_count{};
    std::string prefix, boat_date, boat_hour, boat_entry, boat_id;

    input_file >> boat_count >> prefix;

    for (size_t i{}; i < boat_count; ++i)
    {
        std::getline(input_file, boat_date, ' ');
        std::getline(input_file, boat_hour, ' ');
        std::getline(input_file, boat_entry, ' ');
        std::getline(input_file, boat_id);

        if (boat_id.rfind(prefix, 0) == 0)
            boats_data.push_back(new Boat(boat_date, boat_hour,
                                          boat_entry, boat_id));
    }

    return prefix;
}

/**
 * @brief
 * Writes filtered vector with the desired format into the
 * output file.
 * @param output_file          File where values are going to be stored.
 * @param boats_data           Vector containing all the objects.
 */
void write_data(std::fstream &output_file,
                std::vector<Boat *> &boats_data)
{
    std::string months[] = {"jan", "feb", "mar", "apr",
                            "may", "jun", "jul", "aug",
                            "sep", "oct", "nov", "dec"};
    std::vector<Boat *> med_sea, red_sea;

    for (size_t mon{}; mon < 12; ++mon)
    {
        for (auto *elem : boats_data)
        {
            if (elem->get_tm().tm_mon > mon)
                break;

            else if (elem->get_tm().tm_mon == mon)
            {
                if (elem->get_entry_point().rfind("M", 0) == 0)
                    med_sea.push_back(elem);
                else
                    red_sea.push_back(elem);
            }
        } // end of ranged-based loop

        output_file << months[mon] << std::endl;

        if (med_sea.size() > 0)
        {
            output_file << "M " << med_sea.size() << ": ";

            for (const auto &elem : med_sea)
                output_file << elem->get_boat_id() << " ";

            output_file << std::endl;
        }

        if (red_sea.size() > 0)
        {
            output_file << "R " << red_sea.size() << ": ";

            for (const auto &elem : red_sea)
                output_file << elem->get_boat_id() << " ";

            output_file << std::endl;
        }

        med_sea.clear();
        red_sea.clear();
    } // end of month for loop
}

/**
 * @brief
 * Sorts the vector according to the timestamp assigned.
 * @param boats_vec           Vector containing all the boats data.
 */
void selection_sort(std::vector<Boat *> &boats_vec)
{
    int pos{};

    for (size_t i{}; i < boats_vec.size() - 1; ++i)
    {
        pos = i;

        for (size_t j{i + 1}; j < boats_vec.size(); ++j)
            if (boats_vec[j]->get_time_stamp() <
                boats_vec[pos]->get_time_stamp())
                pos = j;

        if (pos != i)
            swap(boats_vec, i, pos);
    }
}