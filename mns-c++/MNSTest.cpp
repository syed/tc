#include "MNS.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class MNSTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    MNS solution;

    void testCase0() {
        int numbers_[] = {1, 2, 3, 3, 2, 1, 2, 2, 2};
        vector<int> numbers(numbers_, numbers_ + (sizeof(numbers_) / sizeof(numbers_[0])));
		int expected_ = 18;
        assertEquals(0, expected_, solution.combos(numbers));
    }

    void testCase1() {
        int numbers_[] = {4, 4, 4, 4, 4, 4, 4, 4, 4};
        vector<int> numbers(numbers_, numbers_ + (sizeof(numbers_) / sizeof(numbers_[0])));
		int expected_ = 1;
        assertEquals(1, expected_, solution.combos(numbers));
    }

    void testCase2() {
        int numbers_[] = {1, 5, 1, 2, 5, 6, 2, 3, 2};
        vector<int> numbers(numbers_, numbers_ + (sizeof(numbers_) / sizeof(numbers_[0])));
		int expected_ = 36;
        assertEquals(2, expected_, solution.combos(numbers));
    }

    void testCase3() {
        int numbers_[] = {1, 2, 6, 6, 6, 4, 2, 6, 4};
        vector<int> numbers(numbers_, numbers_ + (sizeof(numbers_) / sizeof(numbers_[0])));
		int expected_ = 0;
        assertEquals(3, expected_, solution.combos(numbers));
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
        MNSTest test;
        test.runTest(i);
    }
}
