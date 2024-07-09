#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm> // for find_if, sort
#include <limits>    // for numeric_limits
using namespace std;

// Class to represent a Book
class Book {
private:
    string isbn, title, author, edition, publication;

public:
    // Constructor with optional parameters
    Book(const string& isbn = "", const string& title = "", const string& author = "",
         const string& edition = "", const string& publication = "") :
         isbn(isbn), title(title), author(author), edition(edition), publication(publication) {}

    // Getters
    string getIsbn() const { return isbn; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getEdition() const { return edition; }
    string getPublication() const { return publication; }

    // Setters with validation
    void setIsbn(const string& a) { isbn = a; }
    void setTitle(const string& b) { title = b; }
    void setAuthor(const string& c) { author = c; }
    void setEdition(const string& d) { edition = d; }
    void setPublication(const string& e) { publication = e; }

    // Overloading << operator for easy printing
    friend ostream& operator<<(ostream& os, const Book& book) {
        os << "ISBN: " << book.isbn << "\n"
           << "Title: " << book.title << "\n"
           << "Author: " << book.author << "\n"
           << "Edition: " << book.edition << "\n"
           << "Publication: " << book.publication << "\n";
        return os;
    }

    // Overloading == operator for comparison
    bool operator==(const Book& other) const {
        return isbn == other.isbn;
    }
};

// Function prototypes
void addBook(vector<Book>& books);
void deleteBook(vector<Book>& books);
void editBook(vector<Book>& books);
void searchBook(const vector<Book>& books);
void viewAllBooks(const vector<Book>& books);
void saveBooksToFile(const vector<Book>& books, const string& filename);
void loadBooksFromFile(vector<Book>& books, const string& filename);
void quit();

void displayMenu();
void clearScreen();

int main() {
    vector<Book> books;
    string choice;

    // Load books from file at the beginning
    loadBooksFromFile(books, "library.txt");

    while (true) {
        displayMenu();
        cout << "ENTER CHOICE: ";
        getline(cin, choice);
        clearScreen();

        switch (stoi(choice)) {
            case 1:
                addBook(books);
                break;
            case 2:
                deleteBook(books);
                break;
            case 3:
                editBook(books);
                break;
            case 4:
                searchBook(books);
                break;
            case 5:
                viewAllBooks(books);
                break;
            case 6:
                saveBooksToFile(books, "library.txt");
                break;
            case 7:
                loadBooksFromFile(books, "library.txt");
                break;
            case 8:
                cout << "Total number of books: " << books.size() << "\n";
                break;
            case 9:
                {
                    // Search by title
                    cout << "Enter Title to search: ";
                    string searchTitle;
                    getline(cin, searchTitle);
                    vector<Book> results;
                    copy_if(books.begin(), books.end(), back_inserter(results), [&searchTitle](const Book& book) {
                        return book.getTitle() == searchTitle;
                    });
                    if (!results.empty()) {
                        cout << "Books found with title '" << searchTitle << "':\n";
                        for (const auto& book : results) {
                            cout << book << endl;
                        }
                    } else {
                        cout << "No books found with title '" << searchTitle << "'.\n";
                    }
                }
                break;
            case 10:
                {
                    // Sort books by title
                    sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
                        return a.getTitle() < b.getTitle();
                    });
                    cout << "Books sorted by title.\n";
                }
                break;
            case 11:
                {
                    // Filter books by author
                    cout << "Enter Author to filter: ";
                    string filterAuthor;
                    getline(cin, filterAuthor);
                    vector<Book> filteredBooks;
                    copy_if(books.begin(), books.end(), back_inserter(filteredBooks), [&filterAuthor](const Book& book) {
                        return book.getAuthor() == filterAuthor;
                    });
                    if (!filteredBooks.empty()) {
                        cout << "Books by author '" << filterAuthor << "':\n";
                        for (const auto& book : filteredBooks) {
                            cout << book << endl;
                        }
                    } else {
                        cout << "No books found by author '" << filterAuthor << "'.\n";
                    }
                }
                break;
            case 12:
                {
                    // Filter books by edition
                    cout << "Enter Edition to filter: ";
                    string filterEdition;
                    getline(cin, filterEdition);
                    vector<Book> filteredBooks;
                    copy_if(books.begin(), books.end(), back_inserter(filteredBooks), [&filterEdition](const Book& book) {
                        return book.getEdition() == filterEdition;
                    });
                    if (!filteredBooks.empty()) {
                        cout << "Books of edition '" << filterEdition << "':\n";
                        for (const auto& book : filteredBooks) {
                            cout << book << endl;
                        }
                    } else {
                        cout << "No books found of edition '" << filterEdition << "'.\n";
                    }
                }
                break;
            case 13:
                {
                    // Unique ISBN check
                    vector<string> isbns;
                    bool duplicateFound = false;
                    for (const auto& book : books) {
                        if (find(isbns.begin(), isbns.end(), book.getIsbn()) != isbns.end()) {
                            cout << "Duplicate ISBN found: " << book.getIsbn() << endl;
                            duplicateFound = true;
                            break;
                        }
                        isbns.push_back(book.getIsbn());
                    }
                    if (!duplicateFound) {
                        cout << "No duplicate ISBNs found.\n";
                    }
                }
                break;
            case 14:
                // Delete all books
                books.clear();
                cout << "All books deleted.\n";
                break;
            case 15:
                {
                    // Edit all books
                    for (auto& book : books) {
                        string newIsbn, newTitle, newAuthor, newEdition, newPublication;
                        cout << "Enter new ISBN for book '" << book.getTitle() << "' (or enter to skip): ";
                        getline(cin, newIsbn);
                        if (!newIsbn.empty()) {
                            book.setIsbn(newIsbn);
                        }
                        cout << "Enter new Title for book '" << book.getTitle() << "' (or enter to skip): ";
                        getline(cin, newTitle);
                        if (!newTitle.empty()) {
                            book.setTitle(newTitle);
                        }
                        cout << "Enter new Author for book '" << book.getTitle() << "' (or enter to skip): ";
                        getline(cin, newAuthor);
                        if (!newAuthor.empty()) {
                            book.setAuthor(newAuthor);
                        }
                        cout << "Enter new Edition for book '" << book.getTitle() << "' (or enter to skip): ";
                        getline(cin, newEdition);
                        if (!newEdition.empty()) {
                            book.setEdition(newEdition);
                        }
                        cout << "Enter new Publication for book '" << book.getTitle() << "' (or enter to skip): ";
                        getline(cin, newPublication);
                        if (!newPublication.empty()) {
                            book.setPublication(newPublication);
                        }
                        cout << "Book '" << book.getTitle() << "' edited.\n";
                    }
                }
                break;
            case 16:
                saveBooksToFile(books, "library.txt"); // Save changes before quitting
                quit();
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }

