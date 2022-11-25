/**
 * @file UGraph.h
 * @author Carlos Salguero
 * @brief This file contains the definition of the Unweighted Graph class.
 * @version 0.1
 * @date 2022-11-12
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef UGRAPH_H
#define UGRAPH_H

#include <vector>
#include <set>
#include <queue> // used in bfs function implementation
#include <map>   // std::map used in adjacency list implementation

template <class graph_t>
class UGraph
{
public:
    // Constructor
    UGraph() = default;

    // Destructor
    ~UGraph() = default;

    // Access Methods
    std::map<graph_t, std::set<graph_t>> get_adjacency_list() const;
    std::map<graph_t, bool> get_visited() const;
    std::map<graph_t, graph_t> get_parent() const;
    std::map<graph_t, int> get_distance() const;
    std::map<graph_t, int> get_mnp() const;

    // Operator overload
    template <class ostream_t>
    friend std::ostream &operator<<(std::ostream &os,
                                    const UGraph<ostream_t> &graph);

    // Functions
    void add_edge(const graph_t &, const graph_t &);
    void remove_edge(const graph_t &, const graph_t &);
    void add_vertex(const graph_t &);
    void remove_vertex(const graph_t &);
    void reset();

    // Traversal Algorithm
    void bfs(const graph_t &);

private:
    std::map<graph_t, std::vector<graph_t>> adjacent_list;
    std::map<graph_t, bool> visited;
    std::map<graph_t, graph_t> parent;
    std::map<graph_t, int> distance;
    std::map<graph_t, int> mnp;
};

#endif //! UGRAPH_H