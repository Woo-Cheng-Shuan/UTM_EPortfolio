// Lab 1 - SECJ2013 - 24251 (Lab1.cpp)
// Group Members:
// 1. SABRINA HENG WEI QI
// 2. WOO CHENG SHUAN

#include <iostream>
#include <string>
#include <fstream>
#include "Student.h"

using namespace std;

// main function
int main() {
    const int LIST_SIZE = 10;
    Student* studList[LIST_SIZE];
    int index = 0;
    
    string n;
    int c, f;
    
    fstream inFile("Marks.txt", ios::in);
    fstream outFile("Results.txt", ios::out); 
 
	 	
	while(inFile >> n >> c >> f && index < LIST_SIZE){
		if (index < LIST_SIZE){
			studList[index] = new Student(n, c, f);
			index++;
		}else{
			break;
		}
	}

	inFile.close();
	 
	cout << "Student mark info: " << endl;
	for (int i=0; i<index; i++){
		studList[i] -> printInfo();
		studList[i] -> getTotalMark();
		studList[i] -> getGrade();
	}
	
	cout << endl << endl << "Print and save results to file: " << endl;
	for (int i=0; i<index; i++){
		studList[i] -> printResult();
		studList[i] -> printResultFile(outFile);
		delete studList[i];
	}
    
    return 0;
}