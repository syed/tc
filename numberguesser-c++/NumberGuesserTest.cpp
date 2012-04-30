#include "NumberGuesser.h"
#include <iostream>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::string;

class NumberGuesserTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    NumberGuesser solution;

    void testCase0() {
		string leftOver = "087";
		int expected_ = 3;
        assertEquals(0, expected_, solution.guess(leftOver));
    }

    void testCase1() {
		string leftOver = "099";
		int expected_ = 9;
        assertEquals(1, expected_, solution.guess(leftOver));
    }

    void testCase2() {
		string leftOver = "191";
		int expected_ = 7;
        assertEquals(2, expected_, solution.guess(leftOver));
    }

    void testCase3() {
		string leftOver = "689";
		int expected_ = 4;
        assertEquals(3, expected_, solution.guess(leftOver));
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
        NumberGuesserTest test;
        test.runTest(i);
    }
}
