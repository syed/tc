#include "PartySeats.h"
#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class PartySeatsTest {

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

    PartySeats solution;

    void testCase0() {
        string attendees_[] = {"BOB boy", "SAM girl", "DAVE boy", "JO girl"};
        vector<string> attendees(attendees_, attendees_ + (sizeof(attendees_) / sizeof(attendees_[0])));
        string expected__[] = {"HOST", "JO", "BOB", "HOSTESS", "DAVE", "SAM"};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(0, expected_, solution.seating(attendees));
    }

    void testCase1() {
        string attendees_[] = {"JOHN boy"};
        vector<string> attendees(attendees_, attendees_ + (sizeof(attendees_) / sizeof(attendees_[0])));
        vector<string> expected_;
        assertEquals(1, expected_, solution.seating(attendees));
    }

    void testCase2() {
        string attendees_[] = {"JOHN boy", "CARLA girl"};
        vector<string> attendees(attendees_, attendees_ + (sizeof(attendees_) / sizeof(attendees_[0])));
        vector<string> expected_;
        assertEquals(2, expected_, solution.seating(attendees));
    }

    void testCase3() {
        string attendees_[] = {"BOB boy", "SUZIE girl", "DAVE boy", "JO girl", "AL boy", "BOB boy", "CARLA girl", "DEBBIE girl"};
        vector<string> attendees(attendees_, attendees_ + (sizeof(attendees_) / sizeof(attendees_[0])));
        string expected__[] = {"HOST", "CARLA", "AL", "DEBBIE", "BOB", "HOSTESS", "BOB", "JO", "DAVE", "SUZIE"};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(3, expected_, solution.seating(attendees));
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
        PartySeatsTest test;
        test.runTest(i);
    }
}
