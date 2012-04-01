#include "AimToTen.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class AimToTenTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    AimToTen solution;

    void testCase0() {
        int marks_[] = {9, 10, 10, 9};
        vector<int> marks(marks_, marks_ + (sizeof(marks_) / sizeof(marks_[0])));
		int expected_ = 0;
        assertEquals(0, expected_, solution.need(marks));
    }

    void testCase1() {
        int marks_[] = {8, 9};
        vector<int> marks(marks_, marks_ + (sizeof(marks_) / sizeof(marks_[0])));
		int expected_ = 4;
        assertEquals(1, expected_, solution.need(marks));
    }

    void testCase2() {
        int marks_[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        vector<int> marks(marks_, marks_ + (sizeof(marks_) / sizeof(marks_[0])));
		int expected_ = 950;
        assertEquals(2, expected_, solution.need(marks));
    }

    void testCase3() {
        int marks_[] = {10, 10, 10, 10};
        vector<int> marks(marks_, marks_ + (sizeof(marks_) / sizeof(marks_[0])));
		int expected_ = 0;
        assertEquals(3, expected_, solution.need(marks));
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
        AimToTenTest test;
        test.runTest(i);
    }
}
