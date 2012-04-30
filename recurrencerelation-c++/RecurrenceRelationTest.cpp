#include "RecurrenceRelation.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class RecurrenceRelationTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    RecurrenceRelation solution;

    void testCase0() {
        int coefficients_[] = {2, 1};
        vector<int> coefficients(coefficients_, coefficients_ + (sizeof(coefficients_) / sizeof(coefficients_[0])));
        int initial_[] = {9, 7};
        vector<int> initial(initial_, initial_ + (sizeof(initial_) / sizeof(initial_[0])));
		int N = 6;
		int expected_ = 5;
        assertEquals(0, expected_, solution.moduloTen(coefficients, initial, N));
    }

    void testCase1() {
        int coefficients_[] = {1, 1};
        vector<int> coefficients(coefficients_, coefficients_ + (sizeof(coefficients_) / sizeof(coefficients_[0])));
        int initial_[] = {0, 1};
        vector<int> initial(initial_, initial_ + (sizeof(initial_) / sizeof(initial_[0])));
		int N = 9;
		int expected_ = 4;
        assertEquals(1, expected_, solution.moduloTen(coefficients, initial, N));
    }

    void testCase2() {
        int coefficients_[] = {2};
        vector<int> coefficients(coefficients_, coefficients_ + (sizeof(coefficients_) / sizeof(coefficients_[0])));
        int initial_[] = {1};
        vector<int> initial(initial_, initial_ + (sizeof(initial_) / sizeof(initial_[0])));
		int N = 20;
		int expected_ = 6;
        assertEquals(2, expected_, solution.moduloTen(coefficients, initial, N));
    }

    void testCase3() {
        int coefficients_[] = {2};
        vector<int> coefficients(coefficients_, coefficients_ + (sizeof(coefficients_) / sizeof(coefficients_[0])));
        int initial_[] = {1};
        vector<int> initial(initial_, initial_ + (sizeof(initial_) / sizeof(initial_[0])));
		int N = 64;
		int expected_ = 6;
        assertEquals(3, expected_, solution.moduloTen(coefficients, initial, N));
    }

    void testCase4() {
        int coefficients_[] = {25, 143};
        vector<int> coefficients(coefficients_, coefficients_ + (sizeof(coefficients_) / sizeof(coefficients_[0])));
        int initial_[] = {0, 0};
        vector<int> initial(initial_, initial_ + (sizeof(initial_) / sizeof(initial_[0])));
		int N = 100000;
		int expected_ = 0;
        assertEquals(4, expected_, solution.moduloTen(coefficients, initial, N));
    }

    void testCase5() {
        int coefficients_[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
        vector<int> coefficients(coefficients_, coefficients_ + (sizeof(coefficients_) / sizeof(coefficients_[0])));
        int initial_[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        vector<int> initial(initial_, initial_ + (sizeof(initial_) / sizeof(initial_[0])));
		int N = 654;
		int expected_ = 5;
        assertEquals(5, expected_, solution.moduloTen(coefficients, initial, N));
    }

    void testCase6() {
        int coefficients_[] = {901, 492, 100};
        vector<int> coefficients(coefficients_, coefficients_ + (sizeof(coefficients_) / sizeof(coefficients_[0])));
        int initial_[] = {-6, -15, -39};
        vector<int> initial(initial_, initial_ + (sizeof(initial_) / sizeof(initial_[0])));
		int N = 0;
		int expected_ = 4;
        assertEquals(6, expected_, solution.moduloTen(coefficients, initial, N));
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
        RecurrenceRelationTest test;
        test.runTest(i);
    }
}
