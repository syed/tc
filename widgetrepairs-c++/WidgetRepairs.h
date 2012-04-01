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

class WidgetRepairs {

	public: int days(vector<int> arrivals, int numPerDay) {
		int overflow=0,days=0;
		FOR(i,0,arrivals.size())
		{
			if((arrivals[i]+overflow)!=0)
				days++;

			if((arrivals[i]+overflow)>numPerDay)
				overflow = (arrivals[i]+overflow)-numPerDay;
			else
				overflow=0;
		}

		return days + overflow/numPerDay + (overflow % numPerDay ? 1 : 0) ;
	}

};
