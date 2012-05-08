#include "ProgressBar.h"
#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class ProgressBarTest {

    static void assertEquals(int testCase, const string& expected, const string& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << '"' << expected << '"' << "> but was: <" << '"' << actual << '"' << '>' << endl;
        }
    }

    ProgressBar solution;

    void testCase0() {
        int taskTimes_[] = {19, 6, 23, 17};
        vector<int> taskTimes(taskTimes_, taskTimes_ + (sizeof(taskTimes_) / sizeof(taskTimes_[0])));
		int tasksCompleted = 3;
		string expected_ = "##############......";
        assertEquals(0, expected_, solution.showProgress(taskTimes, tasksCompleted));
    }

    void testCase1() {
        int taskTimes_[] = {2, 3, 7, 1, 4, 3};
        vector<int> taskTimes(taskTimes_, taskTimes_ + (sizeof(taskTimes_) / sizeof(taskTimes_[0])));
		int tasksCompleted = 4;
		string expected_ = "#############.......";
        assertEquals(1, expected_, solution.showProgress(taskTimes, tasksCompleted));
    }

    void testCase2() {
        int taskTimes_[] = {553, 846, 816, 203, 101, 120, 161, 818, 315, 772};
        vector<int> taskTimes(taskTimes_, taskTimes_ + (sizeof(taskTimes_) / sizeof(taskTimes_[0])));
		int tasksCompleted = 4;
		string expected_ = "##########..........";
        assertEquals(2, expected_, solution.showProgress(taskTimes, tasksCompleted));
    }

    void testCase3() {
        int taskTimes_[] = {7, 60, 468, 489, 707, 499, 350, 998, 1000, 716, 457, 104, 597, 583, 396, 862};
        vector<int> taskTimes(taskTimes_, taskTimes_ + (sizeof(taskTimes_) / sizeof(taskTimes_[0])));
		int tasksCompleted = 2;
		string expected_ = "....................";
        assertEquals(3, expected_, solution.showProgress(taskTimes, tasksCompleted));
    }

    void testCase4() {
        int taskTimes_[] = {419, 337, 853, 513, 632, 861, 336, 594, 94, 367, 336, 297, 966, 627, 399, 433, 846, 859, 80, 2};
        vector<int> taskTimes(taskTimes_, taskTimes_ + (sizeof(taskTimes_) / sizeof(taskTimes_[0])));
		int tasksCompleted = 19;
		string expected_ = "###################.";
        assertEquals(4, expected_, solution.showProgress(taskTimes, tasksCompleted));
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
        ProgressBarTest test;
        test.runTest(i);
    }
}
