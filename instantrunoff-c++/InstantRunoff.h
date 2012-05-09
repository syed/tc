#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i < int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

class InstantRunoff {

	public: string outcome(string candidates, vector<string> ballots) {
		//return string();
		int first = 0;
		map< char, int >ranks;
		vector<int> erase_list;
		FOR(i,0,candidates.size())
			ranks[candidates[i]] = 0;
		FOR(i,0,ballots.size())
				ranks[ballots[i][0]]++;

		FORIT(i,ranks)
		{
			int votes = (*i).second;
			if ( votes == 0)
			{
				char name = (*i).first;
				//FIXME
				FOR(x,0,ballots.size())
				{
					erase_list.clear();
					FOR(y,0,ballots[x].size())
							if ( ballots[x][y]== name)
								erase_list.push_back(y);
					FOR(z,0,erase_list.size())
						ballots[x].erase(erase_list[z],1);
				}
				ranks.erase(i);
			}
		}

		while(ballots[0].size() > 0 )
		{
			ranks.clear();
			FOR(i,0,ballots.size())
				ranks[ballots[i][0]]++;

			int lowest = ballots.size();
			FORIT(i,ranks)
			{
				char name = (*i).first;
				int votes = (*i).second;
				//cout<<" name "<< name << " votes "<<votes<<" first "<<first<<" total "<<ballots.size()<<endl;
				if ( votes > ballots.size()/2){
					string ret;
					ret.push_back(name);
					return ret;
				}

				if ( votes < lowest )
					lowest = votes;
			}
			//cout<<" lowest "<<lowest<<endl;
			FORIT(i,ranks)
			{
				int votes = (*i).second;
				if ( votes == lowest)
				{
					char name = (*i).first;
					//FIXME
					FOR(x,0,ballots.size())
					{
						erase_list.clear();
						FOR(y,0,ballots[x].size())
								if ( ballots[x][y]== name)
									erase_list.push_back(y);
						FOR(z,0,erase_list.size())
							ballots[x].erase(erase_list[z],1);
					}
					ranks.erase(i);
				}
			}
			first++;

		}
		return string();
	}

};
