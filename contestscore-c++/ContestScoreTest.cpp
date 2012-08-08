#include "ContestScore.h"
#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class ContestScoreTest {

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

    ContestScore solution;

    void testCase0() {
        string data_[] = {"A 90.7 92.9 87.4", "B 90.5 96.6 88.0", "C 92.2 91.0 95.3"};
        vector<string> data(data_, data_ + (sizeof(data_) / sizeof(data_[0])));
        string expected__[] = {"C 5 278.5", "B 6 275.1", "A 7 271.0"};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(0, expected_, solution.sortResults(data));
    }

    void testCase1() {
        string data_[] = {"STANFORD 85.3 90.1 82.6 84.6 96.6 94.5 87.3 90.3", "MIT 95.5 83.9 80.4 85.5 98.7 98.3 96.7 82.7", "PRINCETON 99.2 79.1 87.6 85.1 93.6 96.4 86.0 90.6", "HARVARD 83.6 92.0 85.5 94.3 97.5 91.5 92.5 83.0", "YALE 99.5 92.6 86.2 82.0 96.4 92.6 84.5 78.6", "COLUMBIA 97.2 87.6 81.7 93.7 88.0 86.3 95.9 89.6", "BROWN 92.2 95.8 92.1 81.5 89.5 87.0 95.5 86.4", "PENN 96.3 80.7 81.2 91.6 85.8 92.2 83.9 87.8", "CORNELL 88.0 83.7 85.0 83.8 99.8 92.1 91.0 88.9"};
        vector<string> data(data_, data_ + (sizeof(data_) / sizeof(data_[0])));
        string expected__[] = {"PRINCETON 34 717.6", "MIT 36 721.7", "HARVARD 38 719.9", "COLUMBIA 39 720.0", "STANFORD 39 711.3", "YALE 40 712.4", "BROWN 41 720.0", "CORNELL 42 712.3", "PENN 51 699.5"};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(1, expected_, solution.sortResults(data));
    }

    void testCase2() {
        vector<string> data;
        vector<string> expected_;
        assertEquals(2, expected_, solution.sortResults(data));
    }

    void testCase3() {
        string data_[] = {"AA 90.0 80.0 70.0 60.0 50.0 40.0", "BBB 80.0 70.0 60.0 50.0 40.0 90.0", "EEE 70.0 60.0 50.0 40.0 90.0 80.0", "AAA 60.0 50.0 40.0 90.0 80.0 70.0", "DDD 50.0 40.0 90.0 80.0 70.0 60.0", "CCC 40.0 90.0 80.0 70.0 60.0 50.0"};
        vector<string> data(data_, data_ + (sizeof(data_) / sizeof(data_[0])));
        string expected__[] = {"AA 21 390.0", "AAA 21 390.0", "BBB 21 390.0", "CCC 21 390.0", "DDD 21 390.0", "EEE 21 390.0"};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(3, expected_, solution.sortResults(data));
    }

    void testCase4() {
        string data_[] = {"A 00.1", "B 05.2", "C 29.0", "D 00.0"};
        vector<string> data(data_, data_ + (sizeof(data_) / sizeof(data_[0])));
        string expected__[] = {"C 1 29.0", "B 2 5.2", "A 3 0.1", "D 4 0.0"};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(4, expected_, solution.sortResults(data));
    }

 //{}
    void testCase5() {
        string data_[] = {"AAA 90.0 80.0 70.0 60.0 50.0 40.0", "BBB 90.0 80.0 70.0 60.0 50.0 40.0", "CCC 90.0 80.0 70.0 60.0 50.0 40.0", "DDD 90.0 80.0 70.0 60.0 50.0 40.0", "EEE 90.0 80.0 70.0 60.0 50.0 40.0", "FFF 90.0 80.0 70.0 60.0 50.0 40.0"};
        vector<string> data(data_, data_ + (sizeof(data_) / sizeof(data_[0])));
        string expected__[] = {"AAA 6 390.0", "BBB 6 390.0", "CCC 6 390.0", "DDD 6 390.0", "EEE 6 390.0", "FFF 6 390.0"};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(5, expected_, solution.sortResults(data));
    }


    void testCase6() {
        string data_[] = {"CROATIA 91.3 81.3 82.4 89.2 90.1 94.3 81.9 86.2", "HUNGARY 82.7 86.2 89.0 88.9 86.3 87.6 87.0 79.0", "SWEDEN 96.8 83.7 80.1 79.5 97.0 91.8 83.9 87.0", "CHINA 96.2 82.8 76.0 82.3 86.6 75.6 98.6 76.1", "NORWAY 90.4 96.0 83.8 89.0 99.6 79.3 77.2 96.5", "POLAND 87.7 84.0 96.2 99.1 86.7 80.6 76.0 77.0", "UKRAINE 90.5 82.2 98.8 99.8 98.5 77.3 94.5 99.7", "GERMANY 99.5 95.3 75.6 78.9 91.6 94.9 86.2 80.4", "FRANCE 95.1 97.7 83.2 88.9 75.8 80.9 89.4 78.0", "AUSTRALIA 90.7 84.0 90.2 75.9 94.4 96.8 91.7 82.8", "DENMARK 88.9 79.4 76.3 75.3 81.8 97.1 84.1 83.6", "SINGAPORE 94.9 87.4 78.6 90.1 81.4 80.1 85.1 83.5", "NETHERLAND 91.9 93.8 77.5 93.6 98.6 77.3 85.0 80.9", "RUSSIANFED 75.8 88.2 77.2 76.0 88.2 81.0 93.5 97.1", "NEWZEALAND 75.9 98.8 83.3 83.4 78.5 87.0 93.9 93.7", "IRELAND 82.9 92.6 83.5 93.0 99.0 92.8 87.2 98.3", "MEXICO 76.2 88.9 89.8 88.8 81.5 79.1 90.2 88.4", "VENEZUELA 78.3 79.5 99.9 77.0 93.1 89.8 81.1 91.8", "IRAN 85.4 89.1 75.6 89.0 78.0 78.8 90.4 85.8", "BULGARIA 95.6 99.0 84.2 92.8 94.3 81.1 95.1 80.0", "ROMANIA 78.9 77.2 97.4 82.1 83.4 90.1 99.5 90.0", "CANADA 88.6 87.9 89.4 97.5 87.8 83.4 75.8 83.7", "BRAZIL 80.8 79.7 77.2 99.1 96.1 82.9 88.3 88.7", "UNITEDKING 85.3 96.9 82.8 83.7 93.5 96.5 76.9 96.4", "UNITEDSTAT 89.3 81.4 87.3 99.6 95.7 79.0 77.6 84.1", "SPAIN 93.8 87.8 98.9 92.2 85.2 84.9 92.3 91.4", "MALAYSIA 81.7 96.5 77.4 78.7 76.8 82.6 98.9 90.7", "INDIA 96.2 91.6 96.7 85.9 94.9 89.4 75.3 91.2", "PORTUGAL 77.6 75.7 82.3 75.8 83.3 85.8 96.5 97.3", "COLOMBIA 75.5 83.2 96.0 76.5 88.3 75.7 95.9 93.3"};
        vector<string> data(data_, data_ + (sizeof(data_) / sizeof(data_[0])));
        string expected__[] = {"IRELAND 77 729.3", "UKRAINE 78 741.3", "BULGARIA 87 722.1", "SPAIN 89 726.5", "INDIA 94 721.2", "NORWAY 100 711.8", "UNITEDKING 106 712.0", "AUSTRALIA 110 706.5", "SWEDEN 115 699.8", "NEWZEALAND 119 694.5", "GERMANY 120 702.4", "NETHERLAND 120 698.6", "ROMANIA 122 698.6", "CROATIA 124 696.7", "CANADA 126 694.1", "UNITEDSTAT 128 694.0", "BRAZIL 128 692.8", "VENEZUELA 132 690.5", "FRANCE 132 689.0", "MALAYSIA 135 683.3", "HUNGARY 138 686.7", "POLAND 140 687.3", "COLOMBIA 141 684.4", "MEXICO 141 682.9", "RUSSIANFED 142 677.0", "SINGAPORE 144 681.1", "PORTUGAL 148 674.3", "IRAN 154 672.1", "CHINA 155 674.2", "DENMARK 167 666.5"};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(6, expected_, solution.sortResults(data));
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
        ContestScoreTest test;
        test.runTest(i);
    }
}
