#include <iostream>
#include <string>
using namespace std;

class Book 
{
protected:
    const int bookId;
    string title;
    static int totalBooks;

public:
    Book(int id, string t) : bookId(id), title(t) {
        totalBooks++;
    }

    virtual ~Book() {
        cout << "Book Removed." << endl;
    }

    void displayBookInfo() const {
        cout << "\n___Book Details___\n";
        cout << "Book ID : " << bookId << endl;
        cout << "Book's Title : " << title << endl;
    }

    virtual void showBookInfo() const {
        cout << "\n___Book Details___\n";
        cout << "Book ID : " << bookId << endl;
        cout << "Book's Title : " << title << endl;
    }

    static void showTotalBooks() {
        cout << "Total Books : " << totalBooks << endl;
    }
};

int Book::totalBooks = 0;

class EBook : public Book
{
protected:
    string fileFormat;

public:
    EBook(string fileform, int id, string t) 
        : Book(id, t), fileFormat(fileform) {}

    ~EBook() {
        cout << "Ebook Removed." << endl;
    }

    void showBookInfo() const override {
        cout << "\n___Ebook Details___\n";
        cout << "File Format : " << fileFormat << endl;
        cout << "Book ID : " << bookId << endl;
        cout << "Book's Title : " << title << endl;
    }
};

int main() {
    Book b[3] = { Book(1, "OOP"), Book(2, "Physics"), Book(3, "Math") };

    for (int i = 0; i < 3; i++) {
        b[i].displayBookInfo();
    }

    EBook e("PDF", 4, "C++");

    Book* ptr;
    ptr = &e;

    ptr->showBookInfo();  
    cout << endl;

    Book::showTotalBooks();

    return 0;
}