        cout << "Press ENTER to continue . . .";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
        cin.get(); // Wait for user to press Enter
    }

    return 0;
}

void displayMenu() {
    cout << "=====================\n";
    cout << "LIBRARY MANAGEMENT SYSTEM\n";
    cout << "=====================\n\n";
    cout << "[1] ADD BOOK\n";
    cout << "[2] DELETE BOOK\n";
    cout << "[3] EDIT BOOK\n";
    cout << "[4] SEARCH BOOK\n";
    cout << "[5] VIEW ALL BOOKS\n";
    cout << "[6] SAVE TO FILE\n";
    cout << "[7] LOAD FROM FILE\n";
    cout << "[8] TOTAL BOOKS COUNT\n";
    cout << "[9] SEARCH BY TITLE\n";
    cout << "[10] SORT BOOKS BY TITLE\n";
    cout << "[11] FILTER BOOKS BY AUTHOR\n";
    cout << "[12] FILTER BOOKS BY EDITION\n";
    cout << "[13] UNIQUE ISBN CHECK\n";
    cout << "[14] DELETE ALL BOOKS\n";
    cout << "[15] EDIT ALL BOOKS\n";
    cout << "[16] EXIT\n";
    cout << "=====================\n";
}

void clearScreen() {
    // Clear screen for Windows and Linux
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

void addBook(vector<Book>& books) {
    string isbn, title, author, edition, publication;

    cout << "Enter ISBN: ";
    getline(cin, isbn);
    cout << "Enter Title: ";
    getline(cin, title);
    cout << "Enter Author: ";
    getline(cin, author);
    cout << "Enter Edition: ";
    getline(cin, edition);
    cout << "Enter Publication: ";
    getline(cin, publication);

    Book newBook(isbn, title, author, edition, publication);
    books.push_back(newBook);

    cout << "Book added successfully.\n";
}

void deleteBook(vector<Book>& books) {
    if (books.empty()) {
        cout << "No books to delete.\n";
        return;
    }

    string isbn;
    cout << "Enter ISBN of book to delete: ";
    getline(cin, isbn);

    auto it = find_if(books.begin(), books.end(), [&isbn](const Book& book) {
        return book.getIsbn() == isbn;
    });

    if (it != books.end()) {
        books.erase(it);
        cout << "Book with ISBN '" << isbn << "' deleted.\n";
    } else {
        cout << "Book with ISBN '" << isbn << "' not found.\n";
    }
}

void editBook(vector<Book>& books) {
    if (books.empty()) {
        cout << "No books to edit.\n";
        return;
    }

    string isbn;
    cout << "Enter ISBN of book to edit: ";
    getline(cin, isbn);

    auto it = find_if(books.begin(), books.end(), [&isbn](const Book& book) {
        return book.getIsbn() == isbn;
    });

    if (it != books.end()) {
        // Modify the book
        string newIsbn, newTitle, newAuthor, newEdition, newPublication;
        cout << "Enter new ISBN (or enter to skip): ";
        getline(cin, newIsbn);
        if (!newIsbn.empty()) {
            it->setIsbn(newIsbn);
        }
        cout << "Enter new Title (or enter to skip): ";
        getline(cin, newTitle);
        if (!newTitle.empty()) {
            it->setTitle(newTitle);
        }
        cout << "Enter new Author (or enter to skip): ";
        getline(cin, newAuthor);
        if (!newAuthor.empty()) {
            it->setAuthor(newAuthor);
        }
        cout << "Enter new Edition (or enter to skip): ";
        getline(cin, newEdition);
        if (!newEdition.empty()) {
            it->setEdition(newEdition);
        }
        cout << "Enter new Publication (or enter to skip): ";
        getline(cin, newPublication);
        if (!newPublication.empty()) {
            it->setPublication(newPublication);
        }
        cout << "Book edited successfully.\n";
    } else {
        cout << "Book with ISBN '" << isbn << "' not found.\n";
    }
}

void searchBook(const vector<Book>& books) {
    if (books.empty()) {
        cout << "No books to search.\n";
        return;
    }

    string isbn;
    cout << "Enter ISBN of book to search: ";
    getline(cin, isbn);

    auto it = find_if(books.begin(), books.end(), [&isbn](const Book& book) {
        return book.getIsbn() == isbn;
    });

    if (it != books.end()) {
        cout << "Book found:\n" << *it;
    } else {
        cout << "Book with ISBN '" << isbn << "' not found.\n";
    }
}

void viewAllBooks(const vector<Book>& books) {
    if (books.empty()) {
        cout << "No books available.\n";
        return;
    }

    cout << "=== LIST OF BOOKS ===\n";
    for (const auto& book : books) {
        cout << book << endl;
    }
}

void saveBooksToFile(const vector<Book>& books, const string& filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error opening file '" << filename << "' for writing.\n";
        return;
    }

    for (const auto& book : books) {
        outFile << book.getIsbn() << ","
                << book.getTitle() << ","
                << book.getAuthor() << ","
                << book.getEdition() << ","
                << book.getPublication() << "\n";
    }

    outFile.close();
    cout << "Books saved to file '" << filename << "'.\n";
}

void loadBooksFromFile(vector<Book>& books, const string& filename) {
    books.clear(); // Clear existing books

    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file '" << filename << "' for reading.\n";
        return;
    }

    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string isbn, title, author, edition, publication;

        getline(ss, isbn, ',');
        getline(ss, title, ',');
        getline(ss, author, ',');
        getline(ss, edition, ',');
        getline(ss, publication, ',');

        Book newBook(isbn, title, author, edition, publication);
        books.push_back(newBook);
    }

    inFile.close();
    cout << "Books loaded from file '" << filename << "'.\n";
}

void quit() {
    cout << "Exiting the program.\n";
    exit(0);
}
