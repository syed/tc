#include "LevelUp.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class LevelUpTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    LevelUp solution;

    void testCase0() {
        int expNeeded_[] = {150, 450, 900, 1800};
        vector<int> expNeeded(expNeeded_, expNeeded_ + (sizeof(expNeeded_) / sizeof(expNeeded_[0])));
		int received = 133;
		int expected_ = 17;
        assertEquals(0, expected_, solution.toNextLevel(expNeeded, received));
    }

    void testCase1() {
        int expNeeded_[] = {150, 450, 900, 1800};
        vector<int> expNeeded(expNeeded_, expNeeded_ + (sizeof(expNeeded_) / sizeof(expNeeded_[0])));
		int received = 312;
		int expected_ = 138;
        assertEquals(1, expected_, solution.toNextLevel(expNeeded, received));
    }

    void testCase2() {
        int expNeeded_[] = {150, 450, 900, 1800};
        vector<int> expNeeded(expNeeded_, expNeeded_ + (sizeof(expNeeded_) / sizeof(expNeeded_[0])));
		int received = 612;
		int expected_ = 288;
        assertEquals(2, expected_, solution.toNextLevel(expNeeded, received));
    }

    void testCase3() {
        int expNeeded_[] = {150, 450, 900, 1800};
        vector<int> expNeeded(expNeeded_, expNeeded_ + (sizeof(expNeeded_) / sizeof(expNeeded_[0])));
		int received = 450;
		int expected_ = 450;
        assertEquals(3, expected_, solution.toNextLevel(expNeeded, received));
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
        LevelUpTest test;
        test.runTest(i);
    }
}
