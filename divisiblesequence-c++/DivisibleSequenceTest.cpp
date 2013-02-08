#include "DivisibleSequence.h"
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

class DivisibleSequenceTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    DivisibleSequence solution;

    void testCase0() {
		int N = 5;
		int H = 3;
		int expected_ = 3;
        assertEquals(0, expected_, solution.count(N, H));
    }

    void testCase1() {
		int N = 6;
		int H = 3;
		int expected_ = 9;
        assertEquals(1, expected_, solution.count(N, H));
    }

    void testCase2() {
		int N = 10;
		int H = 2;
		int expected_ = 4;
        assertEquals(2, expected_, solution.count(N, H));
    }

    void testCase3() {
		int N = 1;
		int H = 10000;
		int expected_ = 1;
        assertEquals(3, expected_, solution.count(N, H));
    }

    void testCase4() {
		int N = 30;
		int H = 4;
		int expected_ = 64;
        assertEquals(4, expected_, solution.count(N, H));
    }

    void testCase5() {
		int N = 25883;
		int H = 100000;
		int expected_ = 991000009;
        assertEquals(5, expected_, solution.count(N, H));
    }
    void testCase6() {
		int N = 128;
		int H = 5;
		int expected_ = 330;
        assertEquals(6, expected_, solution.count(N, H));
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
        DivisibleSequenceTest test;
        test.runTest(i);
    }
}
