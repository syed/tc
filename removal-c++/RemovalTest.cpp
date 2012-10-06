#include "Removal.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class RemovalTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    Removal solution;

    void testCase0() {
		int n = 8;
		int k = 3;
        string remove_[] = {"3-4", "4-5"};
        vector<string> remove(remove_, remove_ + (sizeof(remove_) / sizeof(remove_[0])));
		int expected_ = 5;
        assertEquals(0, expected_, solution.finalPos(n, k, remove));
    }

    void testCase1() {
		int n = 100;
		int k = 13;
        string remove_[] = {"19-50", "19-50", "19-19"};
        vector<string> remove(remove_, remove_ + (sizeof(remove_) / sizeof(remove_[0])));
		int expected_ = 13;
        assertEquals(1, expected_, solution.finalPos(n, k, remove));
    }

    void testCase2() {
		int n = 100;
		int k = 39;
        string remove_[] = {"19-50", "19-50", "19-19"};
        vector<string> remove(remove_, remove_ + (sizeof(remove_) / sizeof(remove_[0])));
		int expected_ = -1;
        assertEquals(2, expected_, solution.finalPos(n, k, remove));
    }
    //{, 30, }

    void testCase3() {
		int n = 2000000000;
		int k = 30;
        string remove_[] = {"30-100", "100-200", "20-100"};
        vector<string> remove(remove_, remove_ + (sizeof(remove_) / sizeof(remove_[0])));
		int expected_ = 283;
        assertEquals(3, expected_, solution.finalPos(n, k, remove));
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
        RemovalTest test;
        test.runTest(i);
    }
}
