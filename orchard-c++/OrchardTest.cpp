#include "Orchard.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class OrchardTest {

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

    Orchard solution;

    void testCase0() {
        string orchard_[] = {"----", "T---", "----", "----"};
        vector<string> orchard(orchard_, orchard_ + (sizeof(orchard_) / sizeof(orchard_[0])));
        int expected__[] = {2, 3};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(0, expected_, solution.nextTree(orchard));
    }

    void testCase1() {
        string orchard_[] = {"---T--", "------", "------", "----T-", "------", "------"};
        vector<string> orchard(orchard_, orchard_ + (sizeof(orchard_) / sizeof(orchard_[0])));
        int expected__[] = {3, 3};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(1, expected_, solution.nextTree(orchard));
    }

    void testCase2() {
        string orchard_[] = {"------------", "------------", "------------", "------------", "------------", "------------", "------------", "------------", "------------", "------------", "------------", "------------"};
        vector<string> orchard(orchard_, orchard_ + (sizeof(orchard_) / sizeof(orchard_[0])));
        int expected__[] = {6, 6};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(2, expected_, solution.nextTree(orchard));
    }

    void testCase3() {
        string orchard_[] = {"-T----T", "T---T--", "-----TT", "---TT--", "T-----T", "-------", "T-T--T-"};
        vector<string> orchard(orchard_, orchard_ + (sizeof(orchard_) / sizeof(orchard_[0])));
        int expected__[] = {2, 3};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(3, expected_, solution.nextTree(orchard));
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
        OrchardTest test;
        test.runTest(i);
    }
}
