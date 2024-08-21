#include <iostream>
#include <direct.h>;

using namespace std;

void list_file();
void create_directory();
void change_directory();


int main() {
	
	int choice;
	
	while (true) {
		cout << "\t MAIN MENU \n";
		cout << "------------------------------ \n";
		cout << "1. To Display List of Files \n";
		cout << "2. To Create New Directory \n";
		cout << "3. To Change the Working Directory \n";
		cout << "4. Exit\n";
		cout << "Enter the Number: ";
		cin >> choice;
		
		switch (choice) {
		case 1: 
			list_file();
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			cout << "\nThanks For Using! \n";
			return 0;
		default:
			cout << "\nInvalid Input! \n";					
		}	
	}	
	return 0;	
}

void list_file() {
	int myChoice;
	cout << "\n\t LIST FILE DETAIL \n";
	cout << "------------------------------ \n";
	cout << "1. List All Files \n";
	cout << "2. List of Extension Files \n";
	cout << "3. List of Name Wise \n";	
	cout << "Enter the Number: ";
	cin >> myChoice;
}



