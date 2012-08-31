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

int calculate_tree_dist(int i , int j , vector<pair<int,int> > trees)
{
	int min_dist = 999999;
	FOR(t,0,trees.size())
	{
		int d = abs(trees[t].first - i) + abs(trees[t].second - j );
		if ( d < min_dist)
			min_dist = d;
	}
	return min_dist;
}

class Orchard {

	public: vector<int> nextTree(vector<string> orchard) {
		int score_arr[50][50];
		int ht = orchard.size() , width = orchard[0].size();
		vector<pair <int,int> > trees;
		FOR(i,0,ht)
		{
			FOR(j,0,width)
			{
				if(orchard[i][j] == 'T')
				{
					score_arr[i][j] = -1;
					trees.push_back(make_pair(i,j));
				}
				else
					score_arr[i][j] = 0;
			}
		}

		int max_score = -1;
		vector<int> values_list;
		pair<int,int> ret_pair;
		FOR(i,0,ht)
		{
			FOR(j,0,width)
			{
				if( score_arr[i][j] != -1 )
				{
					int sc = calculate_tree_dist( i , j , trees);
					//cout<<"  "<<i<<" "<<j<<" "<<sc<<endl;
					values_list.clear();
					// possible values are sc , left dist, right dist ,top dist , bottom dist
					values_list.push_back(sc);
					values_list.push_back(i+1);
					values_list.push_back(j+1);
					values_list.push_back(ht-i);
					values_list.push_back(width-j);

					int max_dist = *min_element(values_list.begin(), values_list.end());
					//cout<<" i , j , min_dist "<<i<<" "<<j<<" "<<max_dist<<endl;

					if ( max_dist > max_score )
					{
						max_score = max_dist;
						ret_pair.first = i;
						ret_pair.second =j;
					}


				}
			}
		}
		vector<int> ret;
		ret.push_back(ret_pair.first+1);
		ret.push_back(ret_pair.second+1);
		return ret;
	}

};
