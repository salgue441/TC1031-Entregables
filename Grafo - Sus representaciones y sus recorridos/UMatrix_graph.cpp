/**
 * @file UMatrix_graph.cpp
 * @author Carlos Salguero
 * @brief Implementation of Unweighted Matrix Graph
 * @version 0.1
 * @date 2022-11-09
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "UMatrix_graph.h"

// Constructors
/**
 * @brief
 * Construct a new matrix graph<vertex>::umatrix graph object
 * @tparam Type of vertex
 * @param c_size size of the graph
 * @param c_direction direction of the graph
 */
template <class Vertex>
UMatrix_graph<Vertex>::UMatrix_graph(unsigned int c_size,
                                     std::optional<bool> c_direction)
    : size(c_size), direction(c_direction.value_or(true))
{
    next = 0;
    vertexes.resize(size);
    edges.resize(size);

    for (size_t i{}; i < size; ++i)
    {
        edges[i].resize(size, false);
        edges[i][i] = true;
    }
}

// Access Methods
/**
 * @brief
 * Get the next vertex
 * @tparam Vertex Type of vertex
 * @return Vertex next vertex
 * @complexity O(1)
 */
template <class Vertex>
int UMatrix_graph<Vertex>::get_next() const
{
    return next;
}

/**
 * @brief
 * Get the size of the graph
 * @tparam Vertex Type of vertex
 * @return Vertex size
 * @complexity O(1)
 */
template <class Vertex>
unsigned int UMatrix_graph<Vertex>::get_size() const
{
    return size;
}

/**
 * @brief
 * Get the direction of the graph
 * @tparam Vertex Type of vertex
 * @return Vertex direction
 * @complexity O(1)
 */
template <class Vertex>
bool UMatrix_graph<Vertex>::get_direction() const
{
    return direction;
}

/**
 * @brief
 * Get the vertexes of the graph
 * @tparam Vertex Type of vertex
 * @return Vertex vertexes
 * @complexity O(1)
 */
template <class Vertex>
std::vector<Vertex> UMatrix_graph<Vertex>::get_vertexes() const
{
    return vertexes;
}

/**
 * @brief
 * Get the neighbours of a vertex
 * @tparam Vertex Type of vertex
 * @param vertex vertex to get the neighbours
 * @return Vertex neighbours
 * @complexity O(n)
 */
template <class Vertex>
std::set<Vertex> UMatrix_graph<Vertex>::get_neighbours(Vertex vertex) const
{
    std::set<Vertex> neighbours;

    for (size_t i{}; i < size; ++i)
        if (edges[vertex][i])
            neighbours.insert(i);

    return neighbours;
}

// Operator overload
/**
 * @brief
 * Overload the << operator
 * @tparam Type of vertex
 * @param os output stream
 * @param graph graph to print
 * @return std::ostream& output stream
 * @complexity O(n^2)
 */
template <class ostream>
std::ostream &operator<<(std::ostream &os,
                         const std::shared_ptr<UMatrix_graph<ostream>> &graph)
{
    os << "Graph size: " << graph->get_size() << std::endl
       << std::endl;

    os << "Adjacent Matrix: " << std::endl;

    for (size_t i{}; i < graph->get_next(); ++i)
        os << graph->vertexes[i] << " ";

    os << std::endl
       << std::endl;

    os << "Edges: " << std::endl;

    for (size_t i{}; i < graph->get_next(); ++i)
    {
        for (size_t j{}; j < graph->get_next(); ++j)
            os << graph->edges[i][j] << " ";

        os << std::endl;
    }

    os << std::endl
       << "Adjacent list: " << std::endl;

    for (size_t i{}; i < graph->size; ++i)
    {
        os << graph->vertexes[i] << " -> ";

        for (size_t j{}; j < graph->size; ++j)
            if (graph->edges[i][j])
                os << graph->vertexes[j] << " ";

        os << std::endl;
    }

    return os;
}

// Private Functions
/**
 * @brief
 * Gets the index of a vertex in the vertexes vector.
 * @tparam Vertex Type of the vertex
 * @param vertex Vertex to search
 * @return Vertex index of the vertex
 * @complexity O(n)
 */
template <class Vertex>
Vertex UMatrix_graph<Vertex>::index_of(Vertex vertex) const
{
    for (size_t i{}; i < size; ++i)
        if (vertexes[i] == vertex)
            return i;

    return -1;
}

/**
 * @brief
 * Checks if a vertex is in the graph
 * @tparam Vertex Type of the vertex
 * @param vertex1 Vertex to search
 * @param vertex2 Vertex to search
 * @return true if the vertex is in the graph
 * @return false if the vertex is not in the graph
 * @complexity O(n)
 */
template <class Vertex>
bool UMatrix_graph<Vertex>::is_edge(Vertex vertex1, Vertex vertex2) const
{
    return edges[vertex1][vertex2];
}

/**
 * @brief
 * Checks if a vertex is in the graph
 * @tparam Vertex Type of the vertex
 * @param vertex Vertex to search
 * @return true if the vertex is in the graph
 * @return false if the vertex is not in the graph
 * @complexity O(n)
 */
template <class Vertex>
bool UMatrix_graph<Vertex>::is_vertex(Vertex vertex) const
{
    return index_of(vertex) != -1;
}

// Public Functions
/**
 * @brief
 * Loads an unweighted matrix graph from a file.
 * @tparam Vertex Type of the vertex
 * @param graph_size Size of the graph
 * @param file File to load the graph from.
 * @complexity O(n^2)
 */
