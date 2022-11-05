/**
 * @file UList_Graph.cpp
 * @author Carlos Salguero
 * @brief Declaration of Unweighted List Graph Class
 * @version 0.1
 * @date 2022-11-04
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "UList_Graph.h"

// Constructor
/**
 * @brief
 * Construct a new ulist graph<vertex>::ulist graph object
 * @tparam Vertex  Type of vertex
 * @param dir Direction of the graph
 */
template <class Vertex>
UList_Graph<Vertex>::UList_Graph(std::optional<bool> dir)
    : direction{dir.value_or(true)} {};

// Access Methods
/**
 * @brief
 * Get the direction of the graph
 * @tparam Vertex  Type of vertex
 * @return true
 * @return false
 */
template <class Vertex>
bool UList_Graph<Vertex>::get_direction() const
{
    return direction;
}

/**
 * @brief
 * Get the vertices of the graph
 * @tparam Vertex  Type of vertex
 * @return std::vector<Vertex>
 */
template <class Vertex>
std::vector<Vertex> UList_Graph<Vertex>::get_vertices() const
{
    return vertexes;
}

/**
 * @brief
 * Get the neighbors of a vertex
 * @tparam Vertex  Type of vertex
 * @param v Vertex
 * @return std::set<Vertex>
 */
template <class Vertex>
std::set<Vertex> UList_Graph<Vertex>::get_neighbors(Vertex v) const
{
    return edges.at(v);
}

// Operator Overload
/**
 * @brief
 * Overload the << operator
 * @tparam Vertex  Type of vertex
 * @param out Output stream
 * @param graph Graph
 * @return std::ostream&
 */
template <class Vertex>
std::ostream &operator<<(std::ostream &out, const UList_Graph<Vertex> &graph)
{
    for (auto &vertex : graph.vertexes)
    {
        out << vertex << " -> ";

        for (auto &neighbor : graph.edges.at(vertex))
            out << neighbor << " ";

        out << std::endl;
    }

    return out;
}

// Functions
/**
 * @brief
 * Add an edge to the graph
 * @tparam Vertex  Type of vertex
 * @param from_vertex From vertex
 * @param to_vertex To vertex
 * @complexity O(1)
 */
template <class Vertex>
void UList_Graph<Vertex>::add_edge(Vertex from_vertex, Vertex to_vertex)
{
    vertexes.insert(from_vertex);
    vertexes.insert(to_vertex);

    edges[from_vertex].insert(to_vertex);

    if (!direction)
        edges[to_vertex].insert(from_vertex);
}

/**
 * @brief
 * Check if the graph contains an edge
 * @tparam Vertex  Type of vertex
 * @param from_vertex From vertex
 * @return true
 * @return false
 * @complexity O(1)
 */
template <class Vertex>
bool UList_Graph<Vertex>::contains_edge(Vertex from_vertex) const
{
    return edges.find(from_vertex) != edges.end();
}

/**
 * @brief
 * Depth First Search
 * @tparam Vertex  Type of vertex
 * @param start_vertex Start vertex
 * @param graph Graph
 * @return std::set<Vertex>
 * @complexity O(1)
 */
template <class Vertex>
std::set<Vertex> UList_Graph<Vertex>::dfs(const Vertex &start_vertex,
                                          const std::unique_ptr<U_Graph<Vertex>> graph) const
{
    std::set<Vertex> visited;
    std::stack<Vertex> stack;

    stack.push(start_vertex);

    while (!stack.empty())
    {
        Vertex vertex = stack.top();
        stack.pop();

        if (visited.find(vertex) == visited.end())
        {
            visited.insert(vertex);

            for (auto &neighbor : graph->get_neighbors(vertex))
                stack.push(neighbor);
        }
    }

    return visited;
}

/**
 * @brief
 * Breadth First Search
 * @tparam Vertex  Type of vertex
 * @param start_vertex Start vertex
 * @param graph Graph
 * @return std::set<Vertex>
 * @complexity O(1)
 */
template <class Vertex>
std::set<Vertex> UList_Graph<Vertex>::bfs(const Vertex &start_vertex,
                                          const std::unique_ptr<U_Graph<Vertex>> graph) const
{
    std::set<Vertex> visited;
    std::queue<Vertex> queue;

    queue.push(start_vertex);

    while (!queue.empty())
    {
        Vertex vertex = queue.front();
        queue.pop();

        if (visited.find(vertex) == visited.end())
        {
            visited.insert(vertex);

            for (auto &neighbor : graph->get_neighbors(vertex))
                queue.push(neighbor);
        }
    }

    return visited;
}