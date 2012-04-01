#include "Time.h"
#include <iostream>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::string;

class TimeTest {

    static void assertEquals(int testCase, const string& expected, const string& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << '"' << expected << '"' << "> but was: <" << '"' << actual << '"' << '>' << endl;
        }
    }

    Time solution;

    void testCase0() {
		int seconds = 0;
		string expected_ = "0:0:0";
        assertEquals(0, expected_, solution.whatTime(seconds));
    }

    void testCase1() {
		int seconds = 3661;
		string expected_ = "1:1:1";
        assertEquals(1, expected_, solution.whatTime(seconds));
    }

    void testCase2() {
		int seconds = 5436;
		string expected_ = "1:30:36";
        assertEquals(2, expected_, solution.whatTime(seconds));
    }

    void testCase3() {
		int seconds = 86399;
		string expected_ = "23:59:59";
        assertEquals(3, expected_, solution.whatTime(seconds));
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
        TimeTest test;
        test.runTest(i);
    }
}
