#include "PowerOutage.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class PowerOutageTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    PowerOutage solution;

    void testCase0() {
        int fromJunction_[] = {0};
        vector<int> fromJunction(fromJunction_, fromJunction_ + (sizeof(fromJunction_) / sizeof(fromJunction_[0])));
        int toJunction_[] = {1};
        vector<int> toJunction(toJunction_, toJunction_ + (sizeof(toJunction_) / sizeof(toJunction_[0])));
        int ductLength_[] = {10};
        vector<int> ductLength(ductLength_, ductLength_ + (sizeof(ductLength_) / sizeof(ductLength_[0])));
		int expected_ = 10;
        assertEquals(0, expected_, solution.estimateTimeOut(fromJunction, toJunction, ductLength));
    }

    void testCase1() {
        int fromJunction_[] = {0, 1, 0};
        vector<int> fromJunction(fromJunction_, fromJunction_ + (sizeof(fromJunction_) / sizeof(fromJunction_[0])));
        int toJunction_[] = {1, 2, 3};
        vector<int> toJunction(toJunction_, toJunction_ + (sizeof(toJunction_) / sizeof(toJunction_[0])));
        int ductLength_[] = {10, 10, 10};
        vector<int> ductLength(ductLength_, ductLength_ + (sizeof(ductLength_) / sizeof(ductLength_[0])));
		int expected_ = 40;
        assertEquals(1, expected_, solution.estimateTimeOut(fromJunction, toJunction, ductLength));
    }

    void testCase2() {
        int fromJunction_[] = {0, 0, 0, 1, 4};
        vector<int> fromJunction(fromJunction_, fromJunction_ + (sizeof(fromJunction_) / sizeof(fromJunction_[0])));
        int toJunction_[] = {1, 3, 4, 2, 5};
        vector<int> toJunction(toJunction_, toJunction_ + (sizeof(toJunction_) / sizeof(toJunction_[0])));
        int ductLength_[] = {10, 10, 100, 10, 5};
        vector<int> ductLength(ductLength_, ductLength_ + (sizeof(ductLength_) / sizeof(ductLength_[0])));
		int expected_ = 165;
        assertEquals(2, expected_, solution.estimateTimeOut(fromJunction, toJunction, ductLength));
    }

    void testCase3() {
        int fromJunction_[] = {0, 0, 0, 1, 4, 4, 6, 7, 7, 7, 20};
        vector<int> fromJunction(fromJunction_, fromJunction_ + (sizeof(fromJunction_) / sizeof(fromJunction_[0])));
        int toJunction_[] = {1, 3, 4, 2, 5, 6, 7, 20, 9, 10, 31};
        vector<int> toJunction(toJunction_, toJunction_ + (sizeof(toJunction_) / sizeof(toJunction_[0])));
        int ductLength_[] = {10, 10, 100, 10, 5, 1, 1, 100, 1, 1, 5};
        vector<int> ductLength(ductLength_, ductLength_ + (sizeof(ductLength_) / sizeof(ductLength_[0])));
		int expected_ = 281;
        assertEquals(3, expected_, solution.estimateTimeOut(fromJunction, toJunction, ductLength));
    }

    void testCase4() {
        int fromJunction_[] = {0, 0, 0, 0, 0};
        vector<int> fromJunction(fromJunction_, fromJunction_ + (sizeof(fromJunction_) / sizeof(fromJunction_[0])));
        int toJunction_[] = {1, 2, 3, 4, 5};
        vector<int> toJunction(toJunction_, toJunction_ + (sizeof(toJunction_) / sizeof(toJunction_[0])));
        int ductLength_[] = {100, 200, 300, 400, 500};
        vector<int> ductLength(ductLength_, ductLength_ + (sizeof(ductLength_) / sizeof(ductLength_[0])));
		int expected_ = 2500;
        assertEquals(4, expected_, solution.estimateTimeOut(fromJunction, toJunction, ductLength));
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
        PowerOutageTest test;
        test.runTest(i);
    }
}
