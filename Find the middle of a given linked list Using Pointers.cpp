/*Method 2: 
Traverse linked list using two-pointers. 
Move one pointer by one and the other pointers by two. 
When the fast pointer reaches the end, the slow pointer will reach the middle of the linked list.
*/

#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
};

class NodeOperation{
	public:
		
		//Function to add new node
		void pushNode(class Node** head_ref, int data_value){
			
			//Allocate Node
			class Node* new_Node = new Node();
			
			//Put in the data 
			new_Node->data = data_value;
			
			//Link the old list of the new node
			new_Node->next = *head_ref;
			
			//Move the head to point to the new node
			*head_ref = new_Node;	
		}
		
		//Function to print the given linked list
		void printNode(class Node* head){
			
			while(head!=NULL){
				cout<< head->data <<" ->";
				head=head->next;
			}
			cout<<"NULL"<<endl;
		}
		
		//Function to print Middle Node
		void printMiddle(class Node* head){
			struct Node *slow_ptr = head;
			struct Node *fast_ptr = head;
			
			if(head!=NULL){
				while(fast_ptr != NULL && fast_ptr->next != NULL){
					fast_ptr = fast_ptr->next->next;
					slow_ptr = slow_ptr->next;
				}
				cout<<"Middle element is ["<< slow_ptr->data <<"]"<<endl;
			}
		}
		
};

int main(){
	class Node *head = NULL;
	class NodeOperation *temp = new NodeOperation();
	
	for(int i=5; i>0; i--){
		temp->pushNode(&head, i);
		temp->printNode(head);
		temp->printMiddle(head);
	} 
	
return 0;
}
