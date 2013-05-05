#include "VacationTime.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class VacationTimeTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    VacationTime solution;

    void testCase0() {
		int N = 3;
		int K = 3;
        int workingDays_[] = {2};
        vector<int> workingDays(workingDays_, workingDays_ + (sizeof(workingDays_) / sizeof(workingDays_[0])));
		int expected_ = 1;
        assertEquals(0, expected_, solution.bestSchedule(N, K, workingDays));
    }

    void testCase1() {
		int N = 4;
		int K = 3;
        int workingDays_[] = {3, 1, 2};
        vector<int> workingDays(workingDays_, workingDays_ + (sizeof(workingDays_) / sizeof(workingDays_[0])));
		int expected_ = 2;
        assertEquals(1, expected_, solution.bestSchedule(N, K, workingDays));
    }

    void testCase2() {
		int N = 5;
		int K = 3;
        int workingDays_[] = {4, 1};
        vector<int> workingDays(workingDays_, workingDays_ + (sizeof(workingDays_) / sizeof(workingDays_[0])));
		int expected_ = 1;
        assertEquals(2, expected_, solution.bestSchedule(N, K, workingDays));
    }

    void testCase3() {
		int N = 9;
		int K = 2;
        int workingDays_[] = {7, 4, 5, 6, 2};
        vector<int> workingDays(workingDays_, workingDays_ + (sizeof(workingDays_) / sizeof(workingDays_[0])));
		int expected_ = 0;
        assertEquals(3, expected_, solution.bestSchedule(N, K, workingDays));
    }

    void testCase4() {
		int N = 1000;
		int K = 513;
        int workingDays_[] = {808, 459, 792, 863, 715, 70, 336, 731};
        vector<int> workingDays(workingDays_, workingDays_ + (sizeof(workingDays_) / sizeof(workingDays_[0])));
		int expected_ = 2;
        assertEquals(4, expected_, solution.bestSchedule(N, K, workingDays));
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
        VacationTimeTest test;
        test.runTest(i);
    }
}
