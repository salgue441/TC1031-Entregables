/**
 * @file boat.cpp
 * @author Carlos Salguero
 * @author Daniel Hurtado
 * @brief Boat class initialization
 * @version 0.1
 * @date 2022-10-16
 *
 * @copyright Copyright (c) 2022
 */

#pragma once

#include "boat.h"

// Constructor
Boat::Boat(std::string_view c_date, std::string_view c_hour,
           std::string_view c_entry, std::string_view c_id)
    : date(c_date), hour(c_hour), entry_point(c_entry),
      boat_id(c_id)
{
    time_stamp = date_format(tm, date);
}

// Access Methods
std::string Boat::get_date() const { return date; }
std::string Boat::get_hour() const { return hour; }
std::string Boat::get_entry_point() const { return entry_point; }
std::string Boat::get_boat_id() const { return boat_id; }
time_t Boat::get_time_stamp() const { return time_stamp; }
struct std::tm Boat::get_tm() const { return tm; }

// Operator overload
/**
 * @brief
 * Overload of output operator for easir output.
 * @param os          data stream
 * @param boat        object from desired class
 * @return std::ostream& overloaded operator.
 */
std::ostream &operator<<(std::ostream &os, const Boat &boat)
{
    os << boat.time_stamp << " "
       << boat.date << " "
       << boat.hour << " "
       << boat.entry_point << "  "
       << boat.boat_id;

    return os;
}

/**
 * @brief
 *
 * @param other_boat
 * @return true
 * @return false
 */
bool Boat::operator>(const Boat &other_boat)
{
    return (this->get_time_stamp() > other_boat.get_time_stamp());
}

// Functions
/**
 * @brief
 * Converts from string to timestamp.
 * @param tm            struct std::tm, used for conversion
 * @param date          string to be converted
 * @return timestamp
 */
time_t Boat::date_format(struct std::tm &tm,
                         const std::string_view date)
{
    std::string date_str(date.data(), date.size());
    date_str.erase(remove(date_str.begin(), date_str.end(), '\n'),
                   date_str.cend());

    std::istringstream ss(date_str);
    ss >> std::get_time(&tm, "%d-%m-%y");

    std::time_t time = std::mktime(&tm);
    return time;
}