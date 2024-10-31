#include <stdio.h>
#include <stdlib.h>

int getLeapYear(int year);
int numberOfDaysSinceYearOne(int year);
int getLeapDays(int year);
void printMonthNames(char* months[], int startMonth, int endMonth);
void printWeekdayNames(char* weekdays[]);
void printCalendar(int totalDaysSinceYearOne, int startMonth, int endMonth, int isLeapYear, char* months[], char* weekdays[]);
int* getFirstDayInMonths(int startMonth, int endMonth, int totalDays, int isLeapYear);
int* getNumberOfDaysPerMonth(int startMonth, int endMonth, int isLeapYear);

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
/// Get number of leap days between year 1 and X
/// </summary>
/// <param name="year"></param>
/// <returns></returns>
int getLeapDays(int year)
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
int numberOfDaysSinceYearOne(int year)
{
	int days = 0;
	days = ((year - 1) * 365) + 1;

	return days;
}

/// <summary>
/// Print month names in three separate columns and four rows, with consistent spacings
/// </summary>
/// <param name="months"></param>
/// <param name="startMonth"></param>
/// <param name="endMonth"></param>
void printMonthNames(char* months[], int startMonth, int endMonth)
{
	printf("%*s", 6, ""); // Offset from left of application
	for (int i = startMonth; i < endMonth; i++)
	{
		printf("%-*s", 26, months[i]);
	}
	printf("\n");
}

/// <summary>
/// Print weekday names, "Su-Sa", with consistent spacings
/// </summary>
/// <param name="weekdays"></param>
void printWeekdayNames(char* weekdays[])
{
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 7; i++)
		{
			printf("%-3s", weekdays[i]);
		}
		printf("%5s", "");
	}
	printf("\n");
}

/// <summary>
/// Print calendar for a specific year, including leap day when needed.
/// </summary>
/// <param name="totalDaysSinceYearOne"></param>
/// <param name="startMonth"></param>
/// <param name="endMonth"></param>
/// <param name="isLeapYear"></param>
/// <param name="months"></param>
/// <param name="weekdays"></param>
void printCalendar(int totalDaysSinceYearOne, int startMonth, int endMonth, int isLeapYear, char* months[], char* weekdays[])
{
	printMonthNames(months, startMonth, endMonth);
	printWeekdayNames(weekdays);
	int* firstDayInMonths = getFirstDayInMonths(startMonth, endMonth, totalDaysSinceYearOne, isLeapYear);
	int* numberOfDaysPerMonth = getNumberOfDaysPerMonth(startMonth, endMonth, isLeapYear);

	int count[3] = { 0,0,0 }; //Keep track of how many days have been printed.

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 7; k++)
			{
				if (k >= firstDayInMonths[j])
				{
					count[j]++;
					if (count[j] <= numberOfDaysPerMonth[j])
					{
						printf("%2d ", count[j]);
					}
					else
					{
						printf("%2s ", "");
					}
				}
				else
				{
					printf("%2s ", "");
				}
			}
			printf("%5s", "");
			firstDayInMonths[j] = 0;
		}
		printf("\n");
	}

	free(firstDayInMonths);
	free(numberOfDaysPerMonth);
}

/// <summary>
/// Get first weekday of the first week of each month, "Su-Sa", translated to 0-6
/// </summary>
/// <param name="startMonth"></param>
/// <param name="endMonth"></param>
/// <param name="totalDays"></param>
/// <param name="isLeapYear"></param>
/// <returns></returns>
int* getFirstDayInMonths(int startMonth, int endMonth, int totalDays, int isLeapYear)
{
	int* firstDayInMonths = (int*)malloc(sizeof(int) * (endMonth - startMonth));

	// Initialize the array
	for (int i = 0; i < (endMonth - startMonth); i++) {
		firstDayInMonths[i] = 0;
	}

	int daysInMonths[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (isLeapYear)
	{
		daysInMonths[1] = 29;
	}

	int totalOffset = 0;
	int ticks = 0;

	for (int i = 0; i < endMonth; i++)
	{
		int offset = daysInMonths[i];
		if(i >= startMonth && i < endMonth)
		{
			firstDayInMonths[ticks] = (totalDays + totalOffset) % 7;
			ticks++;
		}
		totalOffset += offset;
	}

	return firstDayInMonths;
}

/// <summary>
/// Get number of days for the provided months, account for leap year.
/// </summary>
/// <param name="startMonth"></param>
/// <param name="endMonth"></param>
/// <param name="isLeapYear"></param>
/// <returns></returns>
int* getNumberOfDaysPerMonth(int startMonth, int endMonth, int isLeapYear)
{
	int* dayCount = (int*)malloc(sizeof(int) * (endMonth - startMonth));

	// Initialize the array
	for (int i = 0; i < (endMonth - startMonth); i++) {
		dayCount[i] = 0;
	}

	int daysInMonths[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (isLeapYear)
	{
		daysInMonths[1] = 29;
	}
	int ticks = 0;
	for (int i = startMonth; i < endMonth; i++)
	{
		int days = daysInMonths[i];
		dayCount[ticks] = days;
		ticks++;
	}

	return dayCount;
}