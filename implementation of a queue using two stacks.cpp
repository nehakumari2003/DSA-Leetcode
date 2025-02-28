#include <iostream>
#include <stack>
using namespace std;

class Queue {
    stack<int> s1, s2;

public:

    void enqueue(int x) {
        s1.push(x);
    }

    int dequeue() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }


        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }


        int front = s2.top();
        s2.pop();
        return front;
    }


    bool isEmpty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    Queue q;
    
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "Dequeued: " << q.dequeue() << endl; 
    cout << "Dequeued: " << q.dequeue() << endl; 
    
    q.enqueue(4);
    
    cout << "Dequeued: " << q.dequeue() << endl; 
    cout << "Dequeued: " << q.dequeue() << endl; 

    return 0;
}
