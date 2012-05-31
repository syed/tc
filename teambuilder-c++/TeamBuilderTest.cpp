#include "TeamBuilder.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class TeamBuilderTest {

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

    TeamBuilder solution;

    void testCase0() {
        string paths_[] = {"010", "000", "110"};
        vector<string> paths(paths_, paths_ + (sizeof(paths_) / sizeof(paths_[0])));
        int expected__[] = {1, 1};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(0, expected_, solution.specialLocations(paths));
    }

    void testCase1() {
        string paths_[] = {"0010", "1000", "1100", "1000"};
        vector<string> paths(paths_, paths_ + (sizeof(paths_) / sizeof(paths_[0])));
        int expected__[] = {1, 3};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(1, expected_, solution.specialLocations(paths));
    }

    void testCase2() {
        string paths_[] = {"01000", "00100", "00010", "00001", "10000"};
        vector<string> paths(paths_, paths_ + (sizeof(paths_) / sizeof(paths_[0])));
        int expected__[] = {5, 5};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(2, expected_, solution.specialLocations(paths));
    }

    void testCase3() {
        string paths_[] = {"0110000", "1000100", "0000001", "0010000", "0110000", "1000010", "0001000"};
        vector<string> paths(paths_, paths_ + (sizeof(paths_) / sizeof(paths_[0])));
        int expected__[] = {1, 3};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(3, expected_, solution.specialLocations(paths));
    }
//{"0000000", "0001000", "0100100", "0010001", "1000010", "1000000", "0000110"}
    void testCase4() {
        string paths_[] = {"0000000", "0001000", "0100100", "0010001", "1000010", "1000000", "0000110"};
        vector<string> paths(paths_, paths_ + (sizeof(paths_) / sizeof(paths_[0])));
        int expected__[] = {3, 1};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(4, expected_, solution.specialLocations(paths));
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
        TeamBuilderTest test;
        test.runTest(i);
    }
}
