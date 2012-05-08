#include "Twain.h"
#include <iostream>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::string;

class TwainTest {

    static void assertEquals(int testCase, const string& expected, const string& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << '"' << expected << '"' << "> but was: <" << '"' << actual << '"' << '>' << endl;
        }
    }

    Twain solution;

    void testCase0() {
		int year = 1;
		string phrase = "i fixed the chrome xerox by the cyclical church";
		string expected_ = "i fiksed the chrome zeroks by the cyclical church";
        assertEquals(0, expected_, solution.getNewSpelling(year, phrase));
    }

    void testCase1() {
		int year = 2;
		string phrase = "i fixed the chrome xerox by the cyclical church";
		string expected_ = "i fiksed the chrome zeroks bi the ciclical church";
        assertEquals(1, expected_, solution.getNewSpelling(year, phrase));
    }

    void testCase2() {
		int year = 0;
		string phrase = "this is unchanged";
		string expected_ = "this is unchanged";
        assertEquals(2, expected_, solution.getNewSpelling(year, phrase));
    }

    void testCase3() {
		int year = 7;
		string phrase = "sch kn x xschrx cknnchc cyck xxceci";
		string expected_ = "sk n z zskrks nchk sik zksesi";
        assertEquals(3, expected_, solution.getNewSpelling(year, phrase));
    }

    void testCase4() {
		int year = 7;
		string phrase = "  concoction   convalescence   cyclical   cello   ";
		string expected_ = "  konkoktion   konvalesense   siklikal   selo   ";
        assertEquals(4, expected_, solution.getNewSpelling(year, phrase));
    }

    void testCase5() {
		int year = 7;
		string phrase = "";
		string expected_ = "";
        assertEquals(5, expected_, solution.getNewSpelling(year, phrase));
    }

    void testCase6() {
		int year = 7;
		string phrase = "cck xzz aaaaa";
		string expected_ = "k z aaaaa";
        assertEquals(6, expected_, solution.getNewSpelling(year, phrase));
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
        TwainTest test;
        test.runTest(i);
    }
}
