//////////////////////////////////////////////////////////////////////////
// Copyright (C) 2024 Samuel Jeffman
// All rights reserved.
//
// Description: Header file for functions related to calendar operations.
//////////////////////////////////////////////////////////////////////////

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

int getLeapYear(int year);
int getNumberOfDaysSinceYearOne(int year);
int getLeapDays(int year);
void printYear(int year, const char option[]);
void printCalendar(int startMonth, int endMonth, const char* months[], const char* weekdays[], int year, const char option[]);
void runAssertions(void);

#endif  // FUNCTIONS_H_
