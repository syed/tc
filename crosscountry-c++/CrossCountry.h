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

#define INF (1<<30)

typedef struct team_order
{
	int score;
	int sixth;
	char team;
}team_order_t;

bool sort_score(team_order_t a, team_order_t b)
{
	if ( a.score != b.score )
		return a.score < b.score;

	//equala
	if ( a.sixth != b.sixth )
		return a.sixth < b.sixth;

	//both can be num or INF
	return a.team < b.team;
}

class CrossCountry {

	public: string scoreMeet(int numTeams, string finishOrder) {
		map<char,int> scores_map,count,sixth;
		vector< team_order_t > scores;
		string ret;
		FOR(i,0,numTeams)
			sixth['A' +i ] = count['A' + i ] = scores_map['A' + i ] = 0;

		FOR(i,0,finishOrder.size())
		{
			if (  count[finishOrder[i]] < 5 )
				scores_map[finishOrder[i]]+=(i+1);

			if (  count[finishOrder[i]] == 5 )
				 sixth[finishOrder[i]]= i+1;

			count[finishOrder[i]]++;
		}

		FORIT(i,scores_map)
		{
			team_order_t p;
			p.score = (*i).second;
			p.team = (*i).first;
			p.sixth = sixth[(*i).first]?sixth[(*i).first]:INF;
			scores.push_back(p);
		}

		sort(scores.begin(),scores.end(),&sort_score);

		FOR(i,0,scores.size())
		{
			char team = scores[i].team;
			int score = scores[i].score;
			//cout<< "team "<<team<<" score "<<score<<" count "<<count[team]<<endl;
			if ( count[team]>=5)
				ret.push_back(team);
		}
		return ret;

	}

};
