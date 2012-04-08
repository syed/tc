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

class LevelUp {

	public: int toNextLevel(vector<int> expNeeded, int received) {
		int i=0;
		while( received - expNeeded[i] >= 0 && i<expNeeded.size())
			i++;

		if (expNeeded[i] - received == 0 && i > 0 && i < expNeeded.size()-1 )
			return expNeeded[i]- expNeeded[i-1];

		return (expNeeded[i] - received);
	}

};
