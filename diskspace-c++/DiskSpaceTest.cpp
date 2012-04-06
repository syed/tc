#include "DiskSpace.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class DiskSpaceTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    DiskSpace solution;

    void testCase0() {
        int used_[] = {300, 525, 110};
        vector<int> used(used_, used_ + (sizeof(used_) / sizeof(used_[0])));
        int total_[] = {350, 600, 115};
        vector<int> total(total_, total_ + (sizeof(total_) / sizeof(total_[0])));
		int expected_ = 2;
        assertEquals(0, expected_, solution.minDrives(used, total));
    }

    void testCase1() {
        int used_[] = {1, 200, 200, 199, 200, 200};
        vector<int> used(used_, used_ + (sizeof(used_) / sizeof(used_[0])));
        int total_[] = {1000, 200, 200, 200, 200, 200};
        vector<int> total(total_, total_ + (sizeof(total_) / sizeof(total_[0])));
		int expected_ = 1;
        assertEquals(1, expected_, solution.minDrives(used, total));
    }

    void testCase2() {
        int used_[] = {750, 800, 850, 900, 950};
        vector<int> used(used_, used_ + (sizeof(used_) / sizeof(used_[0])));
        int total_[] = {800, 850, 900, 950, 1000};
        vector<int> total(total_, total_ + (sizeof(total_) / sizeof(total_[0])));
		int expected_ = 5;
        assertEquals(2, expected_, solution.minDrives(used, total));
    }

    void testCase3() {
        int used_[] = {49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49, 49};
        vector<int> used(used_, used_ + (sizeof(used_) / sizeof(used_[0])));
        int total_[] = {50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50};
        vector<int> total(total_, total_ + (sizeof(total_) / sizeof(total_[0])));
		int expected_ = 49;
        assertEquals(3, expected_, solution.minDrives(used, total));
    }

    void testCase4() {
        int used_[] = {331, 242, 384, 366, 428, 114, 145, 89, 381, 170, 329, 190, 482, 246, 2, 38, 220, 290, 402, 385};
        vector<int> used(used_, used_ + (sizeof(used_) / sizeof(used_[0])));
        int total_[] = {992, 509, 997, 946, 976, 873, 771, 565, 693, 714, 755, 878, 897, 789, 969, 727, 765, 521, 961, 906};
        vector<int> total(total_, total_ + (sizeof(total_) / sizeof(total_[0])));
		int expected_ = 6;
        assertEquals(4, expected_, solution.minDrives(used, total));
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
        DiskSpaceTest test;
        test.runTest(i);
    }
}
