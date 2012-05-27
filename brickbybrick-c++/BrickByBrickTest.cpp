#include "BrickByBrick.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class BrickByBrickTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    BrickByBrick solution;

    void testCase0() {
        string map_[] = {".B", "BB"};
        vector<string> map(map_, map_ + (sizeof(map_) / sizeof(map_[0])));
		int expected_ = 6;
        assertEquals(0, expected_, solution.timeToClear(map));
    }

    void testCase1() {
        string map_[] = {".BB", "BBB", "BBB"};
        vector<string> map(map_, map_ + (sizeof(map_) / sizeof(map_[0])));
		int expected_ = -1;
        assertEquals(1, expected_, solution.timeToClear(map));
    }

    void testCase2() {
        string map_[] = {"......B", "###.###", "B.....B"};
        vector<string> map(map_, map_ + (sizeof(map_) / sizeof(map_[0])));
		int expected_ = 35;
        assertEquals(2, expected_, solution.timeToClear(map));
    }

    void testCase3() {
        string map_[] = {"..BBB...", ".#BB..#.", "B.#B.B..", "B.B.....", "##.B.B#.", "#BB.#.B.", "B..B.BB.", "#..BB..B", ".B....#."};
        vector<string> map(map_, map_ + (sizeof(map_) / sizeof(map_[0])));
		int expected_ = -1;
        assertEquals(3, expected_, solution.timeToClear(map));
    }

    void testCase4() {
        string map_[] = {".BB..BBB.B...", "B.B...B..BB..", "#B...B#B.....", "B#B.B##...##B", "BB.B#.B##B.B#", "B.B#.BBB.BB#B", "B#BBB##.#B#B.", "B#BB.BBB#BB.#"};
        vector<string> map(map_, map_ + (sizeof(map_) / sizeof(map_[0])));
		int expected_ = 3912;
        assertEquals(4, expected_, solution.timeToClear(map));
    }

    void testCase5() {
        string map_[] = {".BBBBBBBBBBBBBB", "##############B", "BBBBBBBBBBBBBBB", "B##############", "BBBBBBBBBBBBBBB", "##############B", "BBBBBBBBBBBBBBB", "B##############", "BBBBBBBBBBBBBBB", "##############B", "BBBBBBBBBBBBBBB", "B##############", "BBBBBBBBBBBBBBB", "##############B", "BBBBBBBBBBBBBBB"};
        vector<string> map(map_, map_ + (sizeof(map_) / sizeof(map_[0])));
		int expected_ = 31753;
        assertEquals(5, expected_, solution.timeToClear(map));
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
    for (int i = 2; i < 3; i++) {
        BrickByBrickTest test;
        test.runTest(i);
    }
}
