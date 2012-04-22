#include "Sets.h"
#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class SetsTest {

    static void writeTo(std::ostream& out, const vector<int>& v) {
        out << '{';
        for (unsigned int i = 0; i < v.size(); i++) {
            out << v[i];
            if (i + 1 != v.size()) out << ", ";
        }
        out << '}';
    }

    static void assertEquals(int testCase, const vector<int>& expected, const vector<int>& actual) {
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

    Sets solution;

    void testCase0() {
        int A_[] = {1, 2, 3, 4};
        vector<int> A(A_, A_ + (sizeof(A_) / sizeof(A_[0])));
        int B_[] = {3, 4, 5, 6};
        vector<int> B(B_, B_ + (sizeof(B_) / sizeof(B_[0])));
		string operation = "INTERSECTION";
        int expected__[] = {3, 4};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(0, expected_, solution.operate(A, B, operation));
    }

    void testCase1() {
        int A_[] = {1, 2, 3, 4};
        vector<int> A(A_, A_ + (sizeof(A_) / sizeof(A_[0])));
        int B_[] = {3, 4, 5, 6};
        vector<int> B(B_, B_ + (sizeof(B_) / sizeof(B_[0])));
		string operation = "UNION";
        int expected__[] = {1, 2, 3, 4, 5, 6};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(1, expected_, solution.operate(A, B, operation));
    }

    void testCase2() {
        int A_[] = {432, 756, 123};
        vector<int> A(A_, A_ + (sizeof(A_) / sizeof(A_[0])));
        int B_[] = {534, 76, 1209};
        vector<int> B(B_, B_ + (sizeof(B_) / sizeof(B_[0])));
		string operation = "INTERSECTION";
        vector<int> expected_;
        assertEquals(2, expected_, solution.operate(A, B, operation));
    }

    void testCase3() {
        int A_[] = {6, 5, 7, 4};
        vector<int> A(A_, A_ + (sizeof(A_) / sizeof(A_[0])));
        int B_[] = {7, 6, 4, 10};
        vector<int> B(B_, B_ + (sizeof(B_) / sizeof(B_[0])));
		string operation = "SYMMETRIC DIFFERENCE";
        int expected__[] = {5, 10};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(3, expected_, solution.operate(A, B, operation));
    }

    void testCase4() {
        int A_[] = {342, 654, 897, 312, 76, 23, 78};
        vector<int> A(A_, A_ + (sizeof(A_) / sizeof(A_[0])));
        int B_[] = {21, 43, 87, 98, 23, 756, 897, 234, 645, 876, 123};
        vector<int> B(B_, B_ + (sizeof(B_) / sizeof(B_[0])));
		string operation = "SYMMETRIC DIFFERENCE";
        int expected__[] = {21, 43, 76, 78, 87, 98, 123, 234, 312, 342, 645, 654, 756, 876};
        vector<int> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(4, expected_, solution.operate(A, B, operation));
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
        SetsTest test;
        test.runTest(i);
    }
}