template <class Vertex>
void UMatrix_graph<Vertex>::load_graph(std::fstream &input_file)
{
    int from, to;

    while (true)
    {
        input_file >> from >> to;

        if (!from && !to)
            break;

        add_edge(from, to);
    }
}

/**
 * @brief
 * Add a vertex to the graph
 * @tparam Vertex Type of the vertex
 * @param from_vertex Vertex to add
 * @param to_vertex Vertex to add
 * @complexity O(1)
 */
template <class Vertex>
void UMatrix_graph<Vertex>::add_edge(Vertex from_vertex, Vertex to_vertex)
{
    if (!is_vertex(from_vertex))
        add_vertex(from_vertex);

    if (!is_vertex(to_vertex))
        add_vertex(to_vertex);

    int index1 = index_of(from_vertex), index2 = index_of(to_vertex);
    edges[index1][index2] = true;

    if (!direction)
        edges[index2][index1] = true;
}

/**
 * @brief
 * Add a vertex to the graph
 * @tparam Vertex Type of the vertex
 * @param from_vertex Vertex to add
 * @param to_vertex Vertex to add
 * @complexity O(1)
 */
template <class Vertex>
void UMatrix_graph<Vertex>::remove_edge(Vertex from_vertex, Vertex to_vertex)
{
    if (!is_vertex(from_vertex) || !is_vertex(to_vertex))
        throw std::invalid_argument("Vertex not found");

    if (!is_edge(from_vertex, to_vertex))
        throw std::invalid_argument("Edge does not exist");

    edges[from_vertex][to_vertex] = false;

    if (!direction)
        edges[to_vertex][from_vertex] = false;
}

/**
 * @brief
 * Add a vertex to the graph
 * @tparam Vertex Type of the vertex
 * @param vertex Vertex to add
 * @complexity O(1)
 */
template <class Vertex>
void UMatrix_graph<Vertex>::add_vertex(Vertex vertex)
{
    if (is_vertex(vertex))
        throw std::invalid_argument("Vertex already in the graph");

    if (next == size)
        throw std::invalid_argument("Graph is full");

    vertexes[next] = vertex;
    ++next;
}

/**
 * @brief
 * Remove a vertex from the graph
 * @tparam Vertex Type of the vertex
 * @param vertex Vertex to remove
 * @complexity O(n^2)
 */
template <class Vertex>
void UMatrix_graph<Vertex>::remove_vertex(Vertex vertex)
{
    if (!is_vertex(vertex))
        throw std::invalid_argument("Vertex not found");

    for (size_t i{}; i < size; ++i)
    {
        edges[index_of(vertex)][i] = false;
        edges[i][index_of(vertex)] = false;
    }

    for (size_t i{index_of(vertex)}; i < size - 1; ++i)
        vertexes[i] = vertexes[i + 1];

    --next;
}

/**
 * @brief
 * Checks if a vertex is in the graph
 * @tparam Vertex Type of the vertex
 * @param vertex Vertex to search
 * @return true if the vertex is in the graph
 * @return false if the vertex is not in the graph
 * @complexity O(n)
 */
template <class Vertex>
bool UMatrix_graph<Vertex>::contains_vertex(Vertex vertex) const
{
    return is_vertex(vertex);
}

/**
 * @brief
 * Checks if an edge is in the graph
 * @tparam Vertex Type of the vertex
 * @param vertex1 Vertex to search
 * @param vertex2 Vertex to search
 * @return true if the vertex is in the graph
 * @return false if the vertex is not in the graph
 * @complexity O(n)
 */
template <class Vertex>
bool UMatrix_graph<Vertex>::contains_edge(Vertex vertex1, Vertex vertex2) const
{
    return is_edge(vertex1, vertex2);
}

/**
 * @brief
 * Depth First Search. Traversal approach in which the traverse begins at
 * the root node and proceeds through the nodes as far as possible until we
 * reach the node with no unvisited nearby nodes. Uses a stack data structure.
 * @tparam Vertex Type of the vertex
 * @param start Starting vertex
 * @return std::set<Vertex> Set of the vertexes in the order they were visited
 * @complexity O(n^2)
 */
template <class Vertex>
std::set<Vertex> UMatrix_graph<Vertex>::dfs(const Vertex &start) const
{
    std::set<Vertex> visited;
    std::stack<Vertex> stack;

    stack.push(start);

    while (!stack.empty())
    {
        auto v = stack.top();
        stack.pop();

        if (visited.find(v) == visited.end())
        {
            visited.insert(v);
            std::set<Vertex> neighbors = get_neighbours(v);

            for (const auto &neightbor : neighbors)
                stack.push(neightbor);

        } // end of if statement
    }     // end of while loop

    return visited;
}

/**
 * @brief
 * Breadth First Search. Traversal approach in which we first walk through all
 * nodes on the same level before moving on to the next level.
 * Uses a queue data structure.
 * @tparam Vertex Type of the vertex
 * @param start Starting vertex
 * @return std::set<Vertex> Set of the vertexes in the order they were visited
 * @complexity O(n^2)
 */
template <class Vertex>
std::set<Vertex> UMatrix_graph<Vertex>::bfs(const Vertex &start) const
{
    std::set<Vertex> visited;
    std::queue<Vertex> queue;

    queue.push(start);

    while (!queue.empty())
    {
        Vertex v = queue.front();
        queue.pop();

        if (visited.find(v) == visited.end())
        {
            visited.insert(v);
            std::set<Vertex> neighbors = get_neighbours(v);

            for (const auto &neighbor : neighbors)
                queue.push(neighbor);
        } // end of if statement
    }     // end of while loop

    return visited;
}