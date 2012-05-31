#include "BagOfHolding.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class BagOfHoldingTest {

    static void assertEquals(int testCase, double expected, double actual) {
        double delta = max(1e-9, 1e-9 * abs(expected));
        if (abs(expected - actual) <= delta) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout.precision(24);
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    BagOfHolding solution;

    void testCase0() {
        int sizes_[] = {1, 2, 3};
        vector<int> sizes(sizes_, sizes_ + (sizeof(sizes_) / sizeof(sizes_[0])));
		int item = 1;
		double expected_ = 0.5;
        assertEquals(0, expected_, solution.oddsReachable(sizes, item));
    }

    void testCase1() {
        int sizes_[] = {1, 2, 3};
        vector<int> sizes(sizes_, sizes_ + (sizeof(sizes_) / sizeof(sizes_[0])));
		int item = 2;
		double expected_ = 1.0;
        assertEquals(1, expected_, solution.oddsReachable(sizes, item));
    }

    void testCase2() {
        int sizes_[] = {1, 1, 2, 3};
        vector<int> sizes(sizes_, sizes_ + (sizeof(sizes_) / sizeof(sizes_[0])));
		int item = 2;
		double expected_ = 0.5;
        assertEquals(2, expected_, solution.oddsReachable(sizes, item));
    }

    void testCase3() {
        int sizes_[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        vector<int> sizes(sizes_, sizes_ + (sizeof(sizes_) / sizeof(sizes_[0])));
		int item = 4;
		double expected_ = 0.16666666666666666;
        assertEquals(3, expected_, solution.oddsReachable(sizes, item));
    }
//{, 3}

    void testCase4() {
        int sizes_[] = {1, 10, 100, 1000, 10000, 1, 10, 100, 1000, 10000};
        vector<int> sizes(sizes_, sizes_ + (sizeof(sizes_) / sizeof(sizes_[0])));
		int item = 3;
		double expected_ = 0.25;
        assertEquals(4, expected_, solution.oddsReachable(sizes, item));
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
        BagOfHoldingTest test;
        test.runTest(i);
    }
}
