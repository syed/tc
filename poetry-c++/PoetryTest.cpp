#include "Poetry.h"
#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class PoetryTest {

    static void assertEquals(int testCase, const string& expected, const string& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << '"' << expected << '"' << "> but was: <" << '"' << actual << '"' << '>' << endl;
        }
    }

    Poetry solution;

    void testCase0() {
        string poem_[] = {"I hope this problem", "is a whole lot better than", "this stupid haiku"};
        vector<string> poem(poem_, poem_ + (sizeof(poem_) / sizeof(poem_[0])));
		string expected_ = "abc";
        assertEquals(0, expected_, solution.rhymeScheme(poem));
    }

    void testCase1() {
        string poem_[] = {"     ", "Measure your height", "AND WEIGHT      ", "said the doctor", "", "And make sure to take your pills", "   to   cure   your    ills", "Every", "DAY"};
        vector<string> poem(poem_, poem_ + (sizeof(poem_) / sizeof(poem_[0])));
		string expected_ = " aab ccde";
        assertEquals(1, expected_, solution.rhymeScheme(poem));
    }

    void testCase2() {
        string poem_[] = {"One bright day in the middle of the night", "Two dead boys got up to fight", "Back to back they faced each other", "Drew their swords and shot each other", "", "A deaf policeman heard the noise", "And came to arrest the two dead boys", "And if you dont believe this lie is true", "Ask the blind man he saw it too"};
        vector<string> poem(poem_, poem_ + (sizeof(poem_) / sizeof(poem_[0])));
		string expected_ = "aabb cdef";
        assertEquals(2, expected_, solution.rhymeScheme(poem));
    }

    void testCase3() {
        string poem_[] = {"", "", "", ""};
        vector<string> poem(poem_, poem_ + (sizeof(poem_) / sizeof(poem_[0])));
		string expected_ = "    ";
        assertEquals(3, expected_, solution.rhymeScheme(poem));
    }

    void testCase4() {
        string poem_[] = {"This poem has uppercase letters", "In its rhyme scheme", "Alpha", "Blaster", "Cat", "Desert", "Elephant", "Frog", "Gulch", "Horse", "Ireland", "Jam", "Krispy Kreme", "Loofah", "Moo", "Narf", "Old", "Pink", "Quash", "Rainbow", "Star", "Tour", "Uvula", "Very", "Will", "Xmas", "Young", "Zed", "deception", "comic", "grout", "oval", "cable", "rob", "steal", "steel", "weak"};
        vector<string> poem(poem_, poem_ + (sizeof(poem_) / sizeof(poem_[0])));
		string expected_ = "abcdefghibjkblmnopqrstcuvwxyzABCbDEFG";
        assertEquals(4, expected_, solution.rhymeScheme(poem));
    }

    void testCase5() {
        string poem_[] = {" ", "     ", "This poem", "         ", " ", " ", "", "Has lots of blank lines", " ", "      ", "                                            ", "         ", " ", "              ", "                                                  ", "  in      it           "};
        vector<string> poem(poem_, poem_ + (sizeof(poem_) / sizeof(poem_[0])));
		string expected_ = "  a    b       c";
        assertEquals(5, expected_, solution.rhymeScheme(poem));
    }

    void testCase6() {
        string poem_[] = {"too bad   your", "     solution went   sour"};
        vector<string> poem(poem_, poem_ + (sizeof(poem_) / sizeof(poem_[0])));
		string expected_ = "aa";
        assertEquals(6, expected_, solution.rhymeScheme(poem));
    }

    public: void runTest(int testCase) {
        switch (testCase) {
            case (0): testCase0(); break;
            case (1): testCase1(); break;
            case (2): testCase2(); break;
            case (3): testCase3(); break;
            case (4): testCase4(); break;
            case (5): testCase5(); break;
            case (6): testCase6(); break;
            default: cerr << "No such test case: " << testCase << endl; break;
        }
    }

};

int main() {
    for (int i = 0; i < 7; i++) {
        PoetryTest test;
        test.runTest(i);
    }
}
