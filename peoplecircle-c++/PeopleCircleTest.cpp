#include "PeopleCircle.h"
#include <iostream>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::string;

class PeopleCircleTest {

    static void assertEquals(int testCase, const string& expected, const string& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << '"' << expected << '"' << "> but was: <" << '"' << actual << '"' << '>' << endl;
        }
    }

    PeopleCircle solution;

    void testCase0() {
		int numMales = 5;
		int numFemales = 3;
		int K = 2;
		string expected_ = "MFMFMFMM";
        assertEquals(0, expected_, solution.order(numMales, numFemales, K));
    }

    void testCase1() {
		int numMales = 7;
		int numFemales = 3;
		int K = 1;
		string expected_ = "FFFMMMMMMM";
        assertEquals(1, expected_, solution.order(numMales, numFemales, K));
    }

    void testCase2() {
		int numMales = 25;
		int numFemales = 25;
		int K = 1000;
		string expected_ = "MMMMMFFFFFFMFMFMMMFFMFFFFFFFFFMMMMMMMFFMFMMMFMFMMF";
        assertEquals(2, expected_, solution.order(numMales, numFemales, K));
    }

    void testCase3() {
		int numMales = 5;
		int numFemales = 5;
		int K = 3;
		string expected_ = "MFFMMFFMFM";
        assertEquals(3, expected_, solution.order(numMales, numFemales, K));
    }

    void testCase4() {
		int numMales = 1;
		int numFemales = 0;
		int K = 245;
		string expected_ = "M";
        assertEquals(4, expected_, solution.order(numMales, numFemales, K));
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
        PeopleCircleTest test;
        test.runTest(i);
    }
}
