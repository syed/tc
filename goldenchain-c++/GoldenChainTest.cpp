#include "GoldenChain.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class GoldenChainTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    GoldenChain solution;

    void testCase0() {
        int sections_[] = {3, 3, 3, 3};
        vector<int> sections(sections_, sections_ + (sizeof(sections_) / sizeof(sections_[0])));
		int expected_ = 3;
        assertEquals(0, expected_, solution.minCuts(sections));
    }

    void testCase1() {
        int sections_[] = {2000000000};
        vector<int> sections(sections_, sections_ + (sizeof(sections_) / sizeof(sections_[0])));
		int expected_ = 1;
        assertEquals(1, expected_, solution.minCuts(sections));
    }

    void testCase2() {
        int sections_[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50};
        vector<int> sections(sections_, sections_ + (sizeof(sections_) / sizeof(sections_[0])));
		int expected_ = 42;
        assertEquals(2, expected_, solution.minCuts(sections));
    }

    void testCase3() {
        int sections_[] = {20000000, 20000000, 2000000000};
        vector<int> sections(sections_, sections_ + (sizeof(sections_) / sizeof(sections_[0])));
		int expected_ = 3;
        assertEquals(3, expected_, solution.minCuts(sections));
    }

    void testCase4() {
        int sections_[] = {10, 10, 10, 10, 10, 1, 1, 1, 1, 1};
        vector<int> sections(sections_, sections_ + (sizeof(sections_) / sizeof(sections_[0])));
		int expected_ = 5;
        assertEquals(4, expected_, solution.minCuts(sections));
    }

    void testCase5() {
        int sections_[] = {1, 10};
        vector<int> sections(sections_, sections_ + (sizeof(sections_) / sizeof(sections_[0])));
		int expected_ = 1;
        assertEquals(5, expected_, solution.minCuts(sections));
    }
    void testCase6() {
        int sections_[] = {3,3,3};
        vector<int> sections(sections_, sections_ + (sizeof(sections_) / sizeof(sections_[0])));
		int expected_ = 3;
        assertEquals(6, expected_, solution.minCuts(sections));
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
        GoldenChainTest test;
        test.runTest(i);
    }
}
