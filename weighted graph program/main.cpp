#include <iostream>
#include "Vertex.h"
#include "WeightedGraph.h"

using namespace std;

int main() {
    WeightedGraph myGraph(10);

    Vertex* startNode;
    Vertex* aVertex;

    // Adding vertices
    startNode = new Vertex("A"); // Node 0
    myGraph.addVertex(startNode);

    aVertex = new Vertex("B"); // Node 1
    myGraph.addVertex(aVertex);

    aVertex = new Vertex("C"); // Node 2
    myGraph.addVertex(aVertex);

    aVertex = new Vertex("D"); // Node 3
    myGraph.addVertex(aVertex);

    aVertex = new Vertex("E"); // Node 4
    myGraph.addVertex(aVertex);

    // Adding edges
    myGraph.addEdge(0, 1, 10);
    myGraph.addEdge(0, 2, 12);
    myGraph.addEdge(0, 3, 60);
    myGraph.addEdge(0, 4, 7);
    myGraph.addEdge(1, 2, 20);
    myGraph.addEdge(2, 3, 32);

    // Depth First Search from Node E
    cout << "DFS from E: ";
    myGraph.DFS(myGraph.getVertexByTitle("E"));
    cout << endl;

    // Breadth First Search from Node E
    cout << "BFS from E: ";
    myGraph.BFS(myGraph.getVertexByTitle("E"));
    cout << endl;

    // Testing pathfinding function
    cout << endl << "Pathfinding Tests:" << endl;
    myGraph.findPath("E", "C");
    myGraph.findPath("B", "D");
    myGraph.findPath("A", "E");
    myGraph.findPath("C", "A");

    return 0;
}
