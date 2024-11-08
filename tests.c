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
    CU_ASSERT(getLeapDays(2500) == 609); // Leap days from 1 to 2499
}

// Test for leap days from 1 to 2200
void test_getLeapDays_2200() {
    CU_ASSERT(getLeapDays(2200) == 533); // Leap days from 1 to 2199
}

// Test for leap days from 1 to 1800
void test_getLeapDays_1800() {
    CU_ASSERT(getLeapDays(1800) == 440); // Leap days from 1 to 1799
}

// Test for leap days from 1 to 3000
void test_getLeapDays_3000() {
    CU_ASSERT(getLeapDays(3000) == 730); // Leap days from 1 to 2999
}

// Test for leap days from 1 to 1500
void test_getLeapDays_1500() {
    CU_ASSERT(getLeapDays(1500) == 366); // Leap days from 1 to 1499
}

// Test for leap days from 1 to 2100
void test_getLeapDays_2100() {
    CU_ASSERT(getLeapDays(2100) == 525); // Leap days from 1 to 2099
}

// Test for leap days from 1 to 2400
void test_getLeapDays_2400() {
    CU_ASSERT(getLeapDays(2400) == 609); // Leap days from 1 to 2399
}

// Test for leap days from 1 to 1300
void test_getLeapDays_1300() {
    CU_ASSERT(getLeapDays(1300) == 317); // Leap days from 1 to 1299
}

// Test for leap days from 1 to 1700
void test_getLeapDays_1700() {
    CU_ASSERT(getLeapDays(1700) == 400); // Leap days from 1 to 1699
}

// Test for leap days from 1 to 1900
void test_getLeapDays_1900() {
    CU_ASSERT(getLeapDays(1900) == 456); // Leap days from 1 to 1899
}

int main() {
    // Initialize the CUnit test registry
    CU_initialize_registry();

    // Create a test suite
    CU_pSuite suite = CU_add_suite("Leap Year Tests", 0, 0);
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

    // Run the tests
    CU_basic_run_tests();

    // Clean up the registry
    CU_cleanup_registry();
    return 0;
}