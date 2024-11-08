#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "functions.h"

int getLeapDays(int year);

// Test for leap days from 1 to 1600
void test_getLeapDays_1600() {
    CU_ASSERT(getLeapDays(1601) == 397); // Leap days from 1 to 1600
}

// Test for leap days from 1 to 1700
void test_getLeapDays_1700() {
    CU_ASSERT(getLeapDays(1701) == 400); // Leap days from 1 to 1700
}

// Test for leap days from 1 to 1800
void test_getLeapDays_1800() {
    CU_ASSERT(getLeapDays(1801) == 440); // Leap days from 1 to 1800
}

// Test for leap days from 1 to 1900
void test_getLeapDays_1900() {
    CU_ASSERT(getLeapDays(1901) == 456); // Leap days from 1 to 1900
}

// Test for leap days from 1 to 2000
void test_getLeapDays_2000() {
    CU_ASSERT(getLeapDays(2001) == 488); // Leap days from 1 to 2000
}

// Test for leap days from 1 to 1500
void test_getLeapDays_1500() {
    CU_ASSERT(getLeapDays(1501) == 366); // Leap days from 1 to 1500
}

// Test for leap days from 1 to 1601
void test_getLeapDays_1601() {
    CU_ASSERT(getLeapDays(1602) == 397); // Leap days from 1 to 1601
}

// Test for leap days from 1 to 1701
void test_getLeapDays_1701() {
    CU_ASSERT(getLeapDays(1702) == 400); // Leap days from 1 to 1701
}

// Test for leap days from 1 to 1801
void test_getLeapDays_1801() {
    CU_ASSERT(getLeapDays(1802) == 440); // Leap days from 1 to 1801
}

// Test for leap days from 1 to 1901
void test_getLeapDays_1901() {
    CU_ASSERT(getLeapDays(1902) == 456); // Leap days from 1 to 1901
}

// Test for leap days from 1 to 2001
void test_getLeapDays_2001() {
    CU_ASSERT(getLeapDays(2002) == 488); // Leap days from 1 to 2001
}

// Test for leap days from 1 to 1602
void test_getLeapDays_1602() {
    CU_ASSERT(getLeapDays(1603) == 397); // Leap days from 1 to 1602
}

// Test for leap days from 1 to 1702
void test_getLeapDays_1702() {
    CU_ASSERT(getLeapDays(1703) == 400); // Leap days from 1 to 1702
}

// Test for leap days from 1 to 1802
void test_getLeapDays_1802() {
    CU_ASSERT(getLeapDays(1803) == 440); // Leap days from 1 to 1802
}

// Test for leap days from 1 to 1902
void test_getLeapDays_1902() {
    CU_ASSERT(getLeapDays(1903) == 456); // Leap days from 1 to 1902
}

// Test for leap days from 1 to 2002
void test_getLeapDays_2002() {
    CU_ASSERT(getLeapDays(2003) == 488); // Leap days from 1 to 2002
}

// Test for leap days from 1 to 1603
void test_getLeapDays_1603() {
    CU_ASSERT(getLeapDays(1604) == 397); // Leap days from 1 to 1603
}

// Test for leap days from 1 to 1703
void test_getLeapDays_1703() {
    CU_ASSERT(getLeapDays(1704) == 400); // Leap days from 1 to 1703
}

// Test for leap days from 1 to 1803
void test_getLeapDays_1803() {
    CU_ASSERT(getLeapDays(1804) == 440); // Leap days from 1 to 1803
}

// Test for leap days from 1 to 1903
void test_getLeapDays_1903() {
    CU_ASSERT(getLeapDays(1904) == 456); // Leap days from 1 to 1903
}

// Test for leap days from 1 to 2003
void test_getLeapDays_2003() {
    CU_ASSERT(getLeapDays(2004) == 488); // Leap days from 1 to 2003
}

// Test for leap days from 1 to 1604
void test_getLeapDays_1604() {
    CU_ASSERT(getLeapDays(1605) == 397); // Leap days from 1 to 1604
}

// Test for leap days from 1 to 1704
void test_getLeapDays_1704() {
    CU_ASSERT(getLeapDays(1705) == 400); // Leap days from 1 to 1704
}

// Test for leap days from 1 to 1804
void test_getLeapDays_1804() {
    CU_ASSERT(getLeapDays(1805) == 440); // Leap days from 1 to 1804
}

// Test for leap days from 1 to 1904
void test_getLeapDays_1904() {
    CU_ASSERT(getLeapDays(1905) == 456); // Leap days from 1 to 1904
}

// Test for leap days from 1 to 2004
void test_getLeapDays_2004() {
    CU_ASSERT(getLeapDays(2004) == 488); // Leap days from 1 to 2004
}

int main() {
    // Initialize the CUnit test registry
    CU_initialize_registry();

    // Create a test suite
    CU_pSuite suite = CU_add_suite("Leap Year Tests", 0, 0);
    // Add each test to the suite
    CU_add_test(suite, "Test getLeapDays for year 1600", test_getLeapDays_1600);
    CU_add_test(suite, "Test getLeapDays for year 1700", test_getLeapDays_1700);
    CU_add_test(suite, "Test getLeapDays for year 1800", test_getLeapDays_1800);
    CU_add_test(suite, "Test getLeapDays for year 1900", test_getLeapDays_1900);
    CU_add_test(suite, "Test getLeapDays for year 2000", test_getLeapDays_2000);
    CU_add_test(suite, "Test getLeapDays for year 1500", test_getLeapDays_1500);
    CU_add_test(suite, "Test getLeapDays for year 1601", test_getLeapDays_1601);
    CU_add_test(suite, "Test getLeapDays for year 1701", test_getLeapDays_1701);
    CU_add_test(suite, "Test getLeapDays for year 1801", test_getLeapDays_1801);
    CU_add_test(suite, "Test getLeapDays for year 1901", test_getLeapDays_1901);
    CU_add_test(suite, "Test getLeapDays for year 2001", test_getLeapDays_2001);
    CU_add_test(suite, "Test getLeapDays for year 1602", test_getLeapDays_1602);
    CU_add_test(suite, "Test getLeapDays for year 1702", test_getLeapDays_1702);
    CU_add_test(suite, "Test getLeapDays for year 1802", test_getLeapDays_1802);
    CU_add_test(suite, "Test getLeapDays for year 1902", test_getLeapDays_1902);
    CU_add_test(suite, "Test getLeapDays for year 2002", test_getLeapDays_2002);
    CU_add_test(suite, "Test getLeapDays for year 1603", test_getLeapDays_1603);
    CU_add_test(suite, "Test getLeapDays for year 1703", test_getLeapDays_1703);
    CU_add_test(suite, "Test getLeapDays for year 1803", test_getLeapDays_1803);
    CU_add_test(suite, "Test getLeapDays for year 1903", test_getLeapDays_1903);
    CU_add_test(suite, "Test getLeapDays for year 2003", test_getLeapDays_2003);
    CU_add_test(suite, "Test getLeapDays for year 1604", test_getLeapDays_1604);
    CU_add_test(suite, "Test getLeapDays for year 1704", test_getLeapDays_1704);
    CU_add_test(suite, "Test getLeapDays for year 1804", test_getLeapDays_1804);
    CU_add_test(suite, "Test getLeapDays for year 1904", test_getLeapDays_1904);
    CU_add_test(suite, "Test getLeapDays for year 2004", test_getLeapDays_2004);

    // Run the tests
    CU_basic_run_tests();

    // Clean up the registry
    CU_cleanup_registry();
    return 0;
}