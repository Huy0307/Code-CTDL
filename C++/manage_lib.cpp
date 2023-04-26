#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

struct Book
{
    string id;
    string title;
    string author;
    string category;
    string publisher;
    int quantity;
    Book *next;
};

Book *head = nullptr;

// function to add a book to the library
void addBook(string id, string title, string author, string category, string publisher, int quantity)
{
    Book *newBook = new Book;
    newBook->id = id;
    newBook->title = title;
    newBook->author = author;
    newBook->category = category;
    newBook->publisher = publisher;
    newBook->quantity = quantity;
    newBook->next = nullptr;

    if (head == nullptr)
    {
        head = newBook;
    }
    else
    {
        Book *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newBook;
    }
}

// function to display all the books in the library
void displayBooks()
{
    Book *temp = head;
    while (temp != nullptr)
    {
        cout << "-----------------------------------" << endl;
        cout << "Ma sach: " << temp->id << endl;
        cout << "Tieu de: " << temp->title << endl;
        cout << "Tac gia: " << temp->author << endl;
        cout << "The loai: " << temp->category << endl;
        cout << "Nha xuat ban: " << temp->publisher << endl;
        cout << "So luong: " << temp->quantity << endl;
        cout << "-----------------------------------" << endl;
        temp = temp->next;
    }
}

// function to find a book by its id
Book *findBook(string id)
{
    Book *temp = head;
    while (temp != nullptr)
    {
        if (temp->id == id)
        {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

// function to remove a book from the library by its id
void removeBook(string id)
{
    Book *temp = head;
    Book *prev = nullptr;
    while (temp != nullptr)
    {
        if (temp->id == id)
        {
            if (prev == nullptr)
            {
                head = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            delete temp;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

// function to modify a book's information by its id
void modifyBook(string id, string title, string author, string category, string publisher, int quantity)
{
    Book *book = findBook(id);
    if (book != nullptr)
    {
        book->title = title;
        book->author = author;
        book->category = category;
        book->publisher = publisher;
        book->quantity = quantity;
    }
}

// function to issue a book by its id
void issueBook(string id)
{
    Book *book = findBook(id);
    if (book != nullptr)
    {
        if (book->quantity > 0)
        {
            book->quantity--;
            cout << "Muon sach thanh cong!" << endl;
        }
        else
        {

            cout << "Het sach roi, khong the muon!" << endl;
        }
    }
    else
    {
        cout << "Khong tim thay sach!" << endl;
    }
}

// function to return a book by its id
void returnBook(string id)
{
    Book *book = findBook(id);
    if (book != nullptr)
    {
        book->quantity++;
        cout << "Tra sach thanh cong!" << endl;
    }
    else
    {
        cout << "Khong tim thay sach!" << endl;
    }
}

int main()
{
    // code for testing the functions
    addBook("001", "To Kill a Mockingbird", "Harper Lee", "Fiction", "J. B. Lippincott & Co.", 5);
    addBook("002", "The Great Gatsby", "F. Scott Fitzgerald", "Fiction", "Charles Scribner's Sons", 3);
    addBook("003", "1984", "George Orwell", "Fiction", "Secker & Warburg", 2);
    addBook("004", "Pride and Prejudice", "Jane Austen", "Fiction", "T. Egerton, Whitehall", 4);
    displayBooks();

    modifyBook("002", "The Catcher in the Rye", "J. D. Salinger", "Fiction", "Little, Brown and Company", 3);

    displayBooks();

    issueBook("002");
    issueBook("002");
    issueBook("002");
    issueBook("002");
    issueBook("002");

    returnBook("002");
    returnBook("002");
    returnBook("002");
    returnBook("002");
    returnBook("002");
    returnBook("002");

    removeBook("002");

    displayBooks();

    return 0;
}
