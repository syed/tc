#include "ClockWalk.h"
#include <iostream>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::string;

class ClockWalkTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    ClockWalk solution;

    void testCase0() {
		string flips = "hhthh";
		int expected_ = 9;
        assertEquals(0, expected_, solution.finalPosition(flips));
    }

    void testCase1() {
		string flips = "hhtht";
		int expected_ = 11;
        assertEquals(1, expected_, solution.finalPosition(flips));
    }

    void testCase2() {
		string flips = "hthth";
		int expected_ = 3;
        assertEquals(2, expected_, solution.finalPosition(flips));
    }

    void testCase3() {
		string flips = "hthhhhh";
		int expected_ = 12;
        assertEquals(3, expected_, solution.finalPosition(flips));
    }

    void testCase4() {
		string flips = "hthhthtththhtttthttthhhthtttthh";
		int expected_ = 6;
        assertEquals(4, expected_, solution.finalPosition(flips));
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
        ClockWalkTest test;
        test.runTest(i);
    }
}
