/**
 * @file boat.h
 * @author Carlos Salguero
 * @author Daniel Hurtado
 * @brief Boat class declaration
 * @version 0.1
 * @date 2022-10-16
 *
 * @copyright Copyright (c) 2022
 */

#ifndef BOAT_H
#define BOAT_H

#include <string>
#include <vector>
#include <ctime>       // std::tm , std::mktime(), and time_t
#include <algorithm>   // remove()
#include <iomanip>     // std::get_time()
#include <string_view> // copying strings

#include "header.h"

class Boat
{
public:
    // Constructor
    Boat() = default;
    Boat(std::string_view, std::string_view, std::string_view,
         std::string_view); // params constructor

    // Destructor
    ~Boat() = default;

    // Access Methods
    std::string get_date() const;
    std::string get_hour() const;
    std::string get_entry_point() const;
    std::string get_boat_id() const;
    time_t get_time_stamp() const;
    struct std::tm get_tm() const;

    // Operator overload
    friend std::ostream &operator<<(std::ostream &,
                                    const Boat &);
    bool operator>(const Boat &);

    // Functions
    time_t date_format(struct std::tm &, const std::string_view);

private:
    std::string date, hour, entry_point, boat_id;
    time_t time_stamp;
    struct std::tm tm = {0};
};

#endif //! BOAT_H