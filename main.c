#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

/// <summary>
/// Month and weekday names
/// </summary>
const char* months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
const char* weekdays[] = { "Su", "Mo", "Tu", "We", "Th", "Fr", "Sa" };

int main() {

	do
	{
		// Init variables
		int year, isLeapYear, daysSinceYearOne, leapDaysSinceYearOne, totalDaysSinceYearOne;
		char option[10];
		option[0] = '\0'; // Set option to empty string

		// Ask for a specific year
		printf("Enter a year (Option '-w' to display week numbers, less than 0 to exit): \n");
		int y = scanf("%d", &year); // Read only the year first

		// Check if there is an additional option
		if (getchar() == ' ') { // Check if there is a space indicating more input
			int o = scanf("%9s", option); // Read the option if available
		}

		system("cls"); // Clear console screen

		if (year < 0)
		{
			exit(0); // Exit the program
		}

		// Print the parsed values
		printf("Year: %d\n", year);
		printf("Option: %s\n", option);

		// Is the entered year a leap year?
		isLeapYear = getLeapYear(year);

		// Get number of days since year one.
		daysSinceYearOne = numberOfDaysSinceYearOne(year);

		// Get number of leap days since year one.
		leapDaysSinceYearOne = getLeapDays(year);

		// Add days since year one and leap days since year one.
		totalDaysSinceYearOne = daysSinceYearOne + leapDaysSinceYearOne;

		// Print the year.
		printYear(year, option);

		// Print calendar three months at a time.
		printCalendar(totalDaysSinceYearOne, 0, 3, isLeapYear, months, weekdays, year, option); //Jan-Mar
		printCalendar(totalDaysSinceYearOne, 3, 6, isLeapYear, months, weekdays, year, option); //Apr-Jun
		printCalendar(totalDaysSinceYearOne, 6, 9, isLeapYear, months, weekdays, year, option); //Jul-Sep
		printCalendar(totalDaysSinceYearOne, 9, 12, isLeapYear, months, weekdays, year, option); //Oct-Dec
	} while (1); // Ask for another year.

	return 0;
}