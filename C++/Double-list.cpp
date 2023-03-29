#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next, *prev;
};
struct DLList
{
    Node *head = NULL;
    Node *tail = NULL;
    void addFirst(int x)
    {
        Node *p = new Node();
        p->data = x;
        p->prev = NULL;
        p->next = head;
        if (head != NULL)
        {
            head->prev = p;
        }
        else
        {
            tail = p;
        }
        head = p;
    }
    void addLast(int x)
    {
        Node *p = new Node();
        p->data = x;
        p->next = NULL;
        p->prev = tail;
        if (tail != NULL)
        {
            tail->next = p;
        }
        else
        {
            head = p;
        }
        tail = p;
    }
    int addItem(Node *&q, int x)
    {
        if (q == NULL)
        {
            return -1;
        }
        Node *p = new Node();
        p->data = x;
        p->next = NULL;
        p->prev = NULL;
        if (p != NULL)
        {
            Node *p2 = q->next;
            p->next = q->next;
            p->prev = q;
            q->next = p;
            if (p2 != NULL)
                p2->prev = p;
            if (tail == q)
            {
                tail = q;
            }
        }
        return 1;
    }
    DLList operator+(DLList L)
    {
        DLList KQ;
        Node *n = head;
        while (n != NULL)
        {
            KQ.addLast(n->data);
            n = n->next;
        }
        n = L.head;
        while (n != NULL)
        {
            KQ.addLast(n->data);
            n = n->next;
        }
        return KQ;
    }
    void printFW()
    {
        Node *n = head;
        while (n != NULL)
        {
            cout << n->data << "->";
            n = n->next;
        }
    }
    void printBw()
    {
        Node *n = tail;
        while (n != NULL)
        {
            cout << n->data << "<-";
            n = n->prev;
        }
    }
    int Search(int x)
    {
        Node *p = head;
        int vtri = 0;
        while (p != NULL)
        {
            if (p->data == x)
            {
                return vtri + 1;
            };
            p = p->next;
            vtri++;
        }
        return -1;
    }
};
int main()
{
    DLList L1 = DLList(), L2 = DLList();

    for (int i = 1; i <= 10; i++)
    {
        L1.addFirst(i);
        L2.addLast(i);
    }
    cout << "\n=== Danh sach L1 theo chieu thuan===" << endl;
    L1.printFW();
    cout << "\n=== Danh sach L1 theo chieu nguoc===" << endl;
    L1.printBw();
    DLList L3 = L1 + L2;
    cout << "\n====== In danh sach L1 + L2 =====" << endl;
    L3.printFW();
    cout << "\n Tim kiem phan tu trong List 3" << endl;
    int x, vtri;
    cout << "\n Nhap phan tu can tim";
    cin >> x;
    vtri = L3.Search(x);
    if (vtri == -1)
    {
        cout << "\n Khong co phan tu can tim";
    }
    else
    {
        cout << "\n " << x << " o vi tri " << vtri << endl;
    }
    return 0;
}