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

bool is_visited(int n, vector<int> v)
{
	FOR(i,0,v.size())
			if ( v[i] ==n )
				return true;
	return false;
}

int traverse( vector<string> graph,int start,int end, int (visited)[50])
{
	if( graph[start][end] == '1' )
		return true;

	visited[start]= 1;
	FOR(i,0,graph.size())
	{
		if ( graph[start][i] == '1' && ! visited[i])
		{
			if(  traverse(graph,i,end,visited) == true )
				return true;
		}

	}
	return false;
}

class TeamBuilder {

public: vector<int> specialLocations(vector<string> paths) {

	int sz = paths.size();
	int tot_ind=0,tot_outd=0;
	int v[50];
	FOR(i,0,sz)
		v[i] = 0;

	FOR(i,0,sz)
	{
		bool all_reachable = true;
		FOR(j,0,sz)
		{
			FOR(z,0,sz)
				v[z] = 0;
			if ( i!=j && !traverse(paths,i,j,v))
				all_reachable = false;
		}

		if ( all_reachable)
				tot_outd++;
	}

	FOR(i,0,sz)
	{
		bool all_reachable = true;
		FOR(j,0,sz)
		{
			FOR(z,0,sz)
				v[z] = 0;
			if ( i!=j && !traverse(paths,j,i,v))
				all_reachable = false;
		}

		if ( all_reachable)
				tot_ind++;
	}
	vector<int> ret;
	ret.push_back(tot_outd);
	ret.push_back(tot_ind);
	return ret;

 }

};
