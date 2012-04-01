#include "WidgetRepairs.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class WidgetRepairsTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    WidgetRepairs solution;

    void testCase0() {
        int arrivals_[] = {10, 0, 0, 4, 20};
        vector<int> arrivals(arrivals_, arrivals_ + (sizeof(arrivals_) / sizeof(arrivals_[0])));
		int numPerDay = 8;
		int expected_ = 6;
        assertEquals(0, expected_, solution.days(arrivals, numPerDay));
    }

    void testCase1() {
        int arrivals_[] = {0, 0, 0};
        vector<int> arrivals(arrivals_, arrivals_ + (sizeof(arrivals_) / sizeof(arrivals_[0])));
		int numPerDay = 10;
		int expected_ = 0;
        assertEquals(1, expected_, solution.days(arrivals, numPerDay));
    }

    void testCase2() {
        int arrivals_[] = {100, 100};
        vector<int> arrivals(arrivals_, arrivals_ + (sizeof(arrivals_) / sizeof(arrivals_[0])));
		int numPerDay = 10;
		int expected_ = 20;
        assertEquals(2, expected_, solution.days(arrivals, numPerDay));
    }

    void testCase3() {
        int arrivals_[] = {27, 0, 0, 0, 0, 9};
        vector<int> arrivals(arrivals_, arrivals_ + (sizeof(arrivals_) / sizeof(arrivals_[0])));
		int numPerDay = 9;
		int expected_ = 4;
        assertEquals(3, expected_, solution.days(arrivals, numPerDay));
    }

    void testCase4() {
        int arrivals_[] = {6, 5, 4, 3, 2, 1, 0, 0, 1, 2, 3, 4, 5, 6};
        vector<int> arrivals(arrivals_, arrivals_ + (sizeof(arrivals_) / sizeof(arrivals_[0])));
		int numPerDay = 3;
		int expected_ = 15;
        assertEquals(4, expected_, solution.days(arrivals, numPerDay));
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
        WidgetRepairsTest test;
        test.runTest(i);
    }
}
