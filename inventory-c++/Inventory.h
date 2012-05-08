#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>


using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

#define EPSILON (0.000000001)

class Inventory {

	public: int monthlyOrder(vector<int> sales, vector<int> daysAvailable) {
		long double avg=0;
		int mon=0;
		FOR( i, 0, sales.size())
		{
			if ( daysAvailable[i] == 0)
				continue;
			avg += ((long double)(30*sales[i])/(long double)(daysAvailable[i]));
			mon++;
		}
		avg /= mon;

		avg = avg - EPSILON;
		//cout<<" avg : "<< avg << " ep : "<< EPSILON << "Ceil "<<ceil(avg)<< endl;
		return int(ceil(avg));
	}

};
