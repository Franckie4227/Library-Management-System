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

// Derived Class: Reference
class Reference : public Book {
private:
    string subject;

public:
    Reference(int id, string t, string a, string s)
        : Book(id, t, a), subject(s) {}

    void displayBookDetails() const override {
        cout << "Reference Book - ID: " << bookID
             << ", Title: " << title
             << ", Author: " << author
             << ", Subject: " << subject
             << ", Status: " << (isIssued ? "Issued" : "Available") << endl;
    }
};

// Base Class: Member
class Member {
protected:
    int memberID;
    string name;

public:
    Member(int id, string n) : memberID(id), name(n) {}
    virtual void displayMemberDetails() const {
        cout << "Member ID: " << memberID
             << ", Name: " << name << endl;
    }
};

// Derived Class: Student
class Student : public Member {
private:
    string gradeLevel;

public:
    Student(int id, string n, string grade)
        : Member(id, n), gradeLevel(grade) {}

    void displayMemberDetails() const override {
        cout << "Student - ID: " << memberID
             << ", Name: " << name
             << ", Grade Level: " << gradeLevel << endl;
    }
};

// Derived Class: Professor
class Professor : public Member {
private:
    string department;

public:
    Professor(int id, string n, string dept)
        : Member(id, n), department(dept) {}

    void displayMemberDetails() const override {
        cout << "Professor - ID: " << memberID
             << ", Name: " << name
             << ", Department: " << department << endl;
    }
};

// Library Class
class Library{
private:
  vector<Book*> books;  // Store base class pointers
  vector<Member*> members;

public:
    // Add a Book
    void addBook(Book* book) {
        books.push_back(book);
        cout << "Book added successfully!\n";
    }

    // Add a Member
    void addMember(Member* member) {
        members.push_back(member);
        cout << "Member added successfully!\n";
    }

    // Display All Books
    void displayAllBooks() {
        if (books.empty()) {
            cout << "No books in the library.\n";
            return;
        }
        for (const auto& book : books) {
            book->displayBookDetails();
        }
    }

    // Display All Members
    void displayAllMembers() {
        if (members.empty()) {
            cout << "No members in the library.\n";
            return;
        }
        for (const auto& member : members) {
            member->displayMemberDetails();
        }
    }
}