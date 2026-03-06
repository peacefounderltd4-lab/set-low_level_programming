#include <stdio.h>
#include "main.h"

/**
 * print_remaining_days - takes a date and prints how many days are
 * left in the year, taking leap years into account
 * @month: month in number format
 * @day: day of month (already converted to day of year)
 * @year: year
 * Return: void
 */
void print_remaining_days(int month, int day, int year)
{
    int is_leap;

    /* Correct leap year calculation */
    is_leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    /* Adjust day for leap years if past Feb */
    if (is_leap && month > 2)
        day++;

    /* Check for invalid Feb 29 in non-leap years */
    if (!is_leap && month == 2 && day == 60)
    {
        printf("Invalid date: %02d/%02d/%04d\n", month, day - 31, year);
        return;
    }

    /* Print day of year and remaining days */
    if (is_leap)
    {
        printf("Day of the year: %d\n", day);
        printf("Remaining days: %d\n", 366 - day);
    }
    else
    {
        printf("Day of the year: %d\n", day);
        printf("Remaining days: %d\n", 365 - day);
    }
}
