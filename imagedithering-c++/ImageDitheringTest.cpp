#include "ImageDithering.h"
#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class ImageDitheringTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    ImageDithering solution;

    void testCase0() {
		string dithered = "BW";
        string screen_[] = {"AAAAAAAA", "ABWBWBWA", "AWBWBWBA", "ABWBWBWA", "AWBWBWBA", "AAAAAAAA"};
        vector<string> screen(screen_, screen_ + (sizeof(screen_) / sizeof(screen_[0])));
		int expected_ = 24;
        assertEquals(0, expected_, solution.count(dithered, screen));
    }

    void testCase1() {
		string dithered = "BW";
        string screen_[] = {"BBBBBBBB", "BBWBWBWB", "BWBWBWBB", "BBWBWBWB", "BWBWBWBB", "BBBBBBBB"};
        vector<string> screen(screen_, screen_ + (sizeof(screen_) / sizeof(screen_[0])));
		int expected_ = 48;
        assertEquals(1, expected_, solution.count(dithered, screen));
    }

    void testCase2() {
		string dithered = "ACEGIKMOQSUWY";
        string screen_[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX", "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX", "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX", "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX", "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX", "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX"};
        vector<string> screen(screen_, screen_ + (sizeof(screen_) / sizeof(screen_[0])));
		int expected_ = 150;
        assertEquals(2, expected_, solution.count(dithered, screen));
    }

    void testCase3() {
		string dithered = "CA";
        string screen_[] = {"BBBBBBB", "BBBBBBB", "BBBBBBB"};
        vector<string> screen(screen_, screen_ + (sizeof(screen_) / sizeof(screen_[0])));
		int expected_ = 0;
        assertEquals(3, expected_, solution.count(dithered, screen));
    }

    void testCase4() {
		string dithered = "DCBA";
        string screen_[] = {"ACBD"};
        vector<string> screen(screen_, screen_ + (sizeof(screen_) / sizeof(screen_[0])));
		int expected_ = 4;
        assertEquals(4, expected_, solution.count(dithered, screen));
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
        ImageDitheringTest test;
        test.runTest(i);
    }
}
