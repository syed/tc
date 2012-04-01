#include "FallingCoconuts.h"
#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class FallingCoconutsTest {

    static void writeTo(std::ostream& out, const vector<string>& v) {
        out << '{';
        for (unsigned int i = 0; i < v.size(); i++) {
            out << '"' << v[i] << '"';
            if (i + 1 != v.size()) out << ", ";
        }
        out << '}';
    }

    static void assertEquals(int testCase, const vector<string>& expected, const vector<string>& actual) {
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

    FallingCoconuts solution;

    void testCase0() {
        int drops_[] = {8, 9, 10, 11, 12, 8, 12, 10};
        vector<int> drops(drops_, drops_ + (sizeof(drops_) / sizeof(drops_[0])));
        string expected__[] = {"OOOOOOO", "---O---"};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(0, expected_, solution.harvest(drops));
    }

    void testCase1() {
        int drops_[] = {5, 20, 5, 20, 5, 6, 7};
        vector<int> drops(drops_, drops_ + (sizeof(drops_) / sizeof(drops_[0])));
        string expected__[] = {"OOOOO-----------OO"};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(1, expected_, solution.harvest(drops));
    }

    void testCase2() {
        int drops_[] = {6, 8, 10, 7, 9, 8, 8, 8, 8, 8};
        vector<int> drops(drops_, drops_ + (sizeof(drops_) / sizeof(drops_[0])));
        string expected__[] = {"OOOOOO", "-OOO--", "--O---"};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(2, expected_, solution.harvest(drops));
    }

    void testCase3() {
        int drops_[] = {0, 0, 0, 0};
        vector<int> drops(drops_, drops_ + (sizeof(drops_) / sizeof(drops_[0])));
        string expected__[] = {"OOO", "-O-"};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(3, expected_, solution.harvest(drops));
    }

    void testCase4() {
        int drops_[] = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5};
        vector<int> drops(drops_, drops_ + (sizeof(drops_) / sizeof(drops_[0])));
        string expected__[] = {"OOOOOOOOOOOO", "-OOOOOOOOOO-", "--OOOOOOOO--", "---OOOOOO---", "----OOOO----", "-----OO-----"};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(4, expected_, solution.harvest(drops));
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
        FallingCoconutsTest test;
        test.runTest(i);
    }
}
