#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "functions.h"

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


int main() {
    // Initialize the CUnit test registry
    CU_initialize_registry();

    // Create a test suite
    CU_pSuite suite = CU_add_suite("Leap Days Tests", 0, 0);
    CU_pSuite suite1 = CU_add_suite("Leap Year Tests", 0, 0);
    // Add each test to the suite
    CU_add_test(suite, "Test getLeapDays for year 2004", test_getLeapDays_2004);
    CU_add_test(suite, "Test getLeapDays for year 2000", test_getLeapDays_2000);
    CU_add_test(suite, "Test getLeapDays for year 1990", test_getLeapDays_1990);
    CU_add_test(suite, "Test getLeapDays for year 1980", test_getLeapDays_1980);
    CU_add_test(suite, "Test getLeapDays for year 1970", test_getLeapDays_1970);
    CU_add_test(suite, "Test getLeapDays for year 1960", test_getLeapDays_1960);
    CU_add_test(suite, "Test getLeapDays for year 2500", test_getLeapDays_2500);
    CU_add_test(suite, "Test getLeapDays for year 2200", test_getLeapDays_2200);
    CU_add_test(suite, "Test getLeapDays for year 1800", test_getLeapDays_1800);
    CU_add_test(suite, "Test getLeapDays for year 3000", test_getLeapDays_3000);
    CU_add_test(suite, "Test getLeapDays for year 1500", test_getLeapDays_1500);
    CU_add_test(suite, "Test getLeapDays for year 2100", test_getLeapDays_2100);
    CU_add_test(suite, "Test getLeapDays for year 2400", test_getLeapDays_2400);
    CU_add_test(suite, "Test getLeapDays for year 1300", test_getLeapDays_1300);
    CU_add_test(suite, "Test getLeapDays for year 1700", test_getLeapDays_1700);
    CU_add_test(suite, "Test getLeapDays for year 1900", test_getLeapDays_1900);

    CU_add_test(suite1, "Test getLeapYear leap year divisible by 400", test_leapYear_divisibleBy400);
    CU_add_test(suite1, "Test getLeapYear leap year divisible by 4 not 100", test_leapYear_divisibleBy4Not100);
    CU_add_test(suite1, "Test getLeapYear non-leap year divisible by 100 not by 400", test_nonLeapYear_divisibleBy100Not400);
    CU_add_test(suite1, "Test getLeapYear non-leap year not divisible by 4", test_nonLeapYear_notDivisibleBy4);

    
    CU_basic_set_mode(CU_BRM_NORMAL);
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