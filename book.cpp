#include "book.h"
#include <limits>
#include <fstream>
Book::Book() : id(0), name(""), author(""), stock(0) {}
Book::Book(int id_, string name_, string author_, int stock_) : id(id_), name(name_), author(author_), stock(stock_) {}

int Book::getId() const { return id; }
string Book::getName() const { return name; }
string Book::getAuthor() const { return author; }
int Book::getStock() const { return stock; }

void Book::setId(int id_) { id = id_; }
void Book::setName(string name_) { name = name_; }
void Book::setAuthor(string author_) { author = author_; }
void Book::setStock(int stock_) { stock = stock_; }

// 清缓冲区这一整行
void clearLine()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

bool Book::borrow()
{
    if (stock > 0)
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
    cout << "编号\t书名\t作者\t库存" << endl;
    cout << id << '\t' << name << '\t' << author << '\t' << stock << endl;
}

void addBook(vector<Book> &bookList)
{
    int id;
    string name;
    string author;
    int stock;
    cout << "请输入编号：";
    while (!(cin >> id))
    {
        cin.clear();
        clearLine();
        cout << "输入不合法，请输入编号（数字型）:";
    }
    for (auto &b : bookList)
    {
        if (b.getId() == id)
        {
            cout << "编号已存在，添加失败！" << endl;
            return;
        }
    }
    cout << "请输入书名：";
    cin >> name;
    cout << "请输入作者：";
    cin >> author;
    cout << "请输入库存: ";
    while (!(cin >> stock))
    {
        cin.clear();
        clearLine();
        cout << "输入不合法，请输入库存（数字型）：";
    }
    Book newBook(id, name, author, stock);
    bookList.push_back(newBook);
    cout << "添加成功！" << endl;
}

void queryBook(vector<Book> &bookList)
{
    int choice;
    cout << "1.按编号查询    2.按书名查询" << endl;
    cout << "请输入选项：";
    while (!(cin >> choice))
    {
        cin.clear();
        clearLine();
        cout << "输入不合法，请输入选项（数字型）：";
    }
    if (choice == 1)
    {
        int id;
        cout << "请输入编号： ";
        while (!(cin >> id))
        {
            cin.clear();
            clearLine();
            cout << "输入不合法，请输入编号（数字型）：";
        }
        for (auto &b : bookList)
        {
            if (b.getId() == id)
            {
                b.showInfo();
                return;
            }
        }
        cout << "未查找到此书！" << endl;
    }
        else if (choice == 2)
        {
            string name;
            cout << "请输入书名: ";
            cin >> name;
            for (auto &b : bookList)
            {
                if (b.getName() == name)
                {
                    b.showInfo();
                    return;
                }
            }
            cout << "未查找到此书！" << endl;
        }
        else
        {
            cout << "输入选项无效，请重新输入";
        }
}

void modifyBook(vector<Book> &bookList)
{
    int choice;
    cout << "1.按编号修改    2.按书名修改" << endl;
    cout << "请输入选项：";
    while (!(cin >> choice))
    {
        cin.clear();
        clearLine();
        cout << "输入不合法，请输入选项（数字型）：";
    }
    if (choice == 1)
    {
        int id;
        cout << "请输入编号：";
        while (!(cin >> id))
        {
            cin.clear();
            clearLine();
            cout << "输入不合法，请输入编号（数字型）：";
        }
        for (auto &b : bookList)
        {
            if (b.getId() == id)
            {
                int stock;
                cout << "输入库存数：";
                while(!(cin>>stock))
                {
                    cin.clear();
                    clearLine();
                    cout << "输入不合法，请输入库存（数字型）：";
                }
                if (stock < 0)
                {
                    cout << "库存为负，不合法！" << endl;
                    return;
                }
                else
                {
                    b.setStock(stock);
                    cout << "修改成功！" << endl;
                    return;
                }
            }
        }
        cout << "未查找到此书！" << endl;
    }
    else if (choice == 2)
    {
        string name;
        cout << "请输入书名：" << " ";
        cin >> name;
        for (auto &b : bookList)
        {
            if (b.getName() == name)
            {
                int stock;
                cout << "输入库存数：";
                while (!(cin >> stock))
                {
                    cin.clear();
                    clearLine();
                    cout << "输入不合法，请输入库存（数字型）：";
                }
                if (stock < 0)
                {
                    cout << "库存为负，不合法！" << endl;
                    return;
                }
                else
                {
                    b.setStock(stock);
                    cout << "修改成功！" << endl;
                    return;
                }
            }
        }
        cout << "未查找到此书！" << endl;
    }
    else
    {
        cout << "输入选项无效，请重新选择";
    }
}

