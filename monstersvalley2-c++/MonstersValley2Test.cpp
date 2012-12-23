#include "MonstersValley2.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class MonstersValley2Test {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    MonstersValley2 solution;

    void testCase0() {
        int dread_[] = {8, 5, 10};
        vector<int> dread(dread_, dread_ + (sizeof(dread_) / sizeof(dread_[0])));
        int price_[] = {1, 1, 2};
        vector<int> price(price_, price_ + (sizeof(price_) / sizeof(price_[0])));
		int expected_ = 2;
        assertEquals(0, expected_, solution.minimumPrice(dread, price));
    }

    void testCase1() {
        int dread_[] = {1, 2, 4, 1000000000};
        vector<int> dread(dread_, dread_ + (sizeof(dread_) / sizeof(dread_[0])));
        int price_[] = {1, 1, 1, 2};
        vector<int> price(price_, price_ + (sizeof(price_) / sizeof(price_[0])));
		int expected_ = 5;
        assertEquals(1, expected_, solution.minimumPrice(dread, price));
    }

    void testCase2() {
        int dread_[] = {200, 107, 105, 206, 307, 400};
        vector<int> dread(dread_, dread_ + (sizeof(dread_) / sizeof(dread_[0])));
        int price_[] = {1, 2, 1, 1, 1, 2};
        vector<int> price(price_, price_ + (sizeof(price_) / sizeof(price_[0])));
		int expected_ = 2;
        assertEquals(2, expected_, solution.minimumPrice(dread, price));
    }

    void testCase3() {
        int dread_[] = {5216, 12512, 613, 1256, 66, 17202, 30000, 23512, 2125, 33333};
        vector<int> dread(dread_, dread_ + (sizeof(dread_) / sizeof(dread_[0])));
        int price_[] = {2, 2, 1, 1, 1, 1, 2, 1, 2, 1};
        vector<int> price(price_, price_ + (sizeof(price_) / sizeof(price_[0])));
		int expected_ = 5;
        assertEquals(3, expected_, solution.minimumPrice(dread, price));
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
        MonstersValley2Test test;
        test.runTest(i);
    }
}
