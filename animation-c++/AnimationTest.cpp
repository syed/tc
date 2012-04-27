#include "Animation.h"
#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class AnimationTest {

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

    Animation solution;

    void testCase0() {
		int speed = 2;
		string init = "..R....";
        string expected__[] = {"..X....", "....X..", "......X", "......."};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(0, expected_, solution.animate(speed, init));
    }

    void testCase1() {
		int speed = 3;
		string init = "RR..LRL";
        string expected__[] = {"XX..XXX", ".X.XX..", "X.....X", "......."};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(1, expected_, solution.animate(speed, init));
    }

    void testCase2() {
		int speed = 2;
		string init = "LRLR.LRLR";
        string expected__[] = {"XXXX.XXXX", "X..X.X..X", ".X.X.X.X.", ".X.....X.", "........."};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(2, expected_, solution.animate(speed, init));
    }

    void testCase3() {
		int speed = 10;
		string init = "RLRLRLRLRL";
        string expected__[] = {"XXXXXXXXXX", ".........."};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(3, expected_, solution.animate(speed, init));
    }

    void testCase4() {
		int speed = 1;
		string init = "...";
        string expected__[] = {"..."};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(4, expected_, solution.animate(speed, init));
    }

    void testCase5() {
		int speed = 1;
		string init = "LRRL.LR.LRR.R.LRRL.";
        string expected__[] = {"XXXX.XX.XXX.X.XXXX.", "..XXX..X..XX.X..XX.", ".X.XX.X.X..XX.XX.XX", "X.X.XX...X.XXXXX..X", ".X..XXX...X..XX.X..", "X..X..XX.X.XX.XX.X.", "..X....XX..XX..XX.X", ".X.....XXXX..X..XX.", "X.....X..XX...X..XX", ".....X..X.XX...X..X", "....X..X...XX...X..", "...X..X.....XX...X.", "..X..X.......XX...X", ".X..X.........XX...", "X..X...........XX..", "..X.............XX.", ".X...............XX", "X.................X", "..................."};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(5, expected_, solution.animate(speed, init));
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
        AnimationTest test;
        test.runTest(i);
    }
}
