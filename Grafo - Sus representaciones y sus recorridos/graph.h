/**
 * @file graph.h
 * @author Carlos Salguero
 * @brief Declaration of Unweighted Graph Interface
 * @version 0.1
 * @date 2022-11-04
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <set>

template <class Vertex>
class U_Graph
{
public:
    // Access Methods
    virtual std::vector<Vertex> get_vertexes() const = 0;
    virtual std::set<Vertex> get_neighbours(Vertex) const = 0;

    // Funtions
    virtual void add_edge(Vertex, Vertex) = 0;
    virtual bool contains_vertex(Vertex) const = 0;
};

#endif // !GRAPH_H