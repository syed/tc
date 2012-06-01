#include "PaternityTest.h"
#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class PaternityTestTest {

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

    PaternityTest solution;

    void testCase0() {
		string child = "ABCD";
		string mother = "AXCY";
        string men_[] = {"SBTD", "QRCD"};
        vector<string> men(men_, men_ + (sizeof(men_) / sizeof(men_[0])));
        int expected__[] = {0};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(0, expected_, solution.possibleFathers(child, mother, men));
    }

    void testCase1() {
		string child = "ABCD";
		string mother = "ABCX";
        string men_[] = {"ABCY", "ASTD", "QBCD"};
        vector<string> men(men_, men_ + (sizeof(men_) / sizeof(men_[0])));
        int expected__[] = {1, 2};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(1, expected_, solution.possibleFathers(child, mother, men));
    }

    void testCase2() {
		string child = "ABABAB";
		string mother = "ABABAB";
        string men_[] = {"ABABAB", "ABABCC", "ABCCDD", "CCDDEE"};
        vector<string> men(men_, men_ + (sizeof(men_) / sizeof(men_[0])));
        int expected__[] = {0, 1};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(2, expected_, solution.possibleFathers(child, mother, men));
    }

    void testCase3() {
		string child = "YZGLSYQT";
		string mother = "YUQRWYQT";
        string men_[] = {"YZQLDPWT", "BZELSWQM", "OZGPSFKT", "GZTKFYQT", "WQJLSMQT"};
        vector<string> men(men_, men_ + (sizeof(men_) / sizeof(men_[0])));
        vector<int> expected_;
        assertEquals(3, expected_, solution.possibleFathers(child, mother, men));
    }

    void testCase4() {
		string child = "WXETPYCHUWSQEMKKYNVP";
		string mother = "AXQTUQVAUOSQEEKCYNVP";
        string men_[] = {"WNELPYCHXWXPCMNKDDXD", "WFEEPYCHFWDNPMKKALIW", "WSEFPYCHEWEFGMPKIQCK", "WAEXPYCHAWEQXMSKYARN", "WKEXPYCHYWLLFMGKKFBB"};
        vector<string> men(men_, men_ + (sizeof(men_) / sizeof(men_[0])));
        int expected__[] = {1, 3};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(4, expected_, solution.possibleFathers(child, mother, men));
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
        PaternityTestTest test;
        test.runTest(i);
    }
}
