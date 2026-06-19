#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

// List class definition
class List {
    private:
        Student *head, *last;
        
    public:
        List() { 
            cout << "Create list...\n";
            head = NULL; last = NULL;
        }
        
        void insertNode(Student *newStud) {
        	cout << "Insert " << newStud->getName() << "\n";
		
			if(head == NULL){
				head = newStud;
				last = newStud;
				newStud->setNext(NULL);
			}
				
			Student *current = head;
			Student *prev = NULL;
					
			while (current != NULL && newStud->getName() >= current->getName()){
				prev = current;
				current = current->getNext();
			}
						
			if(prev == NULL){	//insert at beginning
				newStud->setNext(head);
				head = newStud;
			} else if (current == NULL){	//insert at end
				prev->setNext(newStud);
				newStud->setNext(NULL);
				last = newStud;
			} else{ 	//insert at end
				prev->setNext(newStud);
				newStud->setNext(current);
			}
		}
            
            
    
        Student *findNode(string name) {
        	Student *current = head;
        	
	        while (current != NULL){
	       		if (current->getName() == name){
	       			return current;
				}
				current = current->getNext();
			}	
			return NULL;
        }
        
        void deleteNode(string name) {
        	Student *current = findNode(name);
			Student *prev = NULL;
			Student *temp = head;
			
			while (temp != current){
				prev = temp;
				temp = temp->getNext();
			}
		
        	if (prev == NULL){
        		head = current->getNext();
			} else if (current->getNext() == NULL){
				prev->setNext(NULL);
				last = prev;
			} else{
				prev->setNext(current->getNext());
			}
			delete current;
        }
        
        void displayList() {
        	Student *stud = head;
        	
        	while (stud != NULL) {
        		stud->printResult();
        		stud = stud->getNext();
			}
        }
        
        Student *getHead() { return head; }
        Student *getLast() { return last; }
        
        ~List() {
        	Student *stud = head;
        	cout << "Destroy list...\n";
        	while (stud != NULL) {
        		Student *prevStud = stud;
        		stud = stud->getNext();
        		delete prevStud;
			}
		}
};
