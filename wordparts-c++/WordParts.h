#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i < int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()


vector<string> all_possible_pfx_sfx(string s)
{

	vector<string> ret;
	FOR(i,1,s.size())
	{
		ret.push_back(string(s.begin(),s.begin()+i));
		ret.push_back(string(s.begin()+i,s.end()));
	}
	ret.push_back(s);
	return ret;
}

map< pair<string,string>,int> dp;

int calculate_pfx_sfx(string s , vector<string> all, int pos)
{
	//if ( pos > s.size())
	//	return -1;
	if ( pos == s.size())
		return 0;

	string curr = string(s.begin()+pos,s.end());


	int ret=-1;
	FOR(i,0,all.size())
	{
		int sz = all[i].size();
		if ( sz<= (curr.size()) && string(curr.begin(), curr.begin()+sz) == all[i] ) //match
		{
			int val;
			if ( dp.find(make_pair(curr,all[i])) != dp.end())
				val = dp[make_pair(curr,all[i])];
			else
				val=calculate_pfx_sfx( s,all,pos+sz );

			dp[make_pair(curr,all[i])] = val;
			if ( val != -1 )
			{
				if ( ret == -1 )
					ret = val+1;
				else if ( ret > val+1 )
					ret = val+1;
			}
		}
	}

	return ret;
}

class WordParts {

	public: int partCount(string original, string compound) {
		dp.clear();
		vector<string> all = all_possible_pfx_sfx(original);
		return calculate_pfx_sfx(compound,all,0);
	}

};
