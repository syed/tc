#include "RPG.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class RPGTest {

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

    RPG solution;

    void testCase0() {
        string dice_[] = {"3d6"};
        vector<string> dice(dice_, dice_ + (sizeof(dice_) / sizeof(dice_[0])));
        int expected__[] = {3, 18, 10};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(0, expected_, solution.dieRolls(dice));
    }

    void testCase1() {
        string dice_[] = {"3d4", "1d6"};
        vector<string> dice(dice_, dice_ + (sizeof(dice_) / sizeof(dice_[0])));
        int expected__[] = {4, 18, 11};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(1, expected_, solution.dieRolls(dice));
    }

    void testCase2() {
        string dice_[] = {"6d5", "10d10", "10d20"};
        vector<string> dice(dice_, dice_ + (sizeof(dice_) / sizeof(dice_[0])));
        int expected__[] = {26, 330, 178};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(2, expected_, solution.dieRolls(dice));
    }

    void testCase3() {
        string dice_[] = {"1d2", "2d2", "4d2", "6d2", "8d2"};
        vector<string> dice(dice_, dice_ + (sizeof(dice_) / sizeof(dice_[0])));
        int expected__[] = {21, 42, 31};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(3, expected_, solution.dieRolls(dice));
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
        RPGTest test;
        test.runTest(i);
    }
}
