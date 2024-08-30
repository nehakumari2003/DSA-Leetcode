#include <stack>
#include <limits.h>
#include <iostream>

using namespace std;

class SpecialStack {
    stack<int> s;
    int mini = INT_MAX;

public:
    void push(int data) {
        if (s.empty()) {
            s.push(data);
            mini = data;
        } 
        else {
            if (data < mini) {
                s.push(2 * data - mini);
                mini = data;
            } 
            else {
                s.push(data);
            }
        }
    }

    int pop() {
        if (s.empty()) {
            return -1;
        }

        int curr = s.top();
        s.pop();

        if (curr > mini) {
            return curr;
        } 
        else {
            int preMin = mini;
            mini = 2 * mini - curr;
            return preMin;
        }
    }

    int top() {
        if (s.empty()) {
            return -1;
        }

        int curr = s.top();

        if (curr < mini) {
            return mini;
        } 
        else {
            return curr;
        }
    }

    int getMin() {
        if (s.empty()) {
            return -1;
        }

        return mini;
    }
};

int main() {
    SpecialStack s;
    s.push(5);
    s.push(3);
    s.push(8);
    s.push(2);
    s.push(4);

    cout << "Top element: " << s.top() << endl;        
    cout << "Minimum element: " << s.getMin() << endl; 

    s.pop(); 
    cout << "Top element after pop: " << s.top() << endl;     
    cout << "Minimum element after pop: " << s.getMin() << endl;

    s.pop(); 
    cout << "Top element after pop: " << s.top() << endl;   
    cout << "Minimum element after pop: " << s.getMin() << endl; 

    return 0;
}
