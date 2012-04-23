#include "CalendarRecycle.h"
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

class CalendarRecycleTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    CalendarRecycle solution;

    void testCase0() {
		int year = 2002;
		int expected_ = 2013;
        assertEquals(0, expected_, solution.useAgain(year));
    }

    void testCase1() {
		int year = 2013;
		int expected_ = 2019;
        assertEquals(1, expected_, solution.useAgain(year));
    }

    void testCase2() {
		int year = 2008;
		int expected_ = 2036;
        assertEquals(2, expected_, solution.useAgain(year));
    }

    void testCase3() {
		int year = 9999;
		int expected_ = 10010;
        assertEquals(3, expected_, solution.useAgain(year));
    }

    void testCase4() {
		int year = 2525;
		int expected_ = 2531;
        assertEquals(4, expected_, solution.useAgain(year));
    }

    public: void runTest(int testCase) {
        switch (testCase) {
            case (0): testCase0(); break;
            case (1): testCase1(); break;
            case (2): testCase2(); break;
            case (3): testCase3(); break;
            case (4): testCase4(); break;
            default: cerr << "No such test case: " << testCase << endl; break;
        }
    }

};

int main() {
    for (int i = 0; i < 5; i++) {
        CalendarRecycleTest test;
        test.runTest(i);
    }
}
