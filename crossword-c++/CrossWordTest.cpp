#include "CrossWord.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class CrossWordTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    CrossWord solution;

    void testCase0() {
        string board_[] = {"X....X", "X.XX.X", "...X..", "X.XX.X", "..X..."};
        vector<string> board(board_, board_ + (sizeof(board_) / sizeof(board_[0])));
		int size = 3;
		int expected_ = 2;
        assertEquals(0, expected_, solution.countWords(board, size));
    }

    void testCase1() {
        string board_[] = {"...X...", ".X...X.", "..X.X..", "X..X..X", "..X.X..", ".X...X.", "...X..."};
        vector<string> board(board_, board_ + (sizeof(board_) / sizeof(board_[0])));
		int size = 3;
		int expected_ = 6;
        assertEquals(1, expected_, solution.countWords(board, size));
    }

    void testCase2() {
        string board_[] = {".....X....X....", ".....X....X....", "..........X....", "....X....X.....", "...X....X....XX", "XXX...X....X...", ".....X....X....", ".......X.......", "....X....X.....", "...X....X...XXX", "XX....X....X...", ".....X....X....", "....X..........", "....X....X.....", "....X....X....."};
        vector<string> board(board_, board_ + (sizeof(board_) / sizeof(board_[0])));
		int size = 5;
		int expected_ = 8;
        assertEquals(2, expected_, solution.countWords(board, size));
    }

    void testCase3() {
        string board_[] = {"...", "...", "..."};
        vector<string> board(board_, board_ + (sizeof(board_) / sizeof(board_[0])));
		int size = 50;
		int expected_ = 0;
        assertEquals(3, expected_, solution.countWords(board, size));
    }

    void testCase4() {
        string board_[] = {"....", "....", "...."};
        vector<string> board(board_, board_ + (sizeof(board_) / sizeof(board_[0])));
		int size = 3;
		int expected_ = 0;
        assertEquals(4, expected_, solution.countWords(board, size));
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
        CrossWordTest test;
        test.runTest(i);
    }
}
