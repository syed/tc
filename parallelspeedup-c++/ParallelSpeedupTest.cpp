#include "ParallelSpeedup.h"
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

class ParallelSpeedupTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    ParallelSpeedup solution;

    void testCase0() {
		int k = 12;
		int overhead = 1;
		int expected_ = 2;
        assertEquals(0, expected_, solution.numProcessors(k, overhead));
    }

    void testCase1() {
		int k = 50;
		int overhead = 3;
		int expected_ = 3;
        assertEquals(1, expected_, solution.numProcessors(k, overhead));
    }

    void testCase2() {
		int k = 9;
		int overhead = 10;
		int expected_ = 1;
        assertEquals(2, expected_, solution.numProcessors(k, overhead));
    }

    void testCase3() {
		int k = 3333;
		int overhead = 2;
		int expected_ = 12;
        assertEquals(3, expected_, solution.numProcessors(k, overhead));
    }

    void testCase4() {
		int k = 1000000;
		int overhead = 4;
		int expected_ = 63;
        assertEquals(4, expected_, solution.numProcessors(k, overhead));
    }

    void testCase5() {
		int k = 1000000;//{1000000, 2}
		int overhead = 2;
		int expected_ = 80;
        assertEquals(5, expected_, solution.numProcessors(k, overhead));
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
        ParallelSpeedupTest test;
        test.runTest(i);
    }
}
