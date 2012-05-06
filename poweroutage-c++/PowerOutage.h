#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()


typedef struct scores_t {
	int cost_ret,cost_max;

}scores;

int calculate_score(int (&graph)[50][50] , vector<scores> &sc, int vertices , int node)
{
	int score = 0;

	FOR(i,0,vertices)
	{
		if ( graph[node][i]>0)
			calculate_score(graph,sc,vertices,i);
	}
	FOR(i,0,vertices)
	{
		if( graph[node][i] >= 0)
		{
			sc[node].cost_ret +=  sc[i].cost_ret +  2*(graph[node][i]);
			if ( sc[node].cost_max < sc[i].cost_max + graph[node][i] )
				sc[node].cost_max = sc[i].cost_max + graph[node][i];
		}
	}
	return score;
}


class PowerOutage {

	public: int estimateTimeOut(vector<int> fromJunction, vector<int> toJunction, vector<int> ductLength) {
		int graph[50][50];
		FOR(i,0,50)
			FOR(j,0,50)
				graph[i][j] = -1;

		int vertices=0;

		FOR(i,0,fromJunction.size())
		{
			int st = fromJunction[i];
			int end = toJunction[i];
			int cost = ductLength[i];

			graph[st][end] = cost;
			if ( vertices < end )
				vertices = end;
		}
		vertices++;

		vector<scores> sc(vertices);
		FOR(i,0,vertices)
		{
			sc[i].cost_max=0;
			sc[i].cost_ret=0;
		}
		calculate_score(graph,sc,vertices,0);

		return sc[0].cost_ret - sc[0].cost_max;
	}

};
