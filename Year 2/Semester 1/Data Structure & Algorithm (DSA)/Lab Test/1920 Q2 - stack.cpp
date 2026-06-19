////////////////////////////////////////////////////////////////////////////////
// School of Computing, Faculty of Engineering, UTM
// SCSJ2013- Data Structures and Algorithms
// Semester 1, 2019/2020
// Lab Test  - Question 2 Stack (30 marks)
// Name - XXXX (Please replace with your name)
// Matric Number - XXXX (Please replace with your matric no)
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class nodeStack
{
	public:
		string plateNum;
		string brand;
		string owner;		
		nodeStack *next;
		
		nodeStack() {
			plateNum = "";
			brand = "";
			owner = "";
		}
		
		nodeStack(string plateNum, string brand, string owner) {
			this->plateNum = plateNum;
			this->brand = brand;
			this->owner = owner;
		}
		
};

class stack
{
	nodeStack *top;
	
	public:
		void createStack() {
			top = NULL;
		}
		
		bool isEmpty() {
			return top == NULL;
		}
		
		void push ();
		void pop ();
		void display();
		void search();
};

void stack::push ()
{
	string newPlateNum, newBrand, newOwner;
	nodeStack *node = new nodeStack;
	
	if (node == NULL)
		cout << "Cannot allocate memory" << endl;
	else
	{
		system("CLS");
		cout << "<<<<<<< Insert Car >>>>>>>" << endl << endl;
		
		//Task 1 - Write the code to insert new car to the stack. Firstly, ask the 
		//		   user to enter the information of the car which is the plate 
		//		   number, brand/ model and owner's name. Note: Please use the variables
		//		   defined in line 59. Then, insert the new car by using the information  
		//		   entered (please use the object pointer defined in line 60) - 8 MARKS
	
		//Answer Task 1 start here
		cout << "Plate Number : ";
		getline(cin, newPlateNum);
		cout << "Brand/ Model : ";
		getline(cin, newBrand);
		cout << "Owner	     : ";
		getline(cin, newOwner);
		
		node->plateNum = newPlateNum;
		node->brand = newBrand;
		node->owner = newOwner;
		
		node->next = top;
		top = node;

		//Task 1 end
	}
}

void stack::pop()
{
	nodeStack *delNode;
	
	system("CLS");
	cout << "<<<<<<< Remove Car >>>>>>>" << endl << endl
		 << "Plate Number : " << top->plateNum << endl
	 	 << "Brand/ Model : " << top->brand << endl
	     << "Owner        : " << top->owner << endl << endl;

	cout << "<< Press any key to continue >>";
	cin.get();

	//Task 2 - Write the code to remove the car from the stack (please use 
	//         the object pointer defined in line 94) - 3 MARKS

	//Answer Task 2 start here
	delNode = top;
	top = top->next;
	delete delNode;
	//Task 2 end
}

void stack::display()
{
	int counter = 1;
	
	nodeStack *currNode; 
	system("CLS");
	cout << "<<<<<<< Display Cars >>>>>>>" << endl << endl;

	//Task 3 - Write the code to display all the cars in the stack (please use 
	//         the object pointer defined in line 121) - 9 MARKS
	
	//Answer Task 3 start here
	currNode = top;
	while(currNode != NULL){
		cout << "[" << counter << "] Plate Number : " << currNode->plateNum << endl
			 << "    Brand/ Model : " << currNode->brand << endl
			 << "    Owner	 : " << currNode->owner << endl;
			 
		currNode = currNode->next;
		counter++;
	}
	//Task 3 end
	
	cout << "<< Press any key to continue >>";
	cin.get();
}

void stack::search()
{
	int choice;
	string input;
	
	nodeStack *currNode; 
	system("CLS");
	
	cout << "<<<<<<< Search Car(s) >>>>>>>" << endl; 

	//Task 4 - Write the code to search the car in the stack based on brand/  
	//         model (please use the object pointer defined in line 151) - 10 MARKS
	
	//Answer Task 4 start here
	cout << "Enter brand/ model: ";
	getline(cin, input);
	
	currNode = top;
	while(currNode != NULL){
		cout << endl << endl;
		
		if(currNode->brand == input){
			cout << "Plate Number : " << currNode->plateNum << endl
				 << "Brand/ Model : " << currNode->brand << endl
				 << "Owner	     : " << currNode->owner << endl;
		}
		break;
	}
	//Task 4 end
	
	cout << "<< Finish searching... Press any key to continue >>";
	cin.get();
}

//To display main menu
void dispMenu()
{
	system("CLS");
	cout << "MUNIR GARAGE MANAGEMENT SYSTEM" << endl
		 << "\n\t1. Insert car" 
		 << "\n\t2. Remove car" 
		 << "\n\t3. Search car" 
		 << "\n\t4. Display cars" 
		 << "\n\t5. Exit" << endl;		 
}

int main()
{
	stack carRec;
	carRec.createStack();
	int choice;
	
	do
	{
		dispMenu();
		cout << "\nEnter your choice [1-5]: ";
		cin >> choice;
		cin.ignore();
		
		switch(choice)
		{
			case 1: carRec.push();
					break;
			case 2: carRec.pop();
					break;
			case 3: carRec.search();
					break;
			case 4: carRec.display();
					break;
			default: cout << "\nThank you.. see you again.." << endl;
					 return 0;
		}
		
	} while ((choice > 0) && (choice < 5));
	
 	return 0;    
}

