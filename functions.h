//////////////////////////////////////////////////////////////////////////
// <summary>
// Grade 5 Task, option 3
// Filename: functions.h
// Created on: 2024-10-20 00:00:00
// Author: Samuel Jeffman
// Description: Header file for functions related to calendar operations.
// </summary>
//////////////////////////////////////////////////////////////////////////

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

int getLeapYear(int year);
int getNumberOfDaysSinceYearOne(int year);
int getLeapDays(int year);
void printYear(int year, const char option[]);
void printCalendar (int startMonth, int endMonth, const char* months[], const char* weekdays[], int year, const char option[]);
void runAssertions(void);

#endif  // FUNCTIONS_H_
