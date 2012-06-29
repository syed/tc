#include "WordParts.h"
#include <iostream>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::string;

class WordPartsTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    WordParts solution;

    void testCase0() {
		string original = "ANTIDISESTABLISHMENTARIANISM";
		string compound = "ANTIDISIANISMISM";
		int expected_ = 3;
        assertEquals(0, expected_, solution.partCount(original, compound));
    }

    void testCase1() {
		string original = "ANTIDISESTABLISHMENTARIANISM";
		string compound = "ESTABLISHMENT";
		int expected_ = -1;
        assertEquals(1, expected_, solution.partCount(original, compound));
    }

    void testCase2() {
		string original = "TOPCODERDOTCOM";
		string compound = "TOMTMODERDOTCOM";
		int expected_ = 5;
        assertEquals(2, expected_, solution.partCount(original, compound));
    }

    void testCase3() {
		string original = "HELLO";
		string compound = "HELLOHEHELLOLOHELLO";
		int expected_ = 5;
        assertEquals(3, expected_, solution.partCount(original, compound));
    }

    void testCase4() {
		string original = "DONTFORGETTHEEMPTYCASE";
		string compound = "";
		int expected_ = 0;
        assertEquals(4, expected_, solution.partCount(original, compound));
    }

    void testCase5() {
		string original = "BAAABA";
		string compound = "BAAABAAA";
		int expected_ = 2;
        assertEquals(5, expected_, solution.partCount(original, compound));
    }

    void testCase6() {
		string original = "ABBBAABABBBAABBABBABABBABAABBAABBBBBABBABABBABAABB";
		string compound = "BBBAABABBBAABBABBABABBABAABBAABBBBBABBABABBABAABAA";
		int expected_ = 17;
        assertEquals(6, expected_, solution.partCount(original, compound));
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
        WordPartsTest test;
        test.runTest(i);
    }
}
