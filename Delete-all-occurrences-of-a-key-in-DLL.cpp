#include <bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

void deleteNode(struct Node** head_ref, struct Node* del)
{
	/* base case */
	if (*head_ref == NULL || del == NULL)
		return;


	if (*head_ref == del)
		*head_ref = del->next;


	if (del->next != NULL)
		del->next->prev = del->prev;

	if (del->prev != NULL)
		del->prev->next = del->next;

	free(del);
}


void deleteAllOccurOfX(struct Node** head_ref, int x)
{
	
	if ((*head_ref) == NULL)
		return;

	struct Node* current = *head_ref;
	struct Node* next;

	while (current != NULL) {

	
		if (current->data == x) {

			
			next = current->next;

			
			deleteNode(head_ref, current);

			
			current = next;
		}

		
		else
			current = current->next;
	}
}

void push(struct Node** head_ref, int new_data)
{

	struct Node* new_node = 
			(struct Node*)malloc(sizeof(struct Node));

	new_node->data = new_data;

	new_node->prev = NULL;


	new_node->next = (*head_ref);


	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;

	(*head_ref) = new_node;
}


void printList(struct Node* head)
{
	/* if list is empty */
	if (head == NULL)
		cout << "Doubly Linked list empty";

	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}


int main()
{

	struct Node* head = NULL;


	push(&head, 2);
	push(&head, 5);
	push(&head, 2);
	push(&head, 4);
	push(&head, 8);
	push(&head, 10);
	push(&head, 2);
	push(&head, 2);

	cout << "Original Doubly linked list:n";
	printList(head);

	int x = 2;


	deleteAllOccurOfX(&head, x);

	cout << "\nDoubly linked list after deletion of "
		<< x << ":n";
	printList(head);

	return 0;
}
