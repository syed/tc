#include "ThePriceIsRight.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class ThePriceIsRightTest {

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

    ThePriceIsRight solution;

    void testCase0() {
        int prices_[] = {30, 10, 20, 40, 50};
        vector<int> prices(prices_, prices_ + (sizeof(prices_) / sizeof(prices_[0])));
        int expected__[] = {4, 1};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(0, expected_, solution.howManyReveals(prices));
    }

    void testCase1() {
        int prices_[] = {39, 88, 67, 5, 69, 87, 82, 64, 58, 61};
        vector<int> prices(prices_, prices_ + (sizeof(prices_) / sizeof(prices_[0])));
        int expected__[] = {4, 2};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(1, expected_, solution.howManyReveals(prices));
    }

    void testCase2() {
        int prices_[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        vector<int> prices(prices_, prices_ + (sizeof(prices_) / sizeof(prices_[0])));
        int expected__[] = {10, 1};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(2, expected_, solution.howManyReveals(prices));
    }

    void testCase3() {
        int prices_[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        vector<int> prices(prices_, prices_ + (sizeof(prices_) / sizeof(prices_[0])));
        int expected__[] = {1, 10};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(3, expected_, solution.howManyReveals(prices));
    }

    void testCase4() {
        int prices_[] = {29, 31, 73, 70, 14, 5, 6, 34, 53, 30, 15, 86};
        vector<int> prices(prices_, prices_ + (sizeof(prices_) / sizeof(prices_[0])));
        int expected__[] = {5, 2};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(4, expected_, solution.howManyReveals(prices));
    }

    void testCase5() {
        int prices_[] = {100, 99, 1, 2, 3};
        vector<int> prices(prices_, prices_ + (sizeof(prices_) / sizeof(prices_[0])));
        int expected__[] = {3, 1};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(5, expected_, solution.howManyReveals(prices));
    }

    void testCase6() {
        int prices_[] = {10, 20, 11, 12};
        vector<int> prices(prices_, prices_ + (sizeof(prices_) / sizeof(prices_[0])));
        int expected__[] = {3, 1};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(6, expected_, solution.howManyReveals(prices));
    }

    public: void runTest(int testCase) {
        switch (testCase) {
            case (0): testCase0(); break;
            case (1): testCase1(); break;
            case (2): testCase2(); break;
            case (3): testCase3(); break;
            case (4): testCase4(); break;
            case (5): testCase5(); break;
            case (6): testCase6(); break;
            default: cerr << "No such test case: " << testCase << endl; break;
        }
    }

};

int main() {
    for (int i = 0; i < 7; i++) {
        ThePriceIsRightTest test;
        test.runTest(i);
    }
}
