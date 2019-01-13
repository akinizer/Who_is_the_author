#include <iostream>
#include "Book.h"
using namespace std;

    Book::Book(){
        aussie=NULL;
        sizeAuthor=0;
    }

    void Book::setTitle(string newTitle){
        Book::title=newTitle;
    }

    string Book::getTitle(){
        return title;
    }

    void Book::setPublisher(string newName){
        name=newName;
    }

    string Book::getPublisher(){
        return name;
    }

    void Book::setYear(int newYear){
        year=newYear;
    }

    int Book::getYear(){
        return year;
    }

    void Book::setSize(int newSize){
        sizeAuthor=newSize;
    }

    int Book::getSize(){
        return sizeAuthor;
    }

     void Book::setAus(int loc, string aName){
        aussie[loc]=aName;
    }

    string Book::getAus(int loc){
        return aussie[loc];
    }



    void Book::authorList(){
        cout<<endl<<"Listing author..."<<endl<<endl;

        if(aussie==NULL){
            cout<<"no author is added yet"<<endl<<endl;

        }
        else{
            cout << "Author amount: "<<sizeAuthor << "\n";
            if (sizeAuthor == 1) {
                cout << "1)  "<< aussie[0] << endl;
            }
            else if (sizeAuthor > 1) {
                for (int c = 0; c < sizeAuthor; c++) {
                    cout << (c + 1) << ") " << aussie[c] << endl;
                }
            }
        }
    }

    void Book::addAuthor(string coauthorName){
         if(aussie!=NULL){
            for(int index = 0; index<sizeAuthor;index++){
                if(findAuthorAt(index)!=NULL){
                    if(toLower(getAus(index))== toLower(coauthorName)) {
                        cout<<"Author already exists"<<endl;
                        return;
                    }
                }
                else return;

            }
        }
        //string strIn = "NaN", strLis = "NaN";
        //strIn = bookTitle;

        //search for the book
        if (aussie == NULL) {
            aussie = new string[1];
            aussie[0]=coauthorName;

            sizeAuthor = 1;
            cout << "Author 1 added"<<endl;
        }
        else{

            string*temp = new string[++sizeAuthor];
            for (int i = 0; i < (sizeAuthor - 1); i++) {
                temp[i] = aussie[i];
            }
            temp[sizeAuthor - 1]=coauthorName;

            delete[] aussie;
            aussie = new string[sizeAuthor];
            for (int i = 0; i < sizeAuthor; i++) {
                aussie[i] = temp[i];
            }
            delete[] temp;

        }



        cout << "Author "<< sizeAuthor<<" added"<<endl;
    }

    void Book::removeAuthor(string authorName){
        //availability
         if(aussie!=NULL){
            for(int index = 0; index<sizeAuthor;index++){
                if(findAuthorAt(index)!=NULL){
                    if(toLower(getAus(index)) == toLower(authorName))
                        break;//found
                }
                else{
                    cout<<"author is not found"<<endl;
                    return;
                }


            }
        }

        //search for the book
        int flag=0;//flag for availability
        for (int i = 0; i < (sizeAuthor); i++) {
            if(aussie[i]==authorName){
                flag = 1;
                break;//book is found
            }
        }
        //if book is not available
        if(flag==0){
            cout<<"author is not available"<<endl;
            return;
        }
        if(aussie!=NULL){
            // Search for title
            int pivot;
            for (pivot=0; pivot<sizeAuthor; pivot++)
                if (aussie[pivot] == authorName)
                    break;//found


           if (pivot < sizeAuthor){
             sizeAuthor--;

             for (int i=pivot; i<sizeAuthor; i++)
                aussie[i] = aussie[i+1];
           }
        }
    }

    void Book::displayAuthor( string authorName ){
        cout<<"Author: "<<*findAuthor( authorName )<<endl;
    }

    void Book::displayAllAuthor(){
        cout<<endl<<"Listing author..."<<endl<<endl;

        if(aussie==NULL){
            cout<<"no author is added yet"<<endl<<endl;

        }
        else{
            cout << "Author amount: "<<sizeAuthor << "\n";
            if (sizeAuthor == 1) {
                cout << aussie[0] << " (for the 1th coauthor)"<< endl;
            }
            else if (sizeAuthor > 1) {
                for (int c = 0; c < sizeAuthor; c++) {
                    cout <<  aussie[c] << " (for the "<< (c + 1) << "th coauthor) " << endl;
                }
            }

        }
    }

    string*Book::findAuthor(string coauthorName){
        if(sizeAuthor==0) return NULL;
        for(int i=0; i<sizeAuthor;i++){
            if(aussie[i]==coauthorName)
                return &aussie[i];
        }
        cout<<"no author found"<<endl;
        return NULL;

    }
    string*Book::findAuthorAt(int loc){
        if(sizeAuthor==0) return NULL;
        for(int i=0; i<sizeAuthor;i++){
            if(i == loc)
                return &aussie[i];
        }
        cout<<"no author found"<<endl;
        return NULL;
    }


    string Book::toLower(string str){
        for(auto& c : str){
            c = tolower(c);
        }
        return str;
    }


    Book::~Book(){
        delete aussie;
    }

