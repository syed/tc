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

class YahtzeeScore {

	public: int maxPoints(vector<int> toss) {
		vector<int> sum(6,0);
		FOR(i,0,toss.size())
			sum[toss[i]-1] += toss[i];
		return *max_element(sum.begin(),sum.end());
	}

};
