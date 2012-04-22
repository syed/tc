#include "Intersect.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class IntersectTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    Intersect solution;

    void testCase0() {
        int x_[] = {0, 2, 3, -4};
        vector<int> x(x_, x_ + (sizeof(x_) / sizeof(x_[0])));
        int y_[] = {17, 1000, 18, 6};
        vector<int> y(y_, y_ + (sizeof(y_) / sizeof(y_[0])));
		int expected_ = 2;
        assertEquals(0, expected_, solution.area(x, y));
    }

    void testCase1() {
        int x_[] = {10000, -10000};
        vector<int> x(x_, x_ + (sizeof(x_) / sizeof(x_[0])));
        int y_[] = {-10000, 10000};
        vector<int> y(y_, y_ + (sizeof(y_) / sizeof(y_[0])));
		int expected_ = 400000000;
        assertEquals(1, expected_, solution.area(x, y));
    }

    void testCase2() {
        int x_[] = {3, 8, 6, 12, 10, 15};
        vector<int> x(x_, x_ + (sizeof(x_) / sizeof(x_[0])));
        int y_[] = {7, 17, 7, 17, 7, 17};
        vector<int> y(y_, y_ + (sizeof(y_) / sizeof(y_[0])));
		int expected_ = 0;
        assertEquals(2, expected_, solution.area(x, y));
    }

    void testCase3() {
        int x_[] = {0, 0, 0, 0, 0, 0, 0, 0};
        vector<int> x(x_, x_ + (sizeof(x_) / sizeof(x_[0])));
        int y_[] = {5, 5, 5, 5, 5, 5, 5, 5};
        vector<int> y(y_, y_ + (sizeof(y_) / sizeof(y_[0])));
		int expected_ = 0;
        assertEquals(3, expected_, solution.area(x, y));
    }

    void testCase4() {
        int x_[] = {2, 100, 5, 32, 1000, -20, 47, 12};
        vector<int> x(x_, x_ + (sizeof(x_) / sizeof(x_[0])));
        int y_[] = {29, -1000, -800, -200, -900, 300, -600, -650};
        vector<int> y(y_, y_ + (sizeof(y_) / sizeof(y_[0])));
		int expected_ = 1000;
        assertEquals(4, expected_, solution.area(x, y));
    }

    void testCase5() {
        int x_[] = {1, 7, 12, 3, 16, 8, 3, 12};
        vector<int> x(x_, x_ + (sizeof(x_) / sizeof(x_[0])));
        int y_[] = {-90, -60, -70, 3, -60, -90, -80, -100};
        vector<int> y(y_, y_ + (sizeof(y_) / sizeof(y_[0])));
		int expected_ = 0;
        assertEquals(5, expected_, solution.area(x, y));
    }

//{{3, 8, 6, 12, 10, 15}, {7, 17, 7, 17, 7, 17}}
  //  {{3, 8, 6, 12, 10, 15}, {7, 17, 7, 17, 7, 17}}
    void testCase6() {
        int x_[] = {3, 8, 6, 12, 10, 15};
        vector<int> x(x_, x_ + (sizeof(x_) / sizeof(x_[0])));
        int y_[] = {7, 17, 7, 17, 7, 17};
        vector<int> y(y_, y_ + (sizeof(y_) / sizeof(y_[0])));
		int expected_ = 0;
        assertEquals(6, expected_, solution.area(x, y));
    }

    public: void runTest(int testCase) {
        switch (testCase) {
            case (0): testCase0(); break;
            case (1): testCase1(); break;
            case (2): testCase2(); break;
            case (3): testCase3(); break;
            case (4): testCase4(); break;
            case (5): testCase5(); break;
            case (6): testCase6(); break;
            default: cerr << "No such test case: " << testCase << endl; break;
        }
    }

};
int main() {
    for (int i = 0; i < 7; i++) {
        IntersectTest test;
        test.runTest(i);
    }
}
