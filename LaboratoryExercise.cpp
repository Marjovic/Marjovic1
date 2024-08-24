#include <iostream>
#include <direct.h>
#include <io.h>

using namespace std;

void displayMenu();
void listFile();
void createDirectory();
void changeDirectory();

int main() {    
    int choice;
    
    while (true) {
        displayMenu();
        cout << "Enter the Number: ";
        cin >> choice;
        
        switch (choice) {
        case 1: 
            listFile();
            break;
        case 2:
            createDirectory();
            break;
        case 3:
            changeDirectory();
            break;
        case 4:
            cout << "\nThanks For Using! \n";
            return 0;
        default:
        	system("cls");
            cout << "\nInvalid Input! Please try again. \n";
			cin.clear();
        	fflush(stdin);                    
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

void listFile() {
    int myChoice;
    cout << "\n\t LIST FILE DETAIL \n";
    cout << "------------------------------ \n";
    cout << "1. List All Files \n";
    cout << "2. List of Extension Files \n";
    cout << "3. List of Name Wise \n";    
    cout << "Enter the Number: ";
    cin >> myChoice;
    
    struct _finddata_t fileinfo;
    long handle;
    string pattern;

    switch (myChoice) {
        case 1:
            cout << "\nList of All (*.*) Files \n";
            pattern = "*.*";
            break;
        case 2:
            {
                string extension;
                cout << "Enter the file extension (e.g., .txt): ";
                cin >> extension;
                pattern = "*" + extension;
                cout << "\nList of Files with Extension: " << extension << "\n";
            }
            break;
        case 3:
            {
                string namePattern;
                cout << "Enter the name pattern (e.g., moha*.*): ";
                cin >> namePattern;
                pattern = namePattern;
                cout << "\nList of Files with Pattern: " << namePattern << "\n";            
            }
            break;
        default:
            cout << "\nInvalid Input! Please try again. \n";
            cin.clear();
        	fflush(stdin);
    }

    handle = _findfirst(pattern.c_str(), &fileinfo);
    if (handle == -1) {
        cout << "No files found.\n \n";
        system("pause");
        system("cls");
        return;
    }

    int fileCount = 0;
    do {
        if (!(fileinfo.attrib & _A_SUBDIR)) {
            cout << fileinfo.name << endl;
            fileCount++;
        }
    } while (_findnext(handle, &fileinfo) == 0);

    _findclose(handle);    

    cout << "\nTotal Files: " << fileCount << endl;
    system("pause");
    system("cls");
}

void createDirectory() {
	system("cls");
    string dirName;
    cout << "Enter the directory name: ";
    cin >>dirName;

    if (_mkdir(dirName.c_str()) == 0) {
        cout << endl << dirName << " Directory Successfully Created. \n \n";
    } 
    else {
    	system("cls");
        cout << "Directory already exists or could not be created. \n \n";
        cin.clear();
        fflush(stdin);
    }
    
    char currentPath[FILENAME_MAX];
    if (getcwd(currentPath, sizeof(currentPath)) != NULL) {
        cout << "Current Directory: " << currentPath << "\\" << dirName << "\n \n";
    } 
    system("pause");
    system("cls");
}


void changeDirectory() {
	system("cls");
    int option;
    string dirName;
    
    char currentPath[FILENAME_MAX];
    if (getcwd(currentPath, sizeof(currentPath)) != NULL) {
        cout << "\nCurrent Directory: " << currentPath << "\\" << dirName << "\n";
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
                system("cls");
            } 
            else {
            	system("cls");
                cout << "\nFailed to move to parent directory. \n \n";
            }
            break;
        case 2:
            if (chdir("/") == 0) {
                cout << "\nMoved to root directory. \n \n";
                system("pause");
                system("cls");
            } 
            else {
            	system("cls");
                cout << "\nFailed to move to root directory. \n \n";
            }
            break;
        case 3:
            cout << "\nEnter the path of the directory: ";
            cin >> dirName;
            
            if (chdir(dirName.c_str()) == 0) {
                cout << "Changed to directory: " << dirName << "\n";
                
                if (getcwd(currentPath, sizeof(currentPath)) != NULL) {
                    cout << "Current Directory: " << currentPath << "\\" << dirName << "\n";
                }   
                system("pause");
                system("cls");
            } 
            else {
            	system("cls");
                cout << "\nDirectory does not exist or failed to change directory. \n \n" ;
                cin.clear();
                fflush(stdin);
            }
            break;
        default:
        	system("cls");
            cout << "\nInvalid choice. \n \n";
            cin.clear();
            fflush(stdin);
    }  
}

