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

class BigBurger {

	public: int maxWait(vector<int> arrival, vector<int> service) {
		vector<int> get_time;
		/* We actually don't need the extra vector
		 * Better solution:
		* int t = 0;
		* int ret = 0;
		* for(int i = 0; i < arrival.length; i++){
		*   if(arrival[i] > t)t=arrival[i];
		*   ret = Math.max(ret,t-arrival[i]);
		*   t += service[i];
		* }
		*/

		return ret;
		get_time.push_back(arrival[0] + service[0]);
		FOR(i,1,service.size())
		{
			if ( arrival[i] > get_time[i-1] ) // came in empty queue
				get_time.push_back(arrival[i] + service[i]);
			else
				get_time.push_back(get_time[i-1] + service[i]);
		}
		// Max waiting time = get - ( arrival + service )
		int max_time =  0;
		FOR(i,0,get_time.size())
		{
			int m;
			m = get_time[i] - ( arrival[i] + service[i]);
			if ( m > max_time )
				max_time = m;
		}
		return max_time;
	}

};
