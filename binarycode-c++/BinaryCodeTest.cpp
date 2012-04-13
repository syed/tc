#include "BinaryCode.h"
#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class BinaryCodeTest {

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

    BinaryCode solution;

    void testCase0() {
		string message = "123210122";
        string expected__[] = {"011100011", "NONE"};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(0, expected_, solution.decode(message));
    }

    void testCase1() {
		string message = "11";
        string expected__[] = {"01", "10"};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(1, expected_, solution.decode(message));
    }

    void testCase2() {
		string message = "22111";
        string expected__[] = {"NONE", "11001"};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(2, expected_, solution.decode(message));
    }

    void testCase3() {
		string message = "123210120";
        string expected__[] = {"NONE", "NONE"};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(3, expected_, solution.decode(message));
    }

    void testCase4() {
		string message = "3";
        string expected__[] = {"NONE", "NONE"};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(4, expected_, solution.decode(message));
    }

    void testCase5() {
		string message = "12221112222221112221111111112221111";
        string expected__[] = {"01101001101101001101001001001101001", "10110010110110010110010010010110010"};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(5, expected_, solution.decode(message));
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
        BinaryCodeTest test;
        test.runTest(i);
    }
}
