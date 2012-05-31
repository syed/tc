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

int fact(int n)
{
	int start=1;
	int fact_val=1;
	while(start!=n+1)
	{
		fact_val = fact_val*start;
		start++;
	}
	return fact_val;
}

int ncr( int n ,int  r )
{
	return(fact(n)/(fact(r)*fact(n-r)));
}
class BagOfHolding {

	public: double oddsReachable(vector<int> sizes, int item) {
		int nm=0;
		int req = sizes[item];
		FOR(i,0,sizes.size())
		{
			if( sizes[i]>=req && i!=item )
				nm++;
		}
		if ( nm == 0  )
			return double(1);
		//see editorial

		return ( (1/double(nm+1)));
	}

};
