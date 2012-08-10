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

int cmprs = 0;
vector<int> merge(vector<int> b , vector<int> c)
{
	vector<int> a;

	while( (!c.empty()) && (!b.empty()) )
	{
		if ( b[0] < c[0] )
		{
			cmprs++;
			a.push_back(b[0]);
			b.erase(b.begin());
		}
		else if ( b[0] > c[0])
		{
			cmprs++;
			a.push_back(c[0]);
			c.erase(c.begin());
		}
		else if ( b[0] == c[0] )
		{
			cmprs++;
			a.push_back(b[0]);
			a.push_back(b[0]);
			c.erase(c.begin());
			b.erase(b.begin());
		}
	}
	while ( !b.empty())
	{
		a.push_back(b[0]);
		b.erase(b.begin());
	}
	while ( !c.empty())
	{
		a.push_back(c[0]);
		c.erase(c.begin());
	}
	return a;
}

vector<int>  merge_count(vector<int> n)
{
	if( n.size() <= 1)
		return n;
	int sz = n.size();
	vector<int> b(n.begin(),n.begin()+sz/2);
	vector<int> c(n.begin()+sz/2  , n.end());


	b = merge_count(b);
	c = merge_count(c);
	return merge(b,c);
}

class MergeSort {

	public: int howManyComparisons(vector<int> numbers) {

		cmprs = 0 ;
		vector<int> res = merge_count(numbers);
		return cmprs;
	}

};
