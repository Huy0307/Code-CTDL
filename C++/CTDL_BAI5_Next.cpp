#include <iostream>
using namespace std;
#define MAX 50
struct Element {
    char beg, mid, end;
    int Ndisk;
    Element* next;
    Element() {}
    Element(int d, char A, char B, char C) {
        beg = A; end = C; mid = B; Ndisk = d;
        next = NULL;
    }
};

struct LLIST {
private:
    Element* top = NULL;
public:
	LLIST() { top = NULL; }
    ~LLIST() {
        while (!isEmpty()) {
            Element* temp = top;
            top = top->next;
            delete temp;
        }
}
    
    bool push(Element x) {
        Element* temp = new Element(x.Ndisk, x.beg, x.mid, x.end);
        if (temp == NULL) {
            return false;
        }
        else{
        temp->next = top;
        top = temp;
        return true;}
    }
    
    int pop() {
        if (isEmpty()) {
            return -1;
        }
        else {
            Element* temp = top;
            top = top->next;
            int value = temp->Ndisk;
            delete temp;
            return value;
        }
    }
    
    Element getTop() {
        Element temp;
        if (top == NULL) {
            cout << "is Empty" << endl;
            return temp;
        }
        else {
            return *top;
        }
    }
    bool isEmpty() { return top == NULL; }
};

int main()
{
    LLIST S = LLIST();
    int n;
    char a = 'A', b = 'B', c = 'C';
    cout << "Nhap so:";
    cin >> n;
    cout << "\n========= KHU DE QUY ==============\n";
    S.push(Element(n, a, b, c));
    while (!S.isEmpty())
    {
        Element Item = S.getTop();
        S.pop();
        a = Item.beg; b = Item.mid; c = Item.end;
        if (Item.Ndisk == 1)
            cout << "\t" << a << "->" << c << endl;
        else
        {
            S.push(Element(Item.Ndisk - 1, b, a, c));
            S.push(Element(1, a, b, c));
            S.push(Element(Item.Ndisk - 1, a, c, b));
        }
    }

    return 0;
}
