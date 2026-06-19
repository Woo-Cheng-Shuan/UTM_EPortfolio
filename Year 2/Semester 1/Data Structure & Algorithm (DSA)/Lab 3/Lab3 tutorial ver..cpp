// Lab 3 - SECJ2013 - 24251 (Lab3.cpp)
// Group Members:
// 1. ???
// 2. ???

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
        //insert at beginning
		void insertNodeAtBeg(int val) {
            Node *newNode = new Node(val);		//create newNode
            newNode->next = head;				//let newNode's next = head
            newNode->prev = NULL;				//let newNode's prev = NULL
            if (last == NULL){					//check if the list is empty
            	last = newNode;					//then asg directly
    		} else {
                head->prev = newNode;			//let original list's prev = newNode's element
			}
            head = newNode;						//asg newNode = head
        }
        
        //insert at end
		void insertNodeAtEnd(int val) {
            Node *newNode = new Node(val);
            newNode->prev = tail;
            newNode->next = NULL;
            if (head == NULL){
            	head = newNode;
			} else{
				last->next = newNode;
			}
			last = newNode;
        }
        
        //sorted linkedlist
        void insertNodeAtEnd(int val) {
        	Node* currentNode = head;
        	Node* prevNode = NULL;
        	
        	while(currentNode && val > currentNode->data){		//currentNode != NULL &&
				prevNode = currentNode;
				currentNode = currentNode->next;
			}
			
			if(prevNode == NULL){			//empty list
				insertAtBeg(val);
			} else if(prevNode == last){
				insertNodeAtEnd(val);
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
            int index = 1;

	        while (currNode && currNode->data != n) {
	            prevNode = currNode;
	            currNode = currNode->next;
	            index++;
	        }
	        if (!currNode) {		//no specific value or empty list
	            cout << "Unable to find specified element: " << n << endl;
	            return 0;
	        }
	
	        //delete at first element
	        if (currNode == head) {
	            head = currNode->next;
	            currNode->next->prev = NULL;
	            delete currNode;
	        }
	        //delete last element
	        else if (currNode == last) {
	            last = prevNode;
	            prevNode->next = NULL;
	            delete currNode;
	        }
	        //delete middle element
	        else {
	            prevNode->next = currNode->next;
	            currNode->next->prev = prevNode;
	            delete currNode;
	        }
	        return index;
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
            
            cout << "\n";
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
