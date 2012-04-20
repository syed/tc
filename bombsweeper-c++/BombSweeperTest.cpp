#include "BombSweeper.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class BombSweeperTest {

    static void assertEquals(int testCase, double expected, double actual) {
        double delta = max(1e-9, 1e-9 * abs(expected));
        if (abs(expected - actual) <= delta) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout.precision(24);
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    BombSweeper solution;

    void testCase0() {
        string board_[] = {".....", ".....", "..B..", ".....", "....."};
        vector<string> board(board_, board_ + (sizeof(board_) / sizeof(board_[0])));
		double expected_ = 94.11764705882354;
        assertEquals(0, expected_, solution.winPercentage(board));
    }

    void testCase1() {
        string board_[] = {"BBBBB", "B...B", "B...B", "B...B", "BBBBB"};
        vector<string> board(board_, board_ + (sizeof(board_) / sizeof(board_[0])));
		double expected_ = 5.882352941176471;
        assertEquals(1, expected_, solution.winPercentage(board));
    }

    void testCase2() {
        string board_[] = {".........", ".B..B..B.", ".........", ".........", ".B..B..B.", ".........", ".........", ".B..B..B.", "........."};
        vector<string> board(board_, board_ + (sizeof(board_) / sizeof(board_[0])));
		double expected_ = 0.0;
        assertEquals(2, expected_, solution.winPercentage(board));
    }

    void testCase3() {
        string board_[] = {".........................", ".........................", ".........................", "........................."};
        vector<string> board(board_, board_ + (sizeof(board_) / sizeof(board_[0])));
		double expected_ = 100.0;
        assertEquals(3, expected_, solution.winPercentage(board));
    }

    void testCase4() {
        string board_[] = {"......B.......B..B...........................B....", "..............B..................BB..B............", "B.B.B.............B.....B..............B..........", "...................B...B....................BB....", "...B.....B.........................B.......B.....B", "B.B.........B.....B.......B..B......B.B...B.BB....", "..B...................BB...............B..........", ".........B...B................B..B................", ".......BB.......B....B................B.....BBB...", ".......BB..........B..............B......BB.......", "...................BB.....................B.......", "...B.B.B......B..............B...B......B.........", "B................B................................", "....B..........B.....B..BB....B...............BB..", "..B....B.....B.............B.....B............B...", "...................B.B........B..B.........B.B....", ".....B.....B......................................", "...........BB......BB...B.B........B...B..........", ".....BBB..........................................", ".B...........B....B...BB......B......B...B.B......", "..................B........BB................B....", "...............................B..B....BBB.B....B.", "..........B.......................................", ".....B..........B....BB......B.B......B......B....", ".....B..................B........B................", "............B.....B..B....BB...B....BB........B...", "..B.................B.........B...................", ".BB..............B................................", "...B....B..................B.................B....", "......B...B......B......................B.B.......", "..............B..................B.......B........", ".....B........BB...B.....B........................", ".......B......B.B..B..........B...........B....B..", "B...B...........B...B...B......B.B...B..B......B..", "....B..B.....B.B.......BB..B............B.B....B..", "B.......B..........B.........B...B.BB......B......", "....B...............................B.............", ".....B.B..........................................", "..........B............B......B.B..B....B.........", "....B...B.......................B.................", "B.................B...........B..B....B...........", "...B.....B........................................", "...B..B......................................BBB..", ".B...B....................................B....B..", "...B...B..........B...B.B.........................", ".....B.............B...BB..........B..BBB.BB......", "....................B.....B.......................", "........B..BB..........B.B....B...........B......B", ".........B.....BB..B.............B....BB..........", "....B..B..............B...B..B..........B........."};
        vector<string> board(board_, board_ + (sizeof(board_) / sizeof(board_[0])));
		double expected_ = 77.67558528428094;
        assertEquals(4, expected_, solution.winPercentage(board));
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
        BombSweeperTest test;
        test.runTest(i);
    }
}
