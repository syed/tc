#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <numeric>

using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

class VacationTime {

	public: int bestSchedule(int N, int K, vector<int> workingDays) {
		vector<int> meets(N,0);
		int max_count = workingDays.size();
		FORIT(i,workingDays)
			meets[(*i) - 1 ] = 1;

		/* Simple Looping cout consecutive elemnts */
		FOR(i,0,N-K+1)
		{
			int meet_count = 0;
			FOR(j,i,i+K)
				meet_count += meets[j];

			if ( meet_count < max_count )
				max_count = meet_count;
		}
		return max_count;
	}

};
