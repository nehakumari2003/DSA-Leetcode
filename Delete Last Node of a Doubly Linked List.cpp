#include <iostream>
#include <bits/stdc++.h>

using namespace std;


class Node {
public:
    int data;       
    Node* next;    
    Node* back;     

    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertArr2DLL(vector<int> arr) {

    Node* head = new Node(arr[0]); 
  

    Node* prev = head;             
    for (int i = 1; i < arr.size(); i++) {

        Node* temp = new Node(arr[i], nullptr, prev);
  

        prev->next = temp;    
       
   
       prev = temp;         
     }


    return head;  
}


void print(Node* head) {
    while (head != nullptr) {
    
        cout << head->data << " "; 
       
        head = head->next;         
    }
}

Node* deleteHead(Node* head) {
    if (head == nullptr || head->next == nullptr) {
    
        return nullptr; 
    }


    Node* prev = head;      
    
    head = head->next;    

    head->back = nullptr;   


    prev->next = nullptr;  

    return head;          
}

Node* deleteTail(Node* head) {
    if (head == nullptr || head->next == nullptr) {

        return nullptr;  
    }
    
    Node* tail = head;
    while (tail->next != nullptr) {

        tail = tail->next; 
    }
    
    Node* newTail = tail->back;
    newTail->next = nullptr;
    tail->back = nullptr;
    

    delete tail;  
    
    return head;
}

int main() {
    vector<int> arr = {12, 5, 8, 7};
    Node* head = convertArr2DLL(arr);
    
    cout << "Original Doubly Linked List: ";
    print(head);
    
    cout << "\n\nAfter deleting the tail node: ";
    head = deleteTail(head);
    print(head);

    return 0;
}
