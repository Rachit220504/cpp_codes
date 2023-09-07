#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
private:
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    Graph(int vertices) : V(vertices) {
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    // Helper function for topological sorting using DFS
    void topologicalSortUtil(int v, vector<bool>& visited, stack<int>& st) {
        visited[v] = true;

        // Visit all adjacent vertices of the current vertex
        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                topologicalSortUtil(neighbor, visited, st);
            }
        }

        // Push the current vertex onto the stack
        st.push(v);
    }

    void topologicalSort() {
        stack<int> st;
        vector<bool> visited(V, false);

        // Call the helper function for all vertices
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                topologicalSortUtil(i, visited, st);
            }
        }

        // Print the topological order
        cout << "Topological Sort Order:" << endl;
        while (!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
};

int main() {
    Graph g(6); // Create a graph with 6 vertices

    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.topologicalSort();

    return 0;
}
