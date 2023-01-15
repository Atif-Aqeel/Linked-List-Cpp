/*Find the middle of a given linked list
Given a singly linked list, find the middle of the linked list. 
For example, if the given linked list is 1->2->3->4->5 then the output should be 3. 
If there are even nodes, then there would be two middle nodes, we need to print the second middle element. 
For example, if the given linked list is 1->2->3->4->5->6 then the output should be 4

Method 1: 
Traverse the whole linked list and count the no. of nodes. Now traverse the list again till count/2 and return the node at count/2. 
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
		
		//Function to find the length of linkedlist
		int getLen(class Node* head){
			
			int len=0;
			class Node* temp=head;
			while(temp){
				len++;
				temp=temp->next;
			}
			return len;
		}
		
		//Function to print Middle Node
		void printMiddle(class Node* head){
			
			if(head){
				//Find Length
				int len = getLen(head);
				class Node* temp=head;
				
				//Traverse till we reached half of length
				int midIndex = len/2;
				while(midIndex-- ){
					temp = temp->next;
				}
				//temp will store the middle elements
				cout<<" Middle Element is ["<<temp->data<<"]"<<endl;
			}
		}
};

int main(){
	class Node* head=NULL;
	class NodeOperation* temp = new NodeOperation();
	
	for(int i=5; i>0; i--){
		temp->pushNode(&head, i);
		temp->printNode(head);
		temp->printMiddle(head);
	}
	
return 0;
}
