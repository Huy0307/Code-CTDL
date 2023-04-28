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
	string keyword;
	string field;
    string IDSV;
    string name;
    string gioitinh;
    string birthdate;
    string cls;
    string number;
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
enum SortField { TITLE, BOOK_ID, AUTHOR, GENRE, PUBLISHER, QUANTITY };

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
                if (stoi(book.bookID) < stoi(tree->data.bookID)) {
  					insertNodeBy(tree->left, book, field);
				} else {
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
void deleteTree(TreeNode *&tree) {
	if (tree != nullptr) {
		deleteTree(tree->left);
		deleteTree(tree->right);
		delete tree;
		tree = nullptr;
	}
}
void displayTree(TreeNode* tree) {
    if (tree != nullptr) {
        displayTree(tree->left);
        cout << "| " << setw(6) << left << tree->data.bookID << " | " << setw(53) << left << tree->data.title << " | " << setw(20) << left << tree->data.author << " | " << setw(15) << left << tree->data.genre << " | " << setw(40) << left << tree->data.publisher << " | " << setw(8) << left << tree->data.quantity << " |\n";
        displayTree(tree->right);
    }
    else {
        cout << "+--------+-------------------------------------------------------+----------------------+-----------------+------------------------------------------+----------+\n";
    }
}
void displaySortListByTree(SortField field) {
	// Xóa cây nh? phân tìm ki?m cu (n?u có)
	deleteTree(root);
	createBinarySearchTreeBy(field);
	cout << "+--------+-------------------------------------------------------+----------------------+-----------------+------------------------------------------+----------+" << endl;
    cout << "| BookID | Title                                                 | Author               | Genre           | Publisher                                | Quantity |" << endl;
    cout << "+--------+-------------------------------------------------------+----------------------+-----------------+------------------------------------------+----------+" << endl;
	displayTree(root);
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
    int count = 0;
    Book *temp = head;
    cout << "+--------+-------------------------------------------------------+----------------------+-----------------+------------------------------------------+----------+" << endl;
    cout << "| BookID | Title                                                 | Author               | Genre           | Publisher                                | Quantity |" << endl;
    cout << "+--------+-------------------------------------------------------+----------------------+-----------------+------------------------------------------+----------+" << endl;
    while (temp != nullptr)
    {
        cout << "| " << setw(6) << left << temp->bookID << " | " << setw(53) << left << temp->title << " | " << setw(20) << left << temp->author << " | " << setw(15) << left << temp->genre << " | " << setw(40) << left << temp->publisher << " | " << setw(8) << left << temp->quantity << " |" << endl;
        cout << "+--------+-------------------------------------------------------+----------------------+-----------------+------------------------------------------+----------+" << endl;
        temp = temp->next;
        count++;
        if (count == 50)
        {
            break;
        }
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

BanDoc* searchHuman(string keyword, string field)
{
    BanDoc *temp = headDoc;
    while (temp != nullptr)
    {
        if (field == "IDSV" && temp->IDSV == keyword)
        {
            return temp;
        }
        else if (field == "name" && temp->name == keyword)
        {
            return temp;
        }
        else if (field == "gioitinh" && temp->gioitinh == keyword)
        {
            return temp;
        }
        else if (field == "birthdate" && temp->birthdate == keyword)
        {
            return temp;
        }
        else if (field == "number" && temp->number == keyword)
        {
            return temp;
        }
        else if (field == "cls" && temp->cls == keyword)
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
    cout << "+------------+-------------------------------------------------------+------------------------+-----------------+------------------------------------------+----------+" << endl;
    cout << "| BookID     | Title                                                 | Author                 | Genre           | Publisher                                | Quantity |" << endl;
    cout << "+------------+-------------------------------------------------------+------------------------+-----------------+------------------------------------------+----------+" << endl;
    cout << "| " << setw(10) << left << bookToFind->bookID << " | " << setw(53) << left << bookToFind->title << " | " << setw(22) << left << bookToFind->author << " | " << setw(15) << left << bookToFind->genre << " | " << setw(40) << left << bookToFind->publisher << " | " << setw(8) << left << bookToFind->quantity << " |" << endl;
    cout << "+------------+-------------------------------------------------------+------------------------+-----------------+------------------------------------------+----------+" << endl;
}
void findHuman(string keyword, string field)
{
    BanDoc *humanToFind = searchHuman(keyword, field);
    if (humanToFind == nullptr)
    {
        cout << "Not found in the system." << endl;
        return;
    }
    cout << "+------------+-------------------------------------------------------+------------------------+-------------------------+------------------------------------------+----------+" << endl;
    cout << "|ID          | Name                                                  | Sex                    | Date of birth           | Number                                   | Class    |" << endl;
    cout << "+------------+-------------------------------------------------------+------------------------+-------------------------+------------------------------------------+----------+" << endl;
    cout << "| " << setw(10) << left << humanToFind->IDSV << " | " << setw(53) << left << humanToFind->name << " | " << setw(22) << left << humanToFind->gioitinh << " | " << setw(23) << left << humanToFind->birthdate << " | " << setw(40) << left << humanToFind->number << " | " << setw(8) << left << humanToFind->cls << " |" << endl;
    cout << "+------------+-------------------------------------------------------+------------------------+-------------------------+------------------------------------------+----------+" << endl;
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
void returnToPreviousFunction() {
    int input;
    do {
        std::cout << "Enter 0 to return to the previous function: ";
        std::cin >> input;
    } while (input != 0);
    std::cout << "Exiting.....";
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    system("cls");
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
        SortField field;
	    int sort;
	    int choice;
	    int find;
        cin >> choice;

        switch (choice){
    
        case 1:
        	system("cls");
            displayBook();
            returnToPreviousFunction();
            break;
        case 2:
        {
        	system("cls");
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
            returnToPreviousFunction();
            break;
        }
        case 3:
        {
        	system("cls");
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
					system("cls");
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
		            returnToPreviousFunction();		    		
		            break;
				} 
				case 2:
				{
				    system("cls"); 
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
		            returnToPreviousFunction();	
		            break;
				}  			
				}
			}while (find != 0);
            break;
        }
        case 4:
        {
            system("cls");
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
        	system("cls");
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
					system("cls");
					string ID;
					string bookID = "bookID"; 
					cout << "Find by ID: ";       	
		    		cin >> ID;
		    		findBook(ID,bookID);
		    		returnToPreviousFunction();
		            break;
				} 
				case 2:
				{ 
					system("cls");
					string name;
					string title = "title";       	
		        	cout << "Find by title: ";
		    		cin >> name;
		    		findBook(name,title);
		    		returnToPreviousFunction();
		            break;
				} 
				case 3:
				{ 
					system("cls");
					string authors; 
					string author = "author";       	
		        	cout << "Find by author:";
		    		cin >> authors;
		    		findBook(authors,author);
		    		returnToPreviousFunction();
		            break;
				} 
				case 4:
				{ 
					system("cls");
					string genres;
					string genre = "genre";       	
		        	cout << "Find by genre:";
		    		cin >> genres;
		    		findBook(genres,genre);
		    		returnToPreviousFunction();
		            break;
				}
				case 5:
				{ 
					system("cls");
					string publishers;
					string publisher = "publisher";        	
		        	cout << "Find by publisher:";
		    		cin >> publishers;
		    		findBook(publishers,publisher);
		    		returnToPreviousFunction();
		            break;
				}  			
				}
			}while (find != 0);
            break;
        }
        case 6:
        {
        	system("cls");
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
                    system("cls");
					cout << "Arrange by title:\n";
                    displaySortListByTree(TITLE);
//                    string sortBy = "title";
//                    displaySortedBooks(sortBy);
                    returnToPreviousFunction();
                    break;
                }
                case 2:
                {
                    system("cls");
					cout << "Arrange by ID:\n";
                    displaySortListByTree(BOOK_ID);
//                    string sortBy = "bookID";
//                    displaySortedBooks(sortBy);
                    returnToPreviousFunction();
                    break;
                }
                case 3:
                {
                    system("cls");
					cout << "Arrange by author:\n";
                    displaySortListByTree(AUTHOR);

//                    string sortBy = "author";
//                    displaySortedBooks(sortBy);
                    returnToPreviousFunction();
                    break;
                }
                case 0:
                {
                    system("cls");
					cout << "Exiting...." << endl;
					system("cls");
                    break;
                }
                }
            } while (sort != 0);
            break;
        }
        case 7:
        {
            system("cls");
			exportData("Sach.txt");
            cout << "Data saved to file Sach.txt" << endl;
            returnToPreviousFunction();
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
        cout << "1. Show reader information" << endl;
        cout << "2. Add reader" << endl;
        cout << "3. Delete reader" << endl;
        cout << "4. Save information" << endl;
        cout << "5. Exit" << endl;
        cout << "==========================" << endl;
        cout << "Select choice: ";
        int choice;
        cin >> choice;
        
        switch (choice) {
            case 1:
                system("cls");
				DisplayBanDoc();
                break;
            case 2:
                {
                    system("cls");
					string IDSV;
                    string name;
                    cout << "Enter student's ID: ";
                    cin >> IDSV;
                    cout << "Enter student's name: ";
                    cin >> name;
                    addBanDoc(IDSV, name);
                    cout << "Add succes!" << endl;
                }
                break;
            case 3:
                {
                    system("cls");
					string IDSV;
                    cout << "Enter ID to delete: ";
                    cin >> IDSV;
                    DeleteBanDoc(IDSV);
                    cout << "Delete success!" << endl;
                }
                break;
            case 4:
		        {
		            system("cls");
					exportDatahuman("human.txt");
		            cout << "Data saved to file human.txt" << endl;
		            std::this_thread::sleep_for(std::chrono::milliseconds(2000)); // d?ng chuong trình trong 2 giây
		            system("cls"); // xóa màn hình
		            break;
		        }
            case 5:
                return;
            default:
            	system("cls");
                cout << "Error, please select again!" << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(2000)); // d?ng chuong trình trong 2 giây
		        system("cls"); // xóa màn hình
        }
        
        cout << endl;
    }
}

void Interface_main(){
	system("cls");
	int choice;
    int find;
	    cout << "               	 NHOM 3___________________________________________  \n";
	    cout << "               	+=================================================+ \n";
	    cout << "               	|          Library management software            | \n";
	    cout << "               	|-------------------------------------------------| \n";
	    cout << "               	|                                                 | \n";
	    cout << "               	|  1. BOOK MANAGEMENT                             | \n";
	    cout << "               	|  2. CUSTOMER MANAGEMENT                         | \n";
	    cout << "               	|  3. Exit                                        | \n";
	    cout << "               	|                                                 | \n";
	    cout << "               	|                                                 | \n";
	    cout << "               	|                                                 | \n";
	    cout << "               	+-------------------------------------------------+ \n";

        cout << "			Select function  (1-3): ";
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


