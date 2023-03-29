#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};
struct LLIST
{
private:
    Node *head = NULL;

public:
    LLIST()
    {
        head = NULL;
    }
    void addFirst(int x)
    {
        Node *p = new Node();
        p->data = x;
        p->next = head;
        head = p;
    }
    void addLast(int x)
    {
        Node *p = new Node();
        p->data = x;
        p->next = NULL;
        if (head == NULL)
        {
            head = p;
        }
        else
        {
            Node *q = head;
            while (q->next != NULL)
                q = q->next;
            q->next = p;
        }
    }
    Node *getLast()
    {
        Node *q = head;
        while (q->next != NULL)
            q = q->next;
        return q;
    }
    Node *getFirst()
    {
        return head;
    }
    void addItem(Node *&p, int x)
    {
        Node *q = new Node();
        q->data = x;
        if (p != NULL)
        {
            q->next = p->next;
            p->next = q;
        }
        else
        {
            q->next = head;
            head = q;
        }
    }
    void deleteFirst()
    {
        if (head != NULL)
        {
            Node *p = head;
            head = head->next;
            delete p;
        }
    }
    void deleteLast()
    {
        if (head == NULL)
        {
            return;
        }
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }
        Node *p = head;
        while (p->next->next != NULL)
        {
            p = p->next;
        }
        delete p->next;
        p->next = NULL;
    }
    void deleteItem()
    {
    }
    void printList()
    {
        Node *n = head;
        while (n != NULL)
        {
            cout << n->data << "->";
            n = n->next;
        }
    }
    Node *searchAt(int position)
    {
        if (head != NULL)
        {
            int count = 1;
            Node *p = head;
            while (p != NULL && count < position)
            {
                p = p->next;
                count++;
            }
            if (p != NULL)
            {
                return p;
            }
        }
        return NULL;
    }
};

int main()
{
    LLIST List1 = LLIST(), List2 = LLIST(), List3;
    for (int x = 1; x <= 10; x++)
    {
        cout << x << "->";
        List1.addFirst(x);
        List2.addFirst(x);
    }
    cout << "\n==========LIST 1==========" << endl;
    List1.printList();
    cout << "\n==========LIST 2==========" << endl;
    List2.printList();
    cout << "\n==========LIST 2*==========" << endl;
    List2.deleteLast();
    List2.printList();
    List3 = List1;
    Node *q = List3.getLast();
    Node *p = List2.getFirst();
    q->next = p;

    cout << "\n==========LIST 3==========" << endl;
    List3.printList();

    cout << "\n==========LIST 1==========" << endl;
    List1.printList();
    return 0;
}