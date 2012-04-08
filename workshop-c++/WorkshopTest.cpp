#include "Workshop.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class WorkshopTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    Workshop solution;

    void testCase0() {
        int pieces_[] = {1, 2, 3, 4, 5};
        vector<int> pieces(pieces_, pieces_ + (sizeof(pieces_) / sizeof(pieces_[0])));
		int expected_ = 3;
        assertEquals(0, expected_, solution.pictureFrames(pieces));
    }

    void testCase1() {
        int pieces_[] = {8, 5, 3};
        vector<int> pieces(pieces_, pieces_ + (sizeof(pieces_) / sizeof(pieces_[0])));
		int expected_ = 0;
        assertEquals(1, expected_, solution.pictureFrames(pieces));
    }

    void testCase2() {
        int pieces_[] = {4, 23, 76, 22, 87, 3, 1, 99};
        vector<int> pieces(pieces_, pieces_ + (sizeof(pieces_) / sizeof(pieces_[0])));
		int expected_ = 7;
        assertEquals(2, expected_, solution.pictureFrames(pieces));
    }

    void testCase3() {
        int pieces_[] = {10000, 9999, 9998, 9997, 9996, 1, 2, 3, 4, 5};
        vector<int> pieces(pieces_, pieces_ + (sizeof(pieces_) / sizeof(pieces_[0])));
		int expected_ = 43;
        assertEquals(3, expected_, solution.pictureFrames(pieces));
    }

    void testCase4() {
        int pieces_[] = {100};
        vector<int> pieces(pieces_, pieces_ + (sizeof(pieces_) / sizeof(pieces_[0])));
		int expected_ = 0;
        assertEquals(4, expected_, solution.pictureFrames(pieces));
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
        WorkshopTest test;
        test.runTest(i);
    }
}
