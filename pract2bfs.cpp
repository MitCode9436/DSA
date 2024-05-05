/*Represent a given graph using adjacency list to perform BFS. Use
non-recursive method*/
#include <iostream>
#include <queue>
using namespace std;

// Node structure for the linked list representing neighbors of a vertex
struct Node {
    int data;
    Node* next;
};

// Class representing the Graph
class Graph {
private:
    int nodes;
    Node** adjList; // Array of pointers to the head of linked lists

public:
    // Constructor
    Graph(int n) : nodes(n) {
        adjList = new Node*[nodes] {nullptr}; // Initialize all pointers to nullptr
    }

    // Destructor
    ~Graph() {
        for (int i = 0; i < nodes; ++i) {
            Node* current = adjList[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] adjList;
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v) {
        Node* newNode = new Node;
        newNode->data = v;
        newNode->next = adjList[u];
        adjList[u] = newNode; // Add new node at the beginning of the list

        // For undirected graph, add the reverse edge as well
        newNode = new Node;
        newNode->data = u;
        newNode->next = adjList[v];
        adjList[v] = newNode;
    }

    // Function to display the graph
    void displayGraph() {
        cout << "Adjacency List Representation of the Graph:\n";
        for (int i = 0; i < nodes; ++i) {
            cout << i << " --> ";
            Node* current = adjList[i];
            while (current != nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    }

    // Function to perform BFS
    void BFS(int start) {
        bool* visited = new bool[nodes] {false};
        queue<int> q;

        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";

            // Traverse the neighbors of current vertex
            Node* neighbor = adjList[current];
            while (neighbor != nullptr) {
                if (!visited[neighbor->data]) {
                    q.push(neighbor->data);
                    visited[neighbor->data] = true;
                }
                neighbor = neighbor->next;
            }
        }

        delete[] visited;
    }
};

int main() {
    int nodes, edges;

    // Taking input for the number of nodes and edges
    cout << "Enter the number of nodes and edges in the graph: ";
    cin >> nodes >> edges;

    Graph g(nodes);

    // Getting edges from the user
    cout << "Enter the edges (format: u v):\n";
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    // Displaying the graph
    g.displayGraph();

    cout << "Enter the starting node for BFS traversal: ";
    int start;
    cin >> start;

    cout << "BFS traversal: ";
    g.BFS(start);
    cout << endl;

    return 0;
}
