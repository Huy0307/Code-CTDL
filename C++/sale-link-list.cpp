#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

struct Product
{
    string name;
    float price;
    int quantity;
    Product *next;
};

Product *head = nullptr;

void addProduct(string name, float price, int quantity)
{
    Product *newProduct = new Product;
    newProduct->name = name;
    newProduct->price = price;
    newProduct->quantity = quantity;
    newProduct->next = nullptr;

    if (head == nullptr)
    {
        head = newProduct;
    }
    else
    {
        Product *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newProduct;
    }
}

void displayList()
{
    Product *temp = head;
    while (temp != nullptr)
    {
        cout << "-----------------------------------" << endl;
        cout << "Ten san pham: " << temp->name << endl;
        cout << "Gia tien: " << fixed << setprecision(2) << temp->price;
        cout << " vnd" << endl;
        cout << "So luong: " << temp->quantity << endl;
        cout << "-----------------------------------" << endl;
        temp = temp->next;
    }
}

void adjustProduct(string name, float newPrice, int newQuantity)
{
    Product *temp = head;
    while (temp != nullptr)
    {
        if (temp->name == name)
        {
            temp->price = newPrice;
            temp->quantity = newQuantity;
            break;
        }
        temp = temp->next;
    }
}

float buyProduct(string name, int quantity)
{
    Product *temp = head;
    while (temp != nullptr)
    {
        if (temp->name == name && temp->quantity >= quantity)
        {
            temp->quantity -= quantity;
            return temp->price * quantity;
        }
        temp = temp->next;
    }
    return -1;
}

void exportInvoice(string filename, string name, int quantity, float total)
{
    ofstream outputFile;
    outputFile.open(filename, ios_base::app);
    outputFile << "-----------------------------------" << endl;
    outputFile << "| Ten san pham: " << name << endl;
    outputFile << "| So luong: " << quantity << endl;
    outputFile << "| Tong cong: " << total << endl;
    outputFile << "-----------------------------------" << endl;
    outputFile.close();
}

void readFromFile(string filename)
{
    ifstream inFile(filename);
    if (!inFile)
    {
        cout << "Khong the mo file!" << endl;
        return;
    }

    string line;
    while (getline(inFile, line))
    {
        istringstream iss(line);
        string name;
        float price;
        int quantity;
        if (iss >> name >> price >> quantity)
        {
            addProduct(name, price, quantity);
        }
    }

    inFile.close();
}

void exportData(string filename)
{
    ofstream outputFile(filename);
    Product *temp = head;

    while (temp != nullptr)
    {
        outputFile << temp->name << " " << temp->price << " " << temp->quantity << endl;
        temp = temp->next;
    }

    outputFile.close();
}

int main()
{
    readFromFile("San pham.txt");

    int choice;
    do
    {
        cout << "================= MENU =================" << endl;
        cout << "1. Hien thi danh sach san pham" << endl;
        cout << "2. Them pham moi" << endl;
        cout << "3. Dieu chinh so luong san pham" << endl;
        cout << "4. Mua san pham va xuat hoa don" << endl;
        cout << "5. Luu du lieu san pham" << endl;
        cout << "0. Thoat chuong trinh" << endl;
        cout << "========================================" << endl;

        cout << "Chon chuc nang (0-5): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            displayList();
            break;
        case 2:
        {
            string name;
            float price;
            int quantity;
            cout << "Nhap ten san pham: ";
            cin >> name;
            cout << "Nhap gia: ";
            cin >> price;
            cout << "Nhap so luong: ";
            cin >> quantity;
            addProduct(name, price, quantity);
            break;
        }
        case 3:
        {
            string name;
            float newPrice;
            int newQuantity;
            cout << "Nhap ten san pham can dieu chinh: ";
            cin >> name;
            cout << "Nhap gia moi: ";
            cin >> newPrice;
            cout << "Nhap so luong moi: ";
            cin >> newQuantity;
            adjustProduct(name, newPrice, newQuantity);
            break;
        }
        case 4:
        {
            string name;
            int quantity;
            cout << "Nhap ten san pham can mua: ";
            cin >> name;
            cout << "Nhap so luong: ";
            cin >> quantity;
            float total = buyProduct(name, quantity);
            if (total == -1)
            {
                cout << "Khong tim thay san pham hoac so luong khong du!" << endl;
            }
            else
            {
                cout << "Tong tien: " << fixed << setprecision(2) << total << " vnd" << endl;
                exportInvoice("Hoa don.txt", name, quantity, total);
            }
            break;
        }
        case 5:
        {
            exportData("San pham.txt");
            cout << "Du lieu da duoc luu vao file San pham.txt" << endl;
            break;
        }
        case 0:
            cout << "Tam biet!" << endl;
            break;
        default:
            cout << "Chuc nang khong hop le! Vui long chon lai." << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}