void deleteBook(vector<Book> &bookList)
{
    int choice;
    cout << "1.按编号删除    2.按名字删除" << endl;
    cout << "请输入选项";
    while (!(cin >> choice))
    {
        cin.clear();
        clearLine();
        cout << "输入不合法，请输入选项（数字型）：";
    }
    if (choice == 1)
    {
        int id;
        cout << "请输入编号：";
        while (!(cin >> id))
        {
            cin.clear();
            clearLine();
            cout << "输入不合法，请输入编号（数字型）：";
        }
        for (auto it = bookList.begin(); it != bookList.end(); it++)
        {
            if (it->getId() == id)
            {
                bookList.erase(it);
                cout << "删除成功！" << endl;
                return;
            }
        }
        cout << "未查找到此书！" << endl;
    }
    else if (choice == 2)
    {
        string name;
        cout << "请输入书名：";
        cin >> name;
        for (auto it = bookList.begin(); it != bookList.end(); it++)
        {
            if (it->getName() == name)
            {
                bookList.erase(it);
                cout << "删除成功！" << endl;
                return;
            }
        }
        cout << "未查找到此书！" << endl;
    }
    else
    {
        cout << "输入选项无效，请重新选择";
    }
}

void borrowBook(vector<Book> &bookList)
{
    int choice;
    cout << "1.按编号借书   2.按书名借书" << endl;
    cout << "请输入选项：";
    while (!(cin >> choice))
    {
        cin.clear();
        clearLine();
        cout << "输入不合法，请输入选项（数字型）：";
    }
    if (choice == 1)
    {
        int id;
        cout << "请输入编号：";
        while (!(cin >> id))
        {
            cin.clear();
            clearLine();
            cout << "输入不合法，请输入编号（数字型）：";
        }
        for (auto it = bookList.begin(); it != bookList.end(); it++)
        {
            if (it->getId() == id)
            {
                int stock = it->getStock();
                if (it->borrow())
                {
                    cout << "借书成功！" << endl;
                    return;
                }
                else
                {
                    cout << "借书失败，库存不够！" << endl;
                    return;
                }
            }
        }
        cout << "未查找到此书！" << endl;
    }
    else if (choice == 2)
    {
        string name;
        cout << "请输入书名：";
        cin >> name;
        for (auto it = bookList.begin(); it != bookList.end(); it++)
        {
            if (it->getName() == name)
            {
                if (it->borrow())
                {
                    cout << "借书成功！" << endl;
                    return;
                }
                else
                {
                    cout << "借书失败，库存不够！" << endl;
                    return;
                }
            }
        }
        cout << "未查找到此书！" << endl;
    }
    else
    {
        cout << "输入选项无效，请重新选择";
    }
}

void givebackBook(vector<Book> &bookList)
{
    int choice;
    cout << "1.按编号还书   2.按书名还书" << endl;
    cout << "请输入选项";
    while (!(cin >> choice))
    {
        cin.clear();
        clearLine();
        cout << "输入不合法，请输入选项（数字型）：";
    }
    if (choice == 1)
    {
        int id;
        cout << "请输入编号：";
        while (!(cin >> id))
        {
            cin.clear();
            clearLine();
            cout << "输入不合法，请输入编号（数字型）：";
        }
        for (auto it = bookList.begin(); it != bookList.end(); it++)
        {
            if (it->getId() == id)
            {
                it->giveBack();
                cout << "还书成功！" << endl;
                return;
            }
        }
        cout << "未查找到此书！" << endl;
    }
    else if (choice == 2)
    {
        string name;
        cout << "请输入书名：" << endl;
        cin >> name;
        for (auto it = bookList.begin(); it != bookList.end(); it++)
        {
            if (it->getName() == name)
            {
                it->giveBack();
                cout << "还书成功！" << endl;
                return;
            }
        }
        cout << "未查找到此书！" << endl;
    }
    else
    {
        cout << "输入选项无效，请重新选择";
    }
}

void showBook(vector<Book> &bookList)
{
    cout << "编号\t书名\t作者\t库存" << endl;
    for (auto &b : bookList)
    {
        cout << b.getId() << '\t';
        cout << b.getName() << '\t';
        cout << b.getAuthor() << '\t';
        cout << b.getStock() << endl;
    }
}

void load(vector<Book> &bookList)
{
    ifstream inFile("books.txt");
    if (!inFile)
    {
        cout << "无法打开文件，可能是第一次运行程序，文件不存在" << endl;
        return;
    }
    int id, stock;
    string name, author;
    while (inFile >> id >> name >> author >> stock)
    {
        Book b(id, name, author, stock);
        bookList.push_back(b);
    }
    inFile.close();
}

void save(vector<Book> &bookList)
{
    ofstream outFile("books.txt");
    if (!outFile)
    {
        cout << "无法打开文件，保存失败" << endl;
        return;
    }
    for (auto &b : bookList)
    {
        outFile << b.getId() << ' ' << b.getName() << ' ' << b.getAuthor() << ' ' << b.getStock() << endl;
    }
    outFile.close();
}
