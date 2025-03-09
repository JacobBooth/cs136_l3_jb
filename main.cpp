#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <iomanip>

using namespace std;

#define MAX_SIZE 100  // Define the maximum size of the stack

// Declare function prototypes 
bool isBalanced(const string &expression);
string extractSymbols(const string &expression);
void processExpressions(const string &filename);

// Main function with menu
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

// Define a Stack class (array-based implementation)
class Stack {
    private:
        char arr[MAX_SIZE];  // Array to hold stack elements
        int top;  // Index of the top element
    public:
        Stack() : top(-1) {}  // Constructor initializes top to -1 (empty stack)
        bool isEmpty() { return top == -1; }  // Check if stack is empty
        bool isFull() { return top == MAX_SIZE - 1; }  // Check if stack is full
        void push(char ch) { if (!isFull()) arr[++top] = ch; }  // Push element onto stack
        char pop() { return isEmpty() ? '\0' : arr[top--]; }  // Pop element from stack
        char peek() { return isEmpty() ? '\0' : arr[top]; }  // Peek at the top element
    };
    
// Function to check if an expression is balanced
bool isBalanced(const string &expression) {
    Stack stack;  // Create a stack instance
    for (size_t i = 0; i < expression.length(); i++) {
        char ch = expression[i];
        
        if (ch == '(' || ch == '{' || ch == '[')
            stack.push(ch);
        
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (stack.isEmpty()) return false;  // Stack should not be empty
            char top = stack.pop();  // Pop the top element
            if ((ch == ')' && top != '(') || (ch == '}' && top != '{') || (ch == ']' && top != '['))
                return false;  // Mismatched symbols
        }
    }
    return stack.isEmpty();  // Stack should be empty if balanced
}

// Function to extract only opening and closing symbols
string extractSymbols(const string &expression) {
    string result;
    for (char ch : expression) {
        if (ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == '[' || ch == ']')
            result += ch;  // Append only bracket symbols
    }
    return result;
}

// Function to process expressions from a file
void processExpressions(const string &filename) {
    ifstream file(filename);  // Open the file
    if (!file) {
        cout << "Error: Could not open file." << endl;
        return;
    }
    
    // Print table header
    cout << left << setw(30) << "Original Expression" << setw(30) << "Symbols Only" << setw(15) << "Balanced" << endl;
    cout << string(75, '-') << endl;
    
    string expression;
    while (getline(file, expression)) {  // Read each line from the file
        if (expression.length() > 60) {  // Check length constraint
            cout << left << setw(30) << "ERROR: Too long" << setw(30) << "" << setw(15) << "NO" << endl;
            continue;
        }
        string symbols = extractSymbols(expression);  // Extract only brackets
        bool balanced = isBalanced(expression);  // Check if balanced
        cout << left << setw(30) << expression << setw(30) << symbols << setw(15) << (balanced ? "YES" : "NO") << endl;
    }
    file.close();  // Close the file
}

/*
Menu:
1. Process expressions from a file
2. Quit
Enter your choice: 1
Enter filename: expressions.txt

Original Expression            Symbols Only                  Balanced      
------------------------------------------------------------------------
(a + b) * {c / [d - e]}        ( { [ ] } )                   YES          
( { [ ] } )                    ( { [ ] } )                   YES          
( { [ } ] )                    ( { [ } ] )                   NO           
"Hello" + 'A'                  " " + ' '                     YES          
<!-- This is a comment -->       <!-- -->                      YES          
(a + b) * { c / [ d - e ]       ( { [ ]                       NO           
/* Valid comment */             /* */                       /*  YES */         
/* Unfinished comment           /*                            NO           
( "string" + 'x' )              ( " " + ' ' )                 YES          

Menu:
1. Process expressions from a file
2. Quit
Enter your choice: 2
Goodbye!
*/
