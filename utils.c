#include <stdio.h>
#include <string.h>
#include <time.h>

#define DATE_LEN 11


/*
    Read an integer from the user
*/
int readInt(char message[])
{
    int value;

    while(1)
    {
        printf("%s", message);

        if(scanf("%d", &value) == 1)
        {
            return value;
        }

        printf("Invalid number. Please try again.\n");

        /* Clear wrong input */
        while(getchar() != '\n');
    }
}


/*
    Get today's date

    Format:
    DD-MM-YYYY
*/
void getCurrentDate(char date[])
{
    time_t currentTime;
    struct tm *today;

    currentTime = time(NULL);

    today = localtime(&currentTime);

    sprintf(date,
            "%02d-%02d-%04d",
            today->tm_mday,
            today->tm_mon + 1,
            today->tm_year + 1900);
}


/*
    Convert DD-MM-YYYY into struct tm
*/
void convertDate(char date[], struct tm *result)
{
    int day;
    int month;
    int year;

    sscanf(date,
           "%d-%d-%d",
           &day,
           &month,
           &year);

    result->tm_sec = 0;
    result->tm_min = 0;
    result->tm_hour = 12;

    result->tm_mday = day;
    result->tm_mon = month - 1;
    result->tm_year = year - 1900;
}


/*
    Add number of days to a date
*/
void addDaysToDate(char date[], int days, char result[])
{
    struct tm temp;
    time_t newTime;
    struct tm *newDate;

    convertDate(date, &temp);

    newTime = mktime(&temp);

    newTime = newTime + (days * 24 * 60 * 60);

    newDate = localtime(&newTime);

    sprintf(result,
            "%02d-%02d-%04d",
            newDate->tm_mday,
            newDate->tm_mon + 1,
            newDate->tm_year + 1900);
}


/*
    Find the difference between two dates

    date2 - date1
*/
long dateDiffDays(char date1[], char date2[])
{
    struct tm firstDate;
    struct tm secondDate;

    time_t time1;
    time_t time2;

    double difference;


    convertDate(date1, &firstDate);
    convertDate(date2, &secondDate);


    time1 = mktime(&firstDate);
    time2 = mktime(&secondDate);


    difference = difftime(time2, time1);


    return (long)(difference / (24 * 60 * 60));
}
