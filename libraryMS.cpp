// base class , book name isbn author name
// issuesbookdetail name emp id emp bookname
//action issue return
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
protected:
    string bookName;
    string isbn;
    string authorName;

public:
    Book() : bookName(""), isbn(""), authorName("") {}

    Book(string bName, string bIsbn, string bAuthor)
        : bookName(bName), isbn(bIsbn), authorName(bAuthor) {}

    void inputBookDetails() {
        cout << "Enter Book Name: ";
        getline(cin, bookName);
        cout << "Enter ISBN: ";
        getline(cin, isbn);
        cout << "Enter Author Name: ";
        getline(cin, authorName);
    }

    void displayBookDetails() {
        cout << "Book Name: " << bookName << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Author Name: " << authorName << endl;
    }

    string getBookName() {
        return bookName;
    }
};

class Employee {
protected:
    string employeeName;
    string employeeId;

public:
    Employee() : employeeName(""), employeeId("") {}

    void inputEmployeeDetails() {
        cout << "Enter Employee Name: ";
        getline(cin, employeeName);
        cout << "Enter Employee ID: ";
        getline(cin, employeeId);
    }

    void displayEmployeeDetails() {
        cout << "Employee Name: " << employeeName << endl;
        cout << "Employee ID: " << employeeId << endl;
    }

    string getEmployeeName() {
        return employeeName;
    }

    string getEmployeeId() {
        return employeeId;
    }
};

class IssuedBook : public Book, public Employee {
private:
    bool isIssued;

public:
    IssuedBook() : Book(), Employee(), isIssued(false) {}

    void issueBook() {
        if (isIssued) {
            cout << "Book is already issued to another employee." << endl;
        } else {
            inputEmployeeDetails();
            isIssued = true;
            cout << "Book issued successfully to " << employeeName << " (ID: " << employeeId << ")." << endl;
        }
    }

    void returnBook() {
        if (isIssued) {
            cout << "Book returned successfully by " << employeeName << " (ID: " << employeeId << ")." << endl;
            employeeName = "";
            employeeId = "";
            isIssued = false;
        } else {
            cout << "Book is not issued to anyone." << endl;
        }
    }

    void displayIssuedDetails() {
        if (isIssued) {
            cout << "Issued Book Details:" << endl;
            displayBookDetails();
            displayEmployeeDetails();
        } else {
            cout << "Book is not issued to anyone." << endl;
        }
    }

    bool checkAvailability() {
        return !isIssued;
    }
};

int main() {
    vector<IssuedBook> library(5);

    
    cout << "Enter details for 5 books:" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "\nBook " << i + 1 << ":" << endl;
        library[i].inputBookDetails();
    }

    int choice;
    string bookName;

    while (true) {
        cout << "\nLibrary Management System" << endl;
        cout << "1. View Books" << endl;
        cout << "2. Issue Book" << endl;
        cout << "3. Return Book" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
        case 1:
            cout << "\nAvailable Books:" << endl;
            for (auto &book : library) {
                book.displayBookDetails();
                cout << (book.checkAvailability() ? "Status: Available" : "Status: Issued") << endl;
                cout << "----------------------" << endl;
            }
            break;

        case 2:
            cout << "Enter the book name to issue: ";
            getline(cin, bookName);
            for (auto &book : library) {
                if (book.getBookName() == bookName) {
                    if (book.checkAvailability()) {
                        book.issueBook();
                    } else {
                        cout << "Book is already issued to someone else." << endl;
                    }
                    break;
                }
            }
            break;

        case 3:
            cout << "Enter the book name to return: ";
            getline(cin, bookName);
            for (auto &book : library) {
                if (book.getBookName() == bookName) {
                    book.returnBook();
                    break;
                }
            }
            break;

        case 4:
            cout << "Exiting the system. Goodbye!" << endl;
            return 0;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
