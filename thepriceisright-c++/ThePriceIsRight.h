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


class ThePriceIsRight {

	public: vector<int> howManyReveals(vector<int> prices) {
		int dp[prices.size()];
		int ways[prices.size()];
		FOR(i,0,prices.size())
		{
			dp[i] = 1;
			FOR(j,0,i)
			{
				if ( prices[j] < prices[i] && dp[j] +1 > dp[i])
					dp[i] =dp[j] + 1;
				//printf("i: %d , j %d , dpi : %d , dpj : %d waysj %d \n",i,j,dp[i],dp[j],ways[j]);
			}
			ways[i] = 0;
			if ( dp[i] == 1)
				ways[i] = 1;
			else
			{
				FOR(j,0,i)
				{
					if ( prices[j] < prices[i] && dp[j] +1 == dp[i] )
						ways[i] += ways[j];
				}
			}
		}
		int max_seq = 1;
		FOR(i,0,prices.size())
			if ( dp[i] > max_seq )
				max_seq = dp[i];

		int max_count = 0;
		FOR(i,0,prices.size())
			if ( dp[i] == max_seq )
				max_count+=ways[i];

		vector<int> ret;
		ret.push_back(max_seq);
		ret.push_back(max_count);
		return ret;
	}

};
