#include <iostream>
#include "Library.h"
using namespace std;

int main()
{
    Library*L=new Library();

    L->displayAllBooks();

    L->addBook("a","b",1);//string bookTitle, string publishingHouse,int publishingYear

    L->addBook("bc","c",100);
    L->addBook("bc","c",100);
    L->addBook("Bc","c",100);

    L->addBook("C++"," is best",100);

    string str;
    str="a";

    cout<<"Book: ( " <<L->findBook(str)->getTitle()<<" "<<L->findBook(str)->getPublisher()
    <<" "<< L->findBook(str)->getYear()<<" )"<<endl;

    cout<<endl;

    L->addCoauthor("a","abx");

    L->addCoauthor("a","abx");

    L->addCoauthor("a","asfad");

    L->addCoauthor("a","abdawearfd");

    L->displayBook("a");

    cout<<"------------------"<<endl;

    L->displayAuthor("aby");


    return 0;
}
