#include <iostream>
#include <string>
using namespace std;

class Book
{
private:
    const int BookId;
    string title;
    static int totalBooks;

public:
    Book(int id, string t) : BookId(id), title(t)
    {
        totalBooks++;
    }

    void displayBookDetails() const
    {
        cout << "Book ID : " << BookId << endl;
        cout << "Book Title : " << title << endl;
        cout << "----------------------" << endl;
    }

    static void displayTotalBooks()
    {
        cout << "Total Books : " << totalBooks << endl;
    }

    ~Book()
    {
        cout << "Book Removed from System." << endl;
    }
};

int Book::totalBooks = 0;

class Library
{
private:
    Book *book;
    int size;

public:
    Library(Book b[], int s)
    {
        book = b;
        size = s;
    }

    void displayBooksInfo() const
    {
        for (int i = 0; i < size; i++)
        {
            book[i].displayBookDetails();   
        }
    }
};

int main()
{
    Book b[5] = {
        Book(1, "OOP"),
        Book(2, "Data Structures"),
        Book(3, "Operating Systems"),
        Book(4, "Database Systems"),
        Book(5, "Computer Networks")};

    Library l(b, 5);   // Array is also a pointer so when we pass an array in a constructor there is no need to pass the address of object.

    cout << "\n_____ LIBRARY BOOKS _____\n";
    l.displayBooksInfo();

    Book::displayTotalBooks();

    return 0;
}