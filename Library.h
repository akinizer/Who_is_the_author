#include <iostream>
#include <iostream>
#include <string>
#include <string>
#include "Book.h"
using namespace std;

class Library{

private:
    Book*bobby;
   
    int sizeBook;
   
    int x;

public:
    Library();
    ~Library();

    void addBook(string bookTitle, string publishingHouse,int publishingYear);
    void removeBook(string bookTitle);
    void addCoauthor(string bookTitle, string coauthorName);
    void removeCoauthor( string bookTitle, string coauthorName);

    void displayAllBooks();
    void displayBook(string bookTitle);
    void displayAuthor(string authorName);

    void setBookSize(int);
    int getBookSize();

    void setAuthorSize(int);
    int getAuthorSize();

    string toLower(string);

    Book*findBook(string bookTitle);
    Book*findBookAt(int loc);



    Book*getBook(){
        return bobby;
    }


















};
