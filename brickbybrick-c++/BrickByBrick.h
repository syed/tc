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
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

int brick_count,brick_time  ;
void calulate_next_pos( vector<string>&map , pair<int,int> &pos , int &vx, int &vy )
{
	int cx,cy,xx,yy;
	char val;
	int height = map.size();
	int width = map[0].size();
	pos.first += vx;
	pos.second += vy;

	cx = pos.first,cy=pos.second;

	if ( cx % 2 == 0 ) //check horizontal
	{

		if ( vx > 0 ) // check forward block
		{
			xx = (cy)/2, yy=cx/2;
		}
		else
		{
			// check behind block
			xx = (cy-1)/2, yy = (cx-1)/2;
		}
		val = map[xx][yy];

		//printf("X:(cx,cy) (%d,%d) | (vx,vy) (%d,%d) | (xx,yy) (%d,%d) , val %c \n",
		//		cx,cy,vx,vy,xx,yy,val);

		if ( val == 'B' || val == '#' || cx == 0 || cy == 0 || cx == width*2 || cy == height*2)
		{
			if ( val == 'B')
			{
				brick_count--;
				brick_time = 0 ;
				map[xx][yy] = '.';
			}
			vx *=(-1); // change direction
		}
	}
	else if ( cy % 2 == 0 ) //check horizontal
	{
		if ( vy > 0 ) // check bottom block
		{
			xx = cy/2, yy = cx/2;
		}
		else
		{
			// check top block
			xx = (cy-1)/2 , yy = (cx-1)/2;
		}
		if ( xx<0 || yy<0 || xx>=height || yy>=width )
			val = '#';
		else
			val = map[xx][yy];


		//printf("Y:(cx,cy) (%d,%d) | (vx,vy) (%d,%d) | (xx,yy) (%d,%d) , val %c \n",
		//		cx,cy,vx,vy,xx,yy,val);

		if ( val == 'B' || val == '#' || cx == 0 || cy == 0 || cx == width*2 || cy == height*2)
		{
			if ( val == 'B')
			{
				brick_count--;
				brick_time = 0;
				map[xx][yy] = '.';
			}

			vy *=(-1); // change direction
		}
	}

}

void print_maze(vector<string>map)
{
	cout<<"--------------"<<endl;
	FOR(i,0,map.size())
	{
		FOR(j,0,map[0].size())
		{
				cout<<map[i][j];
		}
		cout<<endl;
	}
}

void count_bricks(vector<string> map)
{
	FOR(i,0,map.size())
		FOR(j,0,map[i].size())
			if(map[i][j] == 'B')
				brick_count++;
}

class BrickByBrick {

	public: int timeToClear(vector<string> map) {
		pair <int,int> cur_pos(1,0);
		int time=0,vx=1,vy=1;
		int height= map.size(),width = map[0].size();
		//cout<<"height "<<height<<" width "<<width<<endl;
		brick_count=0,brick_time=0;
		count_bricks(map);
		while(1)
		{
			print_maze(map);
			calulate_next_pos(map,cur_pos,vx,vy);
			time++;
			brick_time++;
			if ( brick_time > 4*height*width )
			{
				time=-1;
				break;
			}

			if ( brick_count == 0 )
				break;

		}
		return time;
	}

};
