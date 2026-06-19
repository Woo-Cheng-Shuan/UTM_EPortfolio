// Lab 1 - SECJ2013 - 24251 (Student.h)
// Group Members:
// 1. SABRINA HENG WEI QI
// 2. WOO CHENG SHUAN

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Class defintion
class Student {
    private:
    	string name;
    	int cwMark;
    	int feMark;
    	
    public:
    	Student(string n, int c, int f){
    		name = n;
    		cwMark = c;
    		feMark = f;
		}
    	
    	int getTotalMark(){
    		return cwMark + feMark;
		}
		
    	string getGrade(){
    		int totMark = getTotalMark();
    		if (totMark >= 75)
    			return "A";
    		else if (totMark >= 65)
    			return "B";
    		else if (totMark >= 50)
    			return "C";
    		else if (totMark >= 35)
    			return "D";
    		else
    			return "E";
		}
		
    	void printInfo(){
    		cout << "Name: " << name << endl;
    		cout << "Coursework: " << cwMark << endl;
    		cout << "Final Exam: " << feMark << endl << endl;
		}
		
    	void printResult(){
    		cout << name << " " << getTotalMark() << " " << getGrade() << endl;
		}
		
    	void printResultFile(fstream &outFile){
    		outFile << name << " " << getTotalMark() << " " << getGrade() << endl;
		}
    	
    	~Student(){
    		cout << "Destroy student object - " << name << endl;
		}
};

#endif