#include <stdio.h>
#include <string.h>

#define MAX_ISSUES 1000
#define NAME_LEN 100
#define DATE_LEN 11

#define FINE_PER_DAY 5.0
#define LOAN_DAYS 7


/* Book structure - same as book.c */
#define MAX_BOOKS 500
#define TITLE_LEN 100
#define AUTHOR_LEN 100

typedef struct
{
    int bookID;
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
    int quantity;
} Book;


/* Issue structure */

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


/* Global variables */

extern Book books[MAX_BOOKS];
extern int bookCount;

Issue issues[MAX_ISSUES];
int issueCount = 0;


/* Functions from other files */

int readInt(char message[]);

void getCurrentDate(char date[]);
void addDaysToDate(char date[], int days, char result[]);
long dateDiffDays(char date1[], char date2[]);

int findBook(int id);


/* Issue a book */

void issueBook()
{
    int bookID;
    int userID;
    int bookIndex;

    if(issueCount >= MAX_ISSUES)
    {
        printf("Issue record storage is full.\n");
        return;
    }

    bookID = readInt("Enter Book ID to issue: ");

    /* Find the book */

    bookIndex = findBook(bookID);

    if(bookIndex == -1)
    {
        printf("Book not found.\n");
        return;
    }

    /* Check available quantity */

    if(books[bookIndex].quantity <= 0)
    {
        printf("No copies of \"%s\" are currently available.\n",
               books[bookIndex].title);
        return;
    }


    /* Create issue record */

    issues[issueCount].issueID = issueCount + 1;

    issues[issueCount].bookID = bookID;

    userID = readInt("Enter User ID: ");

    issues[issueCount].userID = userID;


    getchar();

    printf("Enter User Name: ");

    fgets(issues[issueCount].userName,
          NAME_LEN,
          stdin);

    issues[issueCount].userName[
        strcspn(issues[issueCount].userName, "\n")
    ] = '\0';


    /* Get today's date */

    getCurrentDate(issues[issueCount].issueDate);


    /* Due date = issue date + 7 days */

    addDaysToDate(
        issues[issueCount].issueDate,
        LOAN_DAYS,
        issues[issueCount].dueDate
    );


    /* Book has not been returned yet */

    issues[issueCount].returnDate[0] = '\0';

    issues[issueCount].fineAmount = 0.0;

    issues[issueCount].returned = 0;


    /* Increase issue count */

    issueCount++;


    /* Reduce available book quantity */

    books[bookIndex].quantity--;


    printf("\nBook issued successfully.\n");

    printf("Issue ID   : %d\n",
           issues[issueCount - 1].issueID);

    printf("Issue Date : %s\n",
           issues[issueCount - 1].issueDate);

    printf("Due Date   : %s\n",
           issues[issueCount - 1].dueDate);
}


/* Return a book */

void returnBook()
{
    int bookID;
    int userID;

    int issueIndex = -1;
    int bookIndex;

    long lateDays;

    bookID = readInt("Enter Book ID: ");

    bookIndex = findBook(bookID);

    if(bookIndex == -1)
    {
        printf("Book not found.\n");
        return;
    }

userID = readInt("Enter User ID: ");

    /* Find the active issue */

    for(int i = 0; i < issueCount; i++)
    {
        if(issues[i].bookID == bookID &&
           issues[i].userID == userID &&
           issues[i].returned == 0)
        {
            issueIndex = i;
            break;
        }
    }


    if(issueIndex == -1)
    {
        printf("No matching active issue record found.\n");
        return;
    }


    /* Get return date */

    getCurrentDate(issues[issueIndex].returnDate);


    /* Calculate late days */

    lateDays = dateDiffDays(
        issues[issueIndex].dueDate,
        issues[issueIndex].returnDate
    );


    /* Calculate fine */

    if(lateDays > 0)
    {
        issues[issueIndex].fineAmount =
            lateDays * FINE_PER_DAY;
    }
    else
    {
        issues[issueIndex].fineAmount = 0;
    }


    /* Mark book as returned */

    issues[issueIndex].returned = 1;


    /* Increase book quantity */

books[bookIndex].quantity++;

    printf("\nBook returned successfully.\n");


    if(lateDays > 0)
    {
        printf("Book was %ld day(s) late.\n", lateDays);

        printf("Fine: Rs. %.2f\n",
               issues[issueIndex].fineAmount);
    }
    else
    {
        printf("Returned on time. No fine.\n");
    }
}


/* Display all issued books */

void listIssuedBooks()
{
    int bookIndex;

    if(issueCount == 0)
    {
        printf("No issue records yet.\n");
        return;
    }


    printf("\nIssued Books\n");

    printf("-------------------------------------------------------------------------------------------------------------\n");

    printf("%-6s | %-6s | %-25s | %-6s | %-11s | %-11s | %-11s | %-8s | %-9s\n",
           "IssID",
           "BookID",
           "Title",
           "UserID",
           "IssueDate",
           "DueDate",
           "RetDate",
           "Fine",
           "Status");

    printf("-------------------------------------------------------------------------------------------------------------\n");


    for(int i = 0; i < issueCount; i++)
    {
        bookIndex = findBook(issues[i].bookID);


        if(bookIndex != -1)
        {
            printf("%-6d | %-6d | %-25.25s | %-6d | %-11s | %-11s | %-11s | %-8.2f | %-9s\n",

                   issues[i].issueID,

                   issues[i].bookID,

                   books[bookIndex].title,

                   issues[i].userID,

                   issues[i].issueDate,

                   issues[i].dueDate,

                   issues[i].returned ?
                   issues[i].returnDate : "-",

                   issues[i].fineAmount,

                   issues[i].returned ?
                   "Returned" : "Issued");
        }
    }
}
