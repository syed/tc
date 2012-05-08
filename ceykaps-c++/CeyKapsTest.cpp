#include "CeyKaps.h"
#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class CeyKapsTest {

    static void assertEquals(int testCase, const string& expected, const string& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << '"' << expected << '"' << "> but was: <" << '"' << actual << '"' << '>' << endl;
        }
    }

    CeyKaps solution;

    void testCase0() {
		string typed = "AAAAA";
        string switches_[] = {"A:B", "B:C", "A:D"};
        vector<string> switches(switches_, switches_ + (sizeof(switches_) / sizeof(switches_[0])));
		string expected_ = "CCCCC";
        assertEquals(0, expected_, solution.decipher(typed, switches));
    }

    void testCase1() {
		string typed = "ABCDE";
        string switches_[] = {"A:B", "B:C", "C:D", "D:E", "E:A"};
        vector<string> switches(switches_, switches_ + (sizeof(switches_) / sizeof(switches_[0])));
		string expected_ = "AEBCD";
        assertEquals(1, expected_, solution.decipher(typed, switches));
    }

    void testCase2() {
		string typed = "IHWSIOTCHEDMYKEYCAPSARWUND";
        string switches_[] = {"W:O", "W:I"};
        vector<string> switches(switches_, switches_ + (sizeof(switches_) / sizeof(switches_[0])));
		string expected_ = "WHOSWITCHEDMYKEYCAPSAROUND";
        assertEquals(2, expected_, solution.decipher(typed, switches));
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
        CeyKapsTest test;
        test.runTest(i);
    }
}
