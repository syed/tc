#include "BoxLoader.h"
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

class BoxLoaderTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    BoxLoader solution;

    void testCase0() {
		int boxX = 100;
		int boxY = 98;
		int boxZ = 81;
		int itemX = 3;
		int itemY = 5;
		int itemZ = 7;
		int expected_ = 7560;
        assertEquals(0, expected_, solution.mostItems(boxX, boxY, boxZ, itemX, itemY, itemZ));
    }

    void testCase1() {
		int boxX = 10;
		int boxY = 10;
		int boxZ = 10;
		int itemX = 9;
		int itemY = 9;
		int itemZ = 11;
		int expected_ = 0;
        assertEquals(1, expected_, solution.mostItems(boxX, boxY, boxZ, itemX, itemY, itemZ));
    }

    void testCase2() {
		int boxX = 201;
		int boxY = 101;
		int boxZ = 301;
		int itemX = 100;
		int itemY = 30;
		int itemZ = 20;
		int expected_ = 100;
        assertEquals(2, expected_, solution.mostItems(boxX, boxY, boxZ, itemX, itemY, itemZ));
    }

    void testCase3() {
		int boxX = 913;
		int boxY = 687;
		int boxZ = 783;
		int itemX = 109;
		int itemY = 93;
		int itemZ = 53;
		int expected_ = 833;
        assertEquals(3, expected_, solution.mostItems(boxX, boxY, boxZ, itemX, itemY, itemZ));
    }

    void testCase4() {
		int boxX = 6;
		int boxY = 5;
		int boxZ = 4;
		int itemX = 3;
		int itemY = 2;
		int itemZ = 1;
		int expected_ = 20;
        assertEquals(4, expected_, solution.mostItems(boxX, boxY, boxZ, itemX, itemY, itemZ));
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
        BoxLoaderTest test;
        test.runTest(i);
    }
}
