#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

typedef struct node_t {
	float p1,p2,p;
	vector<int> child;
}node;
node t[50];

void calculate_prob( int cur )
{

	float p0 = t[cur].p;
	FOR(i,0,t[cur].child.size())
	{
		int child_inx = t[cur].child[i];
		float pc;
		pc = t[child_inx].p1*p0 + t[child_inx].p2*(1-p0);
		t[child_inx].p = (pc);
	}
	FOR(i,0,t[cur].child.size())
		calculate_prob(t[cur].child[i]);

}

class ProbabilityTree {

	public: vector<int> getOdds(vector<string> tree, int lowerBound, int upperBound) {

		int root_inx = 0 ;
		FOR(i,0, tree.size())
		{
			const char *t_str = tree[i].c_str();
			int p1,p2,par;
			if (  strstr(t_str," ") != NULL)
			{
				sscanf(t_str,"%d %d %d",&par,&p1,&p2);
				//printf("par : %d , p1 : %d , p2 : %d\n",par,p1,p2);
				t[i].p1 = ((float)p1)/100.0,t[i].p2=((float)p2)/100.0;
				t[par].child.push_back(i);
			}
			else
			{
				int p;
				sscanf(t_str,"%d",&p);
				root_inx = i;
				t[i].p=((float)p)/100.0;
			}
		}

		calculate_prob(0);
		vector<int> ret;
		FOR(i,0,tree.size())
		{
			int p  = t[i].p*100;
			//printf("%d is %d\n",i,p);
			if ( p >= lowerBound && p< upperBound)
				ret.push_back(i);
		}

		bzero(t,50*sizeof(t[0]));
		return ret;
	}

};
