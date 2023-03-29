#include <iostream>
#define MAX 100
using namespace std;
struct Student
{
    int roll_no;
    std::string name;
    std::string phone_number;
};

struct ArrList
{
private:
    Student stud[MAX];
    int len;
    int maxLen;

public:
    ArrList()
    {
        len = 0;
        maxLen = MAX;
    }
    int isEmpty() { return len == 0; }
    int isFull() { return len == maxLen; }
    int getLen() { return len; }
    int getMaxLen() { return maxLen; }
    int addItem(Student X, int p)
    {
        if (isFull())
        {
            cout << "Danh sach FULL, khong them duoc" << endl;
            return 0;
        }
        if (p < 0)
            p = 0;
        if (p > len)
            p = len;
        for (int i = len; i > p; i--)
        {
            stud[i] = stud[i - 1];
        }
        stud[p] = X;
        len++;
        return 1;
    }
    int GetItem(int p, Student &sv)
    {
        if (p < 0 || p >= len)
            return 0;
        else
            sv = stud[p];
        return 1;
    }
     int deleteItem(int p)
    {
        if (p < 0 || p >= len)
            return 0;
        for (int i = p; i < len - 1; i++)
            stud[i] = stud[i + 1];
        len--;
        return 1;
    }
    void deleteFirst()
    {
        if (!isEmpty())
            deleteItem(0);
    }
    void deleteLast()
    {
        if (!isEmpty())
            deleteItem(len - 1);
    }
    void sortList()
    {
        for (int i = 0; i < len - 1; i++)
        {
            for (int j = i + 1; j < len; j++)
            {
                if (stud[i].roll_no > stud[j].roll_no)
                {
                    Student temp = stud[i];
                    stud[i] = stud[j];
                    stud[j] = temp;
                }
            }
        }
    }
};

int inputList(ArrList &List, int n)
{
    if (List.getLen() + n > List.getMaxLen())
    {
        return 0;
    }
    else
    {
        Student sv;
        for (int i = 1; i <= n; i++)
        {
            cout << "Student " << i << endl;
            cout << "Enter roll no:";
            cin >> sv.roll_no;
            cout << "Enter name:";
            cin >> sv.name;
            cout << "Enter phone number";
            cin >> sv.phone_number;
            cout << "====================" << endl;
            List.addItem(sv, List.getLen());
        }
        return 1;
    }
}
void printList(ArrList List, int f, int t)
{
    cout << "\n |Student|Roll no|Name | Phone no \n";
    Student sv;
    for (int i = f - 1; i < t; i++)
    {
        if (List.GetItem(i, sv) == 0)
            break;
        cout << "------------------------------" << endl;
        cout << "|" << i + 1 << "|" << sv.roll_no << "|";
        cout << sv.name << "|" << sv.phone_number << endl;
    }
    cout << "--------------------------------" << endl;
}
int main()
{
    ArrList ListS;
    int n = 6;
    inputList(ListS, n);
    cout << "\n ===========Input list================ \n";
    printList(ListS, 1, n);

    ListS.sortList();
    cout << "\n ===========Sorted list================ \n";
    printList(ListS, 1, n);
    
    // Xóa phần tử ở vị trí thứ 2
    cout << "\n ===========Delete item at position 2================ \n";
    ListS.deleteItem(1);
    printList(ListS, 1, n - 1);

    // Xóa phần tử đầu tiên và hiển thị danh sách mới
    cout << "\n ===========Delete first item================ \n";
    ListS.deleteFirst();
    printList(ListS, 1, n - 2);

    // Xóa phần tử cuối cùng và hiển thị danh sách mới
    cout << "\n ===========Delete last item================ \n";
    ListS.deleteLast();
    printList(ListS, 1, n - 3);
    return 0;
}