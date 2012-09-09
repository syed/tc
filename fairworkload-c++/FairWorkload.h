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
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i < (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

int calculate_max_books(vector<int> pos, vector<int> folders)
{
	pos.insert(pos.begin(),0);
	pos.push_back(folders.size());

	int max = -1;
	FOR(i,0,pos.size()-1)
	{
		int books = 0 ;
		FOR(j,pos[i],pos[i+1])
			books+=folders[j];

		if ( books > max )
			max = books;
	}
	//cout<<" max "<<max<<endl;
	return max;
}

int combinations( int n , int r , int count ,int start , vector<int> vals , vector<int> folders)
{
	if ( count == r )
	{
		//FOR(i,0,vals.size())
		//		cout<<" "<<vals[i];
		//cout<<endl;

		return calculate_max_books(vals,folders);
	}

	vector<int> newVals;
	int min = 9999999;
	FOR(i,start,n)
	{
		int v;
		newVals = vals;
		newVals.push_back(i+1);
		v = combinations(n,r,count+1,i+1,newVals,folders);
		if ( v < min )
			min = v;
	}
	return min;
}

class FairWorkload {

	public: int getMostWork(vector<int> folders, int workers) {
		vector<int> res;
		return combinations(folders.size()-1,workers-1,0,0,res,folders);
	}

};
