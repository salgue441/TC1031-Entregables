/**
 * @file UMatrix_graph.cpp
 * @author Carlos Salguero
 * @brief Implementation of Unweighted Matrix Graph class
 * @version 0.1
 * @date 2022-11-04
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "UMatrix_graph.h"

// Constructors
/**
 * @brief
 * Construct a new umatrix graph<vertex>::umatrix graph object
 * @tparam Vertex Type of vertex
 * @param c_size Size of the graph
 * @param o_direction Direction of the graph
 */
template <class Vertex>
UMatrix_graph<Vertex>::UMatrix_graph(int c_size,
                                     std::optional<bool> o_direction)
    : size(c_size), direction(o_direction.value_or(true))
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
 * Gets the next object.
 * @tparam Vertex Type of the vertex.
 * @return int, the next vertex.
 */
template <class Vertex>
int UMatrix_graph<Vertex>::get_next() const
{
    return next;
}

/**
 * @brief
 * Gets the size of the object.
 * @tparam Vertex Type of the vertex.
 * @return int, the size of the graph.
 */
template <class Vertex>
int UMatrix_graph<Vertex>::get_size() const
{
    return size;
}

/**
 * @brief
 * Gets the direction of the object.
 * @tparam Vertex Type of the vertex.
 * @return true, if the graph is directed.
 * @return false, if the graph is undirected.
 */
template <class Vertex>
bool UMatrix_graph<Vertex>::get_direction() const
{
    return direction;
}

/**
 * @brief
 * Gets the vertexes of the graph.
 * @tparam Vertex Type of the vertex.
 * @return std::vector<Vertex>, the vertexes of the graph.
 * @complexity O(n)
 */
template <class Vertex>
std::vector<Vertex> UMatrix_graph<Vertex>::get_vertexes() const
{
    return vertexes;
}

/**
 * @brief
 * Gets the neighbours of a vertex.
 * @tparam Vertex Type of the vertex.
 * @param vertex Vertex to get the neighbours.
 * @return std::set<Vertex>, the neighbours of the vertex.
 * @complexity O(n)
 */
template <class Vertex>
std::set<Vertex> UMatrix_graph<Vertex>::get_neighbours(Vertex vertex) const
{
    std::set<Vertex> neighbours;
    int index = index_of(vertex);

    for (size_t elem{}; elem < get_next(); ++elem)
        if (index != elem && edges[index][elem])
            neighbours.insert(vertexes[elem]);

    return neighbours;
}

// Operator overload
/**
 * @brief
 * Overload of the operator <<.
 * @tparam Vertex Type of the vertex.
 * @param os Output stream.
 * @param graph Graph to print.
 * @return std::ostream&, the output stream.
 * @complexity O(n^2)
 */
template <class T>
std::ostream &operator<<(std::ostream &os, const UMatrix_graph<T> &graph)
{
    os << "---- Graph: ----" << std::endl;
    os << "Vertexes: " << std::endl;

    for (size_t i{}; i < graph.get_next(); ++i)
        os << graph.vertexes[i] << " ";

    os << std::endl
       << std::endl;

    os << "Edges: " << std::endl;

    for (size_t i{}; i < graph.get_next(); ++i)
    {
        for (size_t j{}; j < graph.get_next(); ++j)
            os << graph.edges[i][j] << " ";

        os << std::endl;
    }

    return os;
}

// Private Functions
/**
 * @brief
 * Get the index of a vertex in the vertexes vector.
 * @tparam Vertex Type of the vertex.
 * @param v Vertex to search.
 * @return int index of the vertex.
 * @complexity O(n)
 */
template <class Vertex>
int UMatrix_graph<Vertex>::index_of(Vertex v) const
{
    for (size_t i{}; i < size; ++i)
        if (vertexes[i] == v)
            return i;

    return -1;
}

// Public Functions
/**
 * @brief
 * Adds an edge to the graph.
 * @tparam Vertex
 * @param from_vertex
 * @param to_vertex
 * @complexity O(1)
 */
template <class Vertex>
void UMatrix_graph<Vertex>::add_edge(Vertex from_vertex,
                                     Vertex to_vertex)
{
    int from_p = index_of(from_vertex);
    if (from_p == -1)
    {
        if (get_next() == get_size())
            throw std::out_of_range("Graph is full");

        vertexes[++next] = from_vertex;
        from_p = next - 1;
    }

    int to_p = index_of(to_vertex);
    if (to_p == -1)
    {
        if (get_next() == get_size())
            throw std::out_of_range("Graph is full");

        vertexes[++next] = to_vertex;
        to_p = next - 1;
    }

    edges[from_p][to_p] = true;
    if (!get_direction())
        edges[to_p][from_p] = true;
}

/**
 * @brief
 * Checks if a vertex is in the graph.
 * @tparam Vertex Type of the vertex.
 * @param v       Vertex to search.
 * @return true, if the vertex is in the graph.
 * @return false, if the vertex is not in the graph.
 * @complexity O(n)
 */
template <class Vertex>
bool UMatrix_graph<Vertex>::contains_vertex(Vertex v) const
{
    return index_of(v) != -1;
}

/**
 * @brief
 * Checks if an edge is in the graph.
 * @tparam Vertex Type of the vertex.
 * @param start  Start vertex of the edge.
 * @param graph End vertex of the edge.
 * @return true, if the edge is in the graph.
 * @return false, if the edge is not in the graph.
 * @complexity O(1)
 */
template <class Vertex>
std::set<Vertex> UMatrix_graph<Vertex>::dfs(const Vertex &start,
                                            const std::unique_ptr<U_Graph<Vertex>> graph) const

{
    std::set<Vertex> visited;
    std::stack<Vertex> stack;
    stack.push(start);

    while (!stack.empty())
    {
        Vertex v = stack.top();
        stack.pop();

        if (visited.find(v) == visited.end())
        {
            visited.insert(v);
            std::set<Vertex> neighbours = graph->get_neighbours(v);

            for (auto neighbour : neighbours)
                stack.push(neighbour);
        }
    }

    return visited;
}

/**
 * @brief
 * Checks if an edge is in the graph.
 * @tparam Vertex Type of the vertex.
 * @param start Start vertex of the edge.
 * @param graph End vertex of the edge.
 * @return true, if the edge is in the graph.
 * @return false, if the edge is not in the graph.
 * @complexity O(1)
 */
template <class Vertex>
std::set<Vertex> UMatrix_graph<Vertex>::bfs(const Vertex &start,
                                            const std::unique_ptr<U_Graph<Vertex>> graph) const
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
            std::set<Vertex> neighbours = graph->get_neighbours(v);

            for (auto neighbour : neighbours)
                queue.push(neighbour);
        }
    }

    return visited;
}