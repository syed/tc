#include "Inchworm.h"
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

class InchwormTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    Inchworm solution;

    void testCase0() {
		int branch = 11;
		int rest = 2;
		int leaf = 4;
		int expected_ = 3;
        assertEquals(0, expected_, solution.lunchtime(branch, rest, leaf));
    }

    void testCase1() {
		int branch = 12;
		int rest = 6;
		int leaf = 4;
		int expected_ = 2;
        assertEquals(1, expected_, solution.lunchtime(branch, rest, leaf));
    }

    void testCase2() {
		int branch = 20;
		int rest = 3;
		int leaf = 7;
		int expected_ = 1;
        assertEquals(2, expected_, solution.lunchtime(branch, rest, leaf));
    }

    void testCase3() {
		int branch = 21;
		int rest = 7;
		int leaf = 3;
		int expected_ = 2;
        assertEquals(3, expected_, solution.lunchtime(branch, rest, leaf));
    }

    void testCase4() {
		int branch = 15;
		int rest = 16;
		int leaf = 5;
		int expected_ = 1;
        assertEquals(4, expected_, solution.lunchtime(branch, rest, leaf));
    }

    void testCase5() {
		int branch = 1000;
		int rest = 3;
		int leaf = 7;
		int expected_ = 48;
        assertEquals(5, expected_, solution.lunchtime(branch, rest, leaf));
    }

    void testCase6() {
		int branch = 1000;
		int rest = 7;
		int leaf = 3;
		int expected_ = 48;
        assertEquals(6, expected_, solution.lunchtime(branch, rest, leaf));
    }

    public: void runTest(int testCase) {
        switch (testCase) {
            case (0): testCase0(); break;
            case (1): testCase1(); break;
            case (2): testCase2(); break;
            case (3): testCase3(); break;
            case (4): testCase4(); break;
            case (5): testCase5(); break;
            case (6): testCase6(); break;
            default: cerr << "No such test case: " << testCase << endl; break;
        }
    }

};

int main() {
    for (int i = 0; i < 7; i++) {
        InchwormTest test;
        test.runTest(i);
    }
}
