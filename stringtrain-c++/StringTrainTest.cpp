#include "StringTrain.h"
#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class StringTrainTest {

    static void assertEquals(int testCase, const string& expected, const string& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << '"' << expected << '"' << "> but was: <" << '"' << actual << '"' << '>' << endl;
        }
    }

    StringTrain solution;

    void testCase0() {
        string cars_[] = {"ABCDE", "CDFFF", "CDE", "CDEGG", "GABC"};
        vector<string> cars(cars_, cars_ + (sizeof(cars_) / sizeof(cars_[0])));
		string expected_ = "10 DEGABC";
        assertEquals(0, expected_, solution.buildTrain(cars));
    }

    void testCase1() {
        string cars_[] = {"AAAAA", "AAAAA", "AAAAA"};
        vector<string> cars(cars_, cars_ + (sizeof(cars_) / sizeof(cars_[0])));
		string expected_ = "7 A";
        assertEquals(1, expected_, solution.buildTrain(cars));
    }

    void testCase2() {
        string cars_[] = {"CABABDABAB", "CABAB", "ABABDABAB", "DABAB"};
        vector<string> cars(cars_, cars_ + (sizeof(cars_) / sizeof(cars_[0])));
		string expected_ = "15 CDAB";
        assertEquals(2, expected_, solution.buildTrain(cars));
    }

    void testCase3() {
        string cars_[] = {"ABABAB", "ABABAB", "ABABABAB", "BZZZZZ"};
        vector<string> cars(cars_, cars_ + (sizeof(cars_) / sizeof(cars_[0])));
		string expected_ = "15 ABZ";
        assertEquals(3, expected_, solution.buildTrain(cars));
    }

    void testCase4() {
        string cars_[] = {"A", "A", "A", "AA"};
        vector<string> cars(cars_, cars_ + (sizeof(cars_) / sizeof(cars_[0])));
		string expected_ = "1 A";
        assertEquals(4, expected_, solution.buildTrain(cars));
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
        StringTrainTest test;
        test.runTest(i);
    }
}
