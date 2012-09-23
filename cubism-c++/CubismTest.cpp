#include "Cubism.h"
#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class CubismTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    Cubism solution;

    void testCase0() {
        string lattice_[] = {"BBBBBWWWBWWWBWWW", "BWWWWWWWWWWWWWWW", "BWWWWWWWWWWWWWWW", "BWWWWWWWWWWWWWWW"};
        vector<string> lattice(lattice_, lattice_ + (sizeof(lattice_) / sizeof(lattice_[0])));
		string color = "black";
		int expected_ = 3;
        assertEquals(0, expected_, solution.lines(lattice, color));
    }

    void testCase1() {
        string lattice_[] = {"BWWWWWWWWWWWWWWW", "WWWWWBWWWWWWWWWW", "WWWWWWWWWWBWWWWW", "WWWWWWWWWWWWWWWB"};
        vector<string> lattice(lattice_, lattice_ + (sizeof(lattice_) / sizeof(lattice_[0])));
		string color = "black";
		int expected_ = 1;
        assertEquals(1, expected_, solution.lines(lattice, color));
    }

    void testCase2() {
        string lattice_[] = {"WWWWWWWWWWWWWWWW", "WWWWWWWWWWWWWWWW", "WWWWWWWWWWWWWWWW", "WWWWWWWWWWWWWWWW"};
        vector<string> lattice(lattice_, lattice_ + (sizeof(lattice_) / sizeof(lattice_[0])));
		string color = "black";
		int expected_ = 0;
        assertEquals(2, expected_, solution.lines(lattice, color));
    }

    void testCase3() {
        string lattice_[] = {"WWWWWWWWWWWWWWWW", "WWWWWWWWWWWWWWWW", "WWWWWWWWWWWWWWWW", "WWWWWWWWWWWWWWWW"};
        vector<string> lattice(lattice_, lattice_ + (sizeof(lattice_) / sizeof(lattice_[0])));
		string color = "white";
		int expected_ = 76;
        assertEquals(3, expected_, solution.lines(lattice, color));
    }

    void testCase4() {
        string lattice_[] = {"WWWWWWWWWBWWWWWW", "WWWBWWWWWWWWWWWW", "WWWWWWWWWWWWBWWW", "WWWBWWWWWWWWWWWW"};
        vector<string> lattice(lattice_, lattice_ + (sizeof(lattice_) / sizeof(lattice_[0])));
		string color = "white";
		int expected_ = 58;
        assertEquals(4, expected_, solution.lines(lattice, color));
    }

    void testCase5() {
        string lattice_[] = {"BWBWBWBWBWBWBWBW", "BWBWBWBWBWBWBWBW", "BWBWBWBWBWBWBWBW", "BWBWBWBWBWBWBWBW"};
        vector<string> lattice(lattice_, lattice_ + (sizeof(lattice_) / sizeof(lattice_[0])));
		string color = "white";
		int expected_ = 20;
        assertEquals(5, expected_, solution.lines(lattice, color));
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
        CubismTest test;
        test.runTest(i);
    }
}
