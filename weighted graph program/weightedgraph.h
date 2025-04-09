#ifndef WEIGHTEDGRAPH_H
#define WEIGHTEDGRAPH_H

#include <vector>
#include <string>
#include "Vertex.h"

using namespace std;

class WeightedGraph {
public:
    WeightedGraph(int size);
    void addVertex(Vertex* aVertex);
    void addEdge(int fromVertex, int toVertex, int weight);
    void DFS(Vertex* aVertex);
    void BFS(Vertex* aVertex);
    void findPath(const string& source, const string& destination); // New function
    Vertex* getVertexByTitle(const string& title);                 // Helper function

private:
    static const int NULL_EDGE;
    int indexIs(Vertex* aVertex);
    void clearMarks();
    void doDFS(Vertex* aVertex);
    void doBFS(Vertex* aVertex);

    int m_numVertices;
    int m_maxVertices;
    vector<Vertex*> m_vertices;
    vector<vector<int>> m_edges;
    vector<bool> m_marks;
};

#endif // WEIGHTEDGRAPH_H
