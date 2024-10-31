#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getLeapYear(int year);
int numberOfDaysSinceYearOne(int year);
int getLeapDays(int year);
void printYear(int year);
void printMonthNames(char* months[], int startMonth, int endMonth);
void printWeekdayNames(char* weekdays[]);
void printCalendar(int totalDaysSinceYearOne, int startMonth, int endMonth, int isLeapYear, char* months[], char* weekdays[], int year);
int* getFirstDayInMonths(int startMonth, int endMonth, int totalDays, int isLeapYear);
int* getNumberOfDaysPerMonth(int startMonth, int endMonth, int isLeapYear);
void printWeekNumbers();

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
/// Print year in the middle of the application
/// </summary>
/// <param name="year"></param>
void printYear(int year)
{
	printf("%*s", 38, ""); // Offset from left of application
	printf("%d\n", year);
	printf("\n");
}

/// <summary>
/// Print month names in three separate columns and four rows, with consistent spacings
/// </summary>
/// <param name="months"></param>
/// <param name="startMonth"></param>
/// <param name="endMonth"></param>
void printMonthNames(char* months[], int startMonth, int endMonth)
{
	printf("%*s", 9, ""); // Offset from left of application
	for (int i = startMonth; i < endMonth; i++)
	{
		printf("%-*s", 29, months[i]);
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
		printf("%2s ", "");
		for (int i = 0; i < 7; i++)
		{
			printf("%-3s", weekdays[i]);
		}
		printf("%5s", "");
	}
	printf("\n");
}

/// <summary>
/// Function to calculate the week number for a specific date.
/// </summary>
/// <param name="year"></param>
/// <param name="month"></param>
/// <param name="day"></param>
/// <param name="firstDayOfWeek"></param>
/// <returns></returns>
int getWeekNumber(int year, int month, int day, int firstDayOfWeek) {
	struct tm timeStruct = { 0 };
	timeStruct.tm_year = year - 1900; // tm_year is years since 1900
	timeStruct.tm_mon = month - 1;    // tm_mon is 0-based
	timeStruct.tm_mday = day;

	// Normalize the time structure
	mktime(&timeStruct);

	// Adjust the day of the week if the first day of the week is Monday
	if (firstDayOfWeek == 1) { // 1 for Monday
		if (timeStruct.tm_wday == 0) {
			timeStruct.tm_wday = 6; // Sunday becomes Saturday
		}
		else {
			timeStruct.tm_wday -= 1; // Shift days back by one
		}
	}

	// Calculate the week number
	char buffer[3];
	strftime(buffer, sizeof(buffer), "%U", &timeStruct); // Use %U for week number starting with Sunday
	return atoi(buffer) + 1; // Add 1 to match the expected week number
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
void printCalendar(int totalDaysSinceYearOne, int startMonth, int endMonth, int isLeapYear, char* months[], char* weekdays[], int year)
{
	printMonthNames(months, startMonth, endMonth);
	printWeekdayNames(weekdays);
	int* firstDayInMonths = getFirstDayInMonths(startMonth, endMonth, totalDaysSinceYearOne, isLeapYear);
	int* numberOfDaysPerMonth = getNumberOfDaysPerMonth(startMonth, endMonth, isLeapYear);

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
						if (day == 0)
						{
							int y = year;
							int m = startMonth + month + 1;
							int d = dayCount[month];
							int week = getWeekNumber(y, m, d, 0);
							printf("%2d ", week);
						}
						printf("%2d ", dayCount[month]);
					}
					else
					{
						if (day == 0)
						{
							printf("%2s ", ""); //Trailing non-days of the week
						}
						printf("%2s ", ""); //Trailing non-days of the week
					}
				}
				else
				{
					if (day == 0)
					{
						int y = year;
						int m = startMonth + month + 1;
						int d = dayCount[month]+1;
						int week = getWeekNumber(y, m, d, 0);
						printf("%2d ", week);
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