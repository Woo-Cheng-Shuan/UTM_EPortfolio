// Lab 3 - SECJ2013 - 24251 (Lab3.cpp)
// Group Members:
// 1. Sabrina Heng Wei Qi
// 2. Woo Cheng Shuan

#include <iostream>
#include <string>

using namespace std;

// Class section
class Node {
  public:
    int data;
    Node *next, *prev;

    Node(int n) {
        data = n;
        next = NULL;
        prev = NULL;
    }
};

// List class (linked list)
class List {
    private:
       Node *head;
       Node *last;

    public:
        List() { head = NULL; last = NULL; }

        ~List() {
            Node *n = head;

            while (n != NULL) {
                Node *temp = n;
                n = n->next;
                delete(temp);
            }
        }

        bool isEmpty() {  return head == NULL; }

        // please complete the insertNode function
        void insertNode(int val) {        
	        //sorted linkedlist
        	Node* currentNode = head;
        	Node* prevNode = NULL;
        	
        	while(currentNode != NULL && val > currentNode->data){		
				prevNode = currentNode;
				currentNode = currentNode->next;
			}
			
			//insert at the beginning
			if(prevNode == NULL){						
				Node *newNode = new Node(val);		
	            newNode->next = head;				
	            newNode->prev = NULL;				
	            if (last == NULL){					
	            	last = newNode;					
	    		} else {
	                head->prev = newNode;			
				}
	            head = newNode;
			//insert at the end	
			} else if(prevNode == last){
				Node *newNode = new Node(val);
	            newNode->prev = last;
	            newNode->next = NULL;
	            if (head == NULL){
	            	head = newNode;
				} else{
					last->next = newNode;
				}
				last = newNode;
			//insert at the middle
			} else{
				Node* newNode = new Node(val);
				currentNode->prev->next = newNode;
				newNode->prev = currentNode->prev;
				newNode->next = currentNode;
				currentNode->prev = newNode;
			}
		}
        
        int findNode(int n) {
           Node *currNode = head;
           int post = 1;
           while (currNode != NULL) {
               if (n == currNode->data) return post;
			   currNode = currNode->next;
               post++;
           }
           return 0;
        }

        // please complete the deleteNode function
        int deleteNode(int n) {
            Node* currNode = head;
            Node* prevNode = NULL;
            int position;

	        while (currNode != NULL && currNode->data != n) {
	            prevNode = currNode;
	            currNode = currNode->next;
	        }
	        if (!currNode) {		//no specific value or empty list
	            cout << "Unable to find specified element: " << n << endl;
	            return 0;
	        }
	
	        //delete at first element
	        if (currNode == head) {
	        	position = findNode(n);
	            head = currNode->next;
	            currNode->next->prev = NULL;
	            delete currNode;
	        }
	        //delete last element
	        else if (currNode == last) {
	        	position = findNode(n);
	            last = prevNode;
	            prevNode->next = NULL;
	            delete currNode;
	        }
	        //delete middle element
	        else {
	        	position = findNode(n);
	            prevNode->next = currNode->next;
	            currNode->next->prev = prevNode;
	            delete currNode;
	        }
	        
	        cout << "Delete node " << n << " at position = " << position << "\n\n";
	        return 0;
	    }

        void displayList() {
            Node *n = head;
            cout << "displayList:\n";
            
            while (n != NULL) {
                cout << n->data << " ";
                n = n->next;
            }
            
            cout << "\n";
        }
        
        void displayListReverse() {
            Node *n = last;
            cout << "displayListReverse:\n";
            
            while (n != NULL) {
                cout << n->data << " ";
                n = n->prev;
            }
            
            cout << "\n\n";
        }
};


// Main function section
int main() {
   List linkedList;

   // do not change this insert values sequence
   linkedList.insertNode(0);
   linkedList.insertNode(9);
   linkedList.insertNode(1);
   linkedList.insertNode(6);
   linkedList.insertNode(5);

   linkedList.displayList();
   linkedList.displayListReverse();
   
   linkedList.deleteNode(5);
   linkedList.displayList();
   linkedList.displayListReverse();
   
   linkedList.deleteNode(0);
   linkedList.displayList();
   linkedList.displayListReverse();
   
   linkedList.deleteNode(9);
   linkedList.displayList();
   linkedList.displayListReverse();
   
   return 0;
}
