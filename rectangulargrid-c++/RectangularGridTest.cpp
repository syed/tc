#include "RectangularGrid.h"
#include <iostream>

using std::cerr;
using std::cout;
using std::endl;

class RectangularGridTest {

    static void assertEquals(int testCase, const long long& expected, const long long& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    RectangularGrid solution;

    void testCase0() {
		int width = 3;
		int height = 3;
		long long expected_ = 22LL;
        assertEquals(0, expected_, solution.countRectangles(width, height));
    }

    void testCase1() {
		int width = 5;
		int height = 2;
		long long expected_ = 31LL;
        assertEquals(1, expected_, solution.countRectangles(width, height));
    }

    void testCase2() {
		int width = 10;
		int height = 10;
		long long expected_ = 2640LL;
        assertEquals(2, expected_, solution.countRectangles(width, height));
    }

    void testCase3() {
		int width = 1;
		int height = 1;
		long long expected_ = 0LL;
        assertEquals(3, expected_, solution.countRectangles(width, height));
    }

    void testCase4() {
		int width = 592;
		int height = 964;
		long long expected_ = 81508708664LL;
        assertEquals(4, expected_, solution.countRectangles(width, height));
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
        RectangularGridTest test;
        test.runTest(i);
    }
}
