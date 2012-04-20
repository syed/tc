#include "BenfordsLaw.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class BenfordsLawTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    BenfordsLaw solution;

    void testCase0() {
        int transactions_[] = {5236, 7290, 200, 1907, 3336, 9182, 17, 4209, 8746, 7932, 6375, 909, 2189, 3977, 2389, 2500, 1239, 3448, 6380, 4812};
        vector<int> transactions(transactions_, transactions_ + (sizeof(transactions_) / sizeof(transactions_[0])));
		int threshold = 2;
		int expected_ = 1;
        assertEquals(0, expected_, solution.questionableDigit(transactions, threshold));
    }

    void testCase1() {
        int transactions_[] = {1, 10, 100, 2, 20, 200, 2000, 3, 30, 300};
        vector<int> transactions(transactions_, transactions_ + (sizeof(transactions_) / sizeof(transactions_[0])));
		int threshold = 2;
		int expected_ = 2;
        assertEquals(1, expected_, solution.questionableDigit(transactions, threshold));
    }

    void testCase2() {
        int transactions_[] = {9, 87, 765, 6543, 54321, 43219, 321987, 21987, 1987, 345, 234, 123};
        vector<int> transactions(transactions_, transactions_ + (sizeof(transactions_) / sizeof(transactions_[0])));
		int threshold = 2;
		int expected_ = -1;
        assertEquals(2, expected_, solution.questionableDigit(transactions, threshold));
    }

    void testCase3() {
        int transactions_[] = {1, 2, 3, 4, 5, 6, 7, 8, 7, 6, 5, 4, 3, 2, 1};
        vector<int> transactions(transactions_, transactions_ + (sizeof(transactions_) / sizeof(transactions_[0])));
		int threshold = 8;
		int expected_ = 9;
        assertEquals(3, expected_, solution.questionableDigit(transactions, threshold));
    }

    void testCase4() {
        int transactions_[] = {987, 234, 1234, 234873487, 876, 234562, 17, 7575734, 5555, 4210, 678234, 3999, 8123};
        vector<int> transactions(transactions_, transactions_ + (sizeof(transactions_) / sizeof(transactions_[0])));
		int threshold = 3;
		int expected_ = 8;
        assertEquals(4, expected_, solution.questionableDigit(transactions, threshold));
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
        BenfordsLawTest test;
        test.runTest(i);
    }
}
