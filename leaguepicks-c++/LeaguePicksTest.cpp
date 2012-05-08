#include "LeaguePicks.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class LeaguePicksTest {

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

    LeaguePicks solution;

    void testCase0() {
		int position = 3;
		int friends = 6;
		int picks = 15;
        int expected__[] = {3, 10, 15};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(0, expected_, solution.returnPicks(position, friends, picks));
    }

    void testCase1() {
		int position = 1;
		int friends = 1;
		int picks = 10;
        int expected__[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(1, expected_, solution.returnPicks(position, friends, picks));
    }

    void testCase2() {
		int position = 1;
		int friends = 2;
		int picks = 39;
        int expected__[] = {1, 4, 5, 8, 9, 12, 13, 16, 17, 20, 21, 24, 25, 28, 29, 32, 33, 36, 37};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(2, expected_, solution.returnPicks(position, friends, picks));
    }

    void testCase3() {
		int position = 5;
		int friends = 11;
		int picks = 100;
        int expected__[] = {5, 18, 27, 40, 49, 62, 71, 84, 93};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(3, expected_, solution.returnPicks(position, friends, picks));
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
        LeaguePicksTest test;
        test.runTest(i);
    }
}
