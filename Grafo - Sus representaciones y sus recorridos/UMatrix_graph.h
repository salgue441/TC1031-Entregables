/**
 * @file UMatrix_graph.h
 * @author Carlos Salguero
 * @brief Declaration of Unweighted Matrix Graph
 * @version 0.1
 * @date 2022-11-09
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef UMATRIX_GRAPH_H
#define UMATRIX_GRAPH_H

#include <vector>
#include <sstream>  // for file handling
#include <set>      // for std::set
#include <stack>    // implemented in dfs function
#include <queue>    // implemented in bfs function
#include <optional> // used for optional values encapsulation
#include <memory>   // used for smart pointers

template <class Vertex>
class UMatrix_graph
{
public:
    // Constructor
    UMatrix_graph() = default;
    UMatrix_graph(unsigned int, std::optional<bool> c_direction = true);

    // Destructor
    ~UMatrix_graph() = default;

    // Access Methods
    int get_next() const;
    unsigned int get_size() const;
    bool get_direction() const;

    std::vector<Vertex> get_vertexes() const;
    std::set<Vertex> get_neighbours(Vertex) const;

    // operator overload
    template <class overload>
    friend std::ostream &operator<<(std::ostream &,
                                    const std::shared_ptr<UMatrix_graph<overload>> &);

    // Functions
    void load_graph(int, std::fstream &);
    void add_edge(Vertex, Vertex);
    void remove_edge(Vertex, Vertex);
    void add_vertex(Vertex);
    void remove_vertex(Vertex);

    bool contains_vertex(Vertex) const;
    bool contains_edge(Vertex, Vertex) const;

    std::set<Vertex> dfs(const Vertex &) const;
    std::set<Vertex> bfs(const Vertex &) const;

private:
    unsigned int size;
    int next;
    bool direction;
    std::vector<Vertex> vertexes;
    std::vector<std::vector<bool>> edges;

    // private functions
    Vertex index_of(Vertex) const;
    bool is_edge(Vertex, Vertex) const;
    bool is_vertex(Vertex) const;
};

#endif //! UMATRIX_GRAPH_H