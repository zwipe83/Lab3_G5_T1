#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "functions.h"
#include <stdio.h>
#include <string.h>

int getLeapDays(int year);

// Test for leap days from 1 to 2004
void test_getLeapDays_2004() {
    CU_ASSERT(getLeapDays(2004) == 485); // Leap days from 1 to 2004
}

// Test for leap days from 1 to 2000
void test_getLeapDays_2000() {
    CU_ASSERT(getLeapDays(2000) == 484); // Leap days from 1 to 1999
}

// Test for leap days from 1 to 1990
void test_getLeapDays_1990() {
    CU_ASSERT(getLeapDays(1990) == 482); // Leap days from 1 to 1989
}

// Test for leap days from 1 to 1980
void test_getLeapDays_1980() {
    CU_ASSERT(getLeapDays(1980) == 479); // Leap days from 1 to 1979
}

// Test for leap days from 1 to 1970
void test_getLeapDays_1970() {
    CU_ASSERT(getLeapDays(1970) == 477); // Leap days from 1 to 1969
}

// Test for leap days from 1 to 1960
void test_getLeapDays_1960() {
    CU_ASSERT(getLeapDays(1960) == 474); // Leap days from 1 to 1959
}

// Test for leap days from 1 to 2500
void test_getLeapDays_2500() {
    CU_ASSERT(getLeapDays(2500) == 606); // Leap days from 1 to 2499
}

// Test for leap days from 1 to 2200
void test_getLeapDays_2200() {
    CU_ASSERT(getLeapDays(2200) == 533); // Leap days from 1 to 2199
}

// Test for leap days from 1 to 1800
void test_getLeapDays_1800() {
    CU_ASSERT(getLeapDays(1800) == 436); // Leap days from 1 to 1799
}

// Test for leap days from 1 to 3000
void test_getLeapDays_3000() {
    CU_ASSERT(getLeapDays(3000) == 727); // Leap days from 1 to 2999
}

// Test for leap days from 1 to 1500
void test_getLeapDays_1500() {
    CU_ASSERT(getLeapDays(1500) == 363); // Leap days from 1 to 1499
}

// Test for leap days from 1 to 2100
void test_getLeapDays_2100() {
    CU_ASSERT(getLeapDays(2100) == 509); // Leap days from 1 to 2099
}

// Test for leap days from 1 to 2400
void test_getLeapDays_2400() {
    CU_ASSERT(getLeapDays(2400) == 581); // Leap days from 1 to 2399
}

// Test for leap days from 1 to 1300
void test_getLeapDays_1300() {
    CU_ASSERT(getLeapDays(1300) == 315); // Leap days from 1 to 1299
}

// Test for leap days from 1 to 1700
void test_getLeapDays_1700() {
    CU_ASSERT(getLeapDays(1700) == 412); // Leap days from 1 to 1699
}

// Test for leap days from 1 to 1900
void test_getLeapDays_1900() {
    CU_ASSERT(getLeapDays(1900) == 460); // Leap days from 1 to 1899
}
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
// Test function for leap year divisible by 400
void test_leapYear_divisibleBy400(void) {
    CU_ASSERT_TRUE(getLeapYear(2000));
    CU_ASSERT_TRUE(getLeapYear(2400));
}

// Test function for leap year divisible by 4 but not 100
void test_leapYear_divisibleBy4Not100(void) {
    CU_ASSERT_TRUE(getLeapYear(2020));
}

// Test function for non-leap year divisible by 100 but not 400
void test_nonLeapYear_divisibleBy100Not400(void) {
    CU_ASSERT_FALSE(getLeapYear(1900));
    CU_ASSERT_FALSE(getLeapYear(2100));
}

// Test function for non-leap year not divisible by 4
void test_nonLeapYear_notDivisibleBy4(void) {
    CU_ASSERT_FALSE(getLeapYear(2019));
}
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

// Test function for year 1
void test_numberOfDaysSinceYearOne_year1(void) {
    CU_ASSERT_EQUAL(numberOfDaysSinceYearOne(1), 1);
}

// Test function for year 2
void test_numberOfDaysSinceYearOne_year2(void) {
    CU_ASSERT_EQUAL(numberOfDaysSinceYearOne(2), 366);
}

// Test function for year 3
void test_numberOfDaysSinceYearOne_year3(void) {
    CU_ASSERT_EQUAL(numberOfDaysSinceYearOne(3), 731);
}

// Test function for year 100
void test_numberOfDaysSinceYearOne_year100(void) {
    CU_ASSERT_EQUAL(numberOfDaysSinceYearOne(100), 36136);
}

// Test function for year 2024
void test_numberOfDaysSinceYearOne_year2024(void) {
    CU_ASSERT_EQUAL(numberOfDaysSinceYearOne(2024), 738396);
}
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
// Helper function to capture output
void captureOutput(void (*func)(int, char[]), int year, char option[], char *buffer, size_t size) {
    FILE *fp = freopen("output.txt", "w+", stdout);
    if (fp == NULL) {
        perror("freopen");
        return;
    }
    func(year, option);
    fflush(stdout);
    fseek(fp, 0, SEEK_SET);
    fread(buffer, sizeof(char), size, fp);
    fclose(fp);
    freopen("/dev/tty", "a", stdout); // Restore stdout
}

