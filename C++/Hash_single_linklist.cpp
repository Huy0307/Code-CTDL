#include<iostream>

using namespace std;

class Node
{
public:
    int key;
    Node* next;
    Node(int k)
    {
        key = k;
        next = nullptr;
    }
};

class Hash
{
    int BUCKET; 
    Node** table; 
public:
    Hash(int V); 
    void insertItem(int x);
    void deleteItem(int key);
    int hashFunction(int x) {
        return (x % BUCKET);
    }
    void displayHash();
};

Hash::Hash(int b)
{
    this->BUCKET = b;
    table = new Node*[BUCKET];
    for (int i = 0; i < BUCKET; i++)
        table[i] = nullptr;
}

void Hash::insertItem(int key)
{
    int index = hashFunction(key);
    Node* newNode = new Node(key);
    newNode->next = table[index];
    table[index] = newNode;
}

void Hash::deleteItem(int key)
{
    int index = hashFunction(key);
    Node* temp = table[index];
    Node* prev = nullptr;
    while (temp != nullptr && temp->key != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == nullptr)
        return;
    if (prev == nullptr)
        table[index] = temp->next;
    else
        prev->next = temp->next;
    delete temp;
}

void Hash::displayHash() {
    for (int i = 0; i < BUCKET; i++){
        cout << i;
        Node* temp = table[i];
        while (temp != nullptr)
        {
            cout << " --> " << temp->key;
            temp = temp->next;
        }
        cout << endl;
    }
}

int main()
{
    int a[] = {15, 11, 27, 8, 12, 22, 18};
    int n = sizeof(a)/sizeof(a[0]);
    Hash h(7);
    for (int i = 0; i < n; i++)
        h.insertItem(a[i]);
    h.displayHash();
    h.deleteItem(12);
    h.displayHash();
    return 0;
}
