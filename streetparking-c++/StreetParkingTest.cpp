#include "StreetParking.h"
#include <iostream>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::string;

class StreetParkingTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    StreetParking solution;

    void testCase0() {
		string street = "---B--S-D--S--";
		int expected_ = 4;
        assertEquals(0, expected_, solution.freeParks(street));
    }

    void testCase1() {
		string street = "DDBDDBDDBDD";
		int expected_ = 0;
        assertEquals(1, expected_, solution.freeParks(street));
    }

    void testCase2() {
		string street = "--S--S--S--S--";
		int expected_ = 2;
        assertEquals(2, expected_, solution.freeParks(street));
    }

    void testCase3() {
		string street = "SSD-B---BD-DDSB-----S-S--------S-B----BSB-S--B-S-D";
		int expected_ = 14;
        assertEquals(3, expected_, solution.freeParks(street));
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
        StreetParkingTest test;
        test.runTest(i);
    }
}
