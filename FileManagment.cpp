#include<fstream>
#include<iostream>
#include<string.h>
using namespace std;
class Book
{
    private:
    int book_id;
    char title[30];
    float price;
    public:
    Book()
    {
        book_id=0;
        strcpy(title,"no title");
        price=0;
    }
    void getBookData()
    {
        cout<<"Enter bookid,title and price of a book :";
        cin>>book_id;
        cin.ignore();
        cin.getline(title,20);
        cin>>price;
    }
    void showBookData()
    {
        cout<<"\n"<<book_id<<"  "<<title<<"  "<<price;
    }
    int storeBook();
    void viewAllBooks();
    void serchBook(char *);
};
void Book::serchBook(char *t)
{   
    int counter=0;
    ifstream fin;
    fin.open("BookInfo.txt",ios::in|ios::binary);
    if(!fin)
    {
        cout<<"\n File not found "<<endl;
    }
    else
    {
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof())
        {
            if(!strcmp(t,title))
            {
                counter++;
                showBookData();
            }
            fin.read((char*)this,sizeof(*this));
        }
        if(counter==0)
        {
            cout<<"\nRecord not found "<<endl;
        }
        fin.close();
        // return(1);
    }
}
int Book::storeBook()
{
    if(book_id==0&&price==0)
    {
        cout<<"\nBook data not intialized";
        return(0);
    }
    else{
        ofstream fout;
        fout.open("BookInfo.txt",ios::app|ios::binary);
        fout.write((char*)this,sizeof(*this));
        fout.close();
        return(1);
    }
}
void Book::viewAllBooks()
{
    ifstream fin;
    fin.open("BookInfo.txt",ios::in|ios::binary);
    if(!fin)
    {
        cout<<"File not found :";
    }
    else
    {
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof())
        {
            showBookData();
            fin.read((char*)this,sizeof(*this));
        }
        fin.close();
    }
}
int main()
{
    Book b1,b2;
    b1.getBookData();
    b1.showBookData();
    b1.storeBook();
    b2.showBookData();
    b2.storeBook();
    b1.viewAllBooks();
    b1.serchBook("java");
    return 0;
}