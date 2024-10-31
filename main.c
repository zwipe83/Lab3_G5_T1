#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int getLeapYear(int year);
int numberOfDaysSinceYearOne(int year);
int getLeapDays(int year);
void printCalendar(int totalDaysSinceYearOne, int startMonth, int endMonth, int isLeapYear, char* months[], char* weekdays[]);

int main() {

	do
	{
		// Init variables
		int year, isLeapYear, daysSinceYearOne, leapDaysSinceYearOne, totalDaysSinceYearOne;
		char* months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
		char* weekdays[] = { "Su", "Mo", "Tu", "We", "Th", "Fr", "Sa" };

		//Ask for a specific year
		printf("Enter a year(less than 0 to exit): \n");
		scanf_s("%d", &year);

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

		//Print calendar three months at a time.
		printCalendar(totalDaysSinceYearOne, 0, 3, isLeapYear, months, weekdays); //Jan-Mar
		printCalendar(totalDaysSinceYearOne, 3, 6, isLeapYear, months, weekdays); //Apr-Jun
		printCalendar(totalDaysSinceYearOne, 6, 9, isLeapYear, months, weekdays); //Jul-Sep
		printCalendar(totalDaysSinceYearOne, 9, 12, isLeapYear, months, weekdays); //Oct-Dec
	} while (1); //Ask for another year.

	return 0;
}