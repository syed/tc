#include "ShortPalindromes.h"
#include <iostream>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::string;

class ShortPalindromesTest {

    static void assertEquals(int testCase, const string& expected, const string& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << '"' << expected << '"' << "> but was: <" << '"' << actual << '"' << '>' << endl;
        }
    }

    ShortPalindromes solution;

    void testCase0() {
		string base = "RACE";
		string expected_ = "ECARACE";
        assertEquals(0, expected_, solution.shortest(base));
    }

    void testCase1() {
		string base = "TOPCODER";
		string expected_ = "REDTOCPCOTDER";
        assertEquals(1, expected_, solution.shortest(base));
    }

    void testCase2() {
		string base = "Q";
		string expected_ = "Q";
        assertEquals(2, expected_, solution.shortest(base));
    }

    void testCase3() {
		string base = "MADAMIMADAM";
		string expected_ = "MADAMIMADAM";
        assertEquals(3, expected_, solution.shortest(base));
    }

    void testCase4() {
		string base = "ALRCAGOEUAOEURGCOEUOOIGFA";
		string expected_ = "AFLRCAGIOEOUAEOCEGRURGECOEAUOEOIGACRLFA";
        assertEquals(4, expected_, solution.shortest(base));
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
        ShortPalindromesTest test;
        test.runTest(i);
    }
}
