// Represent a given graph using adjacency
// matrix/list to perform DFS and using adjacency
// list to perform BFS. Use the map of the area
// around the college as the graph. Identify the
// prominent land marks as nodes and perform
// DFS and BFS on that.



#include<iostream>
using namespace std;

class DFS {
public:
    int top, f, r, x;
    int** adjList;
    int data[30], data1[30];
    int visit[20];
    int g[10][10];

    DFS() {
        top = -1;
        f = r = -1;
        adjList = nullptr;
    }

    void createMatrix();
    void displayMatrix();
    void createAdjList();
    void displayAdjList();
    void dfs();
    void bfs();

    int pop();
    void push(int t);
    void enqueue(int t);
    int dequeue();
};

// Stack methods
int DFS::pop() {
    if (top != -1) {
        return data[top--];
    }
    return -1;
}

void DFS::push(int t) {
    data[++top] = t;
}

// Queue methods
void DFS::enqueue(int t) {
    if (f == -1 && r == -1) {
        f = r = 0;
    } else {
        r++;
    }
    data1[r] = t;
}

int DFS::dequeue() {
    if (f == -1 || f > r)
        return -1;

    int y = data1[f];
    if (f == r)
        f = r = -1;
    else
        f++;
    return y;
}

// Matrix-based graph
void DFS::createMatrix() {
    cout << "Number of nodes:\t";
    cin >> x;

    for (int i = 0; i < x; i++) {
        cout << "Enter link status for node " << i << " (" << x << " values: 0 or 1): ";
        for (int j = 0; j < x; j++) {
            cin >> g[i][j];
        }
    }
}

void DFS::displayMatrix() {
    cout << "\nAdjacency Matrix:\n   ";
    for (int i = 0; i < x; i++)
        cout << i << " ";
    cout << "\n";

    for (int i = 0; i < x; i++) {
        cout << i << " | ";
        for (int j = 0; j < x; j++) {
            cout << g[i][j] << " ";
        }
        cout << "\n";
    }
}

// DFS using matrix
void DFS::dfs() {
    for (int i = 0; i < x; i++)
        visit[i] = 0;

    DFS s;
    int start;
    cout << "\nEnter starting node for DFS: ";
    cin >> start;

    s.push(start);
    cout << "DFS Traversal: ";

    while (s.top != -1) {
        int v = s.pop();
        if (!visit[v]) {
            cout << v << " ";
            visit[v] = 1;

            for (int i = x - 1; i >= 0; i--) {
                if (g[v][i] == 1 && !visit[i]) {
                    s.push(i);
                }
            }
        }
    }
    cout << "\n";
}

// Adjacency list
void DFS::createAdjList() {
    cout << "Number of nodes:\t";
    cin >> x;

    adjList = new int*[x];
    for (int i = 0; i < x; i++) {
        adjList[i] = new int[x]();  // Initialize with 0
    }

    int connected, node;
    for (int i = 0; i < x; i++) {
        cout << "\nEnter number of nodes connected to node " << i << ": ";
        cin >> connected;
        cout << "Enter the nodes connected to node " << i << ": ";
        for (int j = 0; j < connected; j++) {
            cin >> node;
            adjList[i][node] = 1;
        }
    }
}

void DFS::displayAdjList() {
    cout << "\nAdjacency List:";
    for (int i = 0; i < x; i++) {
        cout << "\nNode " << i << " -> ";
        for (int j = 0; j < x; j++) {
            if (adjList[i][j] == 1)
                cout << j << " ";
        }
    }
    cout << "\n";
}

// BFS using adjacency list
void DFS::bfs() {
    for (int i = 0; i < x; i++)
        visit[i] = 0;

    DFS s;
    int start;
    cout << "\nEnter starting node for BFS: ";
    cin >> start;

    s.enqueue(start);
    cout << "BFS Traversal: ";

    while (s.f != -1) {
        int v = s.dequeue();
        if (!visit[v]) {
            cout << v << " ";
            visit[v] = 1;

            for (int i = 0; i < x; i++) {
                if (adjList[v][i] == 1 && !visit[i]) {
                    s.enqueue(i);
                }
            }
        }
    }
    cout << "\n";
}

// Main
int main() {
    DFS obj;
    int choice;
    bool flag = true;

    while (flag) {
        cout << "\n*** YOUR CHOICES ***\n";
        cout << "1. Create Graph (Matrix)\n";
        cout << "2. DFS Traversal (Using Matrix)\n";
        cout << "3. Create Graph (Adjacency List)\n";
        cout << "4. BFS Traversal (Using List)\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            obj.createMatrix();
            obj.displayMatrix();
            break;
        case 2:
            obj.dfs();
            break;
        case 3:
            obj.createAdjList();
            obj.displayAdjList();
            break;
        case 4:
            obj.bfs();
            break;
        case 5:
            flag = false;
            break;
        default:
            cout << "Enter a valid choice (1-5).\n";
            break;
        }
    }

    return 0;
}