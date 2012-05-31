#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

class RaceApproximator {

	public: string timeToBeat(int d1, int t1, int d2, int t2, int raceDistance) {
		int t3 = t1*exp(log((double)t2/t1)*log((double)d1/raceDistance)/log((double)d1/d2));

		char out[20];
		sprintf(out,"%01d:%02d:%02d",t3/3600,(t3%3600)/60,t3%60);

		return string(out);
	}

};
