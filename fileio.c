#include <stdio.h>

#define BOOKS_FILE "books.dat"
#define ISSUES_FILE "issues.dat"

#define MAX_BOOKS 500
#define MAX_ISSUES 1000

#define TITLE_LEN 100
#define AUTHOR_LEN 100
#define NAME_LEN 100
#define DATE_LEN 11


/* Book structure */

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


/* Variables from other files */

extern Book books[MAX_BOOKS];
extern int bookCount;

extern Issue issues[MAX_ISSUES];
extern int issueCount;


/* Save all data */

void saveData()
{
    FILE *fp;


    /* Save books */

    fp = fopen(BOOKS_FILE, "wb");

    if(fp == NULL)
    {
        printf("Error opening books file.\n");
        return;
    }

    fwrite(&bookCount, sizeof(int), 1, fp);

    fwrite(books,
           sizeof(Book),
           bookCount,
           fp);

    fclose(fp);


    /* Save issue records */

    fp = fopen(ISSUES_FILE, "wb");

    if(fp == NULL)
    {
        printf("Error opening issues file.\n");
        return;
    }

    fwrite(&issueCount, sizeof(int), 1, fp);

    fwrite(issues,
           sizeof(Issue),
           issueCount,
           fp);

    fclose(fp);


    printf("Data saved successfully.\n");
}


/* Load all data */

void loadData()
{
    FILE *fp;


    /* Load books */

    fp = fopen(BOOKS_FILE, "rb");

    if(fp != NULL)
    {
        fread(&bookCount,
              sizeof(int),
              1,
              fp);

        if(bookCount > MAX_BOOKS)
        {
            bookCount = 0;
        }
        else
        {
            fread(books,
                  sizeof(Book),
                  bookCount,
                  fp);
        }

        fclose(fp);
    }


    /* Load issue records */

    fp = fopen(ISSUES_FILE, "rb");

    if(fp != NULL)
    {
        fread(&issueCount,
              sizeof(int),
              1,
              fp);

        if(issueCount > MAX_ISSUES)
        {
            issueCount = 0;
        }
        else
        {
            fread(issues,
                  sizeof(Issue),
                  issueCount,
                  fp);
        }

        fclose(fp);
    }
}
