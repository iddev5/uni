
#include <iostream>
using namespace std;

class Queue {
private:
    int front, rear;
    int* queue;

public:
    Queue(int s) {
        front = 0; rear = -1;
        queue = new int[s];
    }

    void enqueue(int value) {
        queue[++rear] = value;
    }

    int dequeue() {
        return queue[front++];
    }

    bool isEmpty() {
        return front > rear;
    }
};

class Stack {
private:
    int top;
    int* stack;

public:
    Stack(int s) {
        top = -1;
        stack = new int[s];
    }

    void push(int value) {
        stack[++top] = value;
    }

    int pop() {
        return stack[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};

void BFS(int** adjMatrix, int vertices, int start) {
    bool visited[vertices];
    visited[start] = true;

    Queue q(vertices);
    q.enqueue(start);

    while (!q.isEmpty()) {
        int current = q.dequeue();
        cout << current << " ";

        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.enqueue(i);
            }
        }
    }
}

void DFS(int** adjMatrix, int vertices, int start) {
    Stack s(vertices);
    s.push(start);

    bool visited[vertices];

    while (!s.isEmpty()) {
        int data = s.pop();
        if (!visited[data]) {
            visited[data] = true;
            cout << data << " ";

            for (int i = 0; i < vertices; i++) {
                if (adjMatrix[data][i] == 1)
                    s.push(i);
            }
        }
    }
}


int main() {
    int vertices, start;
    cout << "Enter number of vertices: ";
    cin >> vertices;

    int** adjMatrix = new int*[vertices];
    for (int i = 0; i < vertices; i++) {
        adjMatrix[i] = new int[vertices];
    }

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            cin >> adjMatrix[i][j];
        }
    }

    cout << "Enter starting vertex: ";
    cin >> start;

    cout << "BFS starting from vertex 0: ";
    BFS(adjMatrix, vertices, start);
    cout << endl;

    cout << "DFS starting from vertex 0: ";
    // bool vi/sited[vertices];
    DFS(adjMatrix, vertices, start);
    cout << endl;

    for (int i = 0; i < vertices; i++) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;

    return 0;
}
