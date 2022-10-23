/**
 * @file heap.h
 * @author Carlos Salguero
 * @brief Declaration of heap class
 * @version 0.1
 * @date 2022-10-23
 *
 * @copyright Copyright (c) 2022
 */

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
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
    Heap(const Heap<T> &); // copy constructor

    // Destructor
    ~Heap() = default;

    // Access Methods
    T get_size() const;
    T get_top() const;

    // Functions
    bool is_empty() const;
    void push(T);
    void pop();

    std::string heap_elements() const;

private:
    std::vector<T> elements;

    // Access Method
    unsigned int get_parent(unsigned int) const;
    unsigned int get_left_leaf(unsigned int) const;
    unsigned int get_right_leaf(unsigned int) const;

    // Functions
    void swap(unsigned int, unsigned int);
    void push_up(unsigned int);
};

#endif //! HEAP_H