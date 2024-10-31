#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

const char* months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
const char* weekdays[] = { "Su", "Mo", "Tu", "We", "Th", "Fr", "Sa" };

int getLeapYear(int year);
int numberOfDaysSinceYearOne(int year);
int getLeapDays(int year);
void printCalendar(int totalDaysSinceYearOne, int startMonth, int endMonth, int isLeapYear, char* months[], char* weekdays[], int year);

int main() {

	do
	{
		// Init variables
		int year, isLeapYear, daysSinceYearOne, leapDaysSinceYearOne, totalDaysSinceYearOne;

		int y = 2024;
		int m = 1;
		int d = 6;

		int weekNumber = getWeekNumber(y, m, d, 6);
		printf("The week number for %d-%02d-%02d is: %d\n", y, m, d, weekNumber);

		y = 1983;
		m = 1;
		d = 0;

		weekNumber = getWeekNumber(y, m, d, 6);
		printf("The week number for %d-%02d-%02d is: %d\n", y, m, d, weekNumber);

		//Ask for a specific year
		printf("Enter a year (less than 0 to exit): \n");
		scanf_s("%d", &year);
		system("cls"); // Clear console screen

		if (year < 0)
		{
			exit(0);
		}

		//Is the entered year a leap year?
		isLeapYear = getLeapYear(year);

		//Get number of days since year one.
		daysSinceYearOne = numberOfDaysSinceYearOne(year);

		//Get number of leap days since year one.
		leapDaysSinceYearOne = getLeapDays(year);

		//Add days since year one and leap days since year one.
		totalDaysSinceYearOne = daysSinceYearOne + leapDaysSinceYearOne;

		//Print the year.
		printYear(year);

		//Print calendar three months at a time.
		printCalendar(totalDaysSinceYearOne, 0, 3, isLeapYear, months, weekdays, year); //Jan-Mar
		printCalendar(totalDaysSinceYearOne, 3, 6, isLeapYear, months, weekdays, year); //Apr-Jun
		printCalendar(totalDaysSinceYearOne, 6, 9, isLeapYear, months, weekdays, year); //Jul-Sep
		printCalendar(totalDaysSinceYearOne, 9, 12, isLeapYear, months, weekdays, year); //Oct-Dec
	} while (1); //Ask for another year.

	return 0;
}