#include <iostream>
#include <LinkedList.h>
#include <Stack.h>
#include <Queue.h>

using namespace std;

const int MAX_V = 100;

struct UndirectedGraph {
    int V; 
    Node* adj[MAX_V]; 

    UndirectedGraph(int num_vertices) {
        if (num_vertices > MAX_V) {
            cerr << "Loi: So luong dinh vuot qua gioi han MAX_V." << endl;
            this->V = 0;
            return;
        }
        this->V = num_vertices;
        for (int i = 0; i < V; i++) {
            adj[i] = NULL;
        }
    }
    
    void addUndirectedEdge(int u, int v) {
        if (u >= V || v >= V || u < 0 || v < 0) return;
        Node* newNode_u = createNode(v);
        newNode_u->next = adj[u];
        adj[u] = newNode_u;
        
        Node* newNode_v = createNode(u);
        newNode_v->next = adj[v];
        adj[v] = newNode_v;
    }

    // 1. HÀM BFS
    void BFS(int start_node) {
        if (start_node >= V || start_node < 0) return;
        bool visited[MAX_V]; 
        for(int i = 0; i < V; i++) visited[i] = false;

        Queue q; 
        
        visited[start_node] = true;
        q.enqueue(start_node);

        while (!q.isEmpty()) {
            int u = q.dequeue();

            Node* temp = adj[u];
            while (temp != NULL) {
                int v = temp->data;
                if (!visited[v]) {
                    visited[v] = true;
                    q.enqueue(v);
                }
                temp = temp->next;
            }
        }
        cout << endl;
    }

    // 2. HÀM DFS
    void DFS(int start_node) {
        if (start_node >= V || start_node < 0) return;

        bool visited[MAX_V];
        for(int i = 0; i < V; i++) visited[i] = false;
        Stack s;

        s.push(start_node); 

        while (!s.isEmpty()) {
            int u = s.pop(); 
            
            if (!visited[u]) {
                visited[u] = true;
                
                Node* temp = adj[u];
                while (temp != NULL) {
                    int v = temp->data;
                    if (!visited[v]) {
                        s.push(v);
                    }
                    temp = temp->next;
                }
            }
        }
        cout << endl;
    }
    
    // Destructor
    ~UndirectedGraph() {
        for (int i = 0; i < V; ++i) {
            Node* current = adj[i];
            Node* next;
            while (current != NULL) {
                next = current->next;
                delete current;
                current = next;
            }
        }
    }
};

// --- Ví dụ sử dụng ---
int main() {
    UndirectedGraph g(5); 

    g.addUndirectedEdge(0, 1);
    g.addUndirectedEdge(0, 4);
    g.addUndirectedEdge(1, 2);
    g.addUndirectedEdge(1, 3);
    g.addUndirectedEdge(1, 4);
    g.addUndirectedEdge(2, 3);
    g.addUndirectedEdge(3, 4);

    // Thực hiện DFS
    g.DFS(0); 
    
    // Thực hiện BFS
    g.BFS(0); 

    return 0;
}