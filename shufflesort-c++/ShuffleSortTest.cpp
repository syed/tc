#include "ShuffleSort.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class ShuffleSortTest {

    static void assertEquals(int testCase, double expected, double actual) {
        double delta = max(1e-9, 1e-9 * abs(expected));
        if (abs(expected - actual) <= delta) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout.precision(24);
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    ShuffleSort solution;

    void testCase0() {
        int cards_[] = {1};
        vector<int> cards(cards_, cards_ + (sizeof(cards_) / sizeof(cards_[0])));
		double expected_ = 1.0;
        assertEquals(0, expected_, solution.shuffle(cards));
    }

    void testCase1() {
        int cards_[] = {1, 2};
        vector<int> cards(cards_, cards_ + (sizeof(cards_) / sizeof(cards_[0])));
		double expected_ = 2.0;
        assertEquals(1, expected_, solution.shuffle(cards));
    }

    void testCase2() {
        int cards_[] = {2, 3, 1};
        vector<int> cards(cards_, cards_ + (sizeof(cards_) / sizeof(cards_[0])));
		double expected_ = 4.0;
        assertEquals(2, expected_, solution.shuffle(cards));
    }

    void testCase3() {
        int cards_[] = {15, 16, 4, 8, 42, 23};
        vector<int> cards(cards_, cards_ + (sizeof(cards_) / sizeof(cards_[0])));
		double expected_ = 16.0;
        assertEquals(3, expected_, solution.shuffle(cards));
    }

    void testCase4() {
        int cards_[] = {1, 1, 1, 1, 1, 1, 1, 1};
        vector<int> cards(cards_, cards_ + (sizeof(cards_) / sizeof(cards_[0])));
		double expected_ = 1.0;
        assertEquals(4, expected_, solution.shuffle(cards));
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
        ShuffleSortTest test;
        test.runTest(i);
    }
}
