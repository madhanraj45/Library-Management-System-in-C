# 📚 Library Management System in C

A **console-based Library Management System** developed using the **C programming language**.

This project allows users to manage books, issue and return books, search for books, calculate overdue fines, and store library data permanently using binary files.

---

## 🚀 Features

### 📖 Book Management

* Add new books
* Update book details
* Remove books
* View all books
* Search books by:

  * Book ID
  * Book name
  * Author name
* Case-insensitive book and author searching

### 📕 Issue Management

* Issue books to users
* Check book availability before issuing
* Automatically reduce available quantity
* Generate unique Issue IDs
* Store user information
* Automatically record issue date
* Automatically calculate due date

### 🔄 Return Management

* Return issued books
* Validate Book ID and User ID
* Automatically increase available quantity
* Record return date
* Calculate overdue days
* Automatically calculate fine

### 💰 Fine Calculation

* Loan period: **7 days**
* Fine: **Rs. 5 per overdue day**

### 💾 Data Persistence

The system stores data permanently using binary files:

* `books.dat` — Stores book information
* `issues.dat` — Stores issue and return records

Data is automatically loaded when the program starts and can be saved from the main menu.

---

## 🛠️ Technologies Used

* **C Programming**
* Structures
* Arrays
* Functions
* Pointers
* String handling
* File handling
* `time.h`
* Dynamic date calculation
* Binary file operations
* GCC Compiler

---

## 📂 Project Structure

```text
Library-Management-System/
│
├── book.c
├── main.c
├── issue.c
├── file.c
├── utils.c
│
├── books.dat
├── issues.dat
│
└── README.md
```

### `book.c`

Contains all book-related operations:

* Add book
* Update book
* Remove book
* Search book
* Display all books
* Find book by ID

### `main.c`

Contains:

* Main program
* Main menu
* User interaction
* Function calls

### `issue.c`

Contains:

* Book issuing
* Book returning
* Issue record management
* Fine calculation
* Issued-book listing

### `file.c`

Handles permanent storage:

* Save books
* Save issue records
* Load books
* Load issue records

### `utils.c`

Contains utility functions:

* Integer input validation
* Current date calculation
* Date conversion
* Date addition
* Date difference calculation

---

## 📋 Main Menu

```text
          +-------------------------------------------+
          |          BOOK MANAGEMENT SYSTEM           |
          +-------------------------------------------+
          | 1. Add New Book                           |
          | 2. Update Book Details                    |
          | 3. Remove Book                            |
          | 4. Search Book                            |
          | 5. View All Books                         |
          | 6. Issue Book                             |
          | 7. Return Book                            |
          | 8. List Issued Books                      |
          | 9. Save                                   |
          | 10. Exit                                  |
          +-------------------------------------------+
```

---

## 🔄 Program Workflow

```text
                 ┌───────────────┐
                 │ Start Program │
                 └───────┬───────┘
                         │
                         ▼
                 ┌───────────────┐
                 │ Load Data     │
                 │ from Files    │
                 └───────┬───────┘
                         │
                         ▼
                 ┌───────────────┐
                 │   Main Menu   │
                 └───────┬───────┘
                         │
        ┌────────────────┼─────────────────┐
        │                │                 │
        ▼                ▼                 ▼
   Book Management   Issue Book       Return Book
        │                │                 │
        └────────────────┼─────────────────┘
                         │
                         ▼
                 ┌───────────────┐
                 │   Save Data   │
                 └───────┬───────┘
                         │
                         ▼
                 ┌───────────────┐
                 │     Exit      │
                 └───────────────┘
```

---

## 📦 Book Structure

```c
typedef struct
{
    int bookID;
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
    int quantity;
} Book;
```

Each book contains:

| Field      | Description                |
| ---------- | -------------------------- |
| `bookID`   | Unique ID of the book      |
| `title`    | Book title                 |
| `author`   | Author name                |
| `quantity` | Number of available copies |

---

## 📕 Issue Structure

```c
typedef struct
{
    int issueID;
    int bookID;
    int userID;

    char userName[NAME_LEN];

    char issueDate[DATE_LEN];
    char dueDate[DATE_LEN];
    char returnDate[DATE_LEN];

    double fineAmount;

    int returned;
} Issue;
```

The issue record stores:

* Issue ID
* Book ID
* User ID
* User name
* Issue date
* Due date
* Return date
* Fine amount
* Return status

---

## 💰 Fine Calculation

The default loan period is:

```text
7 days
```

Fine per overdue day:

```text
Rs. 5
```

For example:

```text
Due Date    : 10-08-2026
Return Date : 13-08-2026

Late Days   : 3

Fine        : 3 × Rs.5
            = Rs.15
```

---

## 💾 File Handling

The program uses binary files for persistent storage.

### Books

```text
books.dat
```

Stores:

```text
Book count
Book records
```

### Issues

```text
issues.dat
```

Stores:

```text
Issue count
Issue records
```

The data remains available even after closing and restarting the program.

---

## ▶️ How to Compile

Make sure GCC is installed.

Open the terminal inside the project directory.

Compile all source files together:

```bash
gcc main.c book.c issue.c file.c utils.c -o library
```

Run the program:

### Linux / macOS

```bash
./library
```

### Windows

```bash
gcc main.c book.c issue.c file.c utils.c -o library.exe
```

Then:

```bash
library.exe
```

---

## 🖥️ Example

### Adding a Book

```text
Enter Book ID: 101
Enter Title: The C Programming Language
Enter Author: Dennis Ritchie
Enter Quantity: 5

Book added successfully.
```

### Issuing a Book

```text
Enter Book ID to issue: 101
Enter User ID: 1001
Enter User Name: Madhan

Book issued successfully.

Issue ID   : 1
Issue Date : 19-08-2026
Due Date   : 26-08-2026
```

### Returning a Book

```text
Enter Book ID: 101
Enter User ID: 1001

Book returned successfully.
Returned on time. No fine.
```

---

## 🎯 Learning Objectives

This project was developed to practice and demonstrate:

* C programming fundamentals
* Structures
* Arrays
* Functions
* String manipulation
* File handling
* Modular programming
* Input validation
* Date and time handling
* Searching algorithms
* Record management
* Persistent data storage

---

## 🔮 Future Improvements

Possible improvements for future versions:

* [ ] Login system for librarian/admin
* [ ] Password protection
* [ ] Separate student/member management
* [ ] Multiple copies and reservation system
* [ ] Better input validation
* [ ] Automatic overdue notification
* [ ] Report generation
* [ ] Sorting books by title, author, or ID
* [ ] Improved user interface
* [ ] Database integration
* [ ] GUI version

---

## 👨‍💻 Author

**Madhanraj B**


---

## ⭐ Project

If you find this project useful for learning C programming and file handling, consider giving the repository a ⭐.

---
