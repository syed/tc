#include "ElectionFraudDiv2.h"
#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class ElectionFraudDiv2Test {

    static void assertEquals(int testCase, const string& expected, const string& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << '"' << expected << '"' << "> but was: <" << '"' << actual << '"' << '>' << endl;
        }
    }

    ElectionFraudDiv2 solution;

    void testCase0() {
        int percentages_[] = {100};
        vector<int> percentages(percentages_, percentages_ + (sizeof(percentages_) / sizeof(percentages_[0])));
		string expected_ = "NO";
        assertEquals(0, expected_, solution.IsFraudulent(percentages));
    }

    void testCase1() {
        int percentages_[] = {34, 34, 34};
        vector<int> percentages(percentages_, percentages_ + (sizeof(percentages_) / sizeof(percentages_[0])));
		string expected_ = "YES";
        assertEquals(1, expected_, solution.IsFraudulent(percentages));
    }

    void testCase2() {
        int percentages_[] = {12, 12, 12, 12, 12, 12, 12, 12};
        vector<int> percentages(percentages_, percentages_ + (sizeof(percentages_) / sizeof(percentages_[0])));
		string expected_ = "YES";
        assertEquals(2, expected_, solution.IsFraudulent(percentages));
    }

    void testCase3() {
        int percentages_[] = {13, 13, 13, 13, 13, 13, 13, 13};
        vector<int> percentages(percentages_, percentages_ + (sizeof(percentages_) / sizeof(percentages_[0])));
		string expected_ = "NO";
        assertEquals(3, expected_, solution.IsFraudulent(percentages));
    }

    void testCase4() {
        int percentages_[] = {0, 1, 100};
        vector<int> percentages(percentages_, percentages_ + (sizeof(percentages_) / sizeof(percentages_[0])));
		string expected_ = "NO";
        assertEquals(4, expected_, solution.IsFraudulent(percentages));
    }

    void testCase5() {
        int percentages_[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9, 3, 2, 3, 8};
        vector<int> percentages(percentages_, percentages_ + (sizeof(percentages_) / sizeof(percentages_[0])));
		string expected_ = "NO";
        assertEquals(5, expected_, solution.IsFraudulent(percentages));
    }

    void testCase6() {
        int percentages_[] = {0, 1, 1, 100};
        vector<int> percentages(percentages_, percentages_ + (sizeof(percentages_) / sizeof(percentages_[0])));
		string expected_ = "YES";
        assertEquals(5, expected_, solution.IsFraudulent(percentages));
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
        ElectionFraudDiv2Test test;
        test.runTest(i);
    }
}
