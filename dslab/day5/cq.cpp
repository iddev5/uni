#include <iostream>
using namespace std;

class CircularQueue {
    int *data;
    int front;
    int rear;
    int size;

public:
    CircularQueue(int s) {
        size = s;
        front = -1;
        rear = -1;
        data = new int[s];
    }

    void enqueue(int val) {
        if ((front == 0 && rear == size - 1) || (rear == front - 1)) {
            cout << "Queue overflow" << endl;
            exit(1);
        }

        if (front == -1) front = 0;

        if (rear == size - 1) rear = -1;

        data[++rear] = val;
    }

    int dequeue() {
        if (front == -1 || (front - 1 == rear)) {
            cout << "Queue underflow" << endl;
            exit(1);
        }

        if (front == size - 1) front = 0;

        return data[front++];
    }

    void display() {
        int end = front > rear ? size - 1 : rear;
        if (front > rear)
            for (int i = 0; i <= rear; i++)
                cout << data[i] << "(" << i << ") ";
        for (int i = front; i <= end; i++) 
            cout << data[i] << "(" << i << ") ";
        
        cout << endl;
    }

    void clear() {
        front = -1;
        rear = -1;
    }

    int front_item() {
        return data[front];
    }

    int front_index() {
        return front;
    }

    int rear_item() {
        return data[rear];
    }

    int rear_index() {
        return rear;
    }

};

int main() {
    int ch, data;
    CircularQueue cq(10);

    cout << "Circular Queue program" << endl;
    while (true) { 
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Clear\n5. Front\n6. Rear\n7. Exit\nChoice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter data to enqueue: ";
                cin >> data;
                cq.enqueue(data);
                break;
            case 2:
                cout << "Removed data: " << cq.dequeue() << endl;
                break;
            case 3:
                cout << "Displaying the data: ";
                cq.display();
                break;
            case 4:
                cout << "Clearing the queue" << endl;
                cq.clear();
                break;
            case 5:
                cout << "Front item: " << cq.front_item() << "(" << cq.front_index() << ")" << endl;
                break;
            case 6:
                cout << "Rear item: " << cq.rear_item() << "(" << cq.rear_index() << ")" << endl;
                break;
            case 7:
                cout << "Exiting program" << endl;
                return 0;
            default:
                cout << "Incorrect choice. Try again" << endl;
                break;
        }

        for (int i = 0; i < 15; i++) cout << "-";
        cout << "\n\n";


    }

    return 0;

}
