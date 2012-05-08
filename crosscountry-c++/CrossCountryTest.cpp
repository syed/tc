#include "CrossCountry.h"
#include <iostream>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::string;

class CrossCountryTest {

    static void assertEquals(int testCase, const string& expected, const string& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << '"' << expected << '"' << "> but was: <" << '"' << actual << '"' << '>' << endl;
        }
    }

    CrossCountry solution;

    void testCase0() {
		int numTeams = 2;
		string finishOrder = "AABBABBABBA";
		string expected_ = "AB";
        assertEquals(0, expected_, solution.scoreMeet(numTeams, finishOrder));
    }

    void testCase1() {
		int numTeams = 3;
		string finishOrder = "CCCBBBBBAAACC";
		string expected_ = "BC";
        assertEquals(1, expected_, solution.scoreMeet(numTeams, finishOrder));
    }

    void testCase2() {
		int numTeams = 4;
		string finishOrder = "ABDCBADBDCCDBCDBCAAAC";
		string expected_ = "BDCA";
        assertEquals(2, expected_, solution.scoreMeet(numTeams, finishOrder));
    }

    void testCase3() {
		int numTeams = 10;
		string finishOrder = "BDHCEAJBIDBCCHGCBDJEBAAHEGAGGADHGIECJEHAEBDADJCDHG";
		string expected_ = "BCDAHEG";
        assertEquals(3, expected_, solution.scoreMeet(numTeams, finishOrder));
    }

    void testCase4() {
		int numTeams = 3;
		string finishOrder = "BABCAABABAB";
		string expected_ = "AB";
        assertEquals(4, expected_, solution.scoreMeet(numTeams, finishOrder));
    }
    void testCase5() {
		int numTeams = 3;
		string finishOrder = "ABBABAACBBAB";
		string expected_ = "BA";
        assertEquals(5, expected_, solution.scoreMeet(numTeams, finishOrder));
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
        CrossCountryTest test;
        test.runTest(i);
    }
}
