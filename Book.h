#include <iostream>
//#include "Author.h"
using namespace std;

class Book{
private:
    string title;
    string name;
    int year;
    int sizeAuthor;
    string*aussie;

public:
    Book();

    void setTitle(string);
    string getTitle();

    void setPublisher(string);
    string getPublisher();

    void setYear(int);
    int getYear();

    void setSize(int);
    int getSize();

    void setAus(int,string);
    string getAus(int);

    void authorList();

    void displayAuthor( string authorName );
    void addAuthor(string coauthorName);
    void removeAuthor(string authorName);
    string*findAuthor(string coauthorName);
    string*findAuthorAt(int);

    void displayAllAuthor();


    string toLower(string);


    ~Book();
};

