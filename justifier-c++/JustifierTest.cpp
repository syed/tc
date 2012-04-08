#include "Justifier.h"
#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class JustifierTest {

    static void writeTo(std::ostream& out, const vector<string>& v) {
        out << '{';
        for (unsigned int i = 0; i < v.size(); i++) {
            out << '"' << v[i] << '"';
            if (i + 1 != v.size()) out << ", ";
        }
        out << '}';
    }

    static void assertEquals(int testCase, const vector<string>& expected, const vector<string>& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <";
            writeTo(cout, expected);
            cout << "> but was: <";
            writeTo(cout, actual);
            cout << '>' << endl;
        }
    }

    Justifier solution;

    void testCase0() {
        string textIn_[] = {"BOB", "TOMMY", "JIM"};
        vector<string> textIn(textIn_, textIn_ + (sizeof(textIn_) / sizeof(textIn_[0])));
        string expected__[] = {"  BOB", "TOMMY", "  JIM"};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(0, expected_, solution.justify(textIn));
    }

    void testCase1() {
        string textIn_[] = {"JOHN", "JAKE", "ALAN", "BLUE"};
        vector<string> textIn(textIn_, textIn_ + (sizeof(textIn_) / sizeof(textIn_[0])));
        string expected__[] = {"JOHN", "JAKE", "ALAN", "BLUE"};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(1, expected_, solution.justify(textIn));
    }

    void testCase2() {
        string textIn_[] = {"LONGEST", "A", "LONGER", "SHORT"};
        vector<string> textIn(textIn_, textIn_ + (sizeof(textIn_) / sizeof(textIn_[0])));
        string expected__[] = {"LONGEST", "      A", " LONGER", "  SHORT"};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(2, expected_, solution.justify(textIn));
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
        JustifierTest test;
        test.runTest(i);
    }
}
