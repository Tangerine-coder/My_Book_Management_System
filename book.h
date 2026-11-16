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
    void setId(int id_) const;
    void setName(string name_) const;
    void setAuthor(string author_) const;
    void setStock(int stock_) const;

    //图书自身行为
    void borrow() const;
    void getBack() const;
    void menuInfo() const;
};


//管理一些全局函数
void addBook(vector<Book> &bookList);
void queryBook(vector<Book> &bookList);
void modifyBook(vector<Book> &bookList);
void deleteBook(vector<Book> &bookList);
