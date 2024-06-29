/*Problem statement
You are given a stack/deque of integers 'MY-STACK' and an integer ‘X’. Your task is to insert ‘X’ to the bottom of ‘MY-STACK’ and return the updated stack/deque.
Note :
If ‘MY_STACK’ = [7, 1, 4, 5], then the first element represents the element at the bottom of the stack and the last element represents the element at the top of the stack.*/

#include <bits/stdc++.h>
using namespace std;


void solve(stack<int>& s, int x) {
    // Base case: 
    if(s.empty()) {
        s.push(x);
        return;
    }

    
    int num = s.top();
    s.pop();


    solve(s, x);


    s.push(num);
}


stack<int> pushAtBottom(stack<int>& myStack, int x) {
    solve(myStack, x);
    return myStack;
}


void printStack(stack<int> s) {
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    
    stack<int> myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);

    int x = 0;

   
    myStack = pushAtBottom(myStack, x);

    
    printStack(myStack);

    return 0;
}

