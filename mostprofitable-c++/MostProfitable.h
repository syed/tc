#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

class MostProfitable {

	public: string bestItem(vector<int> costs, vector<int> prices, vector<int> sales, vector<string> items) {
		string ret_item = "";
		int max_profit = 0;
		int profit;
		FOR(i,0,costs.size())
		{
			profit = ( prices[i]  - costs[i] ) * sales[i] ;
			if ( profit >0 && profit > max_profit )
			{
				max_profit = profit;
				ret_item = items[i];
			}
		}
		return ret_item;
	}

};
