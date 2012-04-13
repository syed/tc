#include "ExerciseMachine.h"
#include <iostream>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::string;

class ExerciseMachineTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    ExerciseMachine solution;

    void testCase0() {
		string time = "00:30:00";
		int expected_ = 99;
        assertEquals(0, expected_, solution.getPercentages(time));
    }

    void testCase1() {
		string time = "00:28:00";
		int expected_ = 19;
        assertEquals(1, expected_, solution.getPercentages(time));
    }

    void testCase2() {
		string time = "23:59:59";
		int expected_ = 0;
        assertEquals(2, expected_, solution.getPercentages(time));
    }

    void testCase3() {
		string time = "00:14:10";
		int expected_ = 49;
        assertEquals(3, expected_, solution.getPercentages(time));
    }

    void testCase4() {
		string time = "00:19:16";
		int expected_ = 3;
        assertEquals(4, expected_, solution.getPercentages(time));
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
        ExerciseMachineTest test;
        test.runTest(i);
    }
}
