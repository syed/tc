#include "DivisorDigits.h"
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

class DivisorDigitsTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    DivisorDigits solution;

    void testCase0() {
		int number = 12345;
		int expected_ = 3;
        assertEquals(0, expected_, solution.howMany(number));
    }

    void testCase1() {
		int number = 661232;
		int expected_ = 3;
        assertEquals(1, expected_, solution.howMany(number));
    }

    void testCase2() {
		int number = 52527;
		int expected_ = 0;
        assertEquals(2, expected_, solution.howMany(number));
    }

    void testCase3() {
		int number = 730000000;
		int expected_ = 0;
        assertEquals(3, expected_, solution.howMany(number));
    }
    void testCase4() {
		int number = 1000;
		int expected_ = 1;
        assertEquals(3, expected_, solution.howMany(number));
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
        DivisorDigitsTest test;
        test.runTest(i);
    }
}
