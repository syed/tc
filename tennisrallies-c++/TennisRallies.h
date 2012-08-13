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

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

int check_forbidden(string str , vector<string> forbidden)
{
	int fcount = 0 ,next = 0 ,found;
	FOR(i,0,forbidden.size())
	{
		next = 0;
		while ( (found =  str.find(forbidden[i], next)) != string::npos)
		{
			fcount++;
			next = found+1;
		}
	}
	return fcount;
}

int num_ways( string curr , vector<string> forbidden , int alwd, int len )
{
	if ( len == 0 )
	{
		if ( check_forbidden(curr,forbidden) < alwd )
			return 1;
		return 0;
	}

	return (num_ways(curr + "c" , forbidden ,  alwd , len-1  ) + num_ways(curr + "d" , forbidden ,  alwd , len-1  ));
}

class TennisRallies {

	public: int howMany(int numLength, vector<string> forbidden, int allowed) {
		return num_ways("",forbidden,allowed,numLength);
	}

};
