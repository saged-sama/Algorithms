#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int N = 100005; // Maximum number of nodes

vector<int> graph[N];

void addEdge(int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

bool hasUnvisitedEdges(int node) {
    for (int neighbor : graph[node]) {
        if (graph[neighbor].size() > 0) {
            return true;
        }
    }
    return false;
}

vector<int> findEulerCircuit() {
    vector<int> eulerCircuit;
    stack<int> st;
    st.push(0); // Start from vertex 0 or any starting vertex

    while (!st.empty()) {
        int current = st.top();

        if (hasUnvisitedEdges(current)) {
            int nextVertex = graph[current].back();
            st.push(nextVertex);
            graph[current].pop_back();
            graph[nextVertex].erase(find(graph[nextVertex].begin(), graph[nextVertex].end(), current));
        } else {
            eulerCircuit.push_back(current);
            st.pop();
        }
    }

    reverse(eulerCircuit.begin(), eulerCircuit.end()); // Reverse the circuit to get correct order
    return eulerCircuit;
}

int main() {
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(2, 3);
    addEdge(3, 0); // Adding an edge to close the circuit

    vector<int> eulerCircuit = findEulerCircuit();

    if (!eulerCircuit.empty()) {
        cout << "Eulerian Circuit: ";
        for (int vertex : eulerCircuit) {
            cout << vertex << " ";
        }
        cout << endl;
    } else {
        cout << "No Eulerian Circuit exists." << endl;
    }

    return 0;
}
