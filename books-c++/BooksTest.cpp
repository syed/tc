#include "Books.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class BooksTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    Books solution;

    void testCase0() {
        string titles_[] = {"Algorithms", "Purely Functional Data Structures", "Intro to C", "Automata and Computability"};
        vector<string> titles(titles_, titles_ + (sizeof(titles_) / sizeof(titles_[0])));
		int expected_ = 2;
        assertEquals(0, expected_, solution.sortMoves(titles));
    }

    void testCase1() {
        string titles_[] = {"the fellowship of the ring", "the return of the king", "The two towers"};
        vector<string> titles(titles_, titles_ + (sizeof(titles_) / sizeof(titles_[0])));
		int expected_ = 1;
        assertEquals(1, expected_, solution.sortMoves(titles));
    }

    void testCase2() {
        string titles_[] = {"Basic Engineering Circuit Analysis", "A Course in Combinatorics", "Artificial Intelligence", "Asimovs Guide to Shakespeare", "The Nature of Space and Time", "A Time for Trumpets", "Essentials of Artificial Intelligence", "Life by the Numbers", "Cognitive Psychology", "ColdFusion"};
        vector<string> titles(titles_, titles_ + (sizeof(titles_) / sizeof(titles_[0])));
		int expected_ = 5;
        assertEquals(2, expected_, solution.sortMoves(titles));
    }

    void testCase3() {
        string titles_[] = {"A", "B", "A", "A", "B"};
        vector<string> titles(titles_, titles_ + (sizeof(titles_) / sizeof(titles_[0])));
		int expected_ = 1;
        assertEquals(3, expected_, solution.sortMoves(titles));
    }

    void testCase4() {
        string titles_[] = {"This Book Has No Title", " This Book Does Have A Title"};
        vector<string> titles(titles_, titles_ + (sizeof(titles_) / sizeof(titles_[0])));
		int expected_ = 1;
        assertEquals(4, expected_, solution.sortMoves(titles));
    }

    void testCase5() {
        string titles_[] = {"What Is The", "What Is The ", "What Is The Title Of This Book"};
        vector<string> titles(titles_, titles_ + (sizeof(titles_) / sizeof(titles_[0])));
		int expected_ = 0;
        assertEquals(5, expected_, solution.sortMoves(titles));
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
        BooksTest test;
        test.runTest(i);
    }
}
