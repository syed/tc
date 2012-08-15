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

#define SZ(n) (n>=0?(n>9?(n>99?3:2):1):(n>=-99?((n>=-9)?2:3):4))
int vec[30][30];
int max_score = -999999;
vector<int> res;

int combinations(vector<int> v,int n,int r,int start,int cpos)
{
	if(cpos == r )
	{
		v.push_back(start);
		int score = 0 ;
		FOR(i,1,v.size())
		{
			FOR(j,i,v.size())
				score+= vec[v[i]-1][v[j]-1];
		}
		if ( score > max_score )
		{
			max_score = score;
			res = v;
		}
		return 0;
	}
	v.push_back(start);
	FOR(i,start,n)
		combinations(v,n,r,i+1,cpos+1);

	return 0;
}

class PickTeam {

	public: vector<string> pickPeople(int teamSize, vector<string> people) {

		vector<string> names;
		max_score = -999999;

		FOR(i,0,people.size())
		{
			char name[50];
			char *ip = (char *)people[i].c_str();
			sscanf(ip,"%s",name);
			//printf("%s ",name );
			names.push_back(string(name));
			ip += strlen(name) +1 ;
			FOR(j,0,people.size())
			{
				int n;
				sscanf(ip,"%d",&n);
				//printf(" %d",n);
				vec[i][j] = n;
				ip += SZ(n) + 1;
			}
			printf("\n");
		}
		vector<int> v;
		combinations(v,people.size(),teamSize,0,0);

		vector<string> ret;
		FOR(i,1,res.size())
			ret.push_back(names[res[i]-1]);

		sort(ret.begin(),ret.end());
		return ret;

	}

};
