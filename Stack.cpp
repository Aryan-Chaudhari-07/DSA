#include <iostream>
#include <string>
using namespace std;

#define SIZE 5

class BookStack
{
private:
    string stack[SIZE];
    int topIndex;

public:
    BookStack()
    {
        topIndex = -1;
    }

    // Add Book to Stack
    void addBook(string title)
    {
        if (topIndex == SIZE - 1)
        {
            cout << "Stack Overflow! Shelf is full.\n";
            return;
        }

        stack[++topIndex] = title;
        cout << "\"" << title << "\" added successfully.\n";
    }

    // Remove Book from Stack
    void removeBook()
    {
        if (topIndex == -1)
        {
            cout << "Stack Underflow! No books available.\n";
            return;
        }

        cout << "\"" << stack[topIndex] << "\" removed from the stack.\n";
        topIndex--;
    }

    // Show Top Book
    void viewTopBook()
    {
        if (topIndex == -1)
        {
            cout << "Stack is empty.\n";
            return;
        }

        cout << "Top Book: " << stack[topIndex] << endl;
    }

    // Display All Books
    void displayBooks()
    {
        if (topIndex == -1)
        {
            cout << "No books in the stack.\n";
            return;
        }

        cout << "\nBooks Available (Top to Bottom):\n";

        for (int i = topIndex; i >= 0; i--)
        {
            cout << stack[i] << endl;
        }
    }
};

int main()
{
    BookStack libraryStack;
    int option;
    string bookName;

    do
    {
        cout << "\n========== STACK MENU ==========\n";
        cout << "1. Add Book\n";
        cout << "2. Remove Book\n";
        cout << "3. View Top Book\n";
        cout << "4. Display Books\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> option;

        switch (option)
        {
        case 1:
            cin.ignore();
            cout << "Enter Book Name: ";
            getline(cin, bookName);
            libraryStack.addBook(bookName);
            break;

        case 2:
            libraryStack.removeBook();
            break;

        case 3:
            libraryStack.viewTopBook();
            break;

        case 4:
            libraryStack.displayBooks();
            break;

        case 5:
            cout << "Program Closed Successfully.\n";
            break;

        default:
            cout << "Please enter a valid option.\n";
        }

    } while (option != 5);

    return 0;
}