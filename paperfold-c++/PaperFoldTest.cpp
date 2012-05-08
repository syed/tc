#include "PaperFold.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class PaperFoldTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    PaperFold solution;

    void testCase0() {
        int paper_[] = {8, 11};
        vector<int> paper(paper_, paper_ + (sizeof(paper_) / sizeof(paper_[0])));
        int box_[] = {6, 10};
        vector<int> box(box_, box_ + (sizeof(box_) / sizeof(box_[0])));
		int expected_ = 1;
        assertEquals(0, expected_, solution.numFolds(paper, box));
    }

    void testCase1() {
        int paper_[] = {11, 17};
        vector<int> paper(paper_, paper_ + (sizeof(paper_) / sizeof(paper_[0])));
        int box_[] = {6, 4};
        vector<int> box(box_, box_ + (sizeof(box_) / sizeof(box_[0])));
		int expected_ = 4;
        assertEquals(1, expected_, solution.numFolds(paper, box));
    }

    void testCase2() {
        int paper_[] = {11, 17};
        vector<int> paper(paper_, paper_ + (sizeof(paper_) / sizeof(paper_[0])));
        int box_[] = {5, 4};
        vector<int> box(box_, box_ + (sizeof(box_) / sizeof(box_[0])));
		int expected_ = 4;
        assertEquals(2, expected_, solution.numFolds(paper, box));
    }

    void testCase3() {
        int paper_[] = {1000, 1000};
        vector<int> paper(paper_, paper_ + (sizeof(paper_) / sizeof(paper_[0])));
        int box_[] = {62, 63};
        vector<int> box(box_, box_ + (sizeof(box_) / sizeof(box_[0])));
		int expected_ = -1;
        assertEquals(3, expected_, solution.numFolds(paper, box));
    }

    void testCase4() {
        int paper_[] = {100, 30};
        vector<int> paper(paper_, paper_ + (sizeof(paper_) / sizeof(paper_[0])));
        int box_[] = {60, 110};
        vector<int> box(box_, box_ + (sizeof(box_) / sizeof(box_[0])));
		int expected_ = 0;
        assertEquals(4, expected_, solution.numFolds(paper, box));
    }

    void testCase5() {
        int paper_[] = {1895, 6416};
        vector<int> paper(paper_, paper_ + (sizeof(paper_) / sizeof(paper_[0])));
        int box_[] = {401, 1000};
        vector<int> box(box_, box_ + (sizeof(box_) / sizeof(box_[0])));
		int expected_ = 5;
        assertEquals(5, expected_, solution.numFolds(paper, box));
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
        PaperFoldTest test;
        test.runTest(i);
    }
}
