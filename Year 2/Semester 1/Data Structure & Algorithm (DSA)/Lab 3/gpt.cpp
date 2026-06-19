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

        void insertNode(int val) {
            Node *newNode = new Node(val);

            if (isEmpty()) {
                head = last = newNode;
            } else {
                Node *current = head;
                while (current != NULL && current->data < val) {
                    current = current->next;
                }

                if (current == head) { // Insert at the beginning
                    newNode->next = head;
                    head->prev = newNode;
                    head = newNode;
                } else if (current == NULL) { // Insert at the end
                    newNode->prev = last;
                    last->next = newNode;
                    last = newNode;
                } else { // Insert in the middle
                    newNode->next = current;
                    newNode->prev = current->prev;
                    current->prev->next = newNode;
                    current->prev = newNode;
                }
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

        int deleteNode(int n) {
            Node *current = head;
            int position = 1;

            while (current != NULL && current->data != n) {
                current = current->next;
                position++;
            }

            if (current == NULL) {
                return 0; // Node not found
            }

            if (current == head) { // Delete head node
                head = head->next;
                if (head != NULL) {
                    head->prev = NULL;
                } else {
                    last = NULL; // List becomes empty
                }
            } else if (current == last) { // Delete last node
                last = last->prev;
                last->next = NULL;
            } else { // Delete middle node
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }

            cout << "Delete node " << n << " at position = " << position << "\n";
            delete current;
            return position;
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
