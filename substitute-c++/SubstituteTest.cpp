#include "Substitute.h"
#include <iostream>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::string;

class SubstituteTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    Substitute solution;

    void testCase0() {
		string key = "TRADINGFEW";
		string code = "LGXWEV";
		int expected_ = 709;
        assertEquals(0, expected_, solution.getValue(key, code));
    }

    void testCase1() {
		string key = "ABCDEFGHIJ";
		string code = "XJ";
		int expected_ = 0;
        assertEquals(1, expected_, solution.getValue(key, code));
    }

    void testCase2() {
		string key = "CRYSTALBUM";
		string code = "MMA";
		int expected_ = 6;
        assertEquals(2, expected_, solution.getValue(key, code));
    }

    public: void runTest(int testCase) {
        switch (testCase) {
            case (0): testCase0(); break;
            case (1): testCase1(); break;
            case (2): testCase2(); break;
            default: cerr << "No such test case: " << testCase << endl; break;
        }
    }

};

int main() {
    for (int i = 0; i < 3; i++) {
        SubstituteTest test;
        test.runTest(i);
    }
}
