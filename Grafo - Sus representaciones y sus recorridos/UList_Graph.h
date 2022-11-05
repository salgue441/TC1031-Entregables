/**
 * @file UList_Graph.h
 * @author Carlos Salguero
 * @brief Declaration of Unweighted List Graph Class
 * @version 0.1
 * @date 2022-11-04
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef ULIST_GRAPH_H
#define ULIST_GRAPH_H

#include <vector>
#include <stack>
#include <queue>
#include <optional>
#include <memory>
#include <map>

#include "graph.h"

template <class Vertex>
class UList_Graph : public U_Graph
{
public:
    // Constructor
    UList_Graph() = default;
    UList_Graph(std::optional<bool> direction = true);

    // Destructor
    ~UList_Graph() = default;

    // Access Methods
    bool get_direction() const;
    std::vector<Vertex> get_vertices() const;
    std::set<Vertex> get_neighbors(Vertex v) const;

    // Operator overload
    friend std::ostream &operator<<(std::ostream &out,
                                    const UList_Graph<Vertex> &graph);

    // Functions
    void add_edge(Vertex from_vertex, Vertex to_vertex);
    bool contains_edge(Vertex from_vertex) const;

    std::set<Vertex> dfs(const Vertex &,
                         const std::unique_ptr<U_Graph<Vertex>>) const;
    std::set<Vertex> bfs(const Vertex &,
                         const std::unique_ptr<U_Graph<Vertex>>) const;

private:
    bool direction;
    std::set<Vertex> vertexes;
    std::map<Vertex, std::set<Vertex>> edges;
};

#endif //! ULIST_GRAPH_H