#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Book Class
class Book {
protected:
    int bookID;
    string title;
    string author;
    bool isIssued;

public:
    // Constructor
    Book(int id, string t, string a) : bookID(id), title(t), author(a), isIssued(false) {}

    // Getters
    int getBookID() const { return bookID; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    bool getIsIssued() const { return isIssued; }

    // Issue and Return Methods
    void issueBook() { isIssued = true; }
    void returnBook() { isIssued = false; }

    // Display Book Details
    void displayBook() const {
        cout << "Book ID: " << bookID << ", Title: " << title
             << ", Author: " << author << ", Status: "
             << (isIssued ? "Issued" : "Available") << endl;
    }
};

// Library class
class Library{
private:
    vector<Book> books;

public:
    // Add a Book
    void addBook(int id, string title, string author) {
        books.emplace_back(id, title, author);
        cout << "Book added successfully!\n";
    }

    // Search for a Book
    void searchBook(int id) {
        for (const auto& book : books) {
            if (book.getBookID() == id) {
                book.displayBook();
                return;
            }
        }
        cout << "Book not found!\n";
    }

    // Display All Books
    void displayAllBooks() {
        if (books.empty()) {
            cout << "No books in the library.\n";
            return;
        }
        for (const auto& book : books) {
            book.displayBook();
        }
    }

    // Issue a Book
    void issueBook(int id) {
        for (auto& book : books) {
            if (book.getBookID() == id) {
                if (!book.getIsIssued()) {
                    book.issueBook();
                    cout << "Book issued successfully!\n";
                } else {
                    cout << "Book is already issued!\n";
                }
                return;
            }
        }
        cout << "Book not found!\n";
    }

    // Return a Book
    void returnBook(int id) {
        for (auto& book : books) {
            if (book.getBookID() == id) {
                if (book.getIsIssued()) {
                    book.returnBook();
                    cout << "Book returned successfully!\n";
                } else {
                    cout << "Book was not issued!\n";
                }
                return;
            }
        }
        cout << "Book not found!\n";
    }
};

int main() {
    Library library;
    int choice, id;
    string title, author;

    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Search Book\n";
        cout << "3. Display All Books\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Book ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Title: ";
            getline(cin, title);
            cout << "Enter Author: ";
            getline(cin, author);
            library.addBook(id, title, author);
            break;

            case 2:
                cout << "Enter Book ID to Search: ";
            cin >> id;
            library.searchBook(id);
            break;

            case 3:
                library.displayAllBooks();
            break;

            case 4:
                cout << "Enter Book ID to Issue: ";
            cin >> id;
            library.issueBook(id);
            break;

            case 5:
                cout << "Enter Book ID to Return: ";
            cin >> id;
            library.returnBook(id);
            break;

            case 6:
                cout << "Exiting the system. Goodbye!\n";
            break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}