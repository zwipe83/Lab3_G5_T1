#ifndef FUNCTIONS
#define FUNCTIONS

int getLeapYear(int year);
int numberOfDaysSinceYearOne(int year);
int getLeapDays(int year);
void printMonthNames(char* months[], int startMonth, int endMonth);
void printWeekdayNames(char* weekdays[]);
void printCalendar(int totalDaysSinceYearOne, int startMonth, int endMonth, int isLeapYear, char* months[], char* weekdays[]);
int* getFirstDayInMonths(int startMonth, int endMonth, int totalDays, int isLeapYear);
int* getNumberOfDaysPerMonth(int startMonth, int endMonth, int isLeapYear);

#endif // FUNCTIONS
