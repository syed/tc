#include "BinaryCardinality.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class BinaryCardinalityTest {

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

    BinaryCardinality solution;

    void testCase0() {
        int numbers_[] = {4};
        vector<int> numbers(numbers_, numbers_ + (sizeof(numbers_) / sizeof(numbers_[0])));
        int expected__[] = {4};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(0, expected_, solution.arrange(numbers));
    }

    void testCase1() {
        int numbers_[] = {31, 15, 7, 3, 2};
        vector<int> numbers(numbers_, numbers_ + (sizeof(numbers_) / sizeof(numbers_[0])));
        int expected__[] = {2, 3, 7, 15, 31};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(1, expected_, solution.arrange(numbers));
    }

    void testCase2() {
        int numbers_[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        vector<int> numbers(numbers_, numbers_ + (sizeof(numbers_) / sizeof(numbers_[0])));
        int expected__[] = {1, 2, 4, 8, 3, 5, 6, 9, 10, 7};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(2, expected_, solution.arrange(numbers));
    }

    void testCase3() {
        int numbers_[] = {811385, 340578, 980086, 545001, 774872, 855585, 13848, 863414, 419523, 190151, 784903, 127461};
        vector<int> numbers(numbers_, numbers_ + (sizeof(numbers_) / sizeof(numbers_[0])));
        int expected__[] = {13848, 340578, 545001, 855585, 419523, 811385, 127461, 190151, 774872, 863414, 784903, 980086};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(3, expected_, solution.arrange(numbers));
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
        BinaryCardinalityTest test;
        test.runTest(i);
    }
}
