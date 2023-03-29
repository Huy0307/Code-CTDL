#include<iostream>

#define MAX 100

using namespace std;

struct Student {
    int roll_no;
    string name;
    string phone_number;
};

struct ArrList {
private:
    Student stud[MAX];
    int len;
    int maxLen;

public:
    ArrList() {
        len = 0;
        maxLen = MAX;
    }

    int isEmpty() { return len == 0; }
    int isFull() { return len == maxLen; }
    int getLen() { return len; }
    int getMaxLen() { return maxLen; }

    int addItem(Student X, int p) {
        if (isFull()) {
            cout << "Danh sach FULL, khong them duoc" << endl;
            return 0;
        }
        if (p < 0)
            p = 0;
        if (p > len)
            p = len;
        for (int i = len; i > p; i--) {
            stud[i] = stud[i - 1];
        }
        stud[p] = X;
        len++;
        return 1;
    }

    int getItem(int p, Student& sv) {
        if (p < 0 || p >= len)
            return 0;
        else
            sv = stud[p];
        return 1;
    }

    int deleteItem(int p) {
        if (isEmpty()) {
            cout << "Danh sach rong, khong the xoa" << endl;
            return 0;
        }
        if (p < 0)
            p = 0;
        if (p >= len)
            p = len - 1;
        for (int i = p; i < len - 1; i++) {
            stud[i] = stud[i + 1];
        }
        len--;
        return 1;
    }

    int deleteFirst() {
        return deleteItem(0);
    }

    int deleteLast() {
        return deleteItem(len - 1);
    }

    void sortList() {
        int n = len;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (stud[j].roll_no > stud[j + 1].roll_no) {
                    Student temp = stud[j];
                    stud[j] = stud[j + 1];
                    stud[j + 1] = temp;
                }
            }
        }
    }
};

int inputList(ArrList& List, int n) {
    if (List.getLen() + n > List.getMaxLen()) {
        return 1;
    }
    else {
        Student sv;
        for (int i = 1; i <= n; i++) {
            cout << "Student " << i << endl;
            cout << "Enter roll no:";
            cin >> sv.roll_no;
            cout << "Enter name:";
            cin >> sv.name;
            cout << "Enter phone number:";
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
        if (List.getItem(i, sv) == 0)
            break;
        cout << "------------------------------" << endl;
        cout << "|" << i + 1 << "|" << sv.roll_no << "|";
        cout << sv.name << "|" << sv.phone_number << endl;
    }
    cout << "--------------------------------" << endl;
}
int main() {
    ArrList ListS;
    int choice, pos, n = 2;
    Student sv;

    while (true) {
        cout << "\n======= MENU ========" << endl;
        cout << "1. Add item to list" << endl;
        cout << "2. Print list" << endl;
        cout << "3. Sort list" << endl;
        cout << "4. Delete item at position" << endl;
        cout << "5. Delete first item" << endl;
        cout << "6. Delete last item" << endl;
        cout << "7. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter position to add new item: ";
                cin >> pos;
                cout << "Enter roll no:";
                cin >> sv.roll_no;
                cout << "Enter name:";
                cin >> sv.name;
                cout << "Enter phone number:";
                cin >> sv.phone_number;
                if (ListS.addItem(sv, pos)) {
                    cout << "Add thanh cong" << endl;
                } else {
                    cout << "List full" << endl;
                }
                break;

            case 2:
                printList(ListS, 1, n);
                break;

            case 3:
                ListS.sortList();
                cout << "Sap xep thanh cong" << endl;
                break;

            case 4:
                cout << "Nhap vi tri can xoa: ";
                cin >> pos;
                if (ListS.deleteItem(pos)) {
                    cout << "Delete thanh cong" << endl;
                } else {
                    cout << "List empty" << endl;
                }
                break;

            case 5:
                if (ListS.deleteFirst()) {
                    cout << "Delete thanh cong" << endl;
                } else {
                    cout << "List empty" << endl;
                }
                break;

            case 6:
                if (ListS.deleteLast()) {
                    cout << "Delete thanh cong" << endl;
                } else {
                    cout << "List trong " << endl;
                }
                break;

            case 7:
                return 0;

            default:
                cout << "Invalid choice" << endl;
        }
    }
    return 0;
}
