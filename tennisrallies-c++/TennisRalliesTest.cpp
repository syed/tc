#include "TennisRallies.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class TennisRalliesTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    TennisRallies solution;

    void testCase0() {
		int numLength = 3;
        string forbidden_[] = {"cc", "dd"};
        vector<string> forbidden(forbidden_, forbidden_ + (sizeof(forbidden_) / sizeof(forbidden_[0])));
		int allowed = 1;
		int expected_ = 2;
        assertEquals(0, expected_, solution.howMany(numLength, forbidden, allowed));
    }

    void testCase1() {
		int numLength = 10;
        string forbidden_[] = {"c"};
        vector<string> forbidden(forbidden_, forbidden_ + (sizeof(forbidden_) / sizeof(forbidden_[0])));
		int allowed = 1;
		int expected_ = 1;
        assertEquals(1, expected_, solution.howMany(numLength, forbidden, allowed));
    }

    void testCase2() {
		int numLength = 10;
        string forbidden_[] = {"c"};
        vector<string> forbidden(forbidden_, forbidden_ + (sizeof(forbidden_) / sizeof(forbidden_[0])));
		int allowed = 2;
		int expected_ = 11;
        assertEquals(2, expected_, solution.howMany(numLength, forbidden, allowed));
    }

    void testCase3() {
		int numLength = 18;
        string forbidden_[] = {"c", "d"};
        vector<string> forbidden(forbidden_, forbidden_ + (sizeof(forbidden_) / sizeof(forbidden_[0])));
		int allowed = 1;
		int expected_ = 0;
        assertEquals(3, expected_, solution.howMany(numLength, forbidden, allowed));
    }

    void testCase4() {
		int numLength = 18;
        vector<string> forbidden;
		int allowed = 1;
		int expected_ = 262144;
        assertEquals(4, expected_, solution.howMany(numLength, forbidden, allowed));
    }

    void testCase5() {
		int numLength = 18;
        string forbidden_[] = {"c", "cc", "ccc", "cccc", "ccccc", "cccccc", "ccccccc", "cccccccc", "ccccccccc", "cccccccccc"};
        vector<string> forbidden(forbidden_, forbidden_ + (sizeof(forbidden_) / sizeof(forbidden_[0])));
		int allowed = 100;
		int expected_ = 262122;
        assertEquals(5, expected_, solution.howMany(numLength, forbidden, allowed));
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
        TennisRalliesTest test;
        test.runTest(i);
    }
}
