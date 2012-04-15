#include "BigBurger.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class BigBurgerTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    BigBurger solution;

    void testCase0() {
        int arrival_[] = {3, 3, 9};
        vector<int> arrival(arrival_, arrival_ + (sizeof(arrival_) / sizeof(arrival_[0])));
        int service_[] = {2, 15, 14};
        vector<int> service(service_, service_ + (sizeof(service_) / sizeof(service_[0])));
		int expected_ = 11;
        assertEquals(0, expected_, solution.maxWait(arrival, service));
    }

    void testCase1() {
        int arrival_[] = {182};
        vector<int> arrival(arrival_, arrival_ + (sizeof(arrival_) / sizeof(arrival_[0])));
        int service_[] = {11};
        vector<int> service(service_, service_ + (sizeof(service_) / sizeof(service_[0])));
		int expected_ = 0;
        assertEquals(1, expected_, solution.maxWait(arrival, service));
    }

    void testCase2() {
        int arrival_[] = {2, 10, 11};
        vector<int> arrival(arrival_, arrival_ + (sizeof(arrival_) / sizeof(arrival_[0])));
        int service_[] = {3, 4, 3};
        vector<int> service(service_, service_ + (sizeof(service_) / sizeof(service_[0])));
		int expected_ = 3;
        assertEquals(2, expected_, solution.maxWait(arrival, service));
    }

    void testCase3() {
        int arrival_[] = {2, 10, 12};
        vector<int> arrival(arrival_, arrival_ + (sizeof(arrival_) / sizeof(arrival_[0])));
        int service_[] = {15, 1, 15};
        vector<int> service(service_, service_ + (sizeof(service_) / sizeof(service_[0])));
		int expected_ = 7;
        assertEquals(3, expected_, solution.maxWait(arrival, service));
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
        BigBurgerTest test;
        test.runTest(i);
    }
}
