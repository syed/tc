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

class BritishCoins {

	public: vector<int> coins(int pence) {
		vector<int> res;
		res.push_back( pence/(12*20));
		pence = pence % (12*20);
		res.push_back( pence/(12));
		pence = pence % (12);
		res.push_back(pence);
		return res;

	}

};
