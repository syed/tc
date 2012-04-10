#include "RGBColor.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class RGBColorTest {

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

    RGBColor solution;

    void testCase0() {
        int rgb_[] = {255, 0, 0};
        vector<int> rgb(rgb_, rgb_ + (sizeof(rgb_) / sizeof(rgb_[0])));
        int expected__[] = {0, 255, 255};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(0, expected_, solution.getComplement(rgb));
    }

    void testCase1() {
        int rgb_[] = {115, 115, 143};
        vector<int> rgb(rgb_, rgb_ + (sizeof(rgb_) / sizeof(rgb_[0])));
        int expected__[] = {243, 243, 15};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(1, expected_, solution.getComplement(rgb));
    }

    void testCase2() {
        int rgb_[] = {115, 115, 144};
        vector<int> rgb(rgb_, rgb_ + (sizeof(rgb_) / sizeof(rgb_[0])));
        int expected__[] = {140, 140, 111};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(2, expected_, solution.getComplement(rgb));
    }

    void testCase3() {
        int rgb_[] = {153, 12, 55};
        vector<int> rgb(rgb_, rgb_ + (sizeof(rgb_) / sizeof(rgb_[0])));
        int expected__[] = {102, 243, 200};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(3, expected_, solution.getComplement(rgb));
    }

    public: void runTest(int testCase) {
        switch (testCase) {
            case (0): testCase0(); break;
            case (1): testCase1(); break;
            case (2): testCase2(); break;
            case (3): testCase3(); break;
            default: cerr << "No such test case: " << testCase << endl; break;
        }
    }

};

int main() {
    for (int i = 0; i < 4; i++) {
        RGBColorTest test;
        test.runTest(i);
    }
}
