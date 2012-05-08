#include "SuperRot.h"
#include <iostream>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::string;

class SuperRotTest {

    static void assertEquals(int testCase, const string& expected, const string& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << '"' << expected << '"' << "> but was: <" << '"' << actual << '"' << '>' << endl;
        }
    }

    SuperRot solution;

    void testCase0() {
		string message = "Uryyb 28";
		string expected_ = "Hello 73";
        assertEquals(0, expected_, solution.decoder(message));
    }

    void testCase1() {
		string message = "GbcPbqre";
		string expected_ = "TopCoder";
        assertEquals(1, expected_, solution.decoder(message));
    }

    void testCase2() {
		string message = "";
		string expected_ = "";
        assertEquals(2, expected_, solution.decoder(message));
    }

    void testCase3() {
		string message = "5678901234";
		string expected_ = "0123456789";
        assertEquals(3, expected_, solution.decoder(message));
    }

    void testCase4() {
		string message = "NnOoPpQqRr AaBbCcDdEe";
		string expected_ = "AaBbCcDdEe NnOoPpQqRr";
        assertEquals(4, expected_, solution.decoder(message));
    }

    void testCase5() {
		string message = "Gvzr vf 54 71 CZ ba Whyl 4gu bs gur lrne 7558 NQ";
		string expected_ = "Time is 09 26 PM on July 9th of the year 2003 AD";
        assertEquals(5, expected_, solution.decoder(message));
    }

    void testCase6() {
		string message = "Gur dhvpx oebja sbk whzcf bire n ynml qbt";
		string expected_ = "The quick brown fox jumps over a lazy dog";
        assertEquals(6, expected_, solution.decoder(message));
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
        SuperRotTest test;
        test.runTest(i);
    }
}
