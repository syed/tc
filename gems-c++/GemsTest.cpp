#include "Gems.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class GemsTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    Gems solution;

    void testCase0() {
        string board_[] = {"ABC", "ABC", "BAD"};
        vector<string> board(board_, board_ + (sizeof(board_) / sizeof(board_[0])));
		int expected_ = 1;
        assertEquals(0, expected_, solution.numMoves(board));
    }

    void testCase1() {
        string board_[] = {"ABB", "BAA", "ABB"};
        vector<string> board(board_, board_ + (sizeof(board_) / sizeof(board_[0])));
		int expected_ = 3;
        assertEquals(1, expected_, solution.numMoves(board));
    }

    void testCase2() {
        string board_[] = {"ABA", "BAB", "ABA"};
        vector<string> board(board_, board_ + (sizeof(board_) / sizeof(board_[0])));
		int expected_ = 4;
        assertEquals(2, expected_, solution.numMoves(board));
    }

    void testCase3() {
        string board_[] = {"ABC", "DEF", "GHI"};
        vector<string> board(board_, board_ + (sizeof(board_) / sizeof(board_[0])));
		int expected_ = 0;
        assertEquals(3, expected_, solution.numMoves(board));
    }

    void testCase4() {
        string board_[] = {"SUMEEMEEPGPPG", "USPMIPSUSIISG", "UPSPGEGGPKEII", "KEMGISMKKIUIG", "MGSIIKMSISGKM", "SPGMSMIGMSMGM", "SSIIUKMPEPPUI", "UKUIUEMEEIGKE", "IPUPGUSEGSSUS", "EUPMKGGUKKEMI", "PEPSMUUEUSSIP", "SUMEEUSESUEKG", "EPSKUISGMSKGI", "IUGGUGGSIGUUP", "IUPIKKSGPPEEP", "KGEESGISPGGEM", "UEIUSSKPSSGPE", "KSUMKGEIMKPSE", "ESKEUEMMPPIGG", "UUIEUGGIGMEMK", "GPGMPPIUMEPMU", "IKIGGPIUEMIGS", "IPUSGUMKPKIPP", "UEEMUUEEGIPUS", "PPEKIKEMGGMSS", "EMKPMPUUMKEPU", "UKPGPKSUIEUPM", "PSUUMUKGIIPMS", "ESMGSKUEPGGEM", "SMEEIKGKGGPEG", "UEIEKPMESMEPP", "IPUIMGGMIPKMG", "ISSEKPKGKIUGU", "SSESKUGKISPUK"};
        vector<string> board(board_, board_ + (sizeof(board_) / sizeof(board_[0])));
		int expected_ = 83;
        assertEquals(4, expected_, solution.numMoves(board));
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
        GemsTest test;
        test.runTest(i);
    }
}
