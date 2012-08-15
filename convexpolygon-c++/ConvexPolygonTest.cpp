#include "ConvexPolygon.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class ConvexPolygonTest {

    static void assertEquals(int testCase, double expected, double actual) {
        double delta = max(1e-9, 1e-9 * abs(expected));
        if (abs(expected - actual) <= delta) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout.precision(24);
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    ConvexPolygon solution;

    void testCase0() {
        int x_[] = {0, 0, 1};
        vector<int> x(x_, x_ + (sizeof(x_) / sizeof(x_[0])));
        int y_[] = {0, 1, 0};
        vector<int> y(y_, y_ + (sizeof(y_) / sizeof(y_[0])));
		double expected_ = 0.5;
        assertEquals(0, expected_, solution.findArea(x, y));
    }

    void testCase1() {
        int x_[] = {-10000, -10000, 10000, 10000};
        vector<int> x(x_, x_ + (sizeof(x_) / sizeof(x_[0])));
        int y_[] = {10000, -10000, -10000, 10000};
        vector<int> y(y_, y_ + (sizeof(y_) / sizeof(y_[0])));
		double expected_ = 4.0E8;
        assertEquals(1, expected_, solution.findArea(x, y));
    }

    void testCase2() {
        int x_[] = {100, 80, 30, -30, -80, -100, -80, -30, 30, 80};
        vector<int> x(x_, x_ + (sizeof(x_) / sizeof(x_[0])));
        int y_[] = {0, 58, 95, 95, 58, 0, -58, -95, -95, -58};
        vector<int> y(y_, y_ + (sizeof(y_) / sizeof(y_[0])));
		double expected_ = 29020.0;
        assertEquals(2, expected_, solution.findArea(x, y));
    }

    void testCase3() {
        int x_[] = {-1646, -9172, -9830, -9802, -9749, -9474, -8668, -6832, 120, 8380, 9338, 9307, 8042};
        vector<int> x(x_, x_ + (sizeof(x_) / sizeof(x_[0])));
        int y_[] = {-9998, -8619, -7863, 3976, 4541, 5975, 8127, 9500, 9612, 8734, 5216, -9042, -9689};
        vector<int> y(y_, y_ + (sizeof(y_) / sizeof(y_[0])));
		double expected_ = 3.55115104E8;
        assertEquals(3, expected_, solution.findArea(x, y));
    }

    void testCase4() {
        int x_[] = {-6010, -7937, -8782, -9506, -9654, -9852, -9854, -9998, -9999, -9996, -9901, -9811, -9444, -8798, -8580, -2085, 6842, 8339, 9827, 9946, 9993, 9959, 9940, 9855, 9657, 8504, 8262, 7552, 6326, 5537, 4723};
        vector<int> x(x_, x_ + (sizeof(x_) / sizeof(x_[0])));
        int y_[] = {-9976, -9947, -9873, -9739, -9654, -8501, -8475, -5009, 475, 4926, 7078, 8673, 9417, 9785, 9820, 9974, 9986, 9979, 9862, 9211, -5070, -6599, -7121, -8624, -8912, -9710, -9766, -9863, -9914, -9941, -9962};
        vector<int> y(y_, y_ + (sizeof(y_) / sizeof(y_[0])));
		double expected_ = 3.939960635E8;
        assertEquals(4, expected_, solution.findArea(x, y));
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
        ConvexPolygonTest test;
        test.runTest(i);
    }
}
