#include "BadClock.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::string;

class BadClockTest {

    static void assertEquals(int testCase, double expected, double actual) {
        double delta = max(1e-9, 1e-9 * abs(expected));
        if (abs(expected - actual) <= delta) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout.precision(24);
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    BadClock solution;

    void testCase0() {
		string trueTime = "07:07:07";
		string skewTime = "07:07:07";
		int hourlyGain = 1776;
		double expected_ = 0.0;
        assertEquals(0, expected_, solution.nextAgreement(trueTime, skewTime, hourlyGain));
    }

    void testCase1() {
		string trueTime = "11:59:58";
		string skewTime = "12:03:28";
		int hourlyGain = -3;
		double expected_ = 70.0;
        assertEquals(1, expected_, solution.nextAgreement(trueTime, skewTime, hourlyGain));
    }

    void testCase2() {
		string trueTime = "12:03:28";
		string skewTime = "11:59:58";
		int hourlyGain = 3;
		double expected_ = 70.0;
        assertEquals(2, expected_, solution.nextAgreement(trueTime, skewTime, hourlyGain));
    }

    void testCase3() {
		string trueTime = "03:03:02";
		string skewTime = "03:01:47";
		int hourlyGain = 5;
		double expected_ = 15.0;
        assertEquals(3, expected_, solution.nextAgreement(trueTime, skewTime, hourlyGain));
    }

    void testCase4() {
		string trueTime = "03:03:02";
		string skewTime = "03:01:47";
		int hourlyGain = -5;
		double expected_ = 8625.0;
        assertEquals(4, expected_, solution.nextAgreement(trueTime, skewTime, hourlyGain));
    }

    void testCase5() {
		string trueTime = "07:08:09";
		string skewTime = "09:08:07";
		int hourlyGain = -321;
		double expected_ = 22.42367601246106;
        assertEquals(5, expected_, solution.nextAgreement(trueTime, skewTime, hourlyGain));
    }

    public: void runTest(int testCase) {
        switch (testCase) {
            case (0): testCase0(); break;
            case (1): testCase1(); break;
            case (2): testCase2(); break;
            case (3): testCase3(); break;
            case (4): testCase4(); break;
            case (5): testCase5(); break;
            default: cerr << "No such test case: " << testCase << endl; break;
        }
    }

};

int main() {
    for (int i = 0; i < 6; i++) {
        BadClockTest test;
        test.runTest(i);
    }
}
