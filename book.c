#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

/* Global book data */
Book books[MAX_BOOKS];
int bookCount = 0;


/* Function from utils.c */
int readInt(char message[]);


/* Find a book using Book ID */
int findBook(int id)
{
    int i;

    for(i = 0; i < bookCount; i++)
    {
        if(books[i].bookID == id)
        {
            return i;
        }
    }

    return -1;
}


/* Add a new book */
void addBook()
{
    int id;

    if(bookCount >= MAX_BOOKS)
    {
        printf("Book storage is full. Cannot add more books.\n");
        return;
    }

    printf("Enter Book ID: ");
    scanf("%d", &id);

    /* Check whether ID already exists */
    if(findBook(id) != -1)
    {
        printf("A book with ID %d already exists.\n", id);
        return;
    }

    books[bookCount].bookID = id;

    getchar();

    printf("Enter Title: ");
    fgets(books[bookCount].title, TITLE_LEN, stdin);

    /* Remove newline */
    books[bookCount].title[
        strcspn(books[bookCount].title, "\n")
    ] = '\0';


    printf("Enter Author: ");
    fgets(books[bookCount].author, AUTHOR_LEN, stdin);

    /* Remove newline */
    books[bookCount].author[
        strcspn(books[bookCount].author, "\n")
    ] = '\0';


    printf("Enter Quantity: ");
    scanf("%d", &books[bookCount].quantity);

    bookCount++;

    printf("Book added successfully.\n");
}


/* Update book details */
void updateBookMenu()
{
    int choice;
    int id;
    int index;
    char name[TITLE_LEN];

    printf("\nUpdate Book Details\n");
    printf("1. By Book ID\n");
    printf("2. By Book Name\n");
    printf("3. Back\n");

    choice = readInt("Enter choice: ");

    if(choice == 1)
    {
        id = readInt("Enter Book ID: ");

        index = findBook(id);

        if(index == -1)
        {
            printf("Book not found.\n");
            return;
        }
    }
    else if(choice == 2)
    {
        getchar();

        printf("Enter Book Name: ");
        fgets(name, TITLE_LEN, stdin);

        name[strcspn(name, "\n")] = '\0';

        index = -1;

        for(int i = 0; i < bookCount; i++)
        {
		char title[TITLE_LEN];
		strcpy(title, books[i].title);
		for(int j = 0; title[j] != '\0'; j++)
		{
    			title[j] = tolower(title[j]);
		}
		for(int j = 0; name[j] != '\0'; j++)
		{
    			name[j] = tolower(name[j]);
		}
		if(strcmp(title, name) == 0)
		{
   			index = i;
    			break;
		}
        }

        if(index == -1)
        {
            printf("Book not found.\n");
            return;
        }
    }
    else
    {
        return;
    }


    getchar();

    printf("Current Title: %s\n", books[index].title);

    printf("New Title: ");
    fgets(books[index].title, TITLE_LEN, stdin);

    books[index].title[
        strcspn(books[index].title, "\n")
    ] = '\0';


    printf("Current Author: %s\n", books[index].author);

    printf("New Author: ");
    fgets(books[index].author, AUTHOR_LEN, stdin);

    books[index].author[
        strcspn(books[index].author, "\n")
    ] = '\0';


    printf("Current Quantity: %d\n", books[index].quantity);

    printf("New Quantity: ");
    scanf("%d", &books[index].quantity);

    printf("Book updated successfully.\n");
}


