#include "WordForm.h"
#include <iostream>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::string;

class WordFormTest {

    static void assertEquals(int testCase, const string& expected, const string& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << '"' << expected << '"' << "> but was: <" << '"' << actual << '"' << '>' << endl;
        }
    }

    WordForm solution;

    void testCase0() {
		string word = "WHEREABOUTS";
		string expected_ = "CVCVCVC";
        assertEquals(0, expected_, solution.getSequence(word));
    }

    void testCase1() {
		string word = "yoghurt";
		string expected_ = "CVCVC";
        assertEquals(1, expected_, solution.getSequence(word));
    }

    void testCase2() {
		string word = "YipPy";
		string expected_ = "CVCV";
        assertEquals(2, expected_, solution.getSequence(word));
    }

    void testCase3() {
		string word = "AyYyEYye";
		string expected_ = "VCVCVCV";
        assertEquals(3, expected_, solution.getSequence(word));
    }

    void testCase4() {
		string word = "yC";
		string expected_ = "C";
        assertEquals(4, expected_, solution.getSequence(word));
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
        WordFormTest test;
        test.runTest(i);
    }
}
