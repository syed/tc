#include "FormatAmt.h"
#include <iostream>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::string;

class FormatAmtTest {

    static void assertEquals(int testCase, const string& expected, const string& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << '"' << expected << '"' << "> but was: <" << '"' << actual << '"' << '>' << endl;
        }
    }

    FormatAmt solution;

    void testCase0() {
		int dollars = 123456;
		int cents = 0;
		string expected_ = "$123,456.00";
        assertEquals(0, expected_, solution.amount(dollars, cents));
    }

    void testCase1() {
		int dollars = 49734321;
		int cents = 9;
		string expected_ = "$49,734,321.09";
        assertEquals(1, expected_, solution.amount(dollars, cents));
    }

    void testCase2() {
		int dollars = 0;
		int cents = 99;
		string expected_ = "$0.99";
        assertEquals(2, expected_, solution.amount(dollars, cents));
    }

    void testCase3() {
		int dollars = 249;
		int cents = 30;
		string expected_ = "$249.30";
        assertEquals(3, expected_, solution.amount(dollars, cents));
    }

    void testCase4() {
		int dollars = 1000;
		int cents = 1;
		string expected_ = "$1,000.01";
        assertEquals(4, expected_, solution.amount(dollars, cents));
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
        FormatAmtTest test;
        test.runTest(i);
    }
}
