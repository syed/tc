#include "PrefixCode.h"
#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class PrefixCodeTest {

    static void assertEquals(int testCase, const string& expected, const string& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << '"' << expected << '"' << "> but was: <" << '"' << actual << '"' << '>' << endl;
        }
    }

    PrefixCode solution;

    void testCase0() {
        string words_[] = {"trivial"};
        vector<string> words(words_, words_ + (sizeof(words_) / sizeof(words_[0])));
		string expected_ = "Yes";
        assertEquals(0, expected_, solution.isOne(words));
    }

    void testCase1() {
        string words_[] = {"10001", "011", "100", "001", "10"};
        vector<string> words(words_, words_ + (sizeof(words_) / sizeof(words_[0])));
		string expected_ = "No, 2";
        assertEquals(1, expected_, solution.isOne(words));
    }

    void testCase2() {
        string words_[] = {"no", "nosy", "neighbors", "needed"};
        vector<string> words(words_, words_ + (sizeof(words_) / sizeof(words_[0])));
		string expected_ = "No, 0";
        assertEquals(2, expected_, solution.isOne(words));
    }

    void testCase3() {
        string words_[] = {"1010", "11", "100", "0", "1011"};
        vector<string> words(words_, words_ + (sizeof(words_) / sizeof(words_[0])));
		string expected_ = "Yes";
        assertEquals(3, expected_, solution.isOne(words));
    }

    void testCase4() {
        string words_[] = {"No", "not"};
        vector<string> words(words_, words_ + (sizeof(words_) / sizeof(words_[0])));
		string expected_ = "Yes";
        assertEquals(4, expected_, solution.isOne(words));
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
        PrefixCodeTest test;
        test.runTest(i);
    }
}
