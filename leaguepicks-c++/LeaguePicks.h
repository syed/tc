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

class LeaguePicks {

	public: vector<int> returnPicks(int position, int friends, int picks) {

		vector<int> ret;
		if ( picks < position) /* Not possible */
			return vector<int>();

		ret.push_back(position);
		int front = friends - position;
		int back = position-1;
		int my_pick = position;
		int odd = 1;
		picks-=position;

		while(picks>0)
		{
			my_pick = my_pick + 2*(odd ==1 ? front : back ) + 1;
			picks -= 2*(odd ==1 ? front : back )+1;
			if ( picks<0)
				break;
			ret.push_back(my_pick);
			odd *= -1;
		}
		return ret;
	}

};
