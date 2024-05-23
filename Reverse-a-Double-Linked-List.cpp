
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
        // Print the data in the tail node
        cout << head->data << " ";  
         // Move to the next node
        head = head->next;         
    }
}

 

Node* reverseDLL(Node* head) {
    
   
    if (head == NULL || head->next == NULL) {
      
        return head; 
    }
    
   
    Node* prev = NULL;  
    
    
    Node* current = head;   

   
    while (current != NULL) {
       
        prev = current->back; 
        
        
        current->back = current->next; 
        
        current->next = prev;          
        
       
        current = current->back; 
    }

    return prev->back;
}


int main() {
    vector<int> arr = {12, 5, 8, 7, 4};
    Node* head = convertArr2DLL(arr);
    cout << endl << "Doubly Linked List Initially:  " << endl;
    print(head);
    cout << endl << "Doubly Linked List After Reversing " << endl;
    
     // Insert a node with value 10 at the end
    head = reverseDLL(head);
    print(head);

    return 0;
}

