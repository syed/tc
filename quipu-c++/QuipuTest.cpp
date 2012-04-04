#include "Quipu.h"
#include <iostream>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::string;

class QuipuTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    Quipu solution;

    void testCase0() {
		string knots = "-XX-XXXX-XXX-";
		int expected_ = 243;
        assertEquals(0, expected_, solution.readKnots(knots));
    }

    void testCase1() {
		string knots = "-XX--XXXX---XXX-";
		int expected_ = 204003;
        assertEquals(1, expected_, solution.readKnots(knots));
    }

    void testCase2() {
		string knots = "-X-";
		int expected_ = 1;
        assertEquals(2, expected_, solution.readKnots(knots));
    }

    void testCase3() {
		string knots = "-X-------";
		int expected_ = 1000000;
        assertEquals(3, expected_, solution.readKnots(knots));
    }

    void testCase4() {
		string knots = "-XXXXXXXXX--XXXXXXXXX-XXXXXXXXX-XXXXXXX-XXXXXXXXX-";
		int expected_ = 909979;
        assertEquals(4, expected_, solution.readKnots(knots));
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
        QuipuTest test;
        test.runTest(i);
    }
}
