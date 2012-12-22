#include "ValueHistogram.h"
#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class ValueHistogramTest {

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

    ValueHistogram solution;

    void testCase0() {
        int values_[] = {2, 3, 5, 5, 5, 2, 0, 8};
        vector<int> values(values_, values_ + (sizeof(values_) / sizeof(values_[0])));
        string expected__[] = {"..........", ".....X....", "..X..X....", "X.XX.X..X."};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(0, expected_, solution.build(values));
    }

    void testCase1() {
        int values_[] = {9, 9, 9, 9};
        vector<int> values(values_, values_ + (sizeof(values_) / sizeof(values_[0])));
        string expected__[] = {"..........", ".........X", ".........X", ".........X", ".........X"};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(1, expected_, solution.build(values));
    }

    void testCase2() {
        int values_[] = {6, 4, 0, 0, 3, 9, 8, 8};
        vector<int> values(values_, values_ + (sizeof(values_) / sizeof(values_[0])));
        string expected__[] = {"..........", "X.......X.", "X..XX.X.XX"};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(2, expected_, solution.build(values));
    }

    void testCase3() {
        int values_[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> values(values_, values_ + (sizeof(values_) / sizeof(values_[0])));
        string expected__[] = {"..........", "XXXXXXXXXX"};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(3, expected_, solution.build(values));
    }

    void testCase4() {
        int values_[] = {6, 2, 3, 3, 3, 7, 8, 1, 0, 9, 2, 2, 4, 3};
        vector<int> values(values_, values_ + (sizeof(values_) / sizeof(values_[0])));
        string expected__[] = {"..........", "...X......", "..XX......", "..XX......", "XXXXX.XXXX"};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(4, expected_, solution.build(values));
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
        ValueHistogramTest test;
        test.runTest(i);
    }
}
