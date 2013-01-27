#include "DerivativeSequence.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class DerivativeSequenceTest {

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

    DerivativeSequence solution;

    void testCase0() {
        int a_[] = {5, 6, 3, 9, -1};
        vector<int> a(a_, a_ + (sizeof(a_) / sizeof(a_[0])));
		int n = 1;
        int expected__[] = {1, -3, 6, -10};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(0, expected_, solution.derSeq(a, n));
    }

    void testCase1() {
        int a_[] = {5, 6, 3, 9, -1};
        vector<int> a(a_, a_ + (sizeof(a_) / sizeof(a_[0])));
		int n = 2;
        int expected__[] = {-4, 9, -16};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(1, expected_, solution.derSeq(a, n));
    }

    void testCase2() {
        int a_[] = {5, 6, 3, 9, -1};
        vector<int> a(a_, a_ + (sizeof(a_) / sizeof(a_[0])));
		int n = 4;
        int expected__[] = {-38};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(2, expected_, solution.derSeq(a, n));
    }

    void testCase3() {
        int a_[] = {4, 4, 4, 4, 4, 4, 4, 4};
        vector<int> a(a_, a_ + (sizeof(a_) / sizeof(a_[0])));
		int n = 3;
        int expected__[] = {0, 0, 0, 0, 0};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(3, expected_, solution.derSeq(a, n));
    }

    void testCase4() {
        int a_[] = {-100, 100};
        vector<int> a(a_, a_ + (sizeof(a_) / sizeof(a_[0])));
		int n = 0;
        int expected__[] = {-100, 100};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(4, expected_, solution.derSeq(a, n));
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
        DerivativeSequenceTest test;
        test.runTest(i);
    }
}
