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

// 实现书名、作者可以实现带空格的
string trim(const string &str)
{
    size_t first = str.find_first_not_of("\t\r\n ");
    if (first == string::npos)
        return "";
    size_t last = str.find_last_not_of("\t\r\n ");
    return str.substr(first, (last - first + 1));
}

string readLine()
{
    string line;
    getline(cin, line);
    return trim(line);
}

// 按指定分隔符分割字符串，自动trim首尾空白
vector<string> split(const string &str,char delimiter)
{
    vector<string> res;
    string temp;
    for (char c:str)
    {
        if (c == delimiter)
        {
            res.push_back(trim(temp));
            temp.clear();
        }
        else
        {
            temp += c;
        }
    }
    if (!temp.empty())
    {
        res.push_back(trim(temp));
    }
    return res;
}

// 功能函数实现
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
    int stock;
    cout << "请输入编号：";
    while (!(cin >> id))
    {
        cin.clear();
        clearLine();
        cout << "输入不合法，请输入编号（数字型）:";
    }
    clearLine(); // 清除缓冲区，避免后续输入被截断
    for (auto &b : bookList)
    {
        if (b.getId() == id)
        {
            cout << "编号已存在，添加失败！" << endl;
            return;
        }
    }
    cout << "请输入书名：";
    string name = readLine();
    cout << "请输入作者：";
    string author = readLine();
    cout << "请输入库存: ";
    while (!(cin >> stock))
    {
        cin.clear();
        clearLine();
        cout << "输入不合法，请输入库存（数字型）：";
    }
    clearLine(); // 清除缓冲区，避免后续输入被截断
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
    clearLine(); // 清除缓冲区，避免后续输入被截断
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
            cout << "请输入书名: ";
            string name = readLine();
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
            cout << "输入选项无效，请重新输入" << endl;
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
    clearLine(); // 清除缓冲区，避免后续输入被截断
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
        clearLine(); // 清除缓冲区，避免后续输入被截断
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
                clearLine(); // 清除缓冲区，避免后续输入被截断
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
        cout << "请输入书名：" << " ";
        string name = readLine();
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
                clearLine(); // 清除缓冲区，避免后续输入被截断
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
        cout << "输入选项无效，请重新选择" << endl;
    }
}

void deleteBook(vector<Book> &bookList)
{
    int choice;
    cout << "1.按编号删除    2.按名字删除" << endl;
    cout << "请输入选项：";
    while (!(cin >> choice))
    {
        cin.clear();
        clearLine();
        cout << "输入不合法，请输入选项（数字型）：";
    }
    clearLine(); // 清除缓冲区，避免后续输入被截断
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
        cout << "请输入书名：";
        string name = readLine();
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
        cout << "输入选项无效，请重新选择" << endl;
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
    clearLine(); // 清除缓冲区，避免后续输入被截断
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
        clearLine(); // 清除缓冲区，避免后续输入被截断
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
        cout << "请输入书名：";
        string name = readLine();
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
        cout << "输入选项无效，请重新选择" << endl;
    }
}

void givebackBook(vector<Book> &bookList)
{
    int choice;
    cout << "1.按编号还书   2.按书名还书" << endl;
    cout << "请输入选项：";
    while (!(cin >> choice))
    {
        cin.clear();
        clearLine();
        cout << "输入不合法，请输入选项（数字型）：";
    }
    clearLine(); // 清除缓冲区，避免后续输入被截断
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
        clearLine(); // 清除缓冲区，避免后续输入被截断
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
        cout << "请输入书名：";
        string name = readLine();
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
        cout << "输入选项无效，请重新选择" << endl;
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
    bookList.clear(); // 加载前清空容器，避免重复数据
    string line;
    while (getline(inFile, line))
    {
        if (line.empty())
            continue; // 跳过空行
        vector <string> fields = split(line, ',');
        if (fields.size() != 4)
        {
            cout << "数据格式错误，跳过此行：" << line << endl;
            continue;
        }
        try
        {
            int id = stoi(fields[0]);
            string name = fields[1];
            string author = fields[2];
            int stock = stoi(fields[3]);
            Book b(id, name, author, stock);
            bookList.push_back(b);
        }
        catch(...)
        {
            // 数字转化失败也跳过该行，但是不整体中断
            cout << "跳过数据异常的行：" << line << endl;
        }
    }
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
        outFile << b.getId() << ',' << b.getName() << ',' << b.getAuthor() << ',' << b.getStock() << endl;
    }
    outFile.close();
}
