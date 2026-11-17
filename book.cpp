#include "book.h"

Book::Book():id(0),name(""),author(""),stock(0){}
Book::Book(int id_, string name_, string author_, int stock_):id(id_),name(name_),author(author_),stock(stock_){}

int Book::getId() const{return id;}
string Book::getName() const{return name;}
string Book::getAuthor() const{return author;}
int Book::getStock() const{return stock;}

void Book::setId(int id_) {id = id_;}
void Book::setName(string name_) {name = name_;}
void Book::setAuthor(string author_) {author = author_;}
void Book::setStock(int stock_) {stock = stock_;}

bool Book::borrow()
{
    if (stock>0)
    {
        stock--;
        return true;
    }
    return false;
}

void Book::giveBack()
{
    stock++;
}

void Book::showInfo() const
{
    cout << id << 't' << name << 't' << author << 't' << stock << endl;
}

void addBook(vector<Book> &bookList)
{
    int id;
    string name;
    string author;
    int stock;
    cout << "请输入编号：" <<" ";
    cin >> id;
    for (auto &b:bookList)
    {
        if (b.getId() == id)
        {
            cout << "编号已存在，添加失败！" << endl;
            return;
        }
    }
    cin >> name >> author >> stock;
    Book newBook(id,name,author,stock);
    bookList.push_back(newBook);
}

void queryBook(vector<Book> &bookList)
{
    int choice;
    cout << "1.按编号查询    2.按名字查询" << endl;
    cin >> choice;
    if (choice == 1)
    {
        int id;
        cin >> id;
        for (auto &b:bookList)
        {
            if(b.getId() == id)
            {
                cout << "编号" << '\t' << "书名" << '\t' << "作者" << '\t' << "库存" << endl;
                cout << b.getId() << '\t';
                cout << b.getName() << '\t';
                cout << b.getAuthor() << '\t';
                cout << b.getStock() << '\t';
                return;
            }
        }
        cout << "未查找到此书！" << endl;
    }
    else if (choice == 2)
    {
        string name;
        cin >> name;
        for (auto &b:bookList)
        {
            if (b.getName() == name)
            {
                cout << "编号" << '\t' << "书名" << '\t' << "作者" << '\t' << "库存" << endl;
                cout << b.getId() << '\t';
                cout << b.getName() << '\t';
                cout << b.getAuthor() << '\t';
                cout << b.getStock() << '\t';
                return;
            }
        }
        cout << "未查找到此书！" << endl;
    }
}
