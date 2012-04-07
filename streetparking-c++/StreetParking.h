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



class StreetParking {
	public: int freeParks(string street) {
		int spots=0;
		FOR(i,0,street.size())
		{
				if ( street[i] == 'D' || street[i] == 'B' || street[i] == 'S')
					continue;
				if (  i < street.size()-2 && ( street[i+1] == 'B' || street[i+1] == 'S'))
					continue;
				if ( i < street.size()-3 && street[i+2] == 'B')
					continue;
				if (i > 0 && street[i-1] == 'S')
					continue;
				spots++;
		}
		return spots;
	}
};
