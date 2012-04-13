#include "RandomColoringDiv2.h"
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

class RandomColoringDiv2Test {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    RandomColoringDiv2 solution;

    void testCase0() {
		int maxR = 5;
		int maxG = 1;
		int maxB = 1;
		int startR = 2;
		int startG = 0;
		int startB = 0;
		int d1 = 0;
		int d2 = 1;
		int expected_ = 3;
        assertEquals(0, expected_, solution.getCount(maxR, maxG, maxB, startR, startG, startB, d1, d2));
    }

    void testCase1() {
		int maxR = 4;
		int maxG = 2;
		int maxB = 2;
		int startR = 0;
		int startG = 0;
		int startB = 0;
		int d1 = 3;
		int d2 = 3;
		int expected_ = 4;
        assertEquals(1, expected_, solution.getCount(maxR, maxG, maxB, startR, startG, startB, d1, d2));
    }

    void testCase2() {
		int maxR = 4;
		int maxG = 2;
		int maxB = 2;
		int startR = 0;
		int startG = 0;
		int startB = 0;
		int d1 = 5;
		int d2 = 5;
		int expected_ = 0;
        assertEquals(2, expected_, solution.getCount(maxR, maxG, maxB, startR, startG, startB, d1, d2));
    }

    void testCase3() {
		int maxR = 6;
		int maxG = 9;
		int maxB = 10;
		int startR = 1;
		int startG = 2;
		int startB = 3;
		int d1 = 0;
		int d2 = 10;
		int expected_ = 540;
        assertEquals(3, expected_, solution.getCount(maxR, maxG, maxB, startR, startG, startB, d1, d2));
    }

    void testCase4() {
		int maxR = 6;
		int maxG = 9;
		int maxB = 10;
		int startR = 1;
		int startG = 2;
		int startB = 3;
		int d1 = 4;
		int d2 = 10;
		int expected_ = 330;
        assertEquals(4, expected_, solution.getCount(maxR, maxG, maxB, startR, startG, startB, d1, d2));
    }

    void testCase5() {
		int maxR = 49;
		int maxG = 59;
		int maxB = 53;
		int startR = 12;
		int startG = 23;
		int startB = 13;
		int d1 = 11;
		int d2 = 22;
		int expected_ = 47439;
        assertEquals(5, expected_, solution.getCount(maxR, maxG, maxB, startR, startG, startB, d1, d2));
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
        RandomColoringDiv2Test test;
        test.runTest(i);
    }
}
