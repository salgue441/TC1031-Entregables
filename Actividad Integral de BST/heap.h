/**
 * @file heap.h
 * @author Carlos Salguero
 * @brief Declaration of Heap data structure
 * @version 0.1
 * @date 2022-11-16
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef HEAP_H
#define HEAP_H

#include <string>
#include <sstream>
#include <vector>
#include <climits>

template <class T>
class Heap
{
public:
    // Constructor
    Heap() = default;

    // Destructor
    ~Heap() = default;

    // Access Methods
    int get_size() const;
    std::vector<T> get_data() const;

    // Operator Overload
    template <class ostream_t>
    friend std::ostream &operator<<(std::ostream &, const Heap<ostream_t> &);

    // Functions
    void push(T);
    void clear();

    T pop_front();

    bool is_empty() const;
    bool is_full() const;

private:
    std::vector<T> data;

    // Private Access Methods
    unsigned int get_parent(unsigned int) const;
    unsigned int get_left_child(unsigned int) const;
    unsigned int get_right_child(unsigned int) const;

    // Private Functions
    void heapify(unsigned int);
    void swap(T, T);
    void insert(T);

    T remove();
};

#endif //! HEAP_H