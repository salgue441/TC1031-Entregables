/**
 * @file heap.cpp
 * @author Carlos Salguero
 * @author Sven Chavez
 * @author Hossue Ceja
 * @brief Implementation of Heap data structures
 * @version 0.1
 * @date 2022-11-16
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "heap.h"

// Private Access Methods
/**
 * @brief
 * Get the parent of a node
 * @tparam T Type of data to be stored in the heap
 * @param index Index of the node
 * @return unsigned int Index of the parent
 * @complexity O(1)
 */
template <class T>
unsigned int Heap<T>::get_parent(unsigned int index) const
{
    return (index - 1) / 2;
}

/**
 * @brief
 * Get the left child of a node
 * @tparam T Type of data to be stored in the heap
 * @param index Index of the node
 * @return unsigned int Index of the left child
 * @complexity O(1)
 */
template <class T>
unsigned int Heap<T>::get_left_child(unsigned int index) const
{
    return (2 * index) + 1;
}

/**
 * @brief
 * Get the right child of a node
 * @tparam T Type of data to be stored in the heap
 * @param index Index of the node
 * @return unsigned int Index of the right child
 * @complexity O(1)
 */
template <class T>
unsigned int Heap<T>::get_right_child(unsigned int index) const
{
    return (2 * index) + 2;
}

// Access Methods
/**
 * @brief
 * Get the size of the heap
 * @tparam T Type of data to be stored in the heap
 * @return int Size of the heap
 * @complexity O(1)
 */
template <class T>
int Heap<T>::get_size() const
{
    return data.size();
}

/**
 * @brief
 * Get the data of the heap
 * @tparam T Type of data to be stored in the heap
 * @return std::vector<T> Data of the heap
 * @complexity O(1)
 */
template <class T>
std::vector<T> Heap<T>::get_data() const
{
    return data;
}

// Operator Overload
/**
 * @brief
 * Overload the << operator to print the heap
 * @tparam ostream_t Type of data to be stored in the heap
 * @param os Output stream
 * @param _heap Heap to be printed
 * @return std::ostream& Output stream
 * @complexity O(n)
 */
template <class ostream_t>
std::ostream &operator<<(std::ostream &os, const Heap<ostream_t> &_heap)
{
    for (auto &elem : _heap.data)
        os << elem << " ";

    return os;
}

// Private Functions
/**
 * @brief
 * Heapify the heap (min heap)
 * @tparam T Type of data to be stored in the heap
 * @param index Index of the node
 * @complexity O(log n)
 */
template <class T>
void Heap<T>::heapify(unsigned int index)
{
    unsigned int left_child = get_left_child(index),
                 right_child = get_right_child(index),
                 smallest = index;

    if (left_child < data.size() && data[left_child] < data[smallest])
        smallest = left_child;

    if (right_child < data.size() && data[right_child] < data[smallest])
        smallest = right_child;

    if (index != smallest)
    {
        swap(index, smallest);
        heapify(smallest);
    }
}

/**
 * @brief
 * Swap two elements in the heap
 * @tparam T Type of data to be stored in the heap
 * @param value_1 First element
 * @param value_2 Second element
 */
template <class T>
void Heap<T>::swap(T value_1, T value_2)
{
    T temp = data[value_1];
    data[value_1] = data[value_2];
    data[value_2] = temp;
}

/**
 * @brief
 * Insert an element into the heap
 * @tparam T Type of data to be stored in the heap
 * @param element Element to be inserted
 */
template <class T>
void Heap<T>::insert(T element)
{
    data.push_back(element);
    unsigned int position = data.size() - 1;

    while (position > 0 && element < data[get_parent(position)])
    {
        swap(position, get_parent(position));
        position = get_parent(position);
    }
}

/**
 * @brief
 * Remove the minimum element from the heap
 * @tparam T Type of data to be stored in the heap
 * @return T Minimum element
 * @complexity O(log n)
 */
template <class T>
T Heap<T>::remove()
{
    T min = data[0];
    data[0] = data[data.size() - 1];
    data.pop_back();
    heapify(0);

    return min;
}

// Public Functions
/**
 * @brief
 * Insert an element into the heap
 * @tparam T Type of data to be stored in the heap
 * @param element Element to be inserted
 */
template <class T>
void Heap<T>::push(T element)
{
    insert(element);
}

/**
 * @brief
 * Remove the minimum element from the heap
 * @tparam T Type of data to be stored in the heap
 * @return T Minimum element
 */
template <class T>
T Heap<T>::pop_front()
{
    return remove();
}

/**
 * @brief
 * Check if the heap is empty
 * @tparam T Type of data to be stored in the heap
 * @return true Heap is empty
 * @return false Heap is not empty
 * @complexity O(1)
 */
template <class T>
bool Heap<T>::is_empty() const
{
    return data.empty();
}

/**
 * @brief
 * Check if the heap is full
 * @tparam T Type of data to be stored in the heap
 * @return true Heap is full
 * @return false Heap is not full
 * @complexity O(1)
 */
template <class T>
bool Heap<T>::is_full() const
{
    return data.size() == data.max_size();
}