# README - Library Management System

![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![File I/O](https://img.shields.io/badge/File%20I%2FO-005571?style=for-the-badge)
![OOP](https://img.shields.io/badge/OOP-FF6F00?style=for-the-badge)

## Introduction

The Library Management System is a console-based application developed in C++. It offers a range of features to manage a library's collection of books, including adding, deleting, editing, searching, viewing, and saving books.

## Features

- **Add Book**: Add new books with details such as ISBN, title, author, edition, and publication.
- **Delete Book**: Remove a book from the library using its ISBN.
- **Edit Book**: Modify the details of an existing book.
- **Search Book**: Find a book by its ISBN and view its details.
- **View All Books**: Display a list of all books in the library.
- **Save to File**: Save the current list of books to a file.
- **Load from File**: Load a list of books from a file.
- **Total Books Count**: View the total number of books in the library.
- **Search by Title**: Search for books by their title.
- **Sort Books by Title**: Sort the books alphabetically by their title.
- **Filter Books by Author**: View books written by a specific author.
- **Filter Books by Edition**: View books of a specific edition.
- **Unique ISBN Check**: Ensure that each book has a unique ISBN.
- **Delete All Books**: Remove all books from the library.
- **Edit All Books**: Edit details for all books in the library.
- **Exit**: Exit the application.

## Project Structure

The project consists of a single C++ source file (`main.cpp`) that contains the implementation of the Library Management System. The key components are:

- **Book Class**: Represents a book and includes attributes like ISBN, title, author, edition, and publication. It provides methods to access and modify these attributes.
- **Function Prototypes**: Define operations such as adding, deleting, editing, searching, viewing, saving, and loading books.
- **Main Function**: Implements the main loop of the application, displaying a menu and handling user input to perform various operations.
## System Flow
The following flow chart illustrates the main functionalities of the Library Management System:

```mermaid
graph TD
    A[Start] --> B[Main Menu]
    B --> C{User Choice}
    C -->|1| D[Add Book]
    C -->|2| E[Delete Book]
    C -->|3| F[Edit Book]
    C -->|4| G[Search Book]
    C -->|5| H[View All Books]
    C -->|6| I[Save to File]
    C -->|7| J[Load from File]
    C -->|8| K[Total Books Count]
    C -->|9| L[Search by Title]
    C -->|10| M[Sort Books by Title]
    C -->|11| N[Filter Books by Author]
    C -->|12| O[Filter Books by Edition]
    C -->|13| P[Delete All Books]
    C -->|14| Q[Edit All Books]
    C -->|15| R[Exit]
    D --> B
    E --> B
    F --> B
    G --> B
    H --> B
    I --> B
    J --> B
    K --> B
    L --> B
    M --> B
    N --> B
    O --> B
    P --> B
    Q --> B
    R --> S[End]
## Usage Instructions

### Prerequisites

- A C++ compiler (e.g., g++, clang++)
- Command-line interface (e.g., terminal, command prompt)
- Git installed on your system

### Steps

1. **Clone the Repository**
   ```sh
   git clone https://github.com/kknani24/library-management-system.git
   ```

2. **Navigate to the Project Directory**
   ```sh
   cd library-management-system
   ```

3. **Build the Application**
   Compile the source code using a C++ compiler. For example, with `g++`:
   ```sh
   g++ -o library_management main.cpp
   ```
   This command compiles `main.cpp` and creates an executable named `library_management`.

4. **Run the Application**
   Execute the compiled application:
   ```sh
   ./library_management
   ```
   This will start the Library Management System, and the main menu will be displayed.

## Example Commands

```sh
$ git clone https://github.com/your-username/library-management-system.git
$ cd library-management-system
$ g++ -o library_management main.cpp
$ ./library_management
```

## Conclusion

The Library Management System provides a user-friendly interface for managing a collection of books in a library. By following the steps outlined in this README, users can easily set up and use the application to perform various library management tasks.

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
