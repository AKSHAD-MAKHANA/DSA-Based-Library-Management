
#include <iostream>
#include <string>
using namespace std;

// Book class to store book details
class Book
{
public:
    int id;
    string title;
    string author;
    bool isIssued;
    Book* next;
    Book* prev;

    Book(int id, string title, string author)
    {
        this->id = id;
        this->title = title;
        this->author = author;
        this->isIssued = false;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

// Library class to manage the library
class Library
{
private:
    Book* head;
    Book* tail;
    int size;

public:
    Library()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    // Function to add a book to the library
    void addBook(int id, string title, string author)
    {
        Book* newBook = new Book(id, title, author);
        if (head == nullptr)
        {
            head = tail = newBook;
        }
        else
        {
            tail->next = newBook;
            newBook->prev = tail;
            tail = newBook;
        }
        size++;
        cout << "Book added successfully: " << title << " by " << author << endl;
    }

    // Function to delete a book by ID
    void deleteBook(int id)
    {
        Book* temp = head;
        while (temp != nullptr && temp->id != id)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Book not found." << endl;
            return;
        }

        if (temp->prev != nullptr)
        {
            temp->prev->next = temp->next;
        }
        else
        {
            head = temp->next;
        }

        if (temp->next != nullptr)
        {
            temp->next->prev = temp->prev;
        }
        else
        {
            tail = temp->prev;
        }

        delete temp;
        size--;
        cout << "Book deleted successfully." << endl;
    }

    // Function to search for a book by title
    void searchBookByTitle(string title)
    {
        Book* temp = head;
        while (temp != nullptr)
        {
            if (temp->title == title)
            {
                cout << "Book found: " << temp->title << " by " << temp->author << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Book not found." << endl;
    }

    // Function to display all books
    void displayBooks()
    {
        if (head == nullptr)
        {
            cout << "No books available in the library." << endl;
            return;
        }

        Book* temp = head;
        cout << "Books in the Library:\n";
        while (temp != nullptr)
        {
            cout << "ID: " << temp->id << ", Title: " << temp->title << ", Author: " << temp->author << ", Issued: " << (temp->isIssued ? "Yes" : "No") << endl;
            temp = temp->next;
        }
    }

    // Function to issue a book by ID
    void issueBook(int id)
    {
        Book* temp = head;
        while (temp != nullptr && temp->id != id)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Book not found." << endl;
            return;
        }

        if (temp->isIssued)
        {
            cout << "Book is already issued." << endl;
            return;
        }

        temp->isIssued = true;
        cout << "Book issued successfully: " << temp->title << " by " << temp->author << endl;
    }

    // Function to return a book by ID
    void returnBook(int id)
    {
        Book* temp = head;
        while (temp != nullptr && temp->id != id)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Book not found." << endl;
            return;
        }

        if (!temp->isIssued)
        {
            cout << "Book is not issued." << endl;
            return;
        }

        temp->isIssued = false;
        cout << "Book returned successfully: " << temp->title << " by " << temp->author << endl;
    }

    // Function to count total books in the library
    int countTotalBooks()
    {
        return size;
    }

    // Function to show books by a specific author
    void showBooksByAuthor(string author)
    {
        Book* temp = head;
        bool found = false;
        while (temp != nullptr)
        {
            if (temp->author == author)
            {
                cout << "ID: " << temp->id << ", Title: " << temp->title << ", Issued: " << (temp->isIssued ? "Yes" : "No") << endl;
                found = true;
            }
            temp = temp->next;
        }
        if (!found)
        {
            cout << "No books found by author: " << author << endl;
        }
    }

    // Function to sort books alphabetically by title using Bubble Sort
    void sortBooksByTitle()
    {
        if (head == nullptr)
        {
            return;
        }

        bool swapped;
        Book* ptr1;
        Book* lptr = nullptr;

        do
        {
            swapped = false;
            ptr1 = head;

            while (ptr1->next != lptr)
            {
                if (ptr1->title > ptr1->next->title)
                {
                    swap(ptr1->title, ptr1->next->title);
                    swap(ptr1->author, ptr1->next->author);
                    swap(ptr1->id, ptr1->next->id);
                    swap(ptr1->isIssued, ptr1->next->isIssued);
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
    }
};

int main()
{
    Library library;
    int choice, id;
    string title, author;

    while (true)
    {
        // Display menu options to the user
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Delete Book\n";
        cout << "3. Search Book by Title\n";
        cout << "4. Display All Books\n";
        cout << "5. Issue Book\n";
        cout << "6. Return Book\n";
        cout << "7. Count Total Books\n";
        cout << "8. Show Books by Author\n";
        cout << "9. Sort Books by Title\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            // Take input for adding a book
            cout << "Enter book ID: ";
            cin >> id;
            cout << "Enter book title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter book author: ";
            getline(cin, author);
            library.addBook(id, title, author);
            break;
        case 2:
            // Take input for deleting a book
            cout << "Enter book ID to delete: ";
            cin >> id;
            library.deleteBook(id);
            break;
        case 3:
            // Take input for searching a book by title
            cout << "Enter book title to search: ";
            cin.ignore();
            getline(cin, title);
            library.searchBookByTitle(title);
            break;
        case 4:
            // Display all books
            library.displayBooks();
            break;
        case 5:
            // Take input for issuing a book
            cout << "Enter book ID to issue: ";
            cin >> id;
            library.issueBook(id);
            break;
        case 6:
            // Take input for returning a book
            cout << "Enter book ID to return: ";
            cin >> id;
            library.returnBook(id);
            break;
        case 7:
            // Display total number of books
            cout << "Total books in the library: " << library.countTotalBooks() << endl;
            break;
        case 8:
            // Take input for showing books by a specific author
            cout << "Enter author name: ";
            cin.ignore();
            getline(cin, author);
            library.showBooksByAuthor(author);
            break;
        case 9:
            // Sort books by title
            library.sortBooksByTitle();
            cout << "Books sorted by title." << endl;
            break;
        case 10:
            // Exit the program
            cout << "Exiting...\n";
            return 0;
        default:
            // Handle invalid choices
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

