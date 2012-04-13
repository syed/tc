#include "ImportantSequence.h"
#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class ImportantSequenceTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    ImportantSequence solution;

    void testCase0() {
        int B_[] = {3, -1, 7};
        vector<int> B(B_, B_ + (sizeof(B_) / sizeof(B_[0])));
		string operators = "+-+";
		int expected_ = 2;
        assertEquals(0, expected_, solution.getCount(B, operators));
    }

    void testCase1() {
        int B_[] = {1};
        vector<int> B(B_, B_ + (sizeof(B_) / sizeof(B_[0])));
		string operators = "-";
		int expected_ = -1;
        assertEquals(1, expected_, solution.getCount(B, operators));
    }

    void testCase2() {
        int B_[] = {1};
        vector<int> B(B_, B_ + (sizeof(B_) / sizeof(B_[0])));
		string operators = "+";
		int expected_ = 0;
        assertEquals(2, expected_, solution.getCount(B, operators));
    }

    void testCase3() {
        int B_[] = {10};
        vector<int> B(B_, B_ + (sizeof(B_) / sizeof(B_[0])));
		string operators = "+";
		int expected_ = 9;
        assertEquals(3, expected_, solution.getCount(B, operators));
    }

    void testCase4() {
        int B_[] = {540, 2012, 540, 2012, 540, 2012, 540};
        vector<int> B(B_, B_ + (sizeof(B_) / sizeof(B_[0])));
		string operators = "-+-+-+-";
		int expected_ = 1471;
        assertEquals(4, expected_, solution.getCount(B, operators));
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
        ImportantSequenceTest test;
        test.runTest(i);
    }
}
