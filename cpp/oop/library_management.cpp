#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Book {
public:
    Book(const string& title, const string& author) {
        this->title = title;
        this->author = author;
        isIssued = false;
    }

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    bool getIssuedStatus() const { return isIssued; }
    void setIssuedStatus(bool status) { isIssued = status; }

private:
    string title;
    string author;
    bool isIssued;
};

class Library {
public:
    void addBook(const string& title, const string& author) {
        books[title] = Book(title, author);
    }

    bool issueBook(const string& title) {
        if (books.find(title) != books.end() && !books[title].getIssuedStatus()) {
            books[title].setIssuedStatus(true);
            return true;
        }
        return false;
    }

    bool returnBook(const string& title) {
        if (books.find(title) != books.end() && books[title].getIssuedStatus()) {
            books[title].setIssuedStatus(false);
            return true;
        }
        return false;
    }

    bool checkAvailability(const string& title) const {
        if (books.find(title) != books.end()) {
            return !books.at(title).getIssuedStatus();
        }
        return false;
    }

private:
    unordered_map<string, Book> books;
};

int main() {
    Library library;
    library.addBook("The Great Gatsby", "F. Scott Fitzgerald");
    library.addBook("1984", "George Orwell");

    cout << "Is '1984' available? " << library.checkAvailability("1984") << endl;

    library.issueBook("1984");
    cout << "Is '1984' available after issuing? " << library.checkAvailability("1984") << endl;

    library.returnBook("1984");
    cout << "Is '1984' available after returning? " << library.checkAvailability("1984") << endl;

    return 0;
}
//
