/**
 * @file UMatrix_graph.h
 * @author Carlos Salguero
 * @brief Declaration of Unweighted Matrix Graph Class
 * @version 0.1
 * @date 2022-11-04
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef U_MATRIX_GRAPH_H
#define U_MATRIX_GRAPH_H

#include <vector>
#include <stack>    // for dfs function implementation
#include <queue>    // for bfs function implementation
#include <optional> // C++17 module, used for optional value
#include <memory>   // C++11 module, used for smart pointers

#include "graph.h"

template <class Vertex>
class UMatrix_graph : public U_Graph<Vertex>
{
public:
    // Constructor
    UMatrix_graph() = default;
    UMatrix_graph(int, std::optional<bool> o_direction = true);

    // Destructor
    ~UMatrix_graph() = default;

    // Access Methods
    int get_next() const;
    int get_size() const;
    bool get_direction() const;

    std::vector<Vertex> get_vertexes() const override;
    std::set<Vertex> get_neighbours(Vertex) const override;

    // Operator overload
    template <class T>
    friend std::ostream &operator<<(std::ostream &,
                                    const UMatrix_graph<T> &);

    // Funtions
    void add_edge(Vertex, Vertex) override;
    bool contains_vertex(Vertex) const override;

    std::set<Vertex> dfs(const Vertex &,
                         const std::unique_ptr<U_Graph<Vertex>>) const;
    std::set<Vertex> bfs(const Vertex &,
                         const std::unique_ptr<U_Graph<Vertex>>) const;

private:
    int next, size;
    bool direction;
    std::vector<Vertex> vertexes;
    std::vector<std::vector<bool>> edges;

    // private functions
    int index_of(Vertex) const;
};

#endif //! U_MATRIX_GRAPH_H