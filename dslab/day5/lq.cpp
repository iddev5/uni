#include <iostream>
using namespace std;

class LinearQueue {
    int *data;
    int front;
    int rear;
    int size;

public:
    LinearQueue(int s) {
        size = s;
        front = -1;
        rear = -1;
        data = new int[s];
    }

    void enqueue(int val) {
        if (rear == size - 1) {
            cout << "Queue overflow" << endl;
            exit(1);
        }

        if (front == -1) front = 0;
        data[++rear] = val;
    }

    int dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue overflow" << endl;
            exit(1);
        }

        return data[front++];
    }

    void display() {
        for (int i = front; i <= rear; i++) 
            cout << data[i] << " ";
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
    LinearQueue lq(10);

    cout << "Linear Queue program" << endl;
    while (true) { 
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Clear\n5. Front\n6. Rear\n7. Exit\nChoice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter data to enqueue: ";
                cin >> data;
                lq.enqueue(data);
                break;
            case 2:
                cout << "Removed data: " << lq.dequeue() << endl;
                break;
            case 3:
                cout << "Displaying the data: ";
                lq.display();
                break;
            case 4:
                cout << "Clearing the queue" << endl;
                lq.clear();
                break;
            case 5:
                cout << "Front item: " << lq.front_item() << "(" << lq.front_index() << ")" << endl;
                break;
            case 6:
                cout << "Rear item: " << lq.rear_item() << "(" << lq.rear_index() << ")" << endl;
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
