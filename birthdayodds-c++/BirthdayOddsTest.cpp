#include "BirthdayOdds.h"
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

class BirthdayOddsTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    BirthdayOdds solution;

    void testCase0() {
		int minOdds = 75;
		int daysInYear = 5;
		int expected_ = 4;
        assertEquals(0, expected_, solution.minPeople(minOdds, daysInYear));
    }

    void testCase1() {
		int minOdds = 50;
		int daysInYear = 365;
		int expected_ = 23;
        assertEquals(1, expected_, solution.minPeople(minOdds, daysInYear));
    }

    void testCase2() {
		int minOdds = 1;
		int daysInYear = 365;
		int expected_ = 4;
        assertEquals(2, expected_, solution.minPeople(minOdds, daysInYear));
    }

    void testCase3() {
		int minOdds = 84;
		int daysInYear = 9227;
		int expected_ = 184;
        assertEquals(3, expected_, solution.minPeople(minOdds, daysInYear));
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
        BirthdayOddsTest test;
        test.runTest(i);
    }
}
