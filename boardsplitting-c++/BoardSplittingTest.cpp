#include "BoardSplitting.h"
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

class BoardSplittingTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    BoardSplitting solution;

    void testCase0() {
		int desiredLength = 5;
		int desiredCount = 4;
		int actualLength = 4;
		int expected_ = 3;
        assertEquals(0, expected_, solution.minimumCuts(desiredLength, desiredCount, actualLength));
    }

    void testCase1() {
		int desiredLength = 6;
		int desiredCount = 100;
		int actualLength = 3;
		int expected_ = 0;
        assertEquals(1, expected_, solution.minimumCuts(desiredLength, desiredCount, actualLength));
    }

    void testCase2() {
		int desiredLength = 500;
		int desiredCount = 5;
		int actualLength = 1000;
		int expected_ = 3;
        assertEquals(2, expected_, solution.minimumCuts(desiredLength, desiredCount, actualLength));
    }

    void testCase3() {
		int desiredLength = 314;
		int desiredCount = 159;
		int actualLength = 26;
		int expected_ = 147;
        assertEquals(3, expected_, solution.minimumCuts(desiredLength, desiredCount, actualLength));
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
        BoardSplittingTest test;
        test.runTest(i);
    }
}
