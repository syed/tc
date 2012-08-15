#include "PickTeam.h"
#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class PickTeamTest {

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

    PickTeam solution;

    void testCase0() {
		int teamSize = 3;
        string people_[] = {"ALICE 0 1 -1 3", "BOB 1 0 2 -4", "CAROL -1 2 0 2", "DAVID 3 -4 2 0"};
        vector<string> people(people_, people_ + (sizeof(people_) / sizeof(people_[0])));
        string expected__[] = {"ALICE", "CAROL", "DAVID"};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(0, expected_, solution.pickPeople(teamSize, people));
    }

    void testCase1() {
		int teamSize = 2;
        string people_[] = {"ALICE 0 1 -1 3", "BOB 1 0 2 -4", "CAROL -1 2 0 2", "DAVID 3 -4 2 0"};
        vector<string> people(people_, people_ + (sizeof(people_) / sizeof(people_[0])));
        string expected__[] = {"ALICE", "DAVID"};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(1, expected_, solution.pickPeople(teamSize, people));
    }

    void testCase2() {
		int teamSize = 2;
        string people_[] = {"A 0 -2 -2", "B -2 0 -1", "C -2 -1 0"};
        vector<string> people(people_, people_ + (sizeof(people_) / sizeof(people_[0])));
        string expected__[] = {"B", "C"};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(2, expected_, solution.pickPeople(teamSize, people));
    }

    void testCase3() {
		int teamSize = 13;
        string people_[] = {"A 0 2 8 7 1 -4 -3 1 8 2 8 2 1 -3 7 1 3 9 -6 -5", "A 2 0 0 7 -7 -5 8 -8 -9 -9 6 -9 -4 -8 8 1 7 0 3 3", "A 8 0 0 -5 -5 -7 1 -3 1 9 -6 6 1 5 6 -9 8 6 -8 -8", "A 7 7 -5 0 7 -5 3 9 8 3 -6 -5 -5 2 -6 2 -2 -1 -2 8", "B 1 -7 -5 7 0 7 -2 -9 3 7 0 -2 1 1 -9 -3 -2 2 1 -2", "B -4 -5 -7 -5 7 0 4 8 6 0 -1 4 1 -2 -9 4 0 -7 6 -2", "B -3 8 1 3 -2 4 0 8 -1 1 -2 -7 5 0 -6 9 0 -3 1 3", "B 1 -8 -3 9 -9 8 8 0 0 -2 5 0 5 8 3 5 2 4 5 4", "C 8 -9 1 8 3 6 -1 0 0 8 -3 8 -6 -4 7 -4 1 -5 5 4", "C 2 -9 9 3 7 0 1 -2 8 0 -9 -6 6 5 -8 -3 -8 2 2 4", "C 8 6 -6 -6 0 -1 -2 5 -3 -9 0 2 7 8 2 -6 -4 -6 4 4", "C 2 -9 6 -5 -2 4 -7 0 8 -6 2 0 0 -3 6 7 -1 2 -4 -2", "D 1 -4 1 -5 1 1 5 5 -6 6 7 0 0 -7 -4 8 -6 -3 4 -6", "D -3 -8 5 2 1 -2 0 8 -4 5 8 -3 -7 0 7 -3 5 -8 5 1", "D 7 8 6 -6 -9 -9 -6 3 7 -8 2 6 -4 7 0 9 -5 -5 -8 3", "D 1 1 -9 2 -3 4 9 5 -4 -3 -6 7 8 -3 9 0 -2 -7 8 -7", "E 3 7 8 -2 -2 0 0 2 1 -8 -4 -1 -6 5 -5 -2 0 6 0 5", "E 9 0 6 -1 2 -7 -3 4 -5 2 -6 2 -3 -8 -5 -7 6 0 4 8", "E -6 3 -8 -2 1 6 1 5 5 2 4 -4 4 5 -8 8 0 4 0 1", "E -5 3 -8 8 -2 -2 3 4 4 4 4 -2 -6 1 3 -7 5 8 1 0"};
        vector<string> people(people_, people_ + (sizeof(people_) / sizeof(people_[0])));
        string expected__[] = {"A", "A", "B", "B", "B", "B", "C", "C", "C", "D", "D", "D", "E"};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(3, expected_, solution.pickPeople(teamSize, people));
    }
    void testCase4() {
		int teamSize = 4;
		string people_[] = { "YAX 0 -272 98 -974 -548", "VHT -272 0 -294 -844 783", "CGNA 98 -294 0 131 -740", "UYTPP -974 -844 131 0 -125", "GVTWWJ -548 783 -740 -125 0"};
        vector<string> people(people_, people_ + (sizeof(people_) / sizeof(people_[0])));
        string expected__[] = {"CGNA", "GVTWWJ", "VHT", "YAX"};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(4, expected_, solution.pickPeople(teamSize, people));
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
        PickTeamTest test;
        test.runTest(i);
    }
}