// Test function for printYear with default option
void test_printYear_default(void) {
    char buffer[100] = {0};
    captureOutput(printYear, 2024, "", buffer, sizeof(buffer));
    CU_ASSERT_STRING_EQUAL(buffer, "                                   2024\n\n");
}

// Test function for printYear with -w option
void test_printYear_wide(void) {
    char buffer[100] = {0};
    captureOutput(printYear, 2024, "-w", buffer, sizeof(buffer));
    CU_ASSERT_STRING_EQUAL(buffer, "                                      2024\n\n");
}
//////////////////////////////////////////////////////////////////////////////

int main() {
    // Initialize the CUnit test registry
    CU_initialize_registry();

    // Create a test suite
    CU_pSuite suite1 = CU_add_suite("Leap Days Tests", 0, 0);
    CU_pSuite suite2 = CU_add_suite("Leap Year Tests", 0, 0);
    CU_pSuite suite3 = CU_add_suite("Number of days since year 1 Tests", 0, 0);
    CU_pSuite suite4 = CU_add_suite("Print year Tests", 0, 0);
    // Add each test to the suite
    CU_add_test(suite1, "Test getLeapDays for year 2004", test_getLeapDays_2004);
    CU_add_test(suite1, "Test getLeapDays for year 2000", test_getLeapDays_2000);
    CU_add_test(suite1, "Test getLeapDays for year 1990", test_getLeapDays_1990);
    CU_add_test(suite1, "Test getLeapDays for year 1980", test_getLeapDays_1980);
    CU_add_test(suite1, "Test getLeapDays for year 1970", test_getLeapDays_1970);
    CU_add_test(suite1, "Test getLeapDays for year 1960", test_getLeapDays_1960);
    CU_add_test(suite1, "Test getLeapDays for year 2500", test_getLeapDays_2500);
    CU_add_test(suite1, "Test getLeapDays for year 2200", test_getLeapDays_2200);
    CU_add_test(suite1, "Test getLeapDays for year 1800", test_getLeapDays_1800);
    CU_add_test(suite1, "Test getLeapDays for year 3000", test_getLeapDays_3000);
    CU_add_test(suite1, "Test getLeapDays for year 1500", test_getLeapDays_1500);
    CU_add_test(suite1, "Test getLeapDays for year 2100", test_getLeapDays_2100);
    CU_add_test(suite1, "Test getLeapDays for year 2400", test_getLeapDays_2400);
    CU_add_test(suite1, "Test getLeapDays for year 1300", test_getLeapDays_1300);
    CU_add_test(suite1, "Test getLeapDays for year 1700", test_getLeapDays_1700);
    CU_add_test(suite1, "Test getLeapDays for year 1900", test_getLeapDays_1900);

    CU_add_test(suite2, "Test getLeapYear leap year divisible by 400", test_leapYear_divisibleBy400);
    CU_add_test(suite2, "Test getLeapYear leap year divisible by 4 not 100", test_leapYear_divisibleBy4Not100);
    CU_add_test(suite2, "Test getLeapYear non-leap year divisible by 100 not by 400", test_nonLeapYear_divisibleBy100Not400);
    CU_add_test(suite2, "Test getLeapYear non-leap year not divisible by 4", test_nonLeapYear_notDivisibleBy4);

    CU_add_test(suite3, "Test numberOfDaysSinceYear for year 1", test_numberOfDaysSinceYearOne_year1);
    CU_add_test(suite3, "Test numberOfDaysSinceYear for year 2", test_numberOfDaysSinceYearOne_year2);
    CU_add_test(suite3, "Test numberOfDaysSinceYear for year 3", test_numberOfDaysSinceYearOne_year3);
    CU_add_test(suite3, "Test numberOfDaysSinceYear for year 100", test_numberOfDaysSinceYearOne_year100);
    CU_add_test(suite3, "Test numberOfDaysSinceYear for year 2024", test_numberOfDaysSinceYearOne_year2024);
	
    CU_add_test(suite4, "Test printYear for year default", test_printYear_default);
    CU_add_test(suite4, "Test printYear for year wide", test_printYear_wide);

    
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_set_error_action(CUEA_FAIL);
    printf("\nTests completed with return value %d.\n", CU_basic_run_tests());
	
	if(CU_get_number_of_suites_run() != 0)
	{
		printf("\nSuites run: %d.\n", CU_get_number_of_suites_run());
		
	}
	if(CU_get_number_of_suites_failed() != 0)
	{
		printf("\nSuites failed: %d.\n", CU_get_number_of_suites_failed());
		
	}
	if(CU_get_number_of_tests_run() != 0)
	{
		printf("\nTests run: %d.\n", CU_get_number_of_tests_run());
		
	}
	if(CU_get_number_of_tests_failed() != 0)
	{
		printf("\nTests failed: %d.\n", CU_get_number_of_tests_failed());
		
	}
	if(CU_get_number_of_asserts() != 0)
	{
		printf("\nAsserts run: %d.\n", CU_get_number_of_asserts());
		
	}
	if(CU_get_number_of_successes() != 0)
	{
		printf("\nNumber of successes: %d.\n", CU_get_number_of_successes());
		
	}
	if(CU_get_number_of_failures() != 0)
	{
		printf("\nNumber of failures: %d.\n", CU_get_number_of_failures());
		
	}
	
	int failures = CU_get_number_of_tests_failed();
	
    CU_cleanup_registry();
		
	return failures;
}