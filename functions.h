#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int getLeapYear(int year);
int getNumberOfDaysSinceYearOne(int year);
int getLeapDays(int year);
void printYear(int year, const char option[]);
void printCalendar(int startMonth, int endMonth, const char* months[], const char* weekdays[], int year, char option[]);
void runAssertions(void);

#endif // FUNCTIONS_H
