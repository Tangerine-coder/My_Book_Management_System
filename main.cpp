#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
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
    cout << "0.保存并退出" << endl;
    cout << "请输入选择：";
}
int main()
{
#ifdef _WIN32
    // 让控制台按 UTF-8 显示和接收中文：源码是 UTF-8，不改代码页就会乱码
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    vector<Book> bookList;
    while(true)
    {
        menu();
        int op;
        cin >> op;
        if (op == 0)
        {
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
    }
    return 0;
}
