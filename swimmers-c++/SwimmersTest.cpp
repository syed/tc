#include "Swimmers.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class SwimmersTest {

    static void writeTo(std::ostream& out, const vector<int>& v) {
        out << '{';
        for (unsigned int i = 0; i < v.size(); i++) {
            out << v[i];
            if (i + 1 != v.size()) out << ", ";
        }
        out << '}';
    }

    static void assertEquals(int testCase, const vector<int>& expected, const vector<int>& actual) {
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

    Swimmers solution;

    void testCase0() {
        int distances_[] = {300, 300, 300};
        vector<int> distances(distances_, distances_ + (sizeof(distances_) / sizeof(distances_[0])));
        int speeds_[] = {1, 2, 3};
        vector<int> speeds(speeds_, speeds_ + (sizeof(speeds_) / sizeof(speeds_[0])));
		int current = 2;
        int expected__[] = {-1, -1, 360};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(0, expected_, solution.getSwimTimes(distances, speeds, current));
    }

    void testCase1() {
        int distances_[] = {500, 500};
        vector<int> distances(distances_, distances_ + (sizeof(distances_) / sizeof(distances_[0])));
        int speeds_[] = {4, 5};
        vector<int> speeds(speeds_, speeds_ + (sizeof(speeds_) / sizeof(speeds_[0])));
		int current = 2;
        int expected__[] = {333, 238};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(1, expected_, solution.getSwimTimes(distances, speeds, current));
    }

    void testCase2() {
        int distances_[] = {0, 0};
        vector<int> distances(distances_, distances_ + (sizeof(distances_) / sizeof(distances_[0])));
        int speeds_[] = {1, 2};
        vector<int> speeds(speeds_, speeds_ + (sizeof(speeds_) / sizeof(speeds_[0])));
		int current = 1;
        int expected__[] = {0, 0};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(2, expected_, solution.getSwimTimes(distances, speeds, current));
    }

    void testCase3() {
        int distances_[] = {0, 1};
        vector<int> distances(distances_, distances_ + (sizeof(distances_) / sizeof(distances_[0])));
        int speeds_[] = {0, 0};
        vector<int> speeds(speeds_, speeds_ + (sizeof(speeds_) / sizeof(speeds_[0])));
		int current = 0;
        int expected__[] = {0, -1};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(3, expected_, solution.getSwimTimes(distances, speeds, current));
    }

    void testCase4() {
        int distances_[] = {7507, 7517, 7523, 7529, 7537, 7541, 7547, 7549, 7559, 7561, 7573, 7577, 7583, 7589, 7591, 7603, 7607, 7621, 7639, 7643, 7649, 7669, 7673, 7681, 7687, 7691, 7699, 7703, 7717, 7723, 7727, 7741, 7753, 7757, 7759, 7789, 7793, 7817, 7823, 7829, 7841, 7853, 7867, 7873, 7877, 7879, 7883, 7901, 7907, 7919};
        vector<int> distances(distances_, distances_ + (sizeof(distances_) / sizeof(distances_[0])));
        int speeds_[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 99, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 51};
        vector<int> speeds(speeds_, speeds_ + (sizeof(speeds_) / sizeof(speeds_[0])));
		int current = 6;
        int expected__[] = {-1, -1, -1, 8108, 1950, 1474, 1014, 882, 705, 544, 507, 420, 377, 359, 328, 290, 260, 252, 229, 216, 210, 195, 185, 173, 159, 155, -1, -1, 4409, 2413, 1717, 1354, 1127, 969, 852, 764, 692, 635, 585, 543, 507, 476, 449, 424, 402, 383, 365, 349, 334, 314};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(4, expected_, solution.getSwimTimes(distances, speeds, current));
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
        SwimmersTest test;
        test.runTest(i);
    }
}
