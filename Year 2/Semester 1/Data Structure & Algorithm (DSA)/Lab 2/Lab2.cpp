// Lab 2 - SECJ2013 - 23241 (Lab2.cpp)
// Group Members:
// 1. SABRINA HENG WEI QI A23CS0265
// 2. WOO CHENG SHUAN A23CS0283

#include <iostream>
#include <string>

using namespace std;

void printStar(int n) {
// loop function
//     for (int i = 1; i <= n; i++) {
//         cout << "*";
//     }

// recursive function
	if(n > 0){
		cout << "*";
		printStar(n-1);
	}
}

void printNum(int m, int n) {
// loop function
//     for (int i = 1; i <= n; i++) {
//         cout << i << " - ";
//         printStar(i);
//         cout << endl;
//     }

// recursive function
	if (m <= n){
		cout << m << " - ";
		printStar(m);
		cout << endl;
		printNum (m + 1, n);	
	}
}

int totalOdd(int list[], int total, int i, int n) {
//    int total = 0;

// loop function
//    for (int i = 0; i < n; i++) {
//        if (list[i] % 2 != 0) {
//             cout << list[i] << " ";
//             total += list[i];
//        }
//    }

// recursive function
	if (i < n){
		if (list[i] % 2 != 0){
			cout << list[i] << " ";
			total += list[i];
		}
		return totalOdd(list, total, i+1, n);
	}

    return total;
}

// Main function
int main(int argc, char *argv[])
{
    printNum(1, 6);

    cout << "\n\n";

    int num[6] = {0, 1, 2, 3, 4, 5};
    int result = totalOdd(num, 0, 0, 6);
    cout << "= " << result << endl;
    return 0;
}

