#include "InstantRunoff.h"
#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class InstantRunoffTest {

    static void assertEquals(int testCase, const string& expected, const string& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << '"' << expected << '"' << "> but was: <" << '"' << actual << '"' << '>' << endl;
        }
    }

    InstantRunoff solution;

    void testCase0() {
		string candidates = "ABC";
        string ballots_[] = {"ACB", "BCA", "ACB", "BCA", "CBA"};
        vector<string> ballots(ballots_, ballots_ + (sizeof(ballots_) / sizeof(ballots_[0])));
		string expected_ = "B";
        assertEquals(0, expected_, solution.outcome(candidates, ballots));
    }

    void testCase1() {
		string candidates = "DCBA";
        string ballots_[] = {"ACBD", "ACBD", "ACBD", "BCAD", "BCAD", "DBCA", "CBDA"};
        vector<string> ballots(ballots_, ballots_ + (sizeof(ballots_) / sizeof(ballots_[0])));
		string expected_ = "B";
        assertEquals(1, expected_, solution.outcome(candidates, ballots));
    }

    void testCase2() {
		string candidates = "ACB";
        string ballots_[] = {"ACB", "BCA", "ACB", "BCA", "ACB", "BCA", "CBA", "CAB"};
        vector<string> ballots(ballots_, ballots_ + (sizeof(ballots_) / sizeof(ballots_[0])));
		string expected_ = "";
        assertEquals(2, expected_, solution.outcome(candidates, ballots));
    }

    void testCase3() {
		string candidates = "CAB";
        string ballots_[] = {"ACB", "BCA", "ACB", "BCA", "ACB", "BCA", "CAB", "CAB"};
        vector<string> ballots(ballots_, ballots_ + (sizeof(ballots_) / sizeof(ballots_[0])));
		string expected_ = "A";
        assertEquals(3, expected_, solution.outcome(candidates, ballots));
    }

    void testCase4() {
		string candidates = "Z";
        string ballots_[] = {"Z"};
        vector<string> ballots(ballots_, ballots_ + (sizeof(ballots_) / sizeof(ballots_[0])));
		string expected_ = "Z";
        assertEquals(4, expected_, solution.outcome(candidates, ballots));
    }

    void testCase5() {
		string candidates = "PSNJTEHOWC";
        string ballots_[] = {"EJCNTSHOWP", "SJWNTHECOP", "HSJEWCNTPO", "ETJHSWPOCN", "HPEJTSWNCO", "JCNWOTHSPE", "NHSJCTOPWE", "ENWPTCHJSO", "JESOHCTNWP", "EHJNSOWTPC", "NWJCOEHTPS", "ONPWSHCEJT", "HONCSJPWTE", "JPEOTSNWCH", "NOCTEPSWHJ", "TCHOENSJWP"};
        vector<string> ballots(ballots_, ballots_ + (sizeof(ballots_) / sizeof(ballots_[0])));
		string expected_ = "";
        assertEquals(5, expected_, solution.outcome(candidates, ballots));
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
        InstantRunoffTest test;
        test.runTest(i);
    }
}
