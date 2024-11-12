#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

/// <summary>
/// Month and weekday names
/// </summary>
const char* months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
const char* weekdays[] = { "Su", "Mo", "Tu", "We", "Th", "Fr", "Sa" };

int main() 
{
	//printf("days 2024: %d\n", getNumberOfDaysSinceYearOne(2024));
	//printf("days 1753: %d\n", getNumberOfDaysSinceYearOne(1753));
	//printf("days 100: %d\n", getNumberOfDaysSinceYearOne(100));
	
	//Run assertions
	runAssertions();

	do
	{
		// Init variables
		int year, isLeapYear;
		char option[10];
		option[0] = '\0'; // Set option to empty string

		// Ask for a specific year
		printf("Enter a year (Option '-w' to display week numbers, <= 0 to exit): \n");
		scanf_s("%d", &year); // Read only the year first
		
		system("cls"); // Clear console screen

		if (year <= 0)
		{
			exit(0); // Exit the program
		}

		if (year < 1753)
		{
			printf("Year must be greater than 1752\n"); //Application doesn't handle switch between Julian an Gregorian calendar
			continue;
		}

		// Check if there is an additional option
		if (getchar() == ' ') { // Check if there is a space indicating more input
			int o = scanf("%9s", option); // Read the option if available
		}

		// Print the parsed values
		printf("Year: %d\n", year);
		printf("Option: %s\n", option);

		// Print the year.
		printYear(year, option);

		// Print calendar three months at a time.
		printCalendar(0, 3, months, weekdays, year, option); //Jan-Mar
		printCalendar(3, 6, months, weekdays, year, option); //Apr-Jun
		printCalendar(6, 9, months, weekdays, year, option); //Jul-Sep
		printCalendar(9, 12, months, weekdays, year, option); //Oct-Dec
	} while (1); // Ask for another year.

	return 0;
}