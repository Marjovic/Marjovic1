#include <iostream>
#include <direct.h>

using namespace std;

void displayMenu();
void list_file();
void create_directory();
void change_directory();


int main() {	
	int choice;
	
	while (true) {
		displayMenu();
		cout << "Enter the Number: ";
		cin >> choice;
		
		switch (choice) {
		case 1: 
			list_file();
			break;
		case 2:
			create_directory();
			break;
		case 3:
			change_directory();
			break;
		case 4:
			cout << "\nThanks For Using! \n";
			return 0;
		default:
			cout << "\nInvalid Input! Please try again. \n";					
		}	
	}	
	return 0;	
}

void displayMenu() {
	cout << "\t MAIN MENU \n";
	cout << "------------------------------ \n";
	cout << "1. To Display List of Files \n";
	cout << "2. To Create New Directory \n";
	cout << "3. To Change the Working Directory \n";
	cout << "4. Exit\n";
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

void create_directory() {
    string dir_name;
    
    cout << "Enter the directory name: ";
    cin >> dir_name;

    if (_mkdir(dir_name.c_str()) == 0) {
        cout << endl << dir_name << " Directory Successfully Created. \n \n";
    } 
	else {
        cout << "Directory already exists or could not be created. \n \n";
        cin.clear();
		fflush(stdin);
    }
    
    char currentPath[FILENAME_MAX];
    if (getcwd(currentPath, sizeof(currentPath)) != NULL) {
        cout << "Current Directory: " << currentPath << "\\" << dir_name << "\n \n";
    } 
    system("pause");
}


void change_directory() {
    int option;
    string dir_name;
    
    char currentPath[FILENAME_MAX];
    if (getcwd(currentPath, sizeof(currentPath)) != NULL) {
        cout << "\nCurrent Directory: " << currentPath << "\\" << dir_name << "\n";
    } 

	cout << "\tChange Directory \n";
    cout << "------------------------------ \n";
    cout << "1. Step by Step Backward \n";
    cout << "2. Go to root directory \n";
    cout << "3. Forward Directory \n";
    cout << "Enter your choice: ";
    cin >> option;

    switch (option) {
        case 1:
            if (chdir("..") == 0) {
                cout << "\nMoved to parent directory. \n \n";
                system("pause");
            } 
			else {
                cout << "\nFailed to move to parent directory. \n \n";
            }
            break;
        case 2:
            if (chdir("/") == 0) {
                cout << "\nMoved to root directory. \n \n";
                system("pause");
            } 
			else {
                cout << "\nFailed to move to root directory. \n \n";
            }
            break;
        case 3:
            cout << "\nEnter the path of the directory: ";
            cin >> dir_name;
            
            if (chdir(dir_name.c_str()) == 0) {
                cout << "Changed to directory: " << dir_name << "\n";
                
                if (getcwd(currentPath, sizeof(currentPath)) != NULL) {
        			cout << "Current Directory: " << currentPath << "\\" << dir_name << "\n";
    			}   
                system("pause");
            } 
			else {
                cout << "\nDirectory does not exist or failed to change directory. \n \n" ;
                cin.clear();
				fflush(stdin);
            }
            break;
        default:
            cout << "\nInvalid choice. \n \n";
            break;
    }  
}

