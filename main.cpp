#include <iostream>
#include <book.h>
using namespace std;
void menu()
{
    cout << "1.增加图书" << endl;
    cout << "2.查询图书" << endl;
    cout << "3.修改图书" << endl;
    cout << "4.删除图书" << endl;
    cout << "0.保存并退出" << endl;
}
int main()
{
    vector<Book> bookList;
    int op;
    cin >> op;
    menu();
    while(true)
    {
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
    }
    return 0;
}
