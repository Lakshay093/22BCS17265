#include <iostream>
using namespace std;


class CircularQueue {
private:
    int *queue;
    int size;
    int front;
    int rear;

public:
    CircularQueue(int size) {
        this->size = size;
        queue = new int[size];
        front = -1;
        rear = -1;
    }

    ~CircularQueue() {
        delete[] queue;
    }

    void enqueue(int value) {
        if ((rear + 1) % size == front) {
            cout << "Queue is full. Cannot enqueue." << endl;
        } else if (front == -1) { 
            front = rear = 0;
            queue[rear] = value;
        } else {
            rear = (rear + 1) % size;
            queue[rear] = value;
        }
    }

    int dequeue() {
        if (front == -1) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1;
        } else if (front == rear) { 
            int value = queue[front];
            queue[front] = -1;
            front = rear = -1;
            return value;
        } else {
            int value = queue[front];
            queue[front] = -1;
            front = (front + 1) % size;
            return value;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Queue elements: ";
            int i = front;
            while (true) {
                cout << queue[i] << " ";
                if (i == rear) {
                    break;
                }
                i = (i + 1) % size;
            }
            cout << endl;
        }
    }
};

int main() {
    CircularQueue cq(5); 

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50); 
    cq.display();

    cq.dequeue();
    cq.dequeue();
    cq.display();

    cq.enqueue(60);
    cq.enqueue(70);
    cq.display();

    return 0;
}
