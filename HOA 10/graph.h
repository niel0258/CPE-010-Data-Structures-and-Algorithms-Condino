#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>

#ifndef GRAPH_H
#define GRAPH_H

template <typename T>
class Graph;

template <typename T>
struct Edge
{
    size_t src;
    size_t dest;
    T weight;
    // To compare edges, only compare their weights,
    // and not the source/destination vertices
    inline bool operator<(const Edge<T> &e) const{
        return this->weight < e.weight;
    }
    inline bool operator>(const Edge<T> &e) const{
        return this->weight > e.weight;
    }
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const Graph<T> &G){
    for (auto i = 1; i < G.vertices(); i++){
        os << i << ":\t";
        auto edges = G.outgoing_edges(i);
        for (auto &e : edges)
        os << "{" << e.dest << ": " << e.weight << "}, ";
        os << std::endl;
    }
    return os;
}

template <typename T>
class Graph
{
    public:
    // Initialize the graph with N vertices
        Graph(size_t N) : V(N){}
        // Return number of vertices in the graph
        auto vertices() const{
        return V;
        }
        // Return all edges in the graph
        auto &edges() const{
        return edge_list;
        }
        void add_edge(Edge<T> &&e){
        // Check if the source and destination vertices are within range
        if (e.src >= 1 && e.src <= V && e.dest >= 1 && e.dest <= V) 
            edge_list.emplace_back(e);
        else
            std::cerr << "Vertex out of bounds" << std::endl;
        }
        // Returns all outgoing edges from vertex v
        auto outgoing_edges(size_t v) const{
        std::vector<Edge<T>> edges_from_v;
        for (auto &e : edge_list){
            if (e.src == v)
            edges_from_v.emplace_back(e);
        }
            return edges_from_v;
        }
        // Overloads the << operator so a graph be written directly to a stream
        // Can be used as std::cout << obj << std::endl;
        template <typename U>
        friend std::ostream &operator<<(std::ostream &os, const Graph<U> &G);
    private:
        size_t V; // Stores number of vertices in graph
        std::vector<Edge<T>> edge_list;
};

#endif