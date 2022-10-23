/**
 * @file heap.cpp
 * @author Carlos Salguero
 * @brief Implementation of Heap class
 * @version 0.1
 * @date 2022-10-23
 *
 * @copyright Copyright (c) 2022
 */

#include "heap.h"

// Constructor
/**
 * @brief
 * Copies Heap< T>:: Heap object into current object.
 * @tparam T              Class allowed data types.
 * @param other           Other heap structure to be copied.
 */
template <class T>
Heap<T>::Heap(const Heap<T> &other) : elements(other.elements){};

// Private Access Methods
/**
 * @brief
 * Returns the position of the parent of an element.
 * @tparam T             Class allowed data types.
 * @param position       Index of the child element.
 * @return unsigned int, index of the parent.
 */
template <class T>
unsigned int Heap<T>::get_parent(unsigned int position) const
{
    return (position - 1) / 2;
}

/**
 * @brief
 * Returns the position of the left child of an element.
 * @tparam T             Class allowed data types.
 * @param position       Index of the element.
 * @return unsigned int, Index of the left child.
 */
template <class T>
unsigned int Heap<T>::get_left_leaf(unsigned int position) const
{
    return (position * 2) + 1;
}

/**
 * @brief
 * Returns the position of the right child of an element.
 * @tparam T             Class allowed data types.
 * @param position       Index of the element.
 * @return unsigned int, Index of the right child.
 */
template <class T>
unsigned int Heap<T>::get_right_leaf(unsigned int position) const
{
    return (position * 2) + 2;
}

// Public Acess Methods
/**
 * @brief
 * Returns the size of the heap binary tree.
 * @tparam T        Class allowed data types
 * @return Size of the heap.
 * @complexity      O(1)
 */
template <class T>
T Heap<T>::get_size() const { return elements.size(); }

/**
 * @brief
 * Returns the most significant element from the heap binary tree (top node).
 * @tparam T        Class allowed data types.
 * @return If heap is empty returns INT_MAX, else first element.
 * @complexity      O(1)
 */
template <class T>
T Heap<T>::get_top() const
{
    if (is_empty())
        return INT_MAX;

    return elements[0];
}

// Private Functions
/**
 * @brief
 * Swaps the content of two locations.
 * @tparam T            Class allowed data types.
 * @param first         First index to be swapped.
 * @param second        Second index to be swapped.
 */
template <class T>
void Heap<T>::swap(unsigned int first, unsigned int second)
{
    T temporal = elements[first];
    elements[first] = elements[second];
    elements[second] = temporal;
}

/**
 * @brief
 * Places the item in the correct position. Being a max-heap, the elements
 * must be greater than its children. If not, recursively perform the push_up.
 * @tparam T            Class allowed data types.
 * @param position      The current position of the item being inserted.
 * @complexity          O(1)
 */
template <class T>
void Heap<T>::push_up(unsigned int position)
{
    unsigned int left_leaf = get_left_leaf(position),
                 right_leaf = get_right_leaf(position),
                 smallest_value = position;

    if (left_leaf < elements.size() &&
        elements[left_leaf] > elements[position])
        smallest_value = left_leaf;

    if (right_leaf < elements.size() &&
        elements[right_leaf] > elements[position])
        smallest_value = right_leaf;

    if (position != smallest_value)
    {
        swap(position, smallest_value);
        push_up(smallest_value);
    }
}

// Public Functions
/**
 * @brief
 * Returns if the heap is empty or not.
 * @tparam T      Class allowed data types.
 * @return true   if the heap is empty,
 * @return false  otherwise
 * @complexity    O(1)
 */
template <class T>
bool Heap<T>::is_empty() const
{
    return elements.empty();
}

/**
 * @brief
 * Adds an element to the heap. It's first inserted as the last element of the
 * vector. Then, it's verified if the new value is less significant that its
 * father element. If the condition is true, the values are exchanged.
 * @tparam T         Class allowed data types.
 * @param value      Value to be inserted in the heap structure.
 * @complexity       O(n)
 */
template <class T>
void Heap<T>::push(T value)
{
    elements.push_back(value);
    unsigned int position = elements.size() - 1;

    while (position > 0 && value > elements[get_parent(position)])
    {
        swap(position, get_parent(position));
        position = get_parent(position);
    }
}

/**
 * @brief
 * Pops the most significant element from the heap structure.
 * @tparam T     Class allowed data types.
 * @complexity   O(1)
 */
template <class T>
void Heap<T>::pop()
{
    if (is_empty())
        return;

    elements[0] = elements[elements.size() - 1];
    elements.pop_back();
    push_up(0);
}

/**
 * @brief
 * Auxiliary function. Shows the elements from the heap structure as strings.
 * @tparam T           Class allowed data types.
 * @return stream with all the values shown as strings.
 */
template <class T>
std::string Heap<T>::heap_elements() const
{
    std::stringstream heap_data;

    for (const auto &elem : elements)
        heap_data << elem << " ";

    return heap_data.str();
}