#include "CardCount.h"
#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class CardCountTest {

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

    CardCount solution;

    void testCase0() {
		int numPlayers = 6;
		string deck = "012345012345012345";
        string expected__[] = {"000", "111", "222", "333", "444", "555"};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(0, expected_, solution.dealHands(numPlayers, deck));
    }

    void testCase1() {
		int numPlayers = 4;
		string deck = "111122223333";
        string expected__[] = {"123", "123", "123", "123"};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(1, expected_, solution.dealHands(numPlayers, deck));
    }

    void testCase2() {
		int numPlayers = 1;
		string deck = "012345012345012345";
        string expected__[] = {"012345012345012345"};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(2, expected_, solution.dealHands(numPlayers, deck));
    }

    void testCase3() {
		int numPlayers = 6;
		string deck = "01234";
        string expected__[] = {"", "", "", "", "", ""};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(3, expected_, solution.dealHands(numPlayers, deck));
    }

    void testCase4() {
		int numPlayers = 2;
		string deck = "";
        string expected__[] = {"", ""};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(4, expected_, solution.dealHands(numPlayers, deck));
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
        CardCountTest test;
        test.runTest(i);
    }
}
