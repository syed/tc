#include "MostProfitable.h"
#include <iostream>
#include <string>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class MostProfitableTest {

    static void assertEquals(int testCase, const string& expected, const string& actual) {
        if (expected == actual) {
            cout << "Test case " << testCase << " PASSED!" << endl;
        } else {
            cout << "Test case " << testCase << " FAILED! Expected: <" << '"' << expected << '"' << "> but was: <" << '"' << actual << '"' << '>' << endl;
        }
    }

    MostProfitable solution;

    void testCase0() {
        int costs_[] = {100, 120, 150, 1000};
        vector<int> costs(costs_, costs_ + (sizeof(costs_) / sizeof(costs_[0])));
        int prices_[] = {110, 110, 200, 2000};
        vector<int> prices(prices_, prices_ + (sizeof(prices_) / sizeof(prices_[0])));
        int sales_[] = {20, 100, 50, 3};
        vector<int> sales(sales_, sales_ + (sizeof(sales_) / sizeof(sales_[0])));
        string items_[] = {"Video Card", "256M Mem", "CPU/Mobo combo", "Complete machine"};
        vector<string> items(items_, items_ + (sizeof(items_) / sizeof(items_[0])));
		string expected_ = "Complete machine";
        assertEquals(0, expected_, solution.bestItem(costs, prices, sales, items));
    }

    void testCase1() {
        int costs_[] = {100};
        vector<int> costs(costs_, costs_ + (sizeof(costs_) / sizeof(costs_[0])));
        int prices_[] = {100};
        vector<int> prices(prices_, prices_ + (sizeof(prices_) / sizeof(prices_[0])));
        int sales_[] = {134};
        vector<int> sales(sales_, sales_ + (sizeof(sales_) / sizeof(sales_[0])));
        string items_[] = {"Service, at cost"};
        vector<string> items(items_, items_ + (sizeof(items_) / sizeof(items_[0])));
		string expected_ = "";
        assertEquals(1, expected_, solution.bestItem(costs, prices, sales, items));
    }

    void testCase2() {
        int costs_[] = {38, 24};
        vector<int> costs(costs_, costs_ + (sizeof(costs_) / sizeof(costs_[0])));
        int prices_[] = {37, 23};
        vector<int> prices(prices_, prices_ + (sizeof(prices_) / sizeof(prices_[0])));
        int sales_[] = {1000, 643};
        vector<int> sales(sales_, sales_ + (sizeof(sales_) / sizeof(sales_[0])));
        string items_[] = {"Letter", "Postcard"};
        vector<string> items(items_, items_ + (sizeof(items_) / sizeof(items_[0])));
		string expected_ = "";
        assertEquals(2, expected_, solution.bestItem(costs, prices, sales, items));
    }

    void testCase3() {
        int costs_[] = {10, 10};
        vector<int> costs(costs_, costs_ + (sizeof(costs_) / sizeof(costs_[0])));
        int prices_[] = {11, 12};
        vector<int> prices(prices_, prices_ + (sizeof(prices_) / sizeof(prices_[0])));
        int sales_[] = {2, 1};
        vector<int> sales(sales_, sales_ + (sizeof(sales_) / sizeof(sales_[0])));
        string items_[] = {"A", "B"};
        vector<string> items(items_, items_ + (sizeof(items_) / sizeof(items_[0])));
		string expected_ = "A";
        assertEquals(3, expected_, solution.bestItem(costs, prices, sales, items));
    }

    public: void runTest(int testCase) {
        switch (testCase) {
            case (0): testCase0(); break;
            case (1): testCase1(); break;
            case (2): testCase2(); break;
            case (3): testCase3(); break;
            default: cerr << "No such test case: " << testCase << endl; break;
        }
    }

};

int main() {
    for (int i = 0; i < 4; i++) {
        MostProfitableTest test;
        test.runTest(i);
    }
}
