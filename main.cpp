#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <iomanip>

using namespace std;

#define MAX_SIZE 100  // Define the maximum size of the stack

// Step 1: Declare function prototypes 
bool isBalanced(const string &expression);
string extractSymbols(const string &expression);
void processExpressions(const string &filename);

// Step 2: Main function with menu
int main() {
    int choice;
    string filename;
    
    do {
        // Display menu options
        cout << "\nMenu:\n";
        cout << "1. Process expressions from a file\n";
        cout << "2. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        if (choice == 1) {
            cout << "Enter filename: ";
            cin >> filename;
            processExpressions(filename);  // Call function to process file
        }
    } while (choice != 2);  // Loop until user chooses to quit
    
    cout << "Goodbye!\n";
    return 0;
}


