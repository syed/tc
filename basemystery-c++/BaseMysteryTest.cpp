#include "BaseMystery.h"
#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class BaseMysteryTest {

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

    BaseMystery solution;

    void testCase0() {
		string equation = "1+1=2";
        int expected__[] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(0, expected_, solution.getBase(equation));
    }

    void testCase1() {
		string equation = "1+1=10";
        int expected__[] = {2};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(1, expected_, solution.getBase(equation));
    }

    void testCase2() {
		string equation = "1+1=3";
        vector<int> expected_;
        assertEquals(2, expected_, solution.getBase(equation));
    }

    void testCase3() {
		string equation = "ABCD+211=B000";
        int expected__[] = {14};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(3, expected_, solution.getBase(equation));
    }

    void testCase4() {
		string equation = "ABCD+322=B000";
        int expected__[] = {15};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(4, expected_, solution.getBase(equation));
    }

    void testCase5() {
		string equation = "1+0=1";
        int expected__[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(5, expected_, solution.getBase(equation));
    }

    void testCase6() {
		string equation = "GHIJ+1111=HJ00";
        int expected__[] = {20};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(6, expected_, solution.getBase(equation));
    }

    void testCase7() {
		string equation = "1234+8765=9999";
        int expected__[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(7, expected_, solution.getBase(equation));
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
            case (7): testCase7(); break;
            default: cerr << "No such test case: " << testCase << endl; break;
        }
    }

};

int main() {
    for (int i = 0; i < 8; i++) {
        BaseMysteryTest test;
        test.runTest(i);
    }
}
