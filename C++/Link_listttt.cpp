#include <iostream>
#include <stdio.h>
#include <math.h>
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
    void insertAt(int position, int x)
    {
        Node *p = head;
        int count = 1;
        while (p != NULL && count < position)
        {
            p = p->next;
            count++;
        }
        if (p == NULL)
        {
            addLast(x);
        }
        else if (position == 1)
        {
            addFirst(x);
        }
        else
        {
            addItem(p, x);
        }
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
    if (head != NULL)
    {
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
        }
        else
        {
            Node *p = head;
            while (p->next->next != NULL)
                p = p->next;
            delete p->next;
            p->next = NULL;
        }
    }
}
	void deleteAt(int position)
{
    if (head != NULL)
    {
        if (position == 1)
        {
            deleteFirst();
            return;
        }
        int count = 1;
        Node *p = head;
        while (p != NULL && count < position - 1)
        {
            p = p->next;
            count++;
        }
        if (p != NULL && p->next != NULL)
        {
            Node *q = p->next;
            p->next = q->next;
            delete q;
        }
    }
}

	void sortList()
{
    if (head != NULL)
    {
        Node *p, *q;
        int temp;
        for (p = head; p != NULL; p = p->next)
        {
            for (q = p->next; q != NULL; q = q->next)
            {
                if (p->data > q->data)
                {
                    temp = p->data;
                    p->data = q->data;
                    q->data = temp;
                }
            }
        }
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

Node *search(int x)
{
    Node *p = head;
    int position = 1;
    while (p != NULL)
    {
        if (p->data == x)
        {
            return p; // Tr? v? node ch?a giá tr? c?n tìm
        }
        p = p->next;
        position++;
    }
    return NULL; // Không tìm th?y giá tr? trong danh sách liên k?t
}
	
};

/*int main()
{	int a;
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

    List3 = List1;
    Node *q = List3.getLast();
    Node *p = List2.getFirst();
    q->next = p;

    cout << "\n==========LIST 3==========" << endl;
    List3.printList();

    cout << "\n==========LIST 1==========" << endl;
    List1.printList();
    
    cout << "\nNhap gia tri can tim : ";
    cin>>a;
    
 Node *r = List3.search(a);
    if (r != NULL) {
        cout << "\nPosition of value " << a << " in the list: ";
        int count = 1;
        Node *p = List3.getFirst();
        while (p != NULL) {
            if (p == r) {
                cout << count;
                break;
            }
            p = p->next;
            count++;
        }
    } else {
        cout << "Value not found in the list." << endl;
    }
    return 0;
}*/
int main()
{   
    int choice, value, position;
    LLIST List1 = LLIST();
    
    while (true)
    {
        cout << "\nMENU\n";
        cout << "1. Add item at the beginning\n";
        cout << "2. Add item at the end\n";
        cout << "3. Add item at chosen position\n";
        cout << "4. Delete first item\n";
        cout << "5. Delete last item\n";
        cout << "6. Delete item at chosen position\n";
        cout << "7. Sort list\n";
        cout << "8. Search for an item at chosen position\n";
        cout << "9. Print list\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice)
        {
            case 1:
                cout << "Enter value to add: ";
                cin >> value;
                List1.addFirst(value);
                cout << "Item added at the beginning.\n";
                break;
                
            case 2:
                cout << "Enter value to add: ";
                cin >> value;
                List1.addLast(value);
                cout << "Item added at the end.\n";
                break;
                
            case 3:
                cout << "Enter value to add: ";
                cin >> value;
                cout << "Enter position: ";
                cin >> position;
                List1.insertAt(position, value);
                cout << "Item added at position " << position << ".\n";
                break;
                
            case 4:
                List1.deleteFirst();
                cout << "First item deleted.\n";
                break;
                
            case 5:
                List1.deleteLast();
                cout << "Last item deleted.\n";
                break;
                
            case 6:
                cout << "Enter position: ";
                cin >> position;
                List1.deleteAt(position);
                cout << "Item deleted at position " << position << ".\n";
                break;
                
            case 7:
                List1.sortList();
                cout << "List sorted.\n";
                break;
                
            case 8:
		    int position;
		    cout << "Nhap vi tri can tim: ";
		    cin >> position;

		    {
		        Node *result = List1.searchAt(position);
		        if (result != NULL)
		        {
		            cout << "Gia tri tai vi tri " << position << " la: " << result->data << endl;
		        }
		        else
		        {
		            cout << "Khong tim thay vi tri " << position << " trong danh sach." << endl;
		        }
		    }
		    break;
            case 9:
                List1.printList();
                break;    
            case 0:
                exit(0);
                break;
                
            default:
                cout << "Invalid choice.\n";
                break;
        }
    }
    
    return 0;
}




