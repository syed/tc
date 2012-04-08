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

class EyeDrops {

	public: double closest(int sleepTime, int k) {
		int sleep_min = sleepTime*60;
		double wake_time = 24*60 - sleep_min;

		double doses_hours = 24/(k);

		if ( doses_hours > sleepTime )
			return doses_hours*60;

		return ((double)((24-sleepTime)*60) /(double)(k-1));

	}

};
