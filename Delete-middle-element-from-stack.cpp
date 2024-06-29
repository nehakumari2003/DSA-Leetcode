/*Problem statement
You are having a stack "ARR" of size 'N+1', your task is to delete the middlemost element so that the size of resulting stack is 'N'.

A stack is a linear data structure where both insertion and deletion of elements take place at the top. It follows FILO (First In Last Out) or LIFO (Last In First Out) approaches. Books piled on top of each other is an example of a stack, where you can only remove a single book at a time, which is at the top of the stack. Likewise, you can only add a single book at a time, on the top of the stack only.

Example :-
INPUT : ARR [ ] = [ 1 , 2 , 3 , 4 , 5 ] , N = 4
OUTPUT: ARR [ ] = [ 1 , 2 , 4,  5 ]

The above example contains an odd number of elements, hence the middle element is clearly the (N+1) / 2th element, which is removed from the stack in the output.
*/
#include <bits/stdc++.h>
using namespace std;

void solve(stack<int> &inputStack, int count, int size) {
    // Base case: when count reaches the middle of the stack
    if (count == size / 2) {
        inputStack.pop();
        return;
    }
    
    int num = inputStack.top();
    inputStack.pop();

    // Recursive call to solve for the next element
    solve(inputStack, count + 1, size);

    
    inputStack.push(num);
}


void deleteMiddle(stack<int> &inputStack, int N) {
    int count = 0;
    solve(inputStack, count, N);
}

int main() {
   
    stack<int> inputStack;
    inputStack.push(1);
    inputStack.push(2);
    inputStack.push(3);
    inputStack.push(4);
    inputStack.push(5);

    int N = inputStack.size(); 

 
    deleteMiddle(inputStack, N);


    stack<int> tempStack;
    while (!inputStack.empty()) {
        tempStack.push(inputStack.top());
        inputStack.pop();
    }
    
    while (!tempStack.empty()) {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }

    return 0;
}

