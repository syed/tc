#include "Inventory.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class InventoryTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    Inventory solution;

    void testCase0() {
        int sales_[] = {5};
        vector<int> sales(sales_, sales_ + (sizeof(sales_) / sizeof(sales_[0])));
        int daysAvailable_[] = {15};
        vector<int> daysAvailable(daysAvailable_, daysAvailable_ + (sizeof(daysAvailable_) / sizeof(daysAvailable_[0])));
		int expected_ = 10;
        assertEquals(0, expected_, solution.monthlyOrder(sales, daysAvailable));
    }

    void testCase1() {
        int sales_[] = {75, 120, 0, 93};
        vector<int> sales(sales_, sales_ + (sizeof(sales_) / sizeof(sales_[0])));
        int daysAvailable_[] = {24, 30, 0, 30};
        vector<int> daysAvailable(daysAvailable_, daysAvailable_ + (sizeof(daysAvailable_) / sizeof(daysAvailable_[0])));
		int expected_ = 103;
        assertEquals(1, expected_, solution.monthlyOrder(sales, daysAvailable));
    }

    void testCase2() {
        int sales_[] = {8773};
        vector<int> sales(sales_, sales_ + (sizeof(sales_) / sizeof(sales_[0])));
        int daysAvailable_[] = {16};
        vector<int> daysAvailable(daysAvailable_, daysAvailable_ + (sizeof(daysAvailable_) / sizeof(daysAvailable_[0])));
		int expected_ = 16450;
        assertEquals(2, expected_, solution.monthlyOrder(sales, daysAvailable));
    }

    void testCase3() {
        int sales_[] = {1115, 7264, 3206, 6868, 7301};
        vector<int> sales(sales_, sales_ + (sizeof(sales_) / sizeof(sales_[0])));
        int daysAvailable_[] = {1, 3, 9, 4, 18};
        vector<int> daysAvailable(daysAvailable_, daysAvailable_ + (sizeof(daysAvailable_) / sizeof(daysAvailable_[0])));
		int expected_ = 36091;
        assertEquals(3, expected_, solution.monthlyOrder(sales, daysAvailable));
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
        InventoryTest test;
        test.runTest(i);
    }
}
