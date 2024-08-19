#include <iostream>
using namespace std;

int main() {
	int myChoice;
	
	cout << "\t MAIN MENU \n";
	cout << "------------------------------ \n";
	cout << "1. To Display List of Files \n";
	cout << "2. To Create New Directory \n";
	cout << "3. To Change the Working Directory \n";
	cout << "4. Exit\n";
	cout << "Enter the Number: ";
	cin >> myChoice;
	
	switch (myChoice) {
		case 1: 
			int myNumber;
			
			cout << "\n\t LIST FILE DETAIL \n";
			cout << "------------------------------ \n";
			cout << "1. List All Files \n";
			cout << "2. List of Extension Files \n";
			cout << "3. List of Name Wise \n";	
			cout << "Enter the Number: ";
			cin >> myNumber;
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			cout << "\nThanks For Using!";
			return 0;
		default:
			cout << "Invalid Input!";					
	}	
}
