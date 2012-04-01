#include "CCipher.h"
#include <iostream>
#include <string>

using std::cerr;
using std::cout;
using std::endl;
using std::string;

class CCipherTest {

    static void assertEquals(int testCase, const string& expected, const string& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << '"' << expected << '"' << "> but was: <" << '"' << actual << '"' << '>' << endl;
        }
    }

    CCipher solution;

    void testCase0() {
		string cipherText = "VQREQFGT";
		int shift = 2;
		string expected_ = "TOPCODER";
        assertEquals(0, expected_, solution.decode(cipherText, shift));
    }

    void testCase1() {
		string cipherText = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		int shift = 10;
		string expected_ = "QRSTUVWXYZABCDEFGHIJKLMNOP";
        assertEquals(1, expected_, solution.decode(cipherText, shift));
    }

    void testCase2() {
		string cipherText = "TOPCODER";
		int shift = 0;
		string expected_ = "TOPCODER";
        assertEquals(2, expected_, solution.decode(cipherText, shift));
    }

    void testCase3() {
		string cipherText = "ZWBGLZ";
		int shift = 25;
		string expected_ = "AXCHMA";
        assertEquals(3, expected_, solution.decode(cipherText, shift));
    }

    void testCase4() {
		string cipherText = "DBNPCBQ";
		int shift = 1;
		string expected_ = "CAMOBAP";
        assertEquals(4, expected_, solution.decode(cipherText, shift));
    }

    void testCase5() {
		string cipherText = "LIPPSASVPH";
		int shift = 4;
		string expected_ = "HELLOWORLD";
        assertEquals(5, expected_, solution.decode(cipherText, shift));
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
        CCipherTest test;
        test.runTest(i);
    }
}
