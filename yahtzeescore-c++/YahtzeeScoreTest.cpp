#include "YahtzeeScore.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class YahtzeeScoreTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    YahtzeeScore solution;

    void testCase0() {
        int toss_[] = {2, 2, 3, 5, 4};
        vector<int> toss(toss_, toss_ + (sizeof(toss_) / sizeof(toss_[0])));
		int expected_ = 5;
        assertEquals(0, expected_, solution.maxPoints(toss));
    }

    void testCase1() {
        int toss_[] = {6, 4, 1, 1, 3};
        vector<int> toss(toss_, toss_ + (sizeof(toss_) / sizeof(toss_[0])));
		int expected_ = 6;
        assertEquals(1, expected_, solution.maxPoints(toss));
    }

    void testCase2() {
        int toss_[] = {5, 3, 5, 3, 3};
        vector<int> toss(toss_, toss_ + (sizeof(toss_) / sizeof(toss_[0])));
		int expected_ = 10;
        assertEquals(2, expected_, solution.maxPoints(toss));
    }

    public: void runTest(int testCase) {
        switch (testCase) {
            case (0): testCase0(); break;
            case (1): testCase1(); break;
            case (2): testCase2(); break;
            default: cerr << "No such test case: " << testCase << endl; break;
        }
    }

};

int main() {
    for (int i = 0; i < 3; i++) {
        YahtzeeScoreTest test;
        test.runTest(i);
    }
}
