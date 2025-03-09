#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <iomanip>

using namespace std;

#define MAX_SIZE 100  

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
            processExpressions(filename); 
        }
    } while (choice != 2);  
    
    cout << "Goodbye!\n";
    return 0;
}

// Define a Stack class (array-based implementation)
class Stack {
    private:
        char arr[MAX_SIZE];  
        int top; 
    public:
        Stack() : top(-1) {} 
        bool isEmpty() { return top == -1; } 
        bool isFull() { return top == MAX_SIZE - 1; } 
        void push(char ch) { if (!isFull()) arr[++top] = ch; }  
        char pop() { return isEmpty() ? '\0' : arr[top--]; }  
        char peek() { return isEmpty() ? '\0' : arr[top]; } 
    };
    
// Function to check if an expression is balanced
bool isBalanced(const string &expression) {
    Stack stack;  
    for (size_t i = 0; i < expression.length(); i++) {
        char ch = expression[i];
        
        if (ch == '(' || ch == '{' || ch == '[')
            stack.push(ch);
        
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (stack.isEmpty()) return false;  
            char top = stack.pop();  
            if ((ch == ')' && top != '(') || (ch == '}' && top != '{') || (ch == ']' && top != '['))
                return false;  
        }
    }
    return stack.isEmpty();  
}

// Function to extract only opening and closing symbols
string extractSymbols(const string &expression) {
    string result;
    for (char ch : expression) {
        if (ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == '[' || ch == ']')
            result += ch;  
    }
    return result;
}

// Function to process expressions from a file
void processExpressions(const string &filename) {
    ifstream file(filename); 
    if (!file) {
        cout << "Error: Could not open file." << endl;
        return;
    }
    
    // Print table header
    cout << left << setw(30) << "Original Expression" << setw(30) << "Symbols Only" << setw(15) << "Balanced" << endl;
    cout << string(75, '-') << endl;
    
    string expression;
    while (getline(file, expression)) {  
        if (expression.length() > 60) {  
            cout << left << setw(30) << "ERROR: Too long" << setw(30) << "" << setw(15) << "NO" << endl;
            continue;
        }
        string symbols = extractSymbols(expression);  
        bool balanced = isBalanced(expression);  
        cout << left << setw(30) << expression << setw(30) << symbols << setw(15) << (balanced ? "YES" : "NO") << endl;
    }
    file.close();  
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
