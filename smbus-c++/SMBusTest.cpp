#include "SMBus.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class SMBusTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    SMBus solution;

    void testCase0() {
        string messages_[] = {"123", "124", "134"};
        vector<string> messages(messages_, messages_ + (sizeof(messages_) / sizeof(messages_[0])));
        int times_[] = {1, 2, 3};
        vector<int> times(times_, times_ + (sizeof(times_) / sizeof(times_[0])));
		int expected_ = 25;
        assertEquals(0, expected_, solution.transmitTime(messages, times));
    }

    void testCase1() {
        string messages_[] = {"012", "1234", "1233", "1223", "1123"};
        vector<string> messages(messages_, messages_ + (sizeof(messages_) / sizeof(messages_[0])));
        int times_[] = {4, 1, 5, 2, 9};
        vector<int> times(times_, times_ + (sizeof(times_) / sizeof(times_[0])));
		int expected_ = 94;
        assertEquals(1, expected_, solution.transmitTime(messages, times));
    }

    void testCase2() {
        string messages_[] = {"0002019289019101039663222896280025447", "00201873554718989597528841094293294387326", "010699029378761", "0110118", "011143279122561420", "001046384966198", "00200570375817801109530240012", "0003163277589822", "01100240744590150136673219652442108", "012033596872642679096489479354", "0121059494098", "00001002303019117948961792176", "00216399923558", "02014", "00224999120803846121427603894967637446889670369", "01101009414735635151893037596051740080475886", "0000101211809647472761605153430927981533514", "176845042961739039392207791589", "02000047506929386333221966659552927385017901842706", "021001117450487502127241076595509511", "021010776262723557108100899515", "0210114830738951774606917781619656", "0211798433083855430", "00000005842153604632996228135814", "0001000766929248550736138555144997170272757787", "0001010247593342056062432721557", "01100004828618452515832113396660046634951", "0132559984733529872911444204991646138116334788", "0224149857349431864906523152249992", "00001142929552573133212195441932219", "0011090498947092002457447355036811372647896489218", "000001275414757476198997466", "00010014", "00111025861963467834393486017602553072649743", "000102085", "00120882661783539", "01100018938145727291185020", "01100191373790478446634214244459341793", "0001129060", "001111287431066271555393813846448", "011010160778408696098486370196313", "0002125146381515395"};
        vector<string> messages(messages_, messages_ + (sizeof(messages_) / sizeof(messages_[0])));
        int times_[] = {42, 86, 47, 86, 32, 95, 2, 98, 17, 58, 31, 32, 85, 77, 87, 61, 1, 20, 15, 80, 20, 95, 55, 87, 52, 14, 55, 68, 2, 66, 67, 3, 28, 97, 100, 67, 65, 20, 28, 77, 93, 64};
        vector<int> times(times_, times_ + (sizeof(times_) / sizeof(times_[0])));
		int expected_ = 71048;
        assertEquals(2, expected_, solution.transmitTime(messages, times));
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
        SMBusTest test;
        test.runTest(i);
    }
}
