#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

#define FOR(i,s,e) for (int i = int(s); i < int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

class BadSubstring {

	public: long long howMany(int length) {

		long long dp[44] = {0};
		dp[0] = 1;
		dp[1] = 3;
		FOR(i,2,length+1)
		{
			dp[i] = 3*dp[i-1] - dp[i-2];
		}

		return dp[length];
	}

};
