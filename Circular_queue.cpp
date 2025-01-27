#include <iostream>
using namespace std;

int rear = -1;
int front = -1;
int max_size = 5;  
int a[5];

void enqueue(int x) {
    if (front == -1 && rear == -1) {
        front = rear = 0;
    } else if ((rear + 1) % max_size == front) {
        cout << "Queue is full\n";
        return;
    } else {
        rear = (rear + 1) % max_size;
    }
    a[rear] = x;
}

void dequeue() {
    if (front == -1 && rear == -1) {
        cout << "Queue is empty\n";
    } else if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % max_size;
    }
}

int peek() {
    if (front == -1) return -1;
    return a[front];
}

void print() {
    if (front == -1) {
        cout << "Queue is empty\n";
        return;
    }
    int count = ((rear + max_size - front) % max_size) + 1;
    int i;
    for (i = 0; i < count; i++) {
        cout << a[(front + i) % max_size] << " ";
    }
    cout << "\n";
}

int main(void) {
    enqueue(5);
    cout << "\nFirst insertion in circular Queue\n";
    print();

    cout << "\nSecond insertion in circular Queue\n";
    enqueue(7);
    print();

    cout << "\nThird insertion in circular Queue\n";
    enqueue(-3);
    print();

    cout << "\nFourth insertion in circular Queue\n";
    enqueue(9);
    print();

    cout << "\nCircular queue after first round\n";
    dequeue();
    print();

    cout << "\nCircular queue after first deletion\n";
    dequeue();
    print();

    cout << "\nCircular queue after second deletion\n";
    dequeue();
    print();

    cout << "\nInsertion in circular Queue\n";
    enqueue(14);
    print();

    return 0;
}
