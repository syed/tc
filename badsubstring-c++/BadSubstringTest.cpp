#include "BadSubstring.h"
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

class BadSubstringTest {

    static void assertEquals(int testCase, const long long& expected, const long long& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    BadSubstring solution;

    void testCase0() {
		int length = 0;
		long long expected_ = 1LL;
        assertEquals(0, expected_, solution.howMany(length));
    }

    void testCase1() {
		int length = 3;
		long long expected_ = 21LL;
        assertEquals(1, expected_, solution.howMany(length));
    }

    void testCase2() {
		int length = 29;
		long long expected_ = 1548008755920LL;
        assertEquals(2, expected_, solution.howMany(length));
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
        BadSubstringTest test;
        test.runTest(i);
    }
}
