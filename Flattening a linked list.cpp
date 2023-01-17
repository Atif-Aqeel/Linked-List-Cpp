/*
Flattening a linked list is a problem in which all the nodes of a bigger linked list are combined to form a single horizontal linked list. 
Merge algorithm of merge sort can be used to merge every sublist until all the elements are merged into a single linked list.

Given a linked list where every node represents a linked list and contains two pointers of its type: 
	Pointer to next node in the main list (we call it ‘right’ pointer in the code below) 
	Pointer to a linked list where this node is headed (we call it the ‘down’ pointer in the code below).

Follow the given steps to solve the problem:
	Recursively call to merge the current linked list with the next linked list
	If the current linked list is empty or there is no next linked list then return the current linked list (Base Case)
	Start merging the linked lists, starting from the last linked list
	After merging the current linked list with the next linked list, return the head node of the current linked list
*/

#include <bits/stdc++.h>
using namespace std;

// Linked list node
class Node {
	public:
		int data;
		Node *right, *down;
};

Node* head = NULL;

//Function to merge two sorted linked lists
Node* merge(Node* a, Node* b)
{
	// If first linked list is empty then second is the answer
	if (a == NULL)
		return b;

	// If second linked list is empty then first is the result
	if (b == NULL)
		return a;

	// Compare the data members of the two linked lists and put the larger one in the result
	Node* result;
	if (a->data < b->data){
		result = a;
		result->down = merge(a->down, b);
	}
	else{
		result = b;
		result->down = merge(a, b->down);
	}
	result->right = NULL;
	return result;
}

Node* flatten(Node* root)
{
	// Base Cases
	if (root == NULL || root->right == NULL)
		return root;

	// Recur for list on right
	root->right = flatten(root->right);

	// Now merge
	root = merge(root, root->right);

	// Return the root, it will be in turn merged with its left
	return root;
}

// function to insert a node at beginning of the linked list
Node* push(Node* head_ref, int data)
{
	// Allocate the Node & Put in the data
	Node* new_node = new Node();

	new_node->data = data;
	new_node->right = NULL;

	// Make next of new Node as head
	new_node->down = head_ref;

	// Move the head to point to new Node
	head_ref = new_node;

	return head_ref;
}

void printList()
{
	Node* temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->down;
	}
	cout << endl;
}

int main()
{	
	head = push(head, 30);
	head = push(head, 8);
	head = push(head, 7);
	head = push(head, 5);

	head->right = push(head->right, 20);
	head->right = push(head->right, 10);

	head->right->right = push(head->right->right, 50);
	head->right->right = push(head->right->right, 22);
	head->right->right = push(head->right->right, 19);

	head->right->right->right = push(head->right->right->right, 45);
	head->right->right->right = push(head->right->right->right, 40);
	head->right->right->right = push(head->right->right->right, 35);
	head->right->right->right = push(head->right->right->right, 20);


	head = flatten(head);

	printList();

return 0;
}
