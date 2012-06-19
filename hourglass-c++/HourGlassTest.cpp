#include "HourGlass.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class HourGlassTest {

    static void writeTo(std::ostream& out, const vector<int>& v) {
        out << '{';
        for (unsigned int i = 0; i < v.size(); i++) {
            out << v[i];
            if (i + 1 != v.size()) out << ", ";
        }
        out << '}';
    }

    static void assertEquals(int testCase, const vector<int>& expected, const vector<int>& actual) {
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

    HourGlass solution;

    void testCase0() {
		int glass1 = 5;
		int glass2 = 7;
        int expected__[] = {5, 7, 9, 10, 11, 12, 13, 14, 15, 16};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(0, expected_, solution.measurable(glass1, glass2));
    }

    void testCase1() {
		int glass1 = 13;
		int glass2 = 5;
        int expected__[] = {5, 10, 13, 15, 16, 17, 18, 19, 20, 21};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(1, expected_, solution.measurable(glass1, glass2));
    }

    void testCase2() {
		int glass1 = 23;
		int glass2 = 23;
        int expected__[] = {23, 46, 69, 92, 115, 138, 161, 184, 207, 230};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(2, expected_, solution.measurable(glass1, glass2));
    }

    void testCase3() {
		int glass1 = 24;
		int glass2 = 30;
        int expected__[] = {24, 30, 36, 42, 48, 54, 60, 66, 72, 78};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(3, expected_, solution.measurable(glass1, glass2));
    }

    void testCase4() {
		int glass1 = 1;
		int glass2 = 50;
        int expected__[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(4, expected_, solution.measurable(glass1, glass2));
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
        HourGlassTest test;
        test.runTest(i);
    }
}
