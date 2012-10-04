#include "ProbabilityTree.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class ProbabilityTreeTest {

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

    ProbabilityTree solution;

    void testCase0() {
        string tree_[] = {"40", "0 70 10"};
        vector<string> tree(tree_, tree_ + (sizeof(tree_) / sizeof(tree_[0])));
		int lowerBound = 30;
		int upperBound = 50;
        int expected__[] = {0, 1};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(0, expected_, solution.getOdds(tree, lowerBound, upperBound));
    }

    void testCase1() {
        string tree_[] = {"20", "2 50 50", "0 50 50"};
        vector<string> tree(tree_, tree_ + (sizeof(tree_) / sizeof(tree_[0])));
		int lowerBound = 49;
		int upperBound = 51;
        int expected__[] = {1, 2};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(1, expected_, solution.getOdds(tree, lowerBound, upperBound));
    }

    void testCase2() {
        string tree_[] = {"10", "0 99 41", "1 40 3", "2 91 43"};
        vector<string> tree(tree_, tree_ + (sizeof(tree_) / sizeof(tree_[0])));
		int lowerBound = 81;
		int upperBound = 88;
        vector<int> expected_;
        assertEquals(2, expected_, solution.getOdds(tree, lowerBound, upperBound));
    }

    void testCase3() {
        string tree_[] = {"79", "0 64 52", "1 70 87", "0 38 99", "1 24 8"};
        vector<string> tree(tree_, tree_ + (sizeof(tree_) / sizeof(tree_[0])));
		int lowerBound = 47;
		int upperBound = 81;
        int expected__[] = {0, 1, 2, 3};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(3, expected_, solution.getOdds(tree, lowerBound, upperBound));
    }

    void testCase4() {
        string tree_[] = {"51", "29 58 3", "6 56 86", "18 97 1", "44 99 25", "33 69 90", "27 67 49", "32 15 19", "33 1 21", "45 12 33", "29 24 40", "45 86 74", "40 30 65", "0 18 27", "1 90 65", "0 47 62", "40 81 72", "42 25 56", "45 16 81", "8 94 92", "29 41 92", "24 4 29", "32 56 91", "20 16 77", "1 35 79", "45 77 61", "6 50 19", "20 69 43", "4 6 16", "15 55 26", "42 73 90", "40 8 49", "33 16 33", "15 95 47", "9 66 40", "25 80 39", "35 72 70", "27 10 36", "40 36 10", "32 2 48", "33 44 23", "22 51 45", "25 8 43", "18 32 96", "45 41 74", "0 51 6", "18 48 15"};
        vector<string> tree(tree_, tree_ + (sizeof(tree_) / sizeof(tree_[0])));
		int lowerBound = 8;
		int upperBound = 82;
        int expected__[] = {0, 1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 20, 21, 23, 24, 25, 26, 27, 28, 29, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(4, expected_, solution.getOdds(tree, lowerBound, upperBound));
    }

    void testCase5() {
        string tree_[] = {"98", "0 27 45", "1 87 65", "0 50 89", "2 20 98", "2 54 15", "5 88 60", "1 33 19", "0 36 27", "2 39 32", "7 1 33", "2 55 55", "0 64 72", "6 78 44", "7 16 33", "3 90 99", "12 31 54", "8 21 14", "16 48 53", "2 56 29", "5 44 40", "5 59 84", "10 37 48", "21 65 12", "16 86 37", "4 86 6", "20 27 39", "26 90 86", "21 79 85", "13 37 26", "29 83 35", "18 44 59", "6 5 4", "16 79 25", "29 86 18", "15 60 35", "32 63 15", "33 22 92", "29 46 77"};
        vector<string> tree(tree_, tree_ + (sizeof(tree_) / sizeof(tree_[0])));
		int lowerBound = 48;
		int upperBound = 82;
        int expected__[] = {2, 3, 6, 11, 12, 13, 18, 19, 21, 23, 24, 28, 30, 31, 35, 37, 38};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(5, expected_, solution.getOdds(tree, lowerBound, upperBound));
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
        ProbabilityTreeTest test;
        test.runTest(i);
    }
}
