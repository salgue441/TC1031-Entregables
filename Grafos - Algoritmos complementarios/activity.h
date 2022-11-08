/**
 * @file activity.h
 * @author Carlos Salguero
 * @author Sven Chavez
 * brief Implementation of the desired functions.
 * @version 0.1
 * @date 2022-11-08
 * @copyright Copyright (c) 2022
 */

#ifndef ACTIVITY_H
#define ACTIVITY_

#include "ugraph.h"

/**
 * @brief
 * Searches all the vertices of a graph for a vertex with the given name.
 * The purpose is to make sure that the vertex exists in the graph.
 * @tparam Vertex Type of data
 * @param v The vertex to be visited
 * @param g Graph
 * @param order  the order of the vertices in the graph
 * @param visited Reference of a vector of bools to keep track of
 *  visited vertices
 * @complexity O(n)
 */
template <class Vertex>
void dfs2(Vertex v, const UnweightedGraph<Vertex> &g,
          std::vector<Vertex> &order, std::vector<bool> &visited)
{
  visited[v] = true;

  for (auto w : g.getConnectionFrom(v))
    if (!visited[w])
      dfs2(w, g, order, visited);

  order.push_back(v);
}

/**
 * @brief
 * Is a linear ordering of vertices such that for every directed edge u v,
 * vertex u comes before v in the ordering.
 * @tparam Vertex Type of data
 * @param graph Graph
 * @return A string with the topological sort of the graph
 * @copmlexity O(n)
 */
template <class Vertex>
std::string topologicalSort(const UnweightedGraph<Vertex> *graph)
{
  std::vector<Vertex> order;
  std::vector<bool> visited(graph->getVertexes().size(), false);

  for (auto v : graph->getVertexes())
    if (!visited[v])
      dfs2(v, *graph, order, visited);

  std::stringstream ss;

  ss << "[";

  for (int i = order.size() - 1; i >= 0; i--)
    ss << order[i] << " ";

  ss.seekp(-1, ss.cur);
  ss << "]";

  return ss.str();
}

/**
 * @brief
 *
 * @tparam Vertex Type of data
 * @param graph Graph
 * @return true if the graph is biparite
 * @return false if the graph is not biparite
 * @complexity O(n)
 */
template <class Vertex>
bool isBipartite(const UnweightedGraph<Vertex> *graph)
{
  std::vector<bool> visited(graph->getVertexes().size(), false);
  std::vector<bool> color(graph->getVertexes().size(), false);
  std::queue<Vertex> q;

  for (auto v : graph->getVertexes())
  {
    if (!visited[v])
    {
      q.push(v);
      visited[v] = true;
      color[v] = true;

      while (!q.empty())
      {
        Vertex u = q.front();
        q.pop();

        for (auto w : graph->getConnectionFrom(u))
        {
          if (!visited[w])
          {
            visited[w] = true;
            color[w] = !color[u];
            q.push(w);
          }

          else if (color[w] == color[u])
            return false;
        } // end of inner for loop
      }   // end of while loop
    }     // end of if
  }       // end of outer for loop

  return true;
}

/**
 * @brief
 *
 * @tparam Vertex Type of data
 * @param v The vertex to be visited
 * @param graph Graph
 * @param reached Reference of a vector of bools to keep track of
 *  visited vertices
 * @param parent Reference of a vector of ints to keep track of
 * @return true if the graph is cyclic
 * @return false if the graph is not cyclic
 * @complexity O(n)
 */
template <class Vertex>
bool isCyclic(Vertex v, const UnweightedGraph<Vertex> *graph,
              std::set<Vertex> &reached, Vertex parent)
{
  reached.insert(v);

  for (auto w : graph->getConnectionFrom(v))
  {
    if (reached.find(w) == reached.end())
    {
      if (isCyclic(w, graph, reached, v))
        return true;
    }

    else if (w != parent)
      return true;
  }

  return false;
}

/**
 * @brief
 *
 * @tparam Vertex Type of data
 * @param graph Graph
 * @return true if the graph is a tree
 * @return false if the graph is not a tree
 * @complexity O(n)
 */
template <class Vertex>
bool isTree(const UnweightedGraph<Vertex> *graph)
{
  for (auto v : graph->getVertexes())
  {
    std::set<Vertex> reached;

    if (isCyclic(v, graph, reached, v))
      return false;
  }

  return true;
};

#endif //! ACTIVITY_H