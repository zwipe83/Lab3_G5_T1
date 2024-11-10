#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int getLeapYear(int year);
int numberOfDaysSinceYearOne(int year);
int getLeapDays(int year);
void printYear(int year, const char option[]);
void printCalendar(int totalDaysSinceYearOne, int startMonth, int endMonth, int isLeapYear, const char* months[], const char* weekdays[], int year, char option[]);

#endif // FUNCTIONS_H
