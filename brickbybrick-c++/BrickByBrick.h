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

bool brick_exists(vector<string> map)
{
	FOR(i,0,map.size())
		FOR(j,0,map[i].size())
			if(map[i][j] == 'B')
				return true;

	return false;
}

int calculate_pos(pair<int,int> &cpos, int dir, vector<string> &map)
{
	int width = map[0].size();
	int height = map.size();
	pair<int,int> next_pos;
	int i,j;
	int dir_old = dir;
	if ( dir == 0 ) // down right
	{
		i = cpos.first+1;
		j = cpos.second+1;
	}
	else if ( dir == 1 ) // down left
	{
		i = cpos.first+1;
		j = cpos.second-1;
	}
	else if ( dir == 2 ) // top right
	{
		i = cpos.first-1;
		j = cpos.second-1;
	}
	else if ( dir == 3 ) // top left
	{
		i = cpos.first-1;
		j = cpos.second+1;
	}
	// direction change
	if ( i ==  -1 || i == 2*height || j == -1 || j == 2*width   )
	{
		dir = (dir+1)%4;
	}

	else if ( map[i/2][j/2] == 'B')
	{
		map[i/2][j/2] = '.';
		dir = (dir+1)%4;
	}
	else if ( map[i/2][j/2] == '#')
	{
		dir = (dir+1)%4;
	}
	cout<<"old ( "<<cpos.first<<","<<cpos.second<<","<<dir_old\
		 <<") new ("<<i<<","<<j<<","<<dir<<")"<<endl;
	cpos.first=i;
	cpos.second=j;
	return dir;
}

class BrickByBrick {

	public: int timeToClear(vector<string> map) {
		pair <int,int> cur_pos(0,1);
		int dir=0,time=0;
		int height= map.size(),width = map[0].size();
		cout<<"height "<<height<<"width "<<width<<endl;
		while(1)
		{
			dir = calculate_pos(cur_pos,dir,map);
			int i,j;
			i = cur_pos.first,j=cur_pos.second;

			if (!( i ==  -1 || i == 2*height || j == -1 || j == 2*width))
				time++;

			if ( !brick_exists(map))
				break;

		}
		return time;
	}

};
