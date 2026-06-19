#include <iostream>
using namespace std;

class FruitNode{
	private:
		string name;
		float price;
		
	public:
		FruitNode *next;
		FruitNode(string n, float p){
			name = n;
			price = p;
		}
		
		void getFruitInfo(){
			cout << name << " = RM" << price;
		}
		
};

class List{
	private:
		FruitNode *headNode;
		
	public:
		List(){
			headNode = NULL;
		}
		
		void task1(string, float);
		void task2();
		void task3(int, string, float);
		void task4();
};

void List::task1(string n, float p){
	FruitNode *newNode = new FruitNode(n, p);
	FruitNode *lastNode;
	
	if (headNode == NULL){		//empty list
		headNode = newNode;
		lastNode = newNode;
		headNode->next = newNode;
	} else{						//non-empty list
		lastNode->next = newNode;
		newNode->next = headNode;
		headNode = newNode;
	}
}

void List::task2(){
	cout << "Fruit List" << endl;
	
	FruitNode *current = headNode;
	current->getFruitInfo();
	current = current->next;
	while (current != headNode){
		cout << " >> ";
		current->getFruitInfo();
		current = current->next;
	}
	cout << endl << endl;
}

void List::task3(int i, string n, float p){
	FruitNode *newNode = new FruitNode(n, p);
	FruitNode *current = headNode;
	FruitNode *prev = NULL;
	int index = 1;
	
	do{
		if(index != i){
			prev = current;
			current = current->next;
			index++;
		} else{
			newNode->next = current;
			prev->next = newNode;
			return;
		}
	}while(current != headNode);
}

void List::task4(){
	FruitNode *current = headNode;
	FruitNode *prev = NULL;
	
	while(current->next != headNode){
		prev = current;
		current = current->next;
	}
	
	prev->next = headNode;
	delete current;
}

int main(){
	List fruitList;
	
	//Incomplete main function definition
	fruitList.task1("Kiwi", 21.89);
	fruitList.task2();
	fruitList.task1("Apple", 11.95);
	fruitList.task2();
	fruitList.task1("Orange", 16.5);
	fruitList.task2();
	fruitList.task3(2, "Grape", 19.95);
	fruitList.task2();
	fruitList.task4();
	fruitList.task2();
	fruitList.task4();
	fruitList.task2();

	return 0;
}