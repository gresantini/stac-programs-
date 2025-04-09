#include "WeightedGraph.h"
#include <iostream>
#include <queue>
#include <stack>
#include <climits>

using namespace std;

// Define static member
const int WeightedGraph::NULL_EDGE = 0;

WeightedGraph::WeightedGraph(int size)
    : m_numVertices(0), m_maxVertices(size), m_vertices(size, nullptr), m_marks(size) {
    m_edges.resize(size, vector<int>(size, NULL_EDGE));
}

void WeightedGraph::addVertex(Vertex* aVertex) {
    m_vertices[m_numVertices] = aVertex;
    for (int i = 0; i < m_maxVertices; i++) {
        m_edges[m_numVertices][i] = NULL_EDGE;
        m_edges[i][m_numVertices] = NULL_EDGE;
    }
    m_numVertices++;
}

void WeightedGraph::addEdge(int fromVertex, int toVertex, int weight) {
    int row = fromVertex;
    int column = toVertex;
    m_edges[row][column] = weight;
}

int WeightedGraph::indexIs(Vertex* aVertex) {
    for (int i = 0; i < m_numVertices; i++) {
        if (m_vertices[i] == aVertex) {
            return i;
        }
    }
    return -1;
}

void WeightedGraph::clearMarks() {
    fill(m_marks.begin(), m_marks.end(), false);
}

void WeightedGraph::doDFS(Vertex* aVertex) {
    int index = indexIs(aVertex);
    if (index == -1 || m_marks[index]) return;

    cout << aVertex->getTitle() << " ";
    m_marks[index] = true;

    for (int i = 0; i < m_numVertices; i++) {
        if (m_edges[index][i] != NULL_EDGE && !m_marks[i]) {
            doDFS(m_vertices[i]);
        }
    }
}

void WeightedGraph::DFS(Vertex* aVertex) {
    clearMarks();
    doDFS(aVertex);
}

void WeightedGraph::doBFS(Vertex* aVertex) {
    queue<Vertex*> q;
    int startIdx = indexIs(aVertex);

    if (startIdx == -1) return;

    q.push(aVertex);
    m_marks[startIdx] = true;

    while (!q.empty()) {
        Vertex* current = q.front();
        q.pop();
        int currIdx = indexIs(current);

        cout << current->getTitle() << " ";
        for (int i = 0; i < m_numVertices; i++) {
            if (m_edges[currIdx][i] != NULL_EDGE && !m_marks[i]) {
                m_marks[i] = true;
                q.push(m_vertices[i]);
            }
        }
    }
}

void WeightedGraph::BFS(Vertex* aVertex) {
    clearMarks();
    doBFS(aVertex);
}

Vertex* WeightedGraph::getVertexByTitle(const string& title) {
    for (auto vertex : m_vertices) {
        if (vertex && vertex->getTitle() == title) {
            return vertex;
        }
    }
    return nullptr;
}

void WeightedGraph::findPath(const string& source, const string& destination) {
    Vertex* src = getVertexByTitle(source);
    Vertex* dest = getVertexByTitle(destination);

    if (!src || !dest) {
        cout << "Either source or destination vertex does not exist!" << endl;
        return;
    }

    clearMarks();
    queue<pair<Vertex*, vector<Vertex*>>> q;
    q.push({src, {src}});

    while (!q.empty()) {
        auto [current, path] = q.front();
        q.pop();

        int currIdx = indexIs(current);
        if (current == dest) {
            cout << "Path from " << source << " to " << destination << ": ";
            for (auto vertex : path) {
                cout << vertex->getTitle() << " ";
            }
            cout << " (Cost: " << path.size() - 1 << ")" << endl;
            return;
        }

        m_marks[currIdx] = true;
        for (int i = 0; i < m_numVertices; i++) {
            if (m_edges[currIdx][i] != NULL_EDGE && !m_marks[i]) {
                auto newPath = path;
                newPath.push_back(m_vertices[i]);
                q.push({m_vertices[i], newPath});
            }
        }
    }

    cout << "No path exists from " << source << " to " << destination << endl;
}
