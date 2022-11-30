/**
 * @file UGraph.cpp
 * @author Carlos Salguero
 * @author Sergio Garnica
 * @author Sven Chavez
 * @brief implementation of the Unweighted Graph class.
 * @version 0.1
 * @date 2022-11-12
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "UGraph.h"

// Access Methods
/**
 * @brief
 * Gets the adjacency list of the graph
 * @tparam graph_t Type of the graph
 * @return std::map<graph_t, std::set<graph_t>> adjacency list of the graph
 */
template <class graph_t>
std::map<graph_t, std::set<graph_t>> UGraph<graph_t>::get_adjacency_list() const
{
    std::map<graph_t, std::set<graph_t>> adjacency_list;

    for (auto &adjacent : adjacent_list)
    {
        std::set<graph_t> set(adjacent.second.begin(), adjacent.second.end());
        adjacency_list.insert({adjacent.first, set});
    }

    return adjacency_list;
}

/**
 * @brief
 * Gets the visited set of the graph
 * @tparam graph_t Type of the graph
 * @return std::set<graph_t> visited set of the graph
 */
template <class graph_t>
std::map<graph_t, bool> UGraph<graph_t>::get_visited() const
{
    return visited;
}

/**
 * @brief
 * Gets the parent map of the graph
 * @tparam graph_t Type of the graph
 * @return std::map<graph_t, graph_t> parent map of the graph
 */
template <class graph_t>
std::map<graph_t, graph_t> UGraph<graph_t>::get_parent() const
{
    return parent;
}

/**
 * @brief
 * Gets the distance map of the graph
 * @tparam graph_t Type of the graph
 * @return std::map<graph_t, int> distance map of the graph
 */
template <class graph_t>
std::map<graph_t, int> UGraph<graph_t>::get_distance() const
{
    return distance;
}

/**
 * @brief
 * Gets the mnp map of the graph
 * @tparam graph_t Type of the graph
 * @return std::map<graph_t, int> mnp map of the graph
 */
template <class graph_t>
std::map<graph_t, int> UGraph<graph_t>::get_mnp() const
{
    return mnp;
}

// Operator overload
/**
 * @brief
 * Overloads the << operator to print the graph
 * @tparam ostream_t Type of the graph
 * @param os Output stream
 * @param graph Graph to be printed
 * @return std::ostream& Output stream
 */
template <class ostream_t>
std::ostream &operator<<(std::ostream &os, const UGraph<ostream_t> &graph)
{
    for (auto &adjacent : graph.adjacent_list)
    {
        os << adjacent.first << " -> ";

        for (auto &vertex : adjacent.second)
            os << vertex << " ";

        os << std::endl;
    }
    return os;
}

// Public Functions
/**
 * @brief
 * Adds an edge to the graph
 * @tparam graph_t Type of the graph
 * @param vertex1 First vertex of the edge
 * @param vertex2 Second vertex of the edge
 */
template <class graph_t>
void UGraph<graph_t>::add_edge(const graph_t &vertex1,
                               const graph_t &vertex2)
{
    adjacent_list[vertex1].push_back(vertex2);
    adjacent_list[vertex2].push_back(vertex1);
}

/**
 * @brief
 * Removes an edge from the graph
 * @tparam graph_t Type of the graph
 * @param vertex1 First vertex of the edge
 * @param vertex2 Second vertex of the edge
 */
template <class graph_t>
void UGraph<graph_t>::remove_edge(const graph_t &vertex1,
                                  const graph_t &vertex2)
{
    adjacent_list[vertex1].erase(vertex2);
    adjacent_list[vertex2].erase(vertex1);
}

/**
 * @brief
 * Adds a vertex to the graph
 * @tparam graph_t Type of the graph
 * @param vertex Vertex to be added
 */
template <class graph_t>
void UGraph<graph_t>::add_vertex(const graph_t &vertex)
{
    adjacent_list[vertex];
}

/**
 * @brief
 * Removes a vertex from the graph
 * @tparam graph_t Type of the graph
 * @param vertex Vertex to be removed
 */
template <class graph_t>
void UGraph<graph_t>::remove_vertex(const graph_t &vertex)
{
    for (auto &adjacent : adjacent_list)
        adjacent.second.erase(vertex);

    adjacent_list.erase(vertex);
}

/**
 * @brief
 * Resets the graph.
 */
template <class graph_t>
void UGraph<graph_t>::reset()
{
    this->distance.clear();
    this->parent.clear();
    this->visited.clear();
}

// Traversal Algorithms
/**
 * @brief
 * Performs a BFS traversal of the graph
 * @tparam graph_t Type of the graph
 * @param start Starting vertex of the traversal
 */
template <class graph_t>
void UGraph<graph_t>::bfs(const graph_t &start)
{
    std::queue<graph_t> queue;

    queue.push(start);
    visited[start] = true;
    distance[start] = 0;

    while (!queue.empty())
    {
        graph_t vertex = queue.front();
        queue.pop();

        for (auto &adjacent : adjacent_list[vertex])
        {
            if (!visited[adjacent])
            {
                queue.push(adjacent);
                visited[adjacent] = true;
                distance[adjacent] = distance[vertex] + 1;
                parent[adjacent] = vertex;
            } // comparison
        }     // inner for loop
    }         // outer while loop
}