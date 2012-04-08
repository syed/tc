#include "StairClimb.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class StairClimbTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    StairClimb solution;

    void testCase0() {
        int flights_[] = {15};
        vector<int> flights(flights_, flights_ + (sizeof(flights_) / sizeof(flights_[0])));
		int stairsPerStride = 2;
		int expected_ = 8;
        assertEquals(0, expected_, solution.stridesTaken(flights, stairsPerStride));
    }

    void testCase1() {
        int flights_[] = {15, 15};
        vector<int> flights(flights_, flights_ + (sizeof(flights_) / sizeof(flights_[0])));
		int stairsPerStride = 2;
		int expected_ = 18;
        assertEquals(1, expected_, solution.stridesTaken(flights, stairsPerStride));
    }

    void testCase2() {
        int flights_[] = {5, 11, 9, 13, 8, 30, 14};
        vector<int> flights(flights_, flights_ + (sizeof(flights_) / sizeof(flights_[0])));
		int stairsPerStride = 3;
		int expected_ = 44;
        assertEquals(2, expected_, solution.stridesTaken(flights, stairsPerStride));
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
        StairClimbTest test;
        test.runTest(i);
    }
}
