#include "Centipede.h"
#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class CentipedeTest {

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

    Centipede solution;

    void testCase0() {
        string screenLayout_[] = {"#                #", "# #      #       #", "#   #    #   #   #", "#           #    #", "#   ##         # #", "# #      ##      #", "#    #           #", "#                #"};
        vector<string> screenLayout(screenLayout_, screenLayout_ + (sizeof(screenLayout_) / sizeof(screenLayout_[0])));
		int timeUnits = 24;
        string expected__[] = {"#                #", "# #      #       #", "#   #    #xxx#   #", "#         xx#    #", "#   ##   xxx   # #", "# #      ##      #", "#    #           #", "#                #"};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(0, expected_, solution.simulate(screenLayout, timeUnits));
    }

    void testCase1() {
        string screenLayout_[] = {"#          #", "#          #"};
        vector<string> screenLayout(screenLayout_, screenLayout_ + (sizeof(screenLayout_) / sizeof(screenLayout_[0])));
		int timeUnits = 16;
        string expected__[] = {"#          #", "#xxxx      #"};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(1, expected_, solution.simulate(screenLayout, timeUnits));
    }

    void testCase2() {
        string screenLayout_[] = {"#            #", "#     #      #", "#            #"};
        vector<string> screenLayout(screenLayout_, screenLayout_ + (sizeof(screenLayout_) / sizeof(screenLayout_[0])));
		int timeUnits = 24;
        string expected__[] = {"#xxxxxxxxxx  #", "#     #      #", "#            #"};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(2, expected_, solution.simulate(screenLayout, timeUnits));
    }

    void testCase3() {
        string screenLayout_[] = {"#                        #", "#      #                 #", "#                 #      #", "#  ##    #               #", "#              #    #    #", "#     #                  #", "#       #          #     #", "#          #             #", "#              #         #"};
        vector<string> screenLayout(screenLayout_, screenLayout_ + (sizeof(screenLayout_) / sizeof(screenLayout_[0])));
		int timeUnits = 74607;
        string expected__[] = {"#                        #", "#      #                 #", "#                 #      #", "#  ##    #               #", "#              #    #    #", "#     #xxxxxxx           #", "#      x#          #     #", "#     xx   #             #", "#              #         #"};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(3, expected_, solution.simulate(screenLayout, timeUnits));
    }

    void testCase4() {
        string screenLayout_[] = {"#                            #", "#   #     # # #           # ##", "#   #       #                #", "#                          # #", "#                   #        #", "##    #           #        # #", "#    #    #   #              #", "#  #    #  #          #      #", "#     #   #       #          #", "#                            #", "#     #        #         #   #", "#   ###          #        #  #", "#           ##             # #", "#                     #      #", "##           #               #", "#     #     #   #     # #    #", "#          #  ##   #         #", "#                    #       #", "#                    #  #    #"};
        vector<string> screenLayout(screenLayout_, screenLayout_ + (sizeof(screenLayout_) / sizeof(screenLayout_[0])));
		int timeUnits = 598273167;
        string expected__[] = {"#                            #", "#   #     # # #           # ##", "#   #       #                #", "#                          # #", "#                   #        #", "##    #           #        # #", "#    #    #   #              #", "#  #    #  #          #      #", "#     #   #       #          #", "#                         xxx#", "#     #        #         #xxx#", "#   ###          #        # x#", "#           ##             # #", "#                     #      #", "##           #               #", "#     #     #   #     # #    #", "#          #  ##   #         #", "#                    #       #", "#                    #  #    #"};
        vector<string> expected_(expected__, expected__ + (sizeof(expected__) / sizeof(expected__[0])));
        assertEquals(4, expected_, solution.simulate(screenLayout, timeUnits));
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
    for (int i = 4; i < 5; i++) {
        CentipedeTest test;
        test.runTest(i);
    }
}
