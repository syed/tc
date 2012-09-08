#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i < (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()
int dp[1000][1000];

/*
 * We have a recurrence relation....let us calculate the minimum time required for k people
 * to finish painting the building. Lets add another member there. Now to calculate the time
 * for k+1 persons, we can give the k+1 person 0 colums , 1 column , 2 columns etc... and we
 * take min of those ...
 *
 * T(n+1,w) = min( max( T(k,w-i) , i*tk ) ) ......... where i = 0 ... w,
 *
 * and tk = time taken for the kth person to paint one column.
 *
 *
 */

int calculate_time(int per,int width,vector<int> wt)
{
	//cout<<"per: "<<per<<endl;
	if ( width == 0 )
	{
		dp[per-1][0]=0;
		return 0;
	}

	if ( dp[per-1][width-1])
		return dp[per-1][width-1];

	if ( per == 1 )
	{
		dp[per-1][width-1]= width*wt[per-1];
		return width*wt[per-1];
	}

	vector<int> vals;
	FOR(i,0,width)
	{
		int t1,t2;
		t1 = (dp[per-2][width-i-1] ? (dp[per-2][width-i-1]):calculate_time(per-1,width-i,wt));
		t2 = wt[per-1]*i;
		//cout<<"t1 "<<t1 <<" t2 "<<t2<<" max "<<max(t1,t2)<<endl;
		vals.push_back(max(t1,t2));
	}
	vals.push_back(wt[per-1]*width);

	int minval =  *(min_element(vals.begin(), vals.end() ));
	dp[per-1][width-1] = minval;
	return minval;
}

class WindowWasher {

	public: int fastest(int width, int height, vector<int> washTimes) {

		FOR(i,0,washTimes.size())
			washTimes[i] = washTimes[i]*height;

		FOR(i,0,1000)
			FOR(j,0,1000)
				dp[i][j] = 0;

		return calculate_time(washTimes.size(),width,washTimes);

	}

};
