#include "LCMRange.h"
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

class LCMRangeTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    LCMRange solution;

    void testCase0() {
		int first = 1;
		int last = 5;
		int expected_ = 60;
        assertEquals(0, expected_, solution.lcm(first, last));
    }

    void testCase1() {
		int first = 4;
		int last = 5;
		int expected_ = 20;
        assertEquals(1, expected_, solution.lcm(first, last));
    }

    void testCase2() {
		int first = 1;
		int last = 12;
		int expected_ = 27720;
        assertEquals(2, expected_, solution.lcm(first, last));
    }
    void testCase3() {
		int first = 8;
		int last = 12;
		int expected_ = 3960;
        assertEquals(2, expected_, solution.lcm(first, last));
    }

    public: void runTest(int testCase) {
        switch (testCase) {
            case (0): testCase0(); break;
            case (1): testCase1(); break;
            case (2): testCase2(); break;
            case (3): testCase3(); break;
            default: cerr << "No such test case: " << testCase << endl; break;
        }
    }

};

int main() {
    for (int i = 0; i <= 3; i++) {
        LCMRangeTest test;
        test.runTest(i);
    }
}
