#include "MergeSort.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class MergeSortTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    MergeSort solution;

    void testCase0() {
        int numbers_[] = {1, 2, 3, 4};
        vector<int> numbers(numbers_, numbers_ + (sizeof(numbers_) / sizeof(numbers_[0])));
		int expected_ = 4;
        assertEquals(0, expected_, solution.howManyComparisons(numbers));
    }

    void testCase1() {
        int numbers_[] = {2, 3, 2};
        vector<int> numbers(numbers_, numbers_ + (sizeof(numbers_) / sizeof(numbers_[0])));
		int expected_ = 2;
        assertEquals(1, expected_, solution.howManyComparisons(numbers));
    }

    void testCase2() {
        int numbers_[] = {-17};
        vector<int> numbers(numbers_, numbers_ + (sizeof(numbers_) / sizeof(numbers_[0])));
		int expected_ = 0;
        assertEquals(2, expected_, solution.howManyComparisons(numbers));
    }

    void testCase3() {
        vector<int> numbers;
		int expected_ = 0;
        assertEquals(3, expected_, solution.howManyComparisons(numbers));
    }

    void testCase4() {
        int numbers_[] = {-2000000000, 2000000000, 0, 0, 0, -2000000000, 2000000000, 0, 0, 0};
        vector<int> numbers(numbers_, numbers_ + (sizeof(numbers_) / sizeof(numbers_[0])));
		int expected_ = 19;
        assertEquals(4, expected_, solution.howManyComparisons(numbers));
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
        MergeSortTest test;
        test.runTest(i);
    }
}
