#include "GuessTheNumber.h"
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

class GuessTheNumberTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    GuessTheNumber solution;

    void testCase0() {
		int upper = 9;
		int answer = 6;
		int expected_ = 3;
        assertEquals(0, expected_, solution.noGuesses(upper, answer));
    }

    void testCase1() {
		int upper = 1000;
		int answer = 750;
		int expected_ = 2;
        assertEquals(1, expected_, solution.noGuesses(upper, answer));
    }

    void testCase2() {
		int upper = 643;
		int answer = 327;
		int expected_ = 7;
        assertEquals(2, expected_, solution.noGuesses(upper, answer));
    }

    void testCase3() {
		int upper = 157;
		int answer = 157;
		int expected_ = 8;
        assertEquals(3, expected_, solution.noGuesses(upper, answer));
    }

    void testCase4() {
		int upper = 128;
		int answer = 64;
		int expected_ = 1;
        assertEquals(4, expected_, solution.noGuesses(upper, answer));
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
        GuessTheNumberTest test;
        test.runTest(i);
    }
}
