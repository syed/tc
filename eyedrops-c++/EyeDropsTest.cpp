#include "EyeDrops.h"
#include <algorithm>
#include <cmath>
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

class EyeDropsTest {

    static void assertEquals(int testCase, double expected, double actual) {
        double delta = max(1e-9, 1e-9 * abs(expected));
        if (abs(expected - actual) <= delta) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout.precision(24);
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    EyeDrops solution;

    void testCase0() {
		int sleepTime = 8;
		int k = 2;
		double expected_ = 720.0;
        assertEquals(0, expected_, solution.closest(sleepTime, k));
    }

    void testCase1() {
		int sleepTime = 9;
		int k = 3;
		double expected_ = 450.0;
        assertEquals(1, expected_, solution.closest(sleepTime, k));
    }

    void testCase2() {
		int sleepTime = 23;
		int k = 1;
		double expected_ = 1440.0;
        assertEquals(2, expected_, solution.closest(sleepTime, k));
    }

    void testCase3() {
		int sleepTime = 9;
		int k = 8;
		double expected_ = 128.57142857142856;
        assertEquals(3, expected_, solution.closest(sleepTime, k));
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
    for (int i = 0; i < 4; i++) {
        EyeDropsTest test;
        test.runTest(i);
    }
}
