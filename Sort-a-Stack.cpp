/*Problem statement
You’re given a stack consisting of 'N' integers. Your task is to sort this stack in descending order using recursion.

We can only use the following functions on this stack S.

is_empty(S) : Tests whether stack is empty or not.
push(S) : Adds a new element to the stack.
pop(S) : Removes top element from the stack.
top(S) : Returns value of the top element. Note that this function does not remove elements from the stack.
Note :
1) Use of any loop constructs like while, for..etc is not allowed. 
2) The stack may contain duplicate integers.
3) The stack may contain any integer i.e it may either be negative, positive or zero.*/

#include <bits/stdc++.h>
using namespace std;

void sortInsert(stack<int> &stack, int num) {
    // Base case
    if (stack.empty() || (!stack.empty() && stack.top() < num)) {
        stack.push(num);
        return;
    }
    int n = stack.top();
    stack.pop();
    sortInsert(stack, num);
    stack.push(n);
}

void sortStack(stack<int> &stack) {
    // Base case
    if (stack.empty()) {
        return;
    }
    int num = stack.top();
    stack.pop();

    // Recursive call
    sortStack(stack);
    sortInsert(stack, num);
}

int main() {
    stack<int> s;
    s.push(5);
    s.push(2);
    s.push(7);
    s.push(3);
    s.push(1);

    cout << "Original Stack: ";
    stack<int> temp = s;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    sortStack(s);

    cout << "Sorted Stack: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
