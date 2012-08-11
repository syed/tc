#include "Quilting.h"
#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class QuiltingTest {

    static void assertEquals(int testCase, const string& expected, const string& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << '"' << expected << '"' << "> but was: <" << '"' << actual << '"' << '>' << endl;
        }
    }

    Quilting solution;

    void testCase0() {
		int length = 3;
		int width = 2;
        string colorList_[] = {"RED", "BLUE", "TAN"};
        vector<string> colorList(colorList_, colorList_ + (sizeof(colorList_) / sizeof(colorList_[0])));
		string expected_ = "TAN";
        assertEquals(0, expected_, solution.lastPatch(length, width, colorList));
    }

    void testCase1() {
		int length = 4;
		int width = 3;
        string colorList_[] = {"E", "D", "C", "B", "A"};
        vector<string> colorList(colorList_, colorList_ + (sizeof(colorList_) / sizeof(colorList_[0])));
		string expected_ = "E";
        assertEquals(1, expected_, solution.lastPatch(length, width, colorList));
    }

    void testCase2() {
		int length = 3;
		int width = 3;
        string colorList_[] = {"A", "B", "C", "D"};
        vector<string> colorList(colorList_, colorList_ + (sizeof(colorList_) / sizeof(colorList_[0])));
		string expected_ = "C";
        assertEquals(2, expected_, solution.lastPatch(length, width, colorList));
    }

    void testCase3() {
		int length = 1;
		int width = 1;
        string colorList_[] = {"RED", "BLUE", "YELLOW"};
        vector<string> colorList(colorList_, colorList_ + (sizeof(colorList_) / sizeof(colorList_[0])));
		string expected_ = "RED";
        assertEquals(3, expected_, solution.lastPatch(length, width, colorList));
    }

    void testCase4() {
		int length = 10;
		int width = 10;
        string colorList_[] = {"X", "Y", "Z"};
        vector<string> colorList(colorList_, colorList_ + (sizeof(colorList_) / sizeof(colorList_[0])));
		string expected_ = "Z";
        assertEquals(4, expected_, solution.lastPatch(length, width, colorList));
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
        QuiltingTest test;
        test.runTest(i);
    }
}
