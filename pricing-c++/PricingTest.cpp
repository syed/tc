#include "Pricing.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class PricingTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    Pricing solution;

    void testCase0() {
        int price_[] = {9, 1, 5, 5, 5, 5, 4, 8, 80};
        vector<int> price(price_, price_ + (sizeof(price_) / sizeof(price_[0])));
		int expected_ = 120;
        assertEquals(0, expected_, solution.maxSales(price));
    }

    void testCase1() {
        int price_[] = {17, 50, 2};
        vector<int> price(price_, price_ + (sizeof(price_) / sizeof(price_[0])));
		int expected_ = 69;
        assertEquals(1, expected_, solution.maxSales(price));
    }

    void testCase2() {
        int price_[] = {130, 110, 90, 13, 6, 5, 4, 3, 0};
        vector<int> price(price_, price_ + (sizeof(price_) / sizeof(price_[0])));
		int expected_ = 346;
        assertEquals(2, expected_, solution.maxSales(price));
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
        PricingTest test;
        test.runTest(i);
    }
}
