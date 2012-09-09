#include "FairWorkload.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class FairWorkloadTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    FairWorkload solution;

    void testCase0() {
        int folders_[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
        vector<int> folders(folders_, folders_ + (sizeof(folders_) / sizeof(folders_[0])));
		int workers = 3;
		int expected_ = 170;
        assertEquals(0, expected_, solution.getMostWork(folders, workers));
    }

    void testCase1() {
        int folders_[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
        vector<int> folders(folders_, folders_ + (sizeof(folders_) / sizeof(folders_[0])));
		int workers = 5;
		int expected_ = 110;
        assertEquals(1, expected_, solution.getMostWork(folders, workers));
    }

    void testCase2() {
        int folders_[] = {568, 712, 412, 231, 241, 393, 865, 287, 128, 457, 238, 98, 980, 23, 782};
        vector<int> folders(folders_, folders_ + (sizeof(folders_) / sizeof(folders_[0])));
		int workers = 4;
		int expected_ = 1785;
        assertEquals(2, expected_, solution.getMostWork(folders, workers));
    }

    void testCase3() {
        int folders_[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1000};
        vector<int> folders(folders_, folders_ + (sizeof(folders_) / sizeof(folders_[0])));
		int workers = 2;
		int expected_ = 1000;
        assertEquals(3, expected_, solution.getMostWork(folders, workers));
    }

    void testCase4() {
        int folders_[] = {50, 50, 50, 50, 50, 50, 50};
        vector<int> folders(folders_, folders_ + (sizeof(folders_) / sizeof(folders_[0])));
		int workers = 2;
		int expected_ = 200;
        assertEquals(4, expected_, solution.getMostWork(folders, workers));
    }

    void testCase5() {
        int folders_[] = {1, 1, 1, 1, 100};
        vector<int> folders(folders_, folders_ + (sizeof(folders_) / sizeof(folders_[0])));
		int workers = 5;
		int expected_ = 100;
        assertEquals(5, expected_, solution.getMostWork(folders, workers));
    }

    void testCase6() {
        int folders_[] = {950, 650, 250, 250, 350, 100, 650, 150, 150, 700};
        vector<int> folders(folders_, folders_ + (sizeof(folders_) / sizeof(folders_[0])));
		int workers = 6;
		int expected_ = 950;
        assertEquals(6, expected_, solution.getMostWork(folders, workers));
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
        FairWorkloadTest test;
        test.runTest(i);
    }
}
