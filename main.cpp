#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#include <limits>
#endif

#include <iostream>
#include "book.h"
using namespace std;
void menu()
{
    cout << "=====图书管理系统=====" << endl;
    cout << "1.增加图书" << endl;
    cout << "2.查询图书" << endl;
    cout << "3.修改图书" << endl;
    cout << "4.删除图书" << endl;
    cout << "5.借阅图书" << endl;
    cout << "6.归还图书" << endl;
    cout << "7.显示所有图书信息" << endl;
    cout << "0.保存并退出" << endl;
    cout << "请输入选择：";
}

void clearMainLine()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main()
{
#ifdef _WIN32
    // 让控制台按 UTF-8 显示和接收中文：源码是 UTF-8，不改代码页就会乱码
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    vector<Book> bookList;
    load (bookList);
    while(true)
    {
        menu();
        int op;
        while(!(cin >> op))
        {
            cin.clear();
            clearMainLine();
            cout << "输入不合法，请输入选项（数字型）：";
        }
        if (op == 0)
        {
            save(bookList);
            cout << "保存成功" << endl;
            break;
        }
        else if (op == 1)
        {
            addBook(bookList);
        }
        else if (op == 2)
        {
            queryBook(bookList);
        }
        else if (op == 3)
        {
            modifyBook(bookList);
        }
        else if (op == 4)
        {
            deleteBook(bookList);
        }
        else if (op == 5)
        {
            borrowBook(bookList);
        }
        else if (op == 6)
        {
            givebackBook(bookList);
        }
        else if (op == 7)
        {
            showBook(bookList);
        }
        else
        {
            cout << "输入选项无效，请重新选择：" << endl;
        }
    }
    return 0;
}
