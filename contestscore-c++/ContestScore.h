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

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

typedef struct group_t
{
	string name;
	int rank;
	float score;
} group ;


void calculate_ranks(int (&r)[50][50],float s[50][50],int height,int width)
{
	vector< pair< float, int> > v;
	FOR(i,0,width)
	{
		v.clear();
		FOR(j,0,height)
		{
			v.push_back( make_pair(s[j][i],j ));
		}
		sort(v.rbegin(),v.rend());
		int rank = 1 , next_rank = 1;
		float prev_score = -1;
		FOR(j,0,height)
		{
			if ( v[j].first < prev_score )
			{
				rank+=next_rank;
				next_rank=1;
			}
			else if (  v[j].first == prev_score )
				next_rank++;

			r[v[j].second][i] = rank;
			prev_score = v[j].first;
		}
	}
}

bool group_sort(group g1,group g2)
{
	if ( g1.rank<g2.rank)
		return true;
	else if ( g1.rank == g2.rank )
	{
		if ( g1.score > g2.score )
			return true;
		else if ( g1.score == g2.score )
		{
			if ( g1.name.compare(g2.name) < 0 )
				return true;
		}
	}
	return false;
}

class ContestScore {

	public: vector<string> sortResults(vector<string> data) {

		vector<string> names;
		float scores[50][50];
		int ranks[50][50];
		int width=0;
		FOR(i,0,data.size())
		{
			char name[12];
			char *ip = (char *)data[i].c_str();
			char *end = ip + data[i].size();
			sscanf(ip,"%s",name);
			//printf("Name: %s\n",name);
			ip += strlen(name)+1;
			names.push_back(string(name));
			int j=0;
			while(ip < end)
			{
				float score;
				sscanf(ip,"%f",&score);
				//printf("Score %2.1f\n",score);
				ip+=5;
				scores[i][j] = score;
				j++;
			}
			width=j;
		}
		calculate_ranks(ranks,scores,data.size(),width);

		vector<group> gr;
		FOR(i,0,data.size())
		{
			group g;
			g.name = names[i];
			g.score = 0;
			g.rank = 0;
			FOR(j,0,width)
			{
				g.score += scores[i][j];
				g.rank += ranks[i][j];
			}
			gr.push_back(g);
		}
		sort(gr.begin(),gr.end(),group_sort);
		vector<string> ret;
		FOR(i,0,gr.size())
		{
			char val[50];
			group g= gr[i];
			sprintf(val,"%s %d %03.1f",g.name.c_str(),g.rank,g.score);
			ret.push_back(string(val));
		}
		return ret;
	}
};
