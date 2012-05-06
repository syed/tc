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


class BirthdayOdds {

	public: int minPeople(int minOdds, int daysInYear) {

		double prob=1;
		int count = 0;

		FOR(i,0,daysInYear)
		{
			prob = prob*(double(daysInYear-i)/double(daysInYear));

			if ( (prob * 100) < 100 - minOdds )
				break;
			count++;
		}
		return count+1;
	}

};