/* Remove a book */
void removeBookMenu()
{
    int choice;
    int id;
    int index;
    char name[TITLE_LEN];

    printf("\nRemove Book\n");
    printf("1. By Book ID\n");
    printf("2. By Book Name\n");
    printf("3. Back\n");

    choice = readInt("Enter choice: ");

    if(choice == 1)
    {
        id = readInt("Enter Book ID: ");

        index = findBook(id);

        if(index == -1)
        {
            printf("Book not found.\n");
            return;
        }
    }
    else if(choice == 2)
    {
        getchar();

        printf("Enter Book Name: ");
        fgets(name, TITLE_LEN, stdin);

        name[strcspn(name, "\n")] = '\0';

        index = -1;

        for(int i = 0; i < bookCount; i++)
        {
		char title[TITLE_LEN];
		strcpy(title, books[i].title);
		for(int j = 0; title[j] != '\0'; j++)
		{
    			title[j] = tolower(title[j]);
		}
		for(int j = 0; name[j] != '\0'; j++)
		{
    			name[j] = tolower(name[j]);
		}
		if(strcmp(title, name) == 0)
		{
    			index = i;
    			break;
		}
        }

        if(index == -1)
        {
            printf("Book not found.\n");
            return;
        }
    }
    else
    {
        return;
    }


    /* Shift remaining books one position left */
    for(int i = index; i < bookCount - 1; i++)
    {
        books[i] = books[i + 1];
    }

    bookCount--;

    printf("Book removed successfully.\n");
}


/* Search for a book */
void searchBookMenu()
{
    int choice;
    int id;
    int found = 0;
    char search[100];

    printf("\nSearch Book\n");
    printf("1. By Book ID\n");
    printf("2. By Book Name\n");
    printf("3. By Author Name\n");
    printf("4. Back\n");

    choice = readInt("Enter choice: ");

    if(choice == 1)
    {
        id = readInt("Enter Book ID: ");

        int index = findBook(id);

        if(index != -1)
        {
            printf("\nID\tTitle\t\tAuthor\t\tQuantity\n");

            printf("%d\t%s\t\t%s\t\t%d\n",
                   books[index].bookID,
                   books[index].title,
                   books[index].author,
                   books[index].quantity);

            found = 1;
        }
    }

    else if(choice == 2)
    {
        getchar();

        printf("Enter Book Name: ");
	fgets(search, 100, stdin);
	search[strcspn(search, "\n")] = '\0';
	for(int j = 0; search[j] != '\0'; j++)
	{
    		search[j] = tolower(search[j]);
	}
	for(int i = 0; i < bookCount; i++)
	{
    		char title[TITLE_LEN];
		strcpy(title, books[i].title);
		for(int j = 0; title[j] != '\0'; j++)
    		{
        		title[j] = tolower(title[j]);
    		}
		if(strstr(title, search) != NULL)
    		{
        		if(found == 0)
        		{
            			printf("\nID\tTitle\t\tAuthor\t\tQuantity\n");
       			}
		printf("%d\t%s\t\t%s\t\t%d\n",
                books[i].bookID,
                books[i].title,
                books[i].author,
                books[i].quantity);

                found = 1;
   		}
	}
    }

    else if(choice == 3)
    {
        getchar();

        printf("Enter Author Name: ");
        fgets(search, 100, stdin);

        search[strcspn(search, "\n")] = '\0';

        for(int i = 0; i < bookCount; i++)
        {
		char author[AUTHOR_LEN];

		strcpy(author, books[i].author);

		for(int j = 0; author[j] != '\0'; j++)
		{
   			 author[j] = tolower(author[j]);
		}

		for(int j = 0; search[j] != '\0'; j++)
		{
   			 search[j] = tolower(search[j]);
		}

		if(strstr(author, search) != NULL)
		{
  			if(found == 0)
   			{
       				 printf("\nID\tTitle\t\tAuthor\t\tQuantity\n");
   			}

   			 printf("%d\t%s\t\t%s\t\t%d\n",
          		 books[i].bookID,
          		 books[i].title,
          		 books[i].author,
         		 books[i].quantity);

   			 found = 1;
		}
        }
    }

    else
    {
        return;
    }

    if(found == 0)
    {
        printf("No matching book found.\n");
    }
}


/* Display all books */
void viewAllBooks()
{
    int i;

    if(bookCount == 0)
    {
        printf("No books in the system yet.\n");
        return;
    }

    printf("\nAll Books\n");

    printf("---------------------------------------------------------------------\n");

    printf("%-6s | %-30s | %-20s | %-8s\n",
           "ID",
           "Title",
           "Author",
           "Qty");

    printf("---------------------------------------------------------------------\n");

    for(i = 0; i < bookCount; i++)
    {
        printf("%-6d | %-30s | %-20s | %-8d\n",
               books[i].bookID,
               books[i].title,
               books[i].author,
               books[i].quantity);
    }
}
