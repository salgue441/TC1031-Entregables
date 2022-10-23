#include <iostream>

#include "heap.cpp"

int main()
{
    Heap<int> heap_structure;
    Heap<int> empty_heap_structure;

    // Showing push() functionality
    heap_structure.push(1);
    heap_structure.push(2);
    heap_structure.push(3);
    heap_structure.push(4);
    heap_structure.push(5);
    heap_structure.push(6);
    heap_structure.push(7);
    heap_structure.push(8);
    heap_structure.push(9);
    heap_structure.push(10);
    heap_structure.push(11);

    // showing is_empty() functionality
    (heap_structure.is_empty())
        ? std::cout << "Heap structure is empty" << std::endl
        : std::cout << "Heap structure is not empty." << std::endl;

    (empty_heap_structure.is_empty())
        ? std::cout << "Heap structure is empty" << std::endl
        : std::cout << "Heap structure is not empty" << std::endl;

    // showing size(), top() functionality
    std::cout << heap_structure.heap_elements() << std::endl;
    std::cout << "Size: " << heap_structure.get_size() << std::endl;
    std::cout << "Top value: " << heap_structure.get_top() << std::endl;

    // showing pop functionality
    heap_structure.pop();
    heap_structure.pop();

    // showing size(), top() functionality after pop()
    std::cout << heap_structure.heap_elements() << std::endl;
    std::cout << "Size: " << heap_structure.get_size() << std::endl;
    std::cout << "Top value: " << heap_structure.get_top() << std::endl;
}