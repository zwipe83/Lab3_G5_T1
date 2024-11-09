#ifndef TESTS_H
#define TESTS_H

int getLeapYear(int year);
int getLeapDays(int year);
int numberOfDaysSinceYearOne(int year);
void printYear(int year, char option[]);
void printMonthNames(const char* months[], int startMonth, int endMonth, char option[]);
void printWeekdayNames(const char* weekdays[], char option[]);
int getWeekNumber(int year, int month, int day);
void printWeekNumber(int year, int startMonth, int month, const	int* dayCount, int nextDay);
int* getFirstDayInMonths(int startMonth, int endMonth, int totalDays, int isLeapYear);
int* getNumberOfDaysPerMonth(int startMonth, int endMonth, int isLeapYear);
void printCalendar(int totalDaysSinceYearOne, int startMonth, int endMonth, int isLeapYear, const char* months[], const char* weekdays[], int year, char option[]);

#endif // TESTS_H