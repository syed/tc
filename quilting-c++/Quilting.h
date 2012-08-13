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

#define UP 0
#define LEFT 1
#define DOWN 2
#define RIGHT 3

int elen,clen,cdir;
int total_count[50];
int get_color(int x , int y , int (&spiral_arr)[300][300] , vector<string> clist)
{
	int color_count[clist.size()];
	int xcoord[] = { -1 , 0 , 1 } , ycoord[] = { -1 , 0 , 1 };

	FOR(i,0,clist.size())
		color_count[i]=0;

	FOR( i, 0, 3 )
		FOR ( j, 0 ,3)
			if (x>=0 && y>=0 && x<300 && y< 300 && !(i == 1 && j == 1))
			{
				int val = spiral_arr[x+xcoord[i]][y+ycoord[j]];
				if ( val != -1)
					color_count[val] ++;
			}

	int min = 9999,min_index=0;

	FOR(i,0,clist.size())
	{
		if ( color_count[i] < min)
		{
			min = color_count[i];
			min_index = i;
		}
		else if ( color_count[i] == min)
		{
			if ( total_count[i] < total_count[min_index]) //rule 3
				min_index = i;
		}
	}

	total_count[min_index]++  ;
	return min_index;
}

class Quilting {

	public: string lastPatch(int length, int width, vector<string> colorList) {
		int sz = colorList.size();
		int spiral_arr[300][300];
		vector< pair<int,int> > mapping;
		FOR(i,0,300)
			FOR(j,0,300)
				spiral_arr[i][j] = -1;

		FOR(i,0,sz)
			total_count[i]=0;

		int count = 0 ;
		int x = 150,y=150;
		int cdir = 0 ,elen = 1 , clen = 0 ;
		int color_index = 0;
		int dx[] = {-1,0,1,0 }, dy[] = {0,-1,0,1};

		while(count < length*width)
		{
			color_index = get_color(x,y,spiral_arr,colorList);
			spiral_arr[x][y] = color_index;


			x += dx[cdir] , y+= dy[cdir];
			clen++;
			if ( elen == clen )
			{
				clen = 0;
				if ( cdir == 1 || cdir == 3)
					elen++;
				cdir = (cdir+1)%4;
			}


			total_count[color_index]++;
			count++;
		}

		return colorList[color_index];
	}
};
