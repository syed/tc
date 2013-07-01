#include "ColorfulTilesEasy.h"
#include <iostream>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::string;

class ColorfulTilesEasyTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    ColorfulTilesEasy solution;

    void testCase0() {
		string room = "RRRRRR";
		int expected_ = 3;
        assertEquals(0, expected_, solution.theMin(room));
    }

    void testCase1() {
		string room = "GGGGGGG";
		int expected_ = 3;
        assertEquals(1, expected_, solution.theMin(room));
    }

    void testCase2() {
		string room = "BBBYYYYYY";
		int expected_ = 4;
        assertEquals(2, expected_, solution.theMin(room));
    }

    void testCase3() {
		string room = "BRYGYBGRYR";
		int expected_ = 0;
        assertEquals(3, expected_, solution.theMin(room));
    }

    void testCase4() {
		string room = "RGGBBBRYYB";
		int expected_ = 3;
        assertEquals(4, expected_, solution.theMin(room));
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
        ColorfulTilesEasyTest test;
        test.runTest(i);
    }
}
