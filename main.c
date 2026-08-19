#include <stdio.h>
#include <stdlib.h>


/* Variables from other files */
extern int bookCount;
extern int issueCount;

/* Book functions */
void addBook();
void updateBookMenu();
void removeBookMenu();
void searchBookMenu();
void viewAllBooks();

/* Issue functions */
void issueBook();
void returnBook();
void listIssuedBooks();

/* File functions */
void saveData();
void loadData();

/* Utility function */
int readInt(char message[]);


void printMenu()
{
    printf("\n");
    printf("          +-------------------------------------------+\n");
    printf("          |          BOOK MANAGEMENT SYSTEM           |\n");
    printf("          +-------------------------------------------+\n");
    printf("          | 1. Add New Book                           |\n");
    printf("          | 2. Update Book Details                    |\n");
    printf("          | 3. Remove Book                            |\n");
    printf("          | 4. Search Book                            |\n");
    printf("          | 5. View All Books                         |\n");
    printf("          | 6. Issue Book                             |\n");
    printf("          | 7. Return Book                            |\n");
    printf("          | 8. List Issued Books                      |\n");
    printf("          | 9. Save                                   |\n");
    printf("          | 10. Exit                                  |\n");
    printf("          +-------------------------------------------+\n");
}

void pauseScreen()
{
    printf("\nPress Enter to continue...");
    getchar();
    getchar();
}


int main()
{
    int choice;

    /* Load previously saved data */
    loadData();

    printf("\nLibrary Management System\n");
    printf("Loaded %d book(s) and %d issue record(s).\n",
           bookCount, issueCount);

   
    {
	system("clear");
        printMenu();

        choice = readInt("Enter choice: ");
	while(1)
	{
	    system("clear");
	    printMenu();
	    choice = readInt("Enter choice: ");
	    switch(choice)
   	    {
        	case 1:
            	addBook();
            	pauseScreen();
            	break;

        	case 2:
            	updateBookMenu();
            	pauseScreen();
            	break;

        	case 3:
            	removeBookMenu();
            	pauseScreen();
           	break;

        	case 4:
            	searchBookMenu();
            	pauseScreen();
            	break;

        	case 5:
            	viewAllBooks();
            	pauseScreen();
            	break;

        	case 6:
            	issueBook();
            	pauseScreen();
            	break;

        	case 7:
            	returnBook();
            	pauseScreen();
           	break;

        	case 8:
            	listIssuedBooks();
            	pauseScreen();
            	break;

        	case 9:
            	saveData();
            	pauseScreen();
            	break;

        	case 10:
            	saveData();
            	printf("Goodbye!\n");
            	return 0;

        	default:
            	printf("Invalid choice. Please select 1-10.\n");
            	pauseScreen();
   	}
	}
  
    }
}
