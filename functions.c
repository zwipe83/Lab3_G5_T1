#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "functions.h"

/// Prototypes
static void printMonthNames(const char* months[], int startMonth, int endMonth, const char option[]);
static void printWeekdayNames(const char* weekdays[], const char option[]);
static int getWeekNumber(int year, int month, int day);
static void printWeekNumber(int year, int startMonth, int month, const	int* dayCount, int nextDay);
static int* getFirstDayInMonths(int startMonth, int endMonth, int year, int isLeapYear);
static int* getNumberOfDaysPerMonth(int startMonth, int endMonth, int year, int isLeapYear);

/// <summary>
/// Check if year is a leap year or not
/// </summary>
/// <param name="year"></param>
/// <returns></returns>
int getLeapYear(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

/// <summary>
/// Get number of leap days between year 1 and XXXX
/// AlgoBuild function getLeapDays
/// </summary>
/// <param name="year"></param>
/// <returns></returns>
int getLeapDays(int year) //OBSOLETE
{
	int leapDays = 0;

	for(int i = 1; i < year; i++)
	{
		if (getLeapYear(i))
		{
			leapDays++;
		}
	}

	return leapDays;
}

/// <summary>
/// Get number of days since year 1, not considering leap days
/// </summary>
/// <param name="year"></param>
/// <returns></returns>
int getNumberOfDaysSinceYearOne(int year)
{
	int days = 1; 
	
	for (int i = 1; i < year; i++) 
	{ 
		if (getLeapYear(i)) 
		{ 
			days += 366; //Leap year
		} else 
		{ 
			days += 365; //Non-leap year
		} 
	}
	return days;
}

/// <summary>
/// Print year in the middle of the application
/// </summary>
/// <param name="year"></param>
/// <param name="option"></param>
void printYear(int year, const char option[])
{
	int offset = 35;
	if ((strcmp(option, "-w") == 0))
	{
		offset = 38;
	}
	printf("%*s", offset, ""); // Offset from left of application
	printf("%d\n", year);
	printf("\n");
}

/// <summary>
/// Print month names in three separate columns and four rows, with consistent spacings
/// </summary>
/// <param name="months"></param>
/// <param name="startMonth"></param>
/// <param name="endMonth"></param>
/// <param name="option"></param>
static void printMonthNames(const char* months[], int startMonth, int endMonth, const char option[])
{
	int firstOffset = 6, secondOffset = 26;
	if ((strcmp(option, "-w") == 0))
	{
		firstOffset = 9;
		secondOffset = 29;

	}
	printf("%*s", firstOffset, ""); // Offset from left of application
	for (int i = startMonth; i < endMonth; i++)
	{
		printf("%-*s", secondOffset, months[i]);
	}
	printf("\n");
}

/// <summary>
/// Print weekday names, "Su-Sa", with consistent spacings
/// </summary>
/// <param name="weekdays"></param>
/// <param name="option"></param>
static void printWeekdayNames(const char* weekdays[], const char option[])
{
	for (int j = 0; j < 3; j++) //TODO: Maybe make this dynamic, 3 is hardcoded
	{
		if ((strcmp(option, "-w") == 0))
		{
			printf("%2s ", "");
		}
		for (int i = 0; i < 7; i++)
		{
			printf("%-3s", weekdays[i]);
		}
		printf("%5s", "");
	}
	printf("\n");
}

/// <summary>
/// Function to get week number for a specific date
/// </summary>
/// <param name="year"></param>
/// <param name="month"></param>
/// <param name="day"></param>
/// <returns>Week number 1-52</returns>
static int getWeekNumber(int year, int month, int day)
{
	// Array with the number of days in each month
	int daysInMonths[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	// Check for leap year and adjust February days
	if (getLeapYear != 0) 
	{
		daysInMonths[1] = 29;
	}

	// Calculate the day of the year
	int dayOfYear = day;
	for (int i = 0; i < month - 1; i++) {
		dayOfYear += daysInMonths[i];
	}

	// Zeller's Congruence to calculate the day of the week for January 1st
	int q = 1; // Day of the month
	int m = 13; // January is treated as the 13th month of the previous year
	int K = (year - 1) % 100; // Year of the century
	int J = (year - 1) / 100; // Zero-based century

	int dayOfWeekJan1 = (q + (13 * (m + 1)) / 5 + K + (K / 4) + (J / 4) - (2 * J)) % 7;
	dayOfWeekJan1 = (dayOfWeekJan1 + 5) % 7 + 1; // Adjust to make Sunday = 0, Monday = 1, ..., Saturday = 6

	// Calculate the week number
	int weekNumber = (dayOfYear + dayOfWeekJan1 - 1) / 7 + 1;

	// Ensure the week number does not exceed 52
	if (weekNumber > 52) {
		weekNumber = 1;
	}

	return weekNumber;
}

/// <summary>
/// Print week numbers for each month
/// </summary>
/// <param name="year"></param>
/// <param name="startMonth"></param>
/// <param name="month"></param>
/// <param name="dayCount"></param>
/// <param name="nextDay"></param>
static void printWeekNumber(int year, int startMonth, int month, const	int* dayCount, int nextDay)
{
	int y = year;
	int m = startMonth + month + 1;
	int d = dayCount[month] + nextDay;
	int week = getWeekNumber(y, m, d);
	printf("%2d ", week);
}

/// <summary>
/// Get first weekday of the first week of each month, "Su-Sa", translated to 0-6
/// </summary>
/// <param name="startMonth"></param>
/// <param name="endMonth"></param>
/// <param name="year"></param>
/// <param name="isLeapYear"></param>
/// <returns></returns>
static int* getFirstDayInMonths(int startMonth, int endMonth, int year, int isLeapYear)
{
	int totalDaysSinceYearOne = getNumberOfDaysSinceYearOne(year);
	int* firstDayInMonths = (int*)malloc(sizeof(int) * ((endMonth + 1) - startMonth));

	if (firstDayInMonths)
	{
		// Initialize the array
		for (int i = 0; i <= (endMonth - startMonth); i++) {
			firstDayInMonths[i] = 0;
		}

		int daysInMonths[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		if (isLeapYear)
		{
			daysInMonths[1] = 29;
		}

		int totalOffset = 0;
		int ticks = 0;

		for (int i = 0; i <= endMonth; i++)
		{
			int offset = daysInMonths[i];
			if (i >= startMonth)
			{
				firstDayInMonths[ticks] = (totalDaysSinceYearOne + totalOffset) % 7;
				ticks++;
			}
			totalOffset += offset;
		}
	}

	return firstDayInMonths;
}

/// <summary>
/// Get number of days for the provided months, account for leap year.
/// AlgoBuild function getNumberOfDaysPerMonth
/// </summary>
/// <param name="startMonth"></param>
/// <param name="endMonth"></param>
/// <param name="year"></param>
/// <param name="isLeapYear"></param>
/// <returns></returns>
static int* getNumberOfDaysPerMonth(int startMonth, int endMonth, int year, int isLeapYear)
{
	int* dayCount = (int*)malloc(sizeof(int) * ((endMonth+1) - startMonth));

	if (dayCount)
	{
		// Initialize the array
		for (int i = 0; i <= (endMonth - startMonth); i++) {
			dayCount[i] = 0;
		}

		int daysInMonths[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		if (isLeapYear)
		{
			daysInMonths[1] = 29;
		}

		int ticks = 0;
		for (int i = startMonth; i <= endMonth; i++)
		{
			int days = daysInMonths[i];
			dayCount[ticks] = days;
			ticks++;
		}
	}

	return dayCount;
}

/// <summary>
/// Print calendar for a specific year, including leap day when needed.
/// </summary>
/// <param name="startMonth"></param>
/// <param name="endMonth"></param>
/// <param name="isLeapYear"></param>
/// <param name="months"></param>
/// <param name="weekdays"></param>
/// <param name="year"></param>
/// <param name="option"></param>
void printCalendar(int startMonth, int endMonth, int isLeapYear, const char* months[], const char* weekdays[], int year, char option[])
{
	printMonthNames(months, startMonth, endMonth, option);
	printWeekdayNames(weekdays, option);
	int* firstDayInMonths = getFirstDayInMonths(startMonth, endMonth, year, isLeapYear); //Basically get how many days to skip before starting to print the first of the month
	int* numberOfDaysPerMonth = getNumberOfDaysPerMonth(startMonth, endMonth, year, isLeapYear);

	int dayCount[3] = { 0,0,0 }; //Keep track of how many days have been printed.

	for (int row = 0; row < 7; row++)
	{
		for (int month = 0; month < 3; month++)
		{
			for (int day = 0; day < 7; day++)
			{
				if (day >= firstDayInMonths[month])
				{
					dayCount[month]++;
					if (dayCount[month] <= numberOfDaysPerMonth[month])
					{
						if (day == 0 && (strcmp(option, "-w") == 0))
						{
							printWeekNumber(year, startMonth, month, dayCount, 0);
						}
						printf("%2d ", dayCount[month]);
					}
					else if (day == 0 && (strcmp(option, "-w") == 0))
					{
						printf("%5s ", ""); //Trailing non-days of the week
					}
					else
					{
						printf("%2s ", ""); //Trailing non-days of the week
					}
				}
				else
				{
					if (day == 0 && (strcmp(option, "-w") == 0))
					{
						printWeekNumber(year, startMonth, month, dayCount, 1);
					}
					printf("%2s ", ""); //Leading non-days of the week
				}
			}
			printf("%5s", "");
			firstDayInMonths[month] = 0;
		}
		printf("\n");
	}

	free(firstDayInMonths);
	free(numberOfDaysPerMonth);
}

/// <summary>
/// Run all assertions
/// </summary>
/// <returns></returns>
void runAssertions()
{
	// Test getLeapYear
	assert(getLeapYear(100) == 0);
	assert(getLeapYear(2000) == 1);
	assert(getLeapYear(2001) == 0);
	assert(getLeapYear(2004) == 1);
	assert(getLeapYear(2100) == 0);
	assert(getLeapYear(2400) == 1);

	// Test numberOfDaysSinceYearOne
	assert(getNumberOfDaysSinceYearOne(1) == 1);
	assert(getNumberOfDaysSinceYearOne(100) == 36160);
	assert(getNumberOfDaysSinceYearOne(1753) == 639906);
	assert(getNumberOfDaysSinceYearOne(2024) == 738886);

	// Test getWeekNumber
	assert(getWeekNumber(2024, 1, 1) == 1);
	assert(getWeekNumber(2024, 1, 7) == 2);
	assert(getWeekNumber(2024, 2, 1) == 5);
	assert(getWeekNumber(2024, 12, 28) == 52);

	// Test getFirstDayInMonths
	int* firstDayInMonths = getFirstDayInMonths(0, 2, 2024, 1); //Jan-Mar 2024
	assert(firstDayInMonths[0] == 1);
	assert(firstDayInMonths[1] == 4);
	assert(firstDayInMonths[2] == 5);
	free(firstDayInMonths);

	firstDayInMonths = getFirstDayInMonths(0, 2, 1753, 0); //Jan-Mar 1753
	assert(firstDayInMonths[0] == 1);
	assert(firstDayInMonths[1] == 4);
	assert(firstDayInMonths[2] == 4);
	free(firstDayInMonths);

	// Test getNumberOfDaysPerMonth
	int* numberOfDaysPerMonth = getNumberOfDaysPerMonth(0, 2, 2024, 1); //Jan-Mar Leap year
	assert(numberOfDaysPerMonth[0] == 31);
	assert(numberOfDaysPerMonth[1] == 29);
	assert(numberOfDaysPerMonth[2] == 31);
	free(numberOfDaysPerMonth);

	numberOfDaysPerMonth = getNumberOfDaysPerMonth(0, 2, 2023, 0); //Jan-Mar Non-leap year
	assert(numberOfDaysPerMonth[0] == 31);
	assert(numberOfDaysPerMonth[1] == 28);
	assert(numberOfDaysPerMonth[2] == 31);
	free(numberOfDaysPerMonth);

	numberOfDaysPerMonth = getNumberOfDaysPerMonth(0, 11, 2024, 1); //Jan-Dec Leap year
	assert(numberOfDaysPerMonth[0] == 31);
	assert(numberOfDaysPerMonth[1] == 29);
	assert(numberOfDaysPerMonth[2] == 31);
	assert(numberOfDaysPerMonth[11] == 31);
	free(numberOfDaysPerMonth);

	numberOfDaysPerMonth = getNumberOfDaysPerMonth(0, 11, 2023, 0); //Jan-Dec Non-leap year
	assert(numberOfDaysPerMonth[0] == 31);
	assert(numberOfDaysPerMonth[1] == 28);
	assert(numberOfDaysPerMonth[2] == 31);
	assert(numberOfDaysPerMonth[11] == 31);
	free(numberOfDaysPerMonth);
}