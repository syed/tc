#include "BigCube.h"
#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class BigCubeTest {

    static void assertEquals(int testCase, const string& expected, const string& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << '"' << expected << '"' << "> but was: <" << '"' << actual << '"' << '>' << endl;
        }
    }

    BigCube solution;

    void testCase0() {
        string range_[] = {"1-1000000000001"};
        vector<string> range(range_, range_ + (sizeof(range_) / sizeof(range_[0])));
		string expected_ = "1000000000000";
        assertEquals(0, expected_, solution.largestCube(range));
    }

    void testCase1() {
        string range_[] = {"10-999999999999990", "11-999999999999991", "12-999999999999992", "13-999999999999993", "14-999999999999994", "15-999999999999995", "16-999999999999996", "17-999999999999993", "18-999999999999994", "19-999999999999999"};
        vector<string> range(range_, range_ + (sizeof(range_) / sizeof(range_[0])));
		string expected_ = "999970000299999";
        assertEquals(1, expected_, solution.largestCube(range));
    }

    void testCase2() {
        string range_[] = {"0-3", "10-20", "30-60", "80-120"};
        vector<string> range(range_, range_ + (sizeof(range_) / sizeof(range_[0])));
		string expected_ = "1";
        assertEquals(2, expected_, solution.largestCube(range));
    }

    void testCase3() {
        string range_[] = {"999700030000-999999999999", "999400119993-999700029998", "999100269974-999400119991", "998800479937-999100269972"};
        vector<string> range(range_, range_ + (sizeof(range_) / sizeof(range_[0])));
		string expected_ = "";
        assertEquals(3, expected_, solution.largestCube(range));
    }

    void testCase4() {
        string range_[] = {"0-0", "2-2", "3-3", "4-4", "5-5", "6-6", "7-7", "9-9", "10-10", "12-12", "14-14", "16-16", "18-18", "20-20", "22-22", "24-24", "26-26", "28-28", "30-30", "32-32", "34-34", "36-36", "38-38", "40-40", "42-42", "44-44", "46-46", "48-48", "50-50", "52-52", "54-54", "56-56", "58-58", "60-60", "62-62", "65-65", "67-67", "69-69", "71-71", "73-73", "75-75", "77-77", "79-79", "81-81", "83-83", "85-85", "87-87", "89-89", "99-99", "999970000300000-999999999999999"};
        vector<string> range(range_, range_ + (sizeof(range_) / sizeof(range_[0])));
		string expected_ = "0";
        assertEquals(4, expected_, solution.largestCube(range));
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
        BigCubeTest test;
        test.runTest(i);
    }
}
