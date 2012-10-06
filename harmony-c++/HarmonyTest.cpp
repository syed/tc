#include "Harmony.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class HarmonyTest {

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

    Harmony solution;

    void testCase0() {
        int frequencies_[] = {200, 250, 400, 320, 350};
        vector<int> frequencies(frequencies_, frequencies_ + (sizeof(frequencies_) / sizeof(frequencies_[0])));
        int expected__[] = {200, 250, 400};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(0, expected_, solution.mostHarmonious(frequencies));
    }

    void testCase1() {
        int frequencies_[] = {440, 320, 750, 660, 500, 550};
        vector<int> frequencies(frequencies_, frequencies_ + (sizeof(frequencies_) / sizeof(frequencies_[0])));
        int expected__[] = {440, 550, 660};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(1, expected_, solution.mostHarmonious(frequencies));
    }

    void testCase2() {
        int frequencies_[] = {1960, 1000, 3050, 2341, 7253, 7864, 2000, 2352, 2940, 1534, 7234};
        vector<int> frequencies(frequencies_, frequencies_ + (sizeof(frequencies_) / sizeof(frequencies_[0])));
        int expected__[] = {1960, 2352, 2940};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(2, expected_, solution.mostHarmonious(frequencies));
    }

    void testCase3() {
        int frequencies_[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
        vector<int> frequencies(frequencies_, frequencies_ + (sizeof(frequencies_) / sizeof(frequencies_[0])));
        int expected__[] = {100, 200, 400};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(3, expected_, solution.mostHarmonious(frequencies));
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
        HarmonyTest test;
        test.runTest(i);
    }
}
