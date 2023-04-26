#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include <chrono>
#include <thread>
using namespace std;

struct Book
{
    string bookID;
    string title;
    string author;
    string genre;
    string publisher;
    string field;
    string keyword;
    int quantity;
    Book *next;
};
struct BanDoc {
    string IDSV;
    string name;
    BanDoc *next;
};
struct TreeNode
{
    Book data;
    TreeNode *left;
    TreeNode *right;
};
BanDoc *headDoc = nullptr;
Book *head = nullptr;
TreeNode *root = nullptr;
enum SortField { TITLE, BOOK_ID, AUTHOR, GENRE, PUBLISHER, FIELD, KEYWORD, QUANTITY };

void insertNodeBy(TreeNode *&tree, Book book, SortField field) {
    if (tree == nullptr) {
        tree = new TreeNode{book, nullptr, nullptr};
    }
    else {
        switch (field) {
            case TITLE:
                if (book.title < tree->data.title) {
                    insertNodeBy(tree->left, book, field);
                }
                else {
                    insertNodeBy(tree->right, book, field);
                }
                break;
            case BOOK_ID:
                if (book.bookID < tree->data.bookID) {
                    insertNodeBy(tree->left, book, field);
                }
                else {
                    insertNodeBy(tree->right, book, field);
                }
                break;
            case AUTHOR:
                if (book.author < tree->data.author) {
                    insertNodeBy(tree->left, book, field);
                }
                else {
                    insertNodeBy(tree->right, book, field);
                }
                break;
            case GENRE:
                if (book.genre < tree->data.genre) {
                    insertNodeBy(tree->left, book, field);
                }
                else {
                    insertNodeBy(tree->right, book, field);
                }
                break;
            case PUBLISHER:
                if (book.publisher < tree->data.publisher) {
                    insertNodeBy(tree->left, book, field);
                }
                else {
                    insertNodeBy(tree->right, book, field);
                }
                break;
            case FIELD:
                if (book.field < tree->data.field) {
                    insertNodeBy(tree->left, book, field);
                }
                else {
                    insertNodeBy(tree->right, book, field);
                }
                break;
            case KEYWORD:
                if (book.keyword < tree->data.keyword) {
                    insertNodeBy(tree->left, book, field);
                }
                else {
                    insertNodeBy(tree->right, book, field);
                }
                break;
            case QUANTITY:
                if (book.quantity < tree->data.quantity) {
                    insertNodeBy(tree->left, book, field);
                }
                else {
                    insertNodeBy(tree->right, book, field);
                }
                break;
            default: // Tru?ng h?p không h?p l?
                std::cout << "Invalid sort field!\n";
                break;
        }
    }
}
void createBinarySearchTreeBy(SortField field) {
    Book *temp = head;
    while (temp != nullptr) {
        insertNodeBy(root, *temp, field);
        temp = temp->next;
    }
}
void sortListByTree(SortField field)
{
    root = nullptr;
    createBinarySearchTreeBy(field);
    //displayTree(root);
}
void addBook(string bookID, string title, string author, string genre, string publisher, int quantity)
{
    Book *newBook = new Book;
    newBook->bookID = bookID;
    newBook->title = title;
    newBook->author = author;
    newBook->genre = genre;
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

void displayBook()
{
    Book *temp = head;
    while (temp != nullptr)
    {
        cout << "-----------------------------------" << endl;
        cout << "Book ID: " << temp->bookID << endl;
        cout << "Book title: " << temp->title << endl;
        cout << "Author: " << temp->author << endl;
        cout << "Category: " << temp->genre << endl;
        cout << "Publishing company: " << temp->publisher << endl;
        cout << "Quantity: " << temp->quantity << endl;
        cout << "-----------------------------------" << endl;
        temp = temp->next;
    }
}

Book* searchBook(string keyword, string field)
{
    Book *temp = head;
    while (temp != nullptr)
    {
        if (field == "bookID" && temp->bookID == keyword)
        {
            return temp;
        }
        else if (field == "title" && temp->title == keyword)
        {
            return temp;
        }
        else if (field == "author" && temp->author == keyword)
        {
            return temp;
        }
        else if (field == "genre" && temp->genre == keyword)
        {
            return temp;
        }
        else if (field == "publisher" && temp->publisher == keyword)
        {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr; 
}

void adjustBook(string keyword, string field, string newname_book, string newtacgia, string newtheloai, string newnxb, int newquantity)
{
    Book *bookToAdjust = searchBook(keyword, field);
    bookToAdjust->title = newname_book;
    bookToAdjust->author = newtacgia;
    bookToAdjust->genre = newtheloai;
    bookToAdjust->publisher = newnxb;
    bookToAdjust->quantity = newquantity;
    cout << "Book information updated successfully." << endl;
}

void findBook(string keyword, string field)
{
    Book *bookToFind = searchBook(keyword, field);
    if (bookToFind == nullptr)
    {
        cout << "Book not found in the library." << endl;
        return;
    }
    cout << "-----------------------------------" << endl;
    cout << "Book ID: " << bookToFind->bookID << endl;
    cout << "Book title: " << bookToFind->title << endl;
    cout << "Author: " << bookToFind->author << endl;
    cout << "Category:" << bookToFind->genre << endl;
    cout << "Publishing company:" << bookToFind->publisher << endl;
    cout << "Quantity:" << bookToFind->quantity << endl;
}
void deleteBook(string bookID)
{
    if (head == nullptr)
    {
        cout << "The library is empty." << endl;
        return;
    }
    Book *temp = head;
    Book *prev = nullptr;
    while (temp != nullptr && temp->bookID != bookID)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == nullptr)
    {
        cout << "Book not found in the library." << endl;
        return;
    }
    if (prev == nullptr)
    {
        head = head->next;
    }
    else
    {
        prev->next = temp->next;
    }
    delete temp;
    cout << "Book deleted successfully." << endl;
}
void readFromFile(string filename)
{
    ifstream inFile(filename);
    if (!inFile)
    {
        cout << "Can't open file" << endl;
        return;
    }

    string line;
    while (getline(inFile, line))
    {
        istringstream iss(line);
        string bookID, title, author, genre, publisher;
        int quantity;
        if (iss >> bookID >> title >> author >> genre >> publisher >> quantity)
        {
            addBook(bookID, title, author, genre, publisher, quantity);
        }
    }

    inFile.close();
}
void displaySortedBooks(string sortBy)
{
    if (head == nullptr)
    {
        cout << "The library is empty." << endl;
        return;
    }

    // Copy the linked list to an array
    int listSize = 0;
    Book *temp = head;
    while (temp != nullptr)
    {
        listSize++;
        temp = temp->next;
    }
    Book *bookArray = new Book[listSize];
    temp = head;
    for (int i = 0; i < listSize; i++)
    {
        bookArray[i] = *temp;
        temp = temp->next;
    }

    // Sort the array using insertSort
    for (int i = 1; i < listSize; i++)
    {
        Book key = bookArray[i];
        int j = i - 1;
        while (j >= 0 && (
            (sortBy == "bookID" && bookArray[j].bookID > key.bookID) ||
            (sortBy == "title" && bookArray[j].title > key.title) ||
            (sortBy == "author" && bookArray[j].author > key.author)))
        {
            bookArray[j + 1] = bookArray[j];
            j--;
        }
        bookArray[j + 1] = key;
    }

    // Display the sorted array
    cout << "-----------------------------------" << endl;
    cout << "List of books sorted by " << sortBy << ":" << endl;
    for (int i = 0; i < listSize; i++)
    {
        cout << "Book ID: " << bookArray[i].bookID << endl;
        cout << "Book title: " << bookArray[i].title << endl;
        cout << "Author: " << bookArray[i].author << endl;
        cout << "Category: " << bookArray[i].genre << endl;
        cout << "Publishing company: " << bookArray[i].publisher << endl;
        cout << "Quantity: " << bookArray[i].quantity << endl;
        cout << "-----------------------------------" << endl;
    }
    // Delete the temporary array
    delete[] bookArray;
}

void exportData(string filename)
{
    ofstream outputFile(filename);
    Book *temp = head;

    while (temp != nullptr)
    {
        outputFile << temp->bookID << " " << temp->title << " " << temp->author << " " << temp->genre << " " << temp->publisher << " " << temp->quantity << endl;
        temp = temp->next;
    }

    outputFile.close();
}

void InterfaceBook()
{
	system("cls");
	readFromFile("Sach.txt");
	while (true) {
		cout << "================= MENU =================" << endl;
        cout << "1. Show book list" << endl;
        cout << "2. Add new book" << endl;
        cout << "3. Adjust book list" << endl;
        cout << "4. Delete book" << endl;
        cout << "5. Finding book" << endl;
        cout << "6. Arrange book" << endl;
        cout << "7. Save book data" << endl;
        cout << "0. Exit the program" << endl;
        cout << "========================================" << endl;
        cout << "Select function  (0-7): ";
        
	    int sort;
	    int choice;
	    int find;
        cin >> choice;

        switch (choice){
    
        case 1:
            displayBook();
            std::this_thread::sleep_for(std::chrono::milliseconds(10000)); // d?ng chuong trình trong 10 giây
            system("cls"); // xóa màn hình
            break;
        case 2:
        {
            string bookID, title, author, genre, publisher;
            int quantity;
            cout << "Enter book ID: ";
            cin >> bookID;
            cout << "Enter book title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter book author: ";
            getline(cin, author);
            cout << "Enter book category: ";
            cin >> genre;
            cout << "Enter publishing company: ";
            cin.ignore();
            getline(cin, publisher);
            cout << "Enter quantity: ";
            cin >> quantity;
            while (quantity <= 0){
            	cout << "Wrong enter";
            	cin >> quantity;}
            addBook(bookID, title, author, genre, publisher, quantity);
            std::this_thread::sleep_for(std::chrono::milliseconds(2000)); // d?ng chuong trình trong 2 giây
            system("cls"); // xóa màn hình
            break;
        }
        case 3:
        {
            string newname_book;
            string newtacgia;
            string newtheloai;
            string newnxb;
            int newquantity;
            cout << "Enter the feild of book you want to adjust" << endl;
            do{
                cout << "================= MENU =================" << endl;
                cout << "1. ID" << endl;
                cout << "2. Title" << endl;
                cout << "0. Exit the program" << endl;
                cout << "========================================" << endl;

                cout << "Select function (0-5): ";
				cin >> find;
				switch (find){ 
				case 1:
				{ 
					string ID;
					string bookID = "bookID"; 
					cout << "Find by ID: ";       	
		    		cin >> ID;
		    		findBook(ID,bookID);
		    		Book *bookToFind = searchBook(ID, bookID);
    				if (bookToFind == nullptr)
    				{
						break;
    				}
		            cout << "Enter new book title: ";
		            cin >> newname_book;
		            cout << "Enter new author: ";
		            cin >> newtacgia;
		            cout << "Enter new category: ";
		            cin >> newtheloai;
		            cout << "Enter new publishing company: ";
		            cin >> newnxb;
		            cout << "Enter new quantity: ";
		            cin >> newquantity;
		            while (newquantity <= 0){
		            	cout << "Wrong enter";
		            	cin >> newquantity;}
		            adjustBook(ID, bookID, newname_book, newtacgia, newtheloai, newnxb, newquantity);
		            std::this_thread::sleep_for(std::chrono::milliseconds(2000)); // d?ng chuong trình trong 2 giây
		            system("cls"); // xóa màn hình		    		
		            break;
				} 
				case 2:
				{ 
					string name;
					string title = "title";       	
		        	cout << "Find by title: ";
		    		cin >> name;
		    		findBook(name,title);
					Book *bookToFind = searchBook(name, title);
    				if (bookToFind == nullptr)
    				{
						break;
    				}
					cout << "Enter new book title: ";
		            cin >> newname_book;
		            cout << "Enter new author: ";
		            cin >> newtacgia;
		            cout << "Enter new category: ";
		            cin >> newtheloai;
		            cout << "Enter new publishing company: ";
		            cin >> newnxb;
		            cout << "Enter new quantity: ";
		            cin >> newquantity;
		            while (newquantity <= 0){
		            	cout << "Wrong enter";
		            	cin >> newquantity;}
		            adjustBook(name, title, newname_book, newtacgia, newtheloai, newnxb, newquantity);
		            std::this_thread::sleep_for(std::chrono::milliseconds(2000)); // d?ng chuong trình trong 2 giây
		            system("cls"); // xóa màn hình	
		    		
		            break;
				}  			
				}
			}while (find != 0);
            break;
        }
        case 4:
        {
            string bookID;
            cin >> bookID;            
			cout << "Enter the book ID to be deleted: ";
            deleteBook(bookID);
            std::this_thread::sleep_for(std::chrono::milliseconds(2000)); // d?ng chuong trình trong 2 giây
            system("cls"); // xóa màn hình
            break;
        }
        case 5:
        {
        	do{
                cout << "================= MENU =================" << endl;
                cout << "1. Find by ID" << endl;
                cout << "2. Find by title" << endl;
                cout << "3. Find by author" << endl;
                cout << "4. Find by genre" << endl;
                cout << "5. Find by publisher" << endl;
                cout << "0. Exit the program" << endl;
                cout << "========================================" << endl;

                cout << "Select function (0-5): ";
				cin >> find;
				switch (find){ 
				case 1:
				{ 
					string ID;
					string bookID = "bookID"; 
					cout << "Find by ID: ";       	
		    		cin >> ID;
		    		findBook(ID,bookID);
		    		std::this_thread::sleep_for(std::chrono::milliseconds(5000)); // d?ng chuong trình trong 5 giây
		            system("cls"); // xóa màn hình
		            break;
				} 
				case 2:
				{ 
					string name;
					string title = "title";       	
		        	cout << "Find by title: ";
		    		cin >> name;
		    		findBook(name,title);
		    		std::this_thread::sleep_for(std::chrono::milliseconds(5000)); // d?ng chuong trình trong 5 giây
		            system("cls"); // xóa màn hình
		            break;
				} 
				case 3:
				{ 
					string authors; 
					string author = "author";       	
		        	cout << "Find by author:";
		    		cin >> authors;
		    		findBook(authors,author);
		    		std::this_thread::sleep_for(std::chrono::milliseconds(10000)); // d?ng chuong trình trong 10 giây
		            system("cls"); // xóa màn hình
		            break;
				} 
				case 4:
				{ 
					string genres;
					string genre = "genre";       	
		        	cout << "Find by genre:";
		    		cin >> genres;
		    		findBook(genres,genre);
		    		std::this_thread::sleep_for(std::chrono::milliseconds(10000)); // d?ng chuong trình trong 10 giây
		            system("cls"); // xóa màn hình
		            break;
				}
				case 5:
				{ 
					string publishers;
					string publisher = "publisher";        	
		        	cout << "Find by publisher:";
		    		cin >> publishers;
		    		findBook(publishers,publisher);
		    		std::this_thread::sleep_for(std::chrono::milliseconds(10000)); // d?ng chuong trình trong 10 giây
		            system("cls"); // xóa màn hình
		            break;
				}  			
				}
			}while (find != 0);
            break;
        }
        case 6:
        {
            do
            {

                cout << "================= MENU =================" << endl;
                cout << "1. Arrange by title" << endl;
                cout << "2. Arrange by ID" << endl;
                cout << "3. Arrange by author" << endl;
                cout << "0. Exit the program" << endl;
                cout << "========================================" << endl;

                cout << "Select function (0-3): ";
                cin >> sort;
                switch (sort)
                {
                case 1:
                {
                    cout << "Arrange by title:";
                    string sortBy = "title";
                    displaySortedBooks(sortBy);
                    std::this_thread::sleep_for(std::chrono::milliseconds(2000)); // d?ng chuong trình trong 2 giây
                    system("cls"); // xóa màn hình
                    break;
                }
                case 2:
                {
                    cout << "Arrange by ID:";
                    string sortBy = "bookID";
                    displaySortedBooks(sortBy);
                    std::this_thread::sleep_for(std::chrono::milliseconds(2000)); // d?ng chuong trình trong 2 giây
                    system("cls"); // xóa màn hình
                    break;
                }
                case 3:
                {
                    cout << "Arrange by author:";
                    string sortBy = "author";
                    displaySortedBooks(sortBy);
                    std::this_thread::sleep_for(std::chrono::milliseconds(2000)); // d?ng chuong trình trong 2 giây
                    system("cls"); // xóa màn hình
                    break;
                }
                case 0:
                {
                    cout << "Exiting...." << endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(500)); // d?ng chuong trình trong 2 giây
                    system("cls"); // xóa màn hình
                    break;
                }
                }
            } while (sort != 0);
            break;
        }
        case 7:
        {
            exportData("Sach.txt");
            cout << "Data saved to file Sach.txt" << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(2000)); // d?ng chuong trình trong 2 giây
            system("cls"); // xóa màn hình
            break;
        }
        case 0:
            return;
            default:
                cout << "Lua chon khong hop le, vui long thu lai!" << endl;
            system("cls");
        }
        
        cout << endl;
    }
}
void exportDatahuman(string filename)
{
    ofstream outputFile(filename);
    BanDoc *temp = headDoc;

    while (temp != nullptr)
    {
        outputFile << temp->IDSV << " " << temp->name << " " << endl;
        temp = temp->next;
    }

    outputFile.close();
}
void addBanDoc(string IDSV, string name) {
    BanDoc *newBanDoc = new BanDoc;
    newBanDoc->IDSV = IDSV;
    newBanDoc->name = name;
    newBanDoc->next = nullptr;
    
    if (headDoc == nullptr) {
        headDoc = newBanDoc;
    }
    else
	{
    	BanDoc *temp = headDoc;
    	while (temp->next != nullptr) 
    	{
    		temp = temp->next;
		}
		temp->next = newBanDoc;
	}	
}
void readFromFilehuman(string filename)
{
    ifstream inFile(filename);
    if (!inFile)
    {
        cout << "Can't open file" << endl;
        return;
    }
    string line;
    while (getline(inFile, line))
    {
        istringstream iss(line);
        string IDSV, name;
        if (iss >> IDSV >> name)
        {
            addBanDoc(IDSV, name);
        }
    }
    inFile.close();
}
void DeleteBanDoc(string IDSV) {
    if (headDoc == nullptr) {
        return;
    }
    
    if (headDoc->IDSV == IDSV) {
        BanDoc *temp = headDoc;
        headDoc = headDoc->next;
        delete temp;
        return;
    }
    
    BanDoc *prev = headDoc;
    BanDoc *temp = headDoc->next;
    
    while (temp != nullptr) {
        if (temp->IDSV == IDSV) {
            prev->next = temp->next;
            delete temp;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}
void DisplayBanDoc() {
    BanDoc *temp = headDoc;
    
    while (temp != nullptr) {
        cout << "IDSV: " << temp->IDSV << ", name: " << temp->name << endl;
        temp = temp->next;
    }
}
void InterfaceBanDoc() {
	system("cls");
	readFromFilehuman("human.txt");
    while (true) {
        cout << "========== MENU ==========" << endl;
        cout << "1. Hien thi thong tin ban doc" << endl;
        cout << "2. Them ban doc" << endl;
        cout << "3. Xoa ban doc" << endl;
        cout << "4. Luu thong tin" << endl;
        cout << "5. Thoat" << endl;
        cout << "==========================" << endl;
        cout << "Nhap lua chon: ";
        int choice;
        cin >> choice;
        
        switch (choice) {
            case 1:
                DisplayBanDoc();
                break;
            case 2:
                {
                    string IDSV;
                    string name;
                    cout << "Nhap ma so sinh vien: ";
                    cin >> IDSV;
                    cout << "Nhap ten sinh vien: ";
                    cin >> name;
                    addBanDoc(IDSV, name);
                    cout << "Them ban doc thanh cong!" << endl;
                }
                break;
            case 3:
                {
                    string IDSV;
                    cout << "Nhap ma so sinh vien cua ban doc can xoa: ";
                    cin >> IDSV;
                    DeleteBanDoc(IDSV);
                    cout << "Xoa ban doc thanh cong!" << endl;
                }
                break;
            case 4:
		        {
		            exportDatahuman("human.txt");
		            cout << "Data saved to file human.txt" << endl;
		            std::this_thread::sleep_for(std::chrono::milliseconds(2000)); // d?ng chuong trình trong 2 giây
		            system("cls"); // xóa màn hình
		            break;
		        }
            case 5:
                return;
            default:
                cout << "Lua chon khong hop le, vui long thu lai!" << endl;
        }
        
        cout << endl;
    }
}

void Interface_main(){
	system("cls");
	int choice;
    int find;
	    cout << "                NHOM 3___________________________________________  \n";
	    cout << "               +=================================================+ \n";
	    cout << "               |         CHUONG TRINH QUAN LY THU VIEN           | \n";
	    cout << "               |-------------------------------------------------| \n";
	    cout << "               |                                                 | \n";
	    cout << "               |  1. Quan ly sach trong Thu vien.                | \n";
	    cout << "               |  2. Quan ly ban doc.                            | \n";
	    cout << "               |  3. Exit                                        | \n";
	    cout << "               |                                                 | \n";
	    cout << "               |                                                 | \n";
	    cout << "               |                                                 | \n";
	    cout << "               +-------------------------------------------------+ \n";

        cout << "Select function  (1-3): ";
        cin >> choice;

        switch (choice)
        {
          case 1:
                    system("cls");
                    InterfaceBook();
                    break;
          case 2:
          			system("cls");
                    InterfaceBanDoc();
                    break;
          case 3:
            cout << "Good bye!" << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(500)); // d?ng chuong trình trong 2 giây
            system("cls"); // xóa màn hình
            break;
        default:
            cout << "Invalid function! Please choose another function." << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(2000)); // d?ng chuong trình trong 2 giây
            system("cls"); // xóa màn hình
            break;          
		}
		cout << endl;
	}

int main(){
	Interface_main();
}


