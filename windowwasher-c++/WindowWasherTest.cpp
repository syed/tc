#include "WindowWasher.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class WindowWasherTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    WindowWasher solution;

    void testCase0() {
		int width = 10;
		int height = 10;
        int washTimes_[] = {60};
        vector<int> washTimes(washTimes_, washTimes_ + (sizeof(washTimes_) / sizeof(washTimes_[0])));
		int expected_ = 6000;
        assertEquals(0, expected_, solution.fastest(width, height, washTimes));
    }

    void testCase1() {
		int width = 10;
		int height = 10;
        int washTimes_[] = {60, 60};
        vector<int> washTimes(washTimes_, washTimes_ + (sizeof(washTimes_) / sizeof(washTimes_[0])));
		int expected_ = 3000;
        assertEquals(1, expected_, solution.fastest(width, height, washTimes));
    }

    void testCase2() {
		int width = 10;
		int height = 10;
        int washTimes_[] = {60, 30};
        vector<int> washTimes(washTimes_, washTimes_ + (sizeof(washTimes_) / sizeof(washTimes_[0])));
		int expected_ = 2100;
        assertEquals(2, expected_, solution.fastest(width, height, washTimes));
    }

    void testCase3() {
		int width = 1000;
		int height = 1000;
        int washTimes_[] = {1000};
        vector<int> washTimes(washTimes_, washTimes_ + (sizeof(washTimes_) / sizeof(washTimes_[0])));
		int expected_ = 1000000000;
        assertEquals(3, expected_, solution.fastest(width, height, washTimes));
    }

    void testCase4() {
		int width = 421;
		int height = 936;
        int washTimes_[] = {111, 56, 931, 22, 445, 90, 14, 222};
        vector<int> washTimes(washTimes_, washTimes_ + (sizeof(washTimes_) / sizeof(washTimes_[0])));
		int expected_ = 2450448;
        assertEquals(4, expected_, solution.fastest(width, height, washTimes));
    }

    void testCase5() {
		int width = 25;
		int height = 25;
        int washTimes_[] = {1, 625};
        vector<int> washTimes(washTimes_, washTimes_ + (sizeof(washTimes_) / sizeof(washTimes_[0])));
		int expected_ = 625;
        assertEquals(5, expected_, solution.fastest(width, height, washTimes));
    }

    void testCase6() {
		int width = 12;
		int height = 754;
        int washTimes_[] = {728, 734, 147, 464, 6, 703, 254};
        vector<int> washTimes(washTimes_, washTimes_ + (sizeof(washTimes_) / sizeof(washTimes_[0])));
		int expected_ = 54288;
        assertEquals(6, expected_, solution.fastest(width, height, washTimes));
    }

    void testCase7() {
		int width = 779;
		int height = 359;
        int washTimes_[] = {117, 88, 29, 264, 463, 566, 755, 528, 630, 4, 850, 570, 625, 471, 936, 926, 5, 138, 464, 295, 768, 166, 749, 758, 362, 797, 517, 889, 943, 774, 462, 702, 554, 67, 723, 622};
        vector<int> washTimes(washTimes_, washTimes_ + (sizeof(washTimes_) / sizeof(washTimes_[0])));
		int expected_ = 495420;
        assertEquals(7, expected_, solution.fastest(width, height, washTimes));
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
            case (7): testCase7(); break;
            default: cerr << "No such test case: " << testCase << endl; break;
        }
    }

};

int main() {
    for (int i = 0; i < 8; i++) {
        WindowWasherTest test;
        test.runTest(i);
    }
}
