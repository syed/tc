#include "RaceApproximator.h"
#include <iostream>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::string;

class RaceApproximatorTest {

    static void assertEquals(int testCase, const string& expected, const string& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << '"' << expected << '"' << "> but was: <" << '"' << actual << '"' << '>' << endl;
        }
    }

    RaceApproximator solution;

    void testCase0() {
		int d1 = 800;
		int t1 = 118;
		int d2 = 5000;
		int t2 = 906;
		int raceDistance = 1500;
		string expected_ = "0:03:57";
        assertEquals(0, expected_, solution.timeToBeat(d1, t1, d2, t2, raceDistance));
    }

    void testCase1() {
		int d1 = 400;
		int t1 = 65;
		int d2 = 1600;
		int t2 = 350;
		int raceDistance = 800;
		string expected_ = "0:02:30";
        assertEquals(1, expected_, solution.timeToBeat(d1, t1, d2, t2, raceDistance));
    }

    void testCase2() {
		int d1 = 1600;
		int t1 = 299;
		int d2 = 10000;
		int t2 = 2360;
		int raceDistance = 5000;
		string expected_ = "0:18:00";
        assertEquals(2, expected_, solution.timeToBeat(d1, t1, d2, t2, raceDistance));
    }

    void testCase3() {
		int d1 = 100;
		int t1 = 17;
		int d2 = 10000;
		int t2 = 4500;
		int raceDistance = 9000;
		string expected_ = "1:06:00";
        assertEquals(3, expected_, solution.timeToBeat(d1, t1, d2, t2, raceDistance));
    }

    void testCase4() {
		int d1 = 156;
		int t1 = 117;
		int d2 = 3863;
		int t2 = 2754;
		int raceDistance = 1755;
		string expected_ = "0:21:06";
        assertEquals(4, expected_, solution.timeToBeat(d1, t1, d2, t2, raceDistance));
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
        RaceApproximatorTest test;
        test.runTest(i);
    }
}
