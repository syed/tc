#include "BridgeCrossing.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class BridgeCrossingTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    BridgeCrossing solution;

    void testCase0() {
        int times_[] = {1, 2, 5, 10};
        vector<int> times(times_, times_ + (sizeof(times_) / sizeof(times_[0])));
		int expected_ = 17;
        assertEquals(0, expected_, solution.minTime(times));
    }

    void testCase1() {
        int times_[] = {1, 2, 3, 4, 5};
        vector<int> times(times_, times_ + (sizeof(times_) / sizeof(times_[0])));
		int expected_ = 16;
        assertEquals(1, expected_, solution.minTime(times));
    }

    void testCase2() {
        int times_[] = {100};
        vector<int> times(times_, times_ + (sizeof(times_) / sizeof(times_[0])));
		int expected_ = 100;
        assertEquals(2, expected_, solution.minTime(times));
    }

    void testCase3() {
        int times_[] = {1, 2, 3, 50, 99, 100};
        vector<int> times(times_, times_ + (sizeof(times_) / sizeof(times_[0])));
		int expected_ = 162;
        assertEquals(3, expected_, solution.minTime(times));
    }
    void testCase4() {
        int times_[] =  { 99, 13, 67, 32, 5, 17};
        vector<int> times(times_, times_ + (sizeof(times_) / sizeof(times_[0])));
		int expected_ = 202;
        assertEquals(4, expected_, solution.minTime(times));
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
        BridgeCrossingTest test;
        test.runTest(i);
    }
}
