#include "VendingMachine.h"
#include <iostream>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::vector;

class VendingMachineTest {

    static void assertEquals(int testCase, const int& expected, const int& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << expected << "> but was: <" << actual << '>' << endl;
        }
    }

    VendingMachine solution;

    void testCase0() {
        string prices_[] = {"100 100 100"};
        vector<string> prices(prices_, prices_ + (sizeof(prices_) / sizeof(prices_[0])));
        string purchases_[] = {"0,0:0", "0,2:5", "0,1:10"};
        vector<string> purchases(purchases_, purchases_ + (sizeof(purchases_) / sizeof(purchases_[0])));
		int expected_ = 4;
        assertEquals(0, expected_, solution.motorUse(prices, purchases));
    }

    void testCase1() {
        string prices_[] = {"100 200 300 400 500 600"};
        vector<string> prices(prices_, prices_ + (sizeof(prices_) / sizeof(prices_[0])));
        string purchases_[] = {"0,2:0", "0,3:5", "0,1:10", "0,4:15"};
        vector<string> purchases(purchases_, purchases_ + (sizeof(purchases_) / sizeof(purchases_[0])));
		int expected_ = 17;
        assertEquals(1, expected_, solution.motorUse(prices, purchases));
    }

    void testCase2() {
        string prices_[] = {"100 200 300 400 500 600"};
        vector<string> prices(prices_, prices_ + (sizeof(prices_) / sizeof(prices_[0])));
        string purchases_[] = {"0,2:0", "0,3:4", "0,1:8", "0,4:12"};
        vector<string> purchases(purchases_, purchases_ + (sizeof(purchases_) / sizeof(purchases_[0])));
		int expected_ = 11;
        assertEquals(2, expected_, solution.motorUse(prices, purchases));
    }

    void testCase3() {
        string prices_[] = {"100 100 100"};
        vector<string> prices(prices_, prices_ + (sizeof(prices_) / sizeof(prices_[0])));
        string purchases_[] = {"0,0:10", "0,0:11"};
        vector<string> purchases(purchases_, purchases_ + (sizeof(purchases_) / sizeof(purchases_[0])));
		int expected_ = -1;
        assertEquals(3, expected_, solution.motorUse(prices, purchases));
    }

    void testCase4() {
        string prices_[] = {"100 200 300", "600 500 400"};
        vector<string> prices(prices_, prices_ + (sizeof(prices_) / sizeof(prices_[0])));
        string purchases_[] = {"0,0:0", "1,1:10", "1,2:20", "0,1:21", "1,0:22", "0,2:35"};
        vector<string> purchases(purchases_, purchases_ + (sizeof(purchases_) / sizeof(purchases_[0])));
		int expected_ = 6;
        assertEquals(4, expected_, solution.motorUse(prices, purchases));
    }
    //{{"6998 3034 3524 1915 5796 2184", "2654 2873 9503 8340 7027 8490", "8492 183 852 8119 1971 186", "7950 9479 1887 241 6525 3851", "7814 3362 7347 1951 6086 5687", "8332 2174 1048 4416 5892 2009", "9101 8419 2572 3024 9949 7801", "8183 3845 9617 2539 2427 4343", "2728 4773 718 2577 7046 3008", "8723 9277 1261 2996 8541 6192", "2084 9012 9792 4615 2524 9686", "8344 3910 7214 3150 6856 2091", "2371 2901 1771 1367 4019 5789", "3565 8066 1018 2807 1656 278", "9190 1532 4841 6361 2765 8119", "4566 803 1954 1950 2618 3525", "856 5592 9161 9983 4391 3536", "6029 7298 878 8122 231 6898", "5394 6243 4084 8249 9150 7209", "5228 7590 9686 7788 4101 9083", "3055 8553 5504 2313 3882 6427", "701 2227 2332 7135 3362 7440", "320 5872 2067 2761 8878 5696", "4309 9033 6831 3365 2694 8770", "2891 1345 8853 5836 9572 2916", "4859 2692 2790 7689 9899 4867", "5349 2227 6113 9034 6123 4679", "6698 4925 4055 7616 9990 9239", "5857 438 7 4695 4885 6592", "8888 1128 2888 3615 8457 1268", "1644 2334 4974 8561 6810 5406", "6731 1025 9443 3976 9390 8158", "236 6477 2501 7742 7631 3473", "1935 7280 4551 1347 3678 7187", "5855 3376 7918 2319 2535 8496", "9201 3615 1315 67 2776 7303", "8780 7625 4991 1205 3335 2582", "7280 8889 3931 2919 134 9698", "6622 9505 7104 9515 1096 3356", "7143 7692 8536 586 6238 6563", "5397 4564 5652 8232 1151 4242", "1389 6622 5894 2529 1147 7121", "8567 9115 8117 8968 687 4305"}, {"30,3:5"}}
    void testCase5() {
        string prices_[] = {"6998 3034 3524 1915 5796 2184", "2654 2873 9503 8340 7027 8490", "8492 183 852 8119 1971 186", "7950 9479 1887 241 6525 3851", "7814 3362 7347 1951 6086 5687", "8332 2174 1048 4416 5892 2009", "9101 8419 2572 3024 9949 7801", "8183 3845 9617 2539 2427 4343", "2728 4773 718 2577 7046 3008", "8723 9277 1261 2996 8541 6192", "2084 9012 9792 4615 2524 9686", "8344 3910 7214 3150 6856 2091", "2371 2901 1771 1367 4019 5789", "3565 8066 1018 2807 1656 278", "9190 1532 4841 6361 2765 8119", "4566 803 1954 1950 2618 3525", "856 5592 9161 9983 4391 3536", "6029 7298 878 8122 231 6898", "5394 6243 4084 8249 9150 7209", "5228 7590 9686 7788 4101 9083", "3055 8553 5504 2313 3882 6427", "701 2227 2332 7135 3362 7440", "320 5872 2067 2761 8878 5696", "4309 9033 6831 3365 2694 8770", "2891 1345 8853 5836 9572 2916", "4859 2692 2790 7689 9899 4867", "5349 2227 6113 9034 6123 4679", "6698 4925 4055 7616 9990 9239", "5857 438 7 4695 4885 6592", "8888 1128 2888 3615 8457 1268", "1644 2334 4974 8561 6810 5406", "6731 1025 9443 3976 9390 8158", "236 6477 2501 7742 7631 3473", "1935 7280 4551 1347 3678 7187", "5855 3376 7918 2319 2535 8496", "9201 3615 1315 67 2776 7303", "8780 7625 4991 1205 3335 2582", "7280 8889 3931 2919 134 9698", "6622 9505 7104 9515 1096 3356", "7143 7692 8536 586 6238 6563", "5397 4564 5652 8232 1151 4242", "1389 6622 5894 2529 1147 7121", "8567 9115 8117 8968 687 4305"};
        vector<string> prices(prices_, prices_ + (sizeof(prices_) / sizeof(prices_[0])));
        string purchases_[] = {"30,3:5"};
        vector<string> purchases(purchases_, purchases_ + (sizeof(purchases_) / sizeof(purchases_[0])));
		int expected_ = 5;
        assertEquals(5, expected_, solution.motorUse(prices, purchases));
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
        VendingMachineTest test;
        test.runTest(i);
    }
}
