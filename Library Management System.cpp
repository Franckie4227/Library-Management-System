#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Book Class
class Book {
private:
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