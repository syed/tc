#include "BlackAndWhiteSolitaire.h"
#include <iostream>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::string;

class BlackAndWhiteSolitaireTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    BlackAndWhiteSolitaire solution;

    void testCase0() {
		string cardFront = "BBBW";
		int expected_ = 1;
        assertEquals(0, expected_, solution.minimumTurns(cardFront));
    }

    void testCase1() {
		string cardFront = "WBWBW";
		int expected_ = 0;
        assertEquals(1, expected_, solution.minimumTurns(cardFront));
    }

    void testCase2() {
		string cardFront = "WWWWWWWWW";
		int expected_ = 4;
        assertEquals(2, expected_, solution.minimumTurns(cardFront));
    }

    void testCase3() {
		string cardFront = "BBWBWWBWBWWBBBWBWBWBBWBBW";
		int expected_ = 10;
        assertEquals(3, expected_, solution.minimumTurns(cardFront));
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
        BlackAndWhiteSolitaireTest test;
        test.runTest(i);
    }
}
