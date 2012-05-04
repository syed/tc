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

#define HRS(s) ((s[0]-'0')*10 + (s[1]-'0'))
#define MIN(s) ((s[3]-'0')*10 + (s[4]-'0'))
#define SEC(s) ((s[6]-'0')*10 + (s[7]-'0'))

#define TIMESTAMP(s) ( HRS(s)*3600 + MIN(s)*60 + SEC(s))

class BadClock {

	public: double nextAgreement(string trueTime, string skewTime, int hourlyGain) {
		double ret=0;
		int ttime = TIMESTAMP(trueTime);
		int stime = TIMESTAMP(skewTime);

		ret = (double(ttime - stime))/hourlyGain;

		if ( ret < 0 )
		{
			// back clock going back or front clock going front
			ret =  (double( stime - ttime + (12*3600)))/abs(hourlyGain);

		}
		return ret;
	}

};
