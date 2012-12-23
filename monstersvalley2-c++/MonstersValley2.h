#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

#define FOR(i,s,e) for (int i = int(s); i < int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

int min_cost(int i, long long cur_dread, vector<int> dread , vector<int> price)
{
	int val;
	if ( i >= dread.size() )
		return 0;

	if ( cur_dread < dread[i] )
		val =  price[i] + min_cost(i+1, cur_dread + dread[i], dread, price);
	else
		val =  min(price[i] + min_cost(i+1, cur_dread + dread[i], dread, price),
						min_cost(i+1, cur_dread, dread, price));

	return val;
}


class MonstersValley2 {

	public: int minimumPrice(vector<int> dread, vector<int> price) {
		return min_cost(0,0,dread,price);
	}

};
