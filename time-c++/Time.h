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

class Time {

	public: string whatTime(int seconds) {
		ostringstream out;
		int hours  = seconds / (3600);
		seconds = seconds - (hours*3600);
		int mins  = seconds/60;
		seconds = seconds - mins*60;
		out << hours << ":" <<mins<< ":" << seconds;

		return out.str();
	}

};
