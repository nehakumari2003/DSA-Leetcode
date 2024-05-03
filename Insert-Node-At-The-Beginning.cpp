/*Problem statement
You are given the head of a linked list ‘list’ of size ‘N’ and an integer ‘newValue’.
Your task is to insert a node with the value ‘newValue’ at the beginning of the ‘list’ and return the new head of the linked list.
You must write an algorithm whose time complexity is O(1) and whose space complexity is O(1).
*/
#include<bits/stdc++.h>
using namespace std;
class ListNode{
    public:
        int val;
        ListNode *Next;
        ListNode(int x){
            val = x;
            Next = NULL;
        }
};
void print(ListNode* head){
    ListNode *current = head;
    for(; current!= NULL ; current = current->Next)
        cout << current -> val << "-->";
    cout << "null" << endl;
}
ListNode * insertatFirst(int val, ListNode* head){
    ListNode* Newnode = new ListNode(val);
    Newnode -> Next = head;
    head = Newnode;
    return head;
}
int main() {
  ListNode * head = NULL; // head of the LinkedList
  head = insertatFirst(40, head);
  head = insertatFirst(30, head);
  head = insertatFirst(20, head);
  head = insertatFirst(10, head);
  cout << "LinkedList before inserting 0 at beginning : " << endl;
  print(head);
  head = insertatFirst(0, head);
  cout << "LinkedList after inserting 0 at beginning : " << endl;
  print(head);
  return 0;
}