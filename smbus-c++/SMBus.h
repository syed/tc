#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i < int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

typedef struct master {
	string data;
	int time;
	bool matches;
} master_t ;

bool master_cmp( master_t a , master_t b)
{
	if ( a.data < b.data )
		return true;
	return false;
}

int max_time(vector<master_t> m )
{
	int max_time = m[0].time;
	FOR(i,0,m.size())
		if ( m[i].time > max_time  && m[i].matches == true)
			max_time = m[i].time;

	return max_time;
}

class SMBus {

	public: int transmitTime(vector<string> messages, vector<int> times) {
		vector<master_t> mst;
		FOR(i,0,messages.size())
		{
			master_t m;
			m.data = messages[i];
			m.time = times[i];
			mst.push_back(m);
		}

		sort(mst.begin() , mst.end() , master_cmp);

		int total_time = 0 ;
		while( mst.size() > 0 )
		{
			master_t curr = mst[0];
			vector<master_t> matches = mst;
			FOR(i,0,matches.size())
				matches[i].matches = true;

			FOR(i,0,curr.data.size())
			{
				int time = max_time(matches);
				total_time+=time;

				FOR(j,1,matches.size())
					if ( curr.data[i] != matches[j].data[i] )
						matches[j].matches=false; // mark the jth element

			}
			mst.erase(mst.begin()); //remove from list
		}
		return total_time;
	}

};
