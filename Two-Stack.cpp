/*Problem statement
Design a data structure, which represents two stacks using only one array common for both stacks. The data structure should support the following operations:

push1(NUM) - Push ‘NUM’ into stack1.
push2(NUM) - Push ‘NUM’ into stack2.
pop1() - Pop out a top element from stack1 and return popped element, in case of underflow return -1.
pop2() - Pop out a top element from stack2 and return popped element, in case of underflow return -1.
There are 2 types of queries in the input

Type 1 - These queries correspond to Push operation.
Type 2 - These queries correspond to Pop operation.*/
#include <bits/stdc++.h>
using namespace std;

class TwoStack {
    int *arr;
    int top1;
    int top2;
    int size;

public:
    // Initialize TwoStack.
    TwoStack(int s) {
        this->size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }

    // Push in stack 1.
    void push1(int num) {
        if (top2 - top1 > 1) {
            top1++;
            arr[top1] = num;
        } else {
            cout << "Stack Overflow" << endl;
        }
    }

    // Push in stack 2.
    void push2(int num) {
        if (top2 - top1 > 1) {
            top2--;
            arr[top2] = num;
        } else {
            cout << "Stack Overflow" << endl;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        if (top1 >= 0) {
            int ans = arr[top1];
            top1--;
            return ans;
        } else {
            cout << "Stack Underflow" << endl;
            return -1;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        if (top2 < size) {
            int ans = arr[top2];
            top2++;
            return ans;
        } else {
            cout << "Stack Underflow" << endl;
            return -1;
        }
    }

    ~TwoStack() {
        delete[] arr;
    }
};

int main() {
    TwoStack ts(5);

    ts.push1(5);
    ts.push2(10);
    ts.push1(15);
    ts.push2(20);

    cout << "Popped from stack 1: " << ts.pop1() << endl;
    cout << "Popped from stack 2: " << ts.pop2() << endl;

    ts.push1(25);
    ts.push2(30);

    cout << "Popped from stack 1: " << ts.pop1() << endl;
    cout << "Popped from stack 2: " << ts.pop2() << endl;

    return 0;
}
