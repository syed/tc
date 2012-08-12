#include "WhatSort.h"
#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class WhatSortTest {

    static void assertEquals(int testCase, const string& expected, const string& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << '"' << expected << '"' << "> but was: <" << '"' << actual << '"' << '>' << endl;
        }
    }

    WhatSort solution;

    void testCase0() {
        string name_[] = {"BOB", "BOB", "DAVE", "JOE"};
        vector<string> name(name_, name_ + (sizeof(name_) / sizeof(name_[0])));
        int age_[] = {22, 35, 35, 30};
        vector<int> age(age_, age_ + (sizeof(age_) / sizeof(age_[0])));
        int wt_[] = {122, 122, 195, 200};
        vector<int> wt(wt_, wt_ + (sizeof(wt_) / sizeof(wt_[0])));
		string expected_ = "IND";
        assertEquals(0, expected_, solution.sortType(name, age, wt));
    }

    void testCase1() {
        string name_[] = {"BOB", "BOB", "DAVE", "DAVE"};
        vector<string> name(name_, name_ + (sizeof(name_) / sizeof(name_[0])));
        int age_[] = {22, 35, 35, 30};
        vector<int> age(age_, age_ + (sizeof(age_) / sizeof(age_[0])));
        int wt_[] = {122, 122, 195, 200};
        vector<int> wt(wt_, wt_ + (sizeof(wt_) / sizeof(wt_[0])));
		string expected_ = "NOT";
        assertEquals(1, expected_, solution.sortType(name, age, wt));
    }

    void testCase2() {
        string name_[] = {"BOB", "BOB", "DAVE", "DAVE"};
        vector<string> name(name_, name_ + (sizeof(name_) / sizeof(name_[0])));
        int age_[] = {22, 35, 35, 30};
        vector<int> age(age_, age_ + (sizeof(age_) / sizeof(age_[0])));
        int wt_[] = {122, 122, 195, 190};
        vector<int> wt(wt_, wt_ + (sizeof(wt_) / sizeof(wt_[0])));
		string expected_ = "NWA";
        assertEquals(2, expected_, solution.sortType(name, age, wt));
    }

    public: void runTest(int testCase) {
        switch (testCase) {
            case (0): testCase0(); break;
            case (1): testCase1(); break;
            case (2): testCase2(); break;
            default: cerr << "No such test case: " << testCase << endl; break;
        }
    }

};

int main() {
    for (int i = 0; i < 3; i++) {
        WhatSortTest test;
        test.runTest(i);
    }
}
