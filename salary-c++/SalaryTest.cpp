#include "Salary.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class SalaryTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    Salary solution;

    void testCase0() {
        string arrival_[] = {"08:00:00", "13:00:00", "19:27:32"};
        vector<string> arrival(arrival_, arrival_ + (sizeof(arrival_) / sizeof(arrival_[0])));
        string departure_[] = {"12:00:00", "17:00:00", "20:48:10"};
        vector<string> departure(departure_, departure_ + (sizeof(departure_) / sizeof(departure_[0])));
		int wage = 1000;
		int expected_ = 10015;
        assertEquals(0, expected_, solution.howMuch(arrival, departure, wage));
    }

    void testCase1() {
        string arrival_[] = {"01:05:47", "16:48:12"};
        vector<string> arrival(arrival_, arrival_ + (sizeof(arrival_) / sizeof(arrival_[0])));
        string departure_[] = {"09:27:30", "21:17:59"};
        vector<string> departure(departure_, departure_ + (sizeof(departure_) / sizeof(departure_[0])));
		int wage = 2000;
		int expected_ = 33920;
        assertEquals(1, expected_, solution.howMuch(arrival, departure, wage));
    }

    void testCase2() {
        string arrival_[] = {"00:00:00"};
        vector<string> arrival(arrival_, arrival_ + (sizeof(arrival_) / sizeof(arrival_[0])));
        string departure_[] = {"23:59:59"};
        vector<string> departure(departure_, departure_ + (sizeof(departure_) / sizeof(departure_[0])));
		int wage = 10000;
		int expected_ = 299995;
        assertEquals(2, expected_, solution.howMuch(arrival, departure, wage));
    }

    void testCase3() {
        string arrival_[] = {"10:00:00"};
        vector<string> arrival(arrival_, arrival_ + (sizeof(arrival_) / sizeof(arrival_[0])));
        string departure_[] = {"18:00:00"};
        vector<string> departure(departure_, departure_ + (sizeof(departure_) / sizeof(departure_[0])));
		int wage = 10000;
		int expected_ = 80000;
        assertEquals(3, expected_, solution.howMuch(arrival, departure, wage));
    }

    void testCase4() {
        string arrival_[] = {"22:19:46"};
        vector<string> arrival(arrival_, arrival_ + (sizeof(arrival_) / sizeof(arrival_[0])));
        string departure_[] = {"23:12:46"};
        vector<string> departure(departure_, departure_ + (sizeof(departure_) / sizeof(departure_[0])));
		int wage = 5320;
		int expected_ = 7049;
        assertEquals(4, expected_, solution.howMuch(arrival, departure, wage));
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
        SalaryTest test;
        test.runTest(i);
    }
}
