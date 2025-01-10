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

    virtual void displayBookDetails() const {
        cout << "Book ID: " << bookID
             << ", Title: " << title
             << ", Author: " << author
             << ", Status: " << (isIssued ? "Issued" : "Available") << endl;
    }

    // Issue and Return Methods
    void issueBook() { isIssued = true; }
    void returnBook() { isIssued = false; }
    bool getIsIssued() const { return isIssued; }
    int getBookID() const { return bookID; }
};

// Derived Class: Fiction
class Fiction : public Book {
private:
    string genre;

public:
    Fiction(int id, string t, string a, string g)
        : Book(id, t, a), genre(g) {}

    void displayBookDetails() const override {
        cout << "Fiction Book - ID: " << bookID
             << ", Title: " << title
             << ", Author: " << author
             << ", Genre: " << genre
             << ", Status: " << (isIssued ? "Issued" : "Available") << endl;
    }
};