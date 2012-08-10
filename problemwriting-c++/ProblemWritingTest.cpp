#include "ProblemWriting.h"
#include <iostream>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::string;

class ProblemWritingTest {

    static void assertEquals(int testCase, const string& expected, const string& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << '"' << expected << '"' << "> but was: <" << '"' << actual << '"' << '>' << endl;
        }
    }

    ProblemWriting solution;

    void testCase0() {
		string dotForm = "3+5";
		string expected_ = "";
        assertEquals(0, expected_, solution.myCheckData(dotForm));
    }

    void testCase1() {
		string dotForm = "9..+.5...*....3";
		string expected_ = "";
        assertEquals(1, expected_, solution.myCheckData(dotForm));
    }

    void testCase2() {
		string dotForm = "5.3+4";
		string expected_ = "dotForm is not in dot notation, check character 2.";
        assertEquals(2, expected_, solution.myCheckData(dotForm));
    }

    void testCase3() {
		string dotForm = "9*9*9*9*9*9*9*9*9*9*9*9*9*9";
		string expected_ = "dotForm must contain between 1 and 25 characters, inclusive.";
        assertEquals(3, expected_, solution.myCheckData(dotForm));
    }

    void testCase4() {
		string dotForm = "3.........../...........4";
		string expected_ = "";
        assertEquals(4, expected_, solution.myCheckData(dotForm));
    }
    void testCase5() {
		string dotForm = "34";
		string expected_ = "dotForm is not in dot notation, check character 1.";
        assertEquals(5, expected_, solution.myCheckData(dotForm));
    }

    public: void runTest(int testCase) {
        switch (testCase) {
            case (0): testCase0(); break;
            case (1): testCase1(); break;
            case (2): testCase2(); break;
            case (3): testCase3(); break;
            case (4): testCase4(); break;
            case (5): testCase5(); break;
            default: cerr << "No such test case: " << testCase << endl; break;
        }
    }

};

int main() {
    for (int i = 0; i < 6; i++) {
        ProblemWritingTest test;
        test.runTest(i);
    }
}
