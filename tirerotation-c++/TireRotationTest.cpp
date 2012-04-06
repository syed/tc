#include "TireRotation.h"
#include <iostream>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::string;

class TireRotationTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    TireRotation solution;

    void testCase0() {
		string initial = "ABCD";
		string current = "ABCD";
		int expected_ = 1;
        assertEquals(0, expected_, solution.getCycle(initial, current));
    }

    void testCase1() {
		string initial = "ABCD";
		string current = "DCAB";
		int expected_ = 2;
        assertEquals(1, expected_, solution.getCycle(initial, current));
    }

    void testCase2() {
		string initial = "ABCD";
		string current = "CDBA";
		int expected_ = 4;
        assertEquals(2, expected_, solution.getCycle(initial, current));
    }

    void testCase3() {
		string initial = "ABCD";
		string current = "ABDC";
		int expected_ = -1;
        assertEquals(3, expected_, solution.getCycle(initial, current));
    }

    void testCase4() {
		string initial = "ZAXN";
		string current = "XNAZ";
		int expected_ = 4;
        assertEquals(4, expected_, solution.getCycle(initial, current));
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
        TireRotationTest test;
        test.runTest(i);
    }
}
