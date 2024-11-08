#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "functions.h"

int getLeapDays(int year);

// Test case for getLeapDays
void test_getLeapDays() {
    CU_ASSERT(getLeapDays(2001) == 488); // Leap days from 1 to 2000
    CU_ASSERT(getLeapDays(1901) == 456); // Leap days from 1 to 1900
    CU_ASSERT(getLeapDays(2021) == 505); // Leap days from 1 to 2020
    CU_ASSERT(getLeapDays(1601) == 397); // Leap days from 1 to 1600
}

int main() {
    // Initialize the CUnit test registry
    CU_initialize_registry();

    // Create a test suite
    CU_pSuite suite = CU_add_suite("Leap Year Tests", 0, 0);
    CU_add_test(suite, "Test getLeapDays", test_getLeapDays);

    // Run the tests
    CU_basic_run_tests();

    // Clean up the registry
    CU_cleanup_registry();
    return 0;
}