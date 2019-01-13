#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include "Library.h"
using namespace std;

//main constructor
Library::Library() {
	bobby = NULL;
}

//add book to list
void Library::addBook(string bookTitle, string publishingHouse, int publishingYear) {

    //check for title availability

    if(bobby!=NULL){
        for(int index = 0; index<sizeBook;index++){
            if(findBookAt(index)!=NULL){

                if(toLower(findBookAt(index)->getTitle()) == toLower(bookTitle)) {
                    cout<<"Book already exists"<<endl;
                    return;
                }
            }
            else return;

        }
    }

	//search for the book
	if (bobby == NULL) {
		bobby = new Book[1];
		bobby[0].setTitle(bookTitle);
		bobby[0].setPublisher(publishingHouse);
		bobby[0].setYear(publishingYear);

		sizeBook = 1;
        cout << "Book 1 added"<<endl;
	}
	else{

        for(int index = 0; index<sizeBook;index++){
             //similarity

            if(toLower(findBookAt(index)->getTitle())==toLower(bookTitle)){
                cout<<"found: "<<findBookAt(index)->getTitle()<<" "<<bookTitle<<endl;
                return;
            }
        }

        //Add book
		Book*temp = new Book[++sizeBook];
		for (int i = 0; i < (sizeBook - 1); i++) {
			temp[i] = bobby[i];
		}
		temp[sizeBook - 1].setTitle(bookTitle);
		temp[sizeBook - 1].setPublisher(publishingHouse);
		temp[sizeBook - 1].setYear(publishingYear);

		delete[] bobby;
		bobby = new Book[sizeBook];
		for (int i = 0; i < sizeBook; i++) {
			bobby[i] = temp[i];
		}
		delete[] temp;

		cout << "Book "<< sizeBook<<" added"<<endl;
	}
}


void Library::removeBook(string bookTitle){

    //check book availability
    if(bobby!=NULL){
        for(int index = 0; index<sizeBook;index++){
            if(findBookAt(index)!=NULL){
                if(toLower(findBookAt(index)->getTitle()) == toLower(bookTitle))
                    break;

            }
            else {
                cout<<"book is not found"<<endl;
                return;
            }

        }
    }



    //search for the book
    int flag=0;//flag for availability
	for (int i = 0; i < (sizeBook); i++) {
        if(bobby[i].getTitle()==bookTitle){
			flag = 1;
			break;//book is found
        }
    }
    //if book is not available
    if(flag==0){
        cout<<"entitled book is not available"<<endl;
        return;
    }
	if(bobby!=NULL){
        // Search for title
        int pivot;
        for (pivot=0; pivot<sizeBook; pivot++)
            if (bobby[pivot].getTitle() == bookTitle)
                break;//found


       if (pivot < sizeBook){
         sizeBook--;

         for (int i=pivot; i<sizeBook; i++)
            bobby[i] = bobby[i+1];
       }
	}
}

Book*Library::findBook(string bookTitle){
    if(sizeBook==0) return NULL;
    for(int i=0; i<sizeBook;i++){
        if(bobby[i].getTitle()==bookTitle)
            return &bobby[i];
    }
    cout<<"no book found"<<endl;
    return NULL;
}

Book*Library::findBookAt(int loc){
    if(sizeBook==0) return NULL;
    for(int i=0; i<sizeBook;i++){
        if(i == loc)
            return &bobby[i];
    }
    cout<<"no book found"<<endl;
    return NULL;
}

//add co-author/*

void Library::addCoauthor(string bookTitle, string coauthorName) {

    if(findBook(bookTitle)==NULL){
        cout<<"title does not exist"<<endl;
        return;
    }

    findBook(bookTitle)->addAuthor(coauthorName);



}

//remove co-author

void Library::removeCoauthor(string bookTitle, string coauthorName) {

    findBook(bookTitle)->removeAuthor(coauthorName);

}


//show all books' info

void Library::displayAllBooks() {
    cout<<endl<<"Listing book..."<<endl<<endl;

    if(bobby==NULL){
        cout<<"no book is added yet"<<endl<<endl;

    }
    else{
        cout << "Book amount: "<<sizeBook << "\n";
        if (sizeBook == 1) {
            cout << "1)  "<< bobby[0].getTitle() << " " << bobby[0].getPublisher() << " " << bobby[0].getYear() << endl;
        }
        else if (sizeBook > 1) {
            for (int c = 0; c < sizeBook; c++) {
                cout << (c + 1) << ") " << bobby[c].getTitle() << " " << bobby[c].getPublisher() << " " << bobby[c].getYear() << endl;
            }
        }
    }
    cout<<endl;
}

//show a specific book' info

void Library::displayBook(string bookTitle) {

    if (sizeBook == 1) {
        cout<<endl<<"Listing entitled book:"<<endl;

		cout << bobby[0].getTitle() << ", " << bobby[0].getPublisher() << "," << bobby[0].getYear() << endl;
		bobby[0].displayAllAuthor();


	}
	else if (sizeBook > 1) {
        cout<<endl<<"Listing entitled book:"<<endl;
		for (int c = 0; c < sizeBook; c++) {
            if(toLower(bobby[c].getTitle())==toLower(bookTitle)){
                cout << bobby[c].getTitle() << ", " << bobby[c].getPublisher() << ", " << bobby[c].getYear() << endl;
                bobby[0].displayAllAuthor();
            }
		}
	}
}

//list all authors for the book

void Library::displayAuthor(string newAuthorName) {
    int count=0;
   cout<<newAuthorName<<endl;
   for(int i=0;i<sizeBook;i++){
        for(int j=0;j<findBookAt(i)->getSize();j++){
            if(findBookAt(i)->getAus(j)==newAuthorName){
                cout<<findBookAt(i)->getTitle()<<", "<<findBookAt(i)->getYear()<<" for the " <<i+1<<" th book"<<endl;
                count++;
            }
        }
    }
    if(count==0) cout<<"--EMPTY--"<<endl;
}

//Set and get for book size

void Library::setBookSize(int newSizeBook) {
	sizeBook = newSizeBook;
}
int Library::getBookSize() {
	return sizeBook;
}


//convert a string to upper case

string  Library::toLower(string str){
    for(auto& c : str){
        c = tolower(c);
    }
    return str;
}



// Delete library
Library::~Library() {
    if(bobby!=NULL)
        delete[] bobby;
 }
