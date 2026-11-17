#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Book
{
private:
    int id;
    string name;
    string author;
    int stock;

public:
    Book();
    Book(int id_,string name_,string author_,int stock_);
    //getter
    int getId() const;
    string getName() const;
    string getAuthor() const;
    int getStock() const;

    //setting
    void setId(int id_);
    void setName(string name_);
    void setAuthor(string author_);
    void setStock(int stock_);

    //图书自身行为
    bool borrow();
    void giveBack();
    void showInfo() const;
};


//管理一些全局函数
void addBook(vector<Book> &bookList);
void queryBook(vector<Book> &bookList);
void modifyBook(vector<Book> &bookList);
void deleteBook(vector<Book> &bookList);


#endif
