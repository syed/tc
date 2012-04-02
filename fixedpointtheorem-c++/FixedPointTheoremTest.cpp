#include "FixedPointTheorem.h"
#include <algorithm>
#include <cmath>
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

class FixedPointTheoremTest {

    static void assertEquals(int testCase, double expected, double actual) {
        double delta = max(1e-9, 1e-9 * abs(expected));
        if (abs(expected - actual) <= delta) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout.precision(24);
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    FixedPointTheorem solution;

    void testCase0() {
		double R = 0.1;
		double expected_ = 0.0;
        assertEquals(0, expected_, solution.cycleRange(R));
    }

    void testCase1() {
		double R = 3.05;
		double expected_ = 0.14754098360655865;
        assertEquals(1, expected_, solution.cycleRange(R));
    }

    void testCase2() {
		double R = 3.4499;
		double expected_ = 0.4175631735867292;
        assertEquals(2, expected_, solution.cycleRange(R));
    }

    void testCase3() {
		double R = 3.55;
		double expected_ = 0.5325704489850351;
        assertEquals(3, expected_, solution.cycleRange(R));
    }

    void testCase4() {
		double R = 3.565;
		double expected_ = 0.5454276003030636;
        assertEquals(4, expected_, solution.cycleRange(R));
    }

    void testCase5() {
		double R = 3.5689;
		double expected_ = 0.5489996297493569;
        assertEquals(5, expected_, solution.cycleRange(R));
    }

    void testCase6() {
		double R = 3.00005;
		double expected_ = 0.004713996108955176;
        assertEquals(6, expected_, solution.cycleRange(R));
    }

    public: void runTest(int testCase) {
        switch (testCase) {
            case (0): testCase0(); break;
            case (1): testCase1(); break;
            case (2): testCase2(); break;
            case (3): testCase3(); break;
            case (4): testCase4(); break;
            case (5): testCase5(); break;
            case (6): testCase6(); break;
            default: cerr << "No such test case: " << testCase << endl; break;
        }
    }

};

int main() {
    for (int i = 0; i < 7; i++) {
        FixedPointTheoremTest test;
        test.runTest(i);
    }
}
