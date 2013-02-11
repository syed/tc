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

/* let f(n) denote the solution to string of length n having no "ab", 
 * for a simple solution without considiering the "ab" constraint
 * we can say f(n) = 3*f(n-1) as we can append a,b,c to f(n-1) and get
 * f(n).
 *
 * Now to get our solution, consider the cases where f(n-1) ends with 
 * a ie if we fix a at the last position we get f(n-2) ways. Now if 
 * f(n-1) ends with a, we cannot append b to get our solution since
 * that will form "ab" so, if we remove all the cases which ends with
 * a and we had b as the char to append we will get our solution
 *
 *      =>  f(n) = 3*f(n-1) - f(n-2)
 */

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
