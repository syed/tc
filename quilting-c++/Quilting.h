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
int get_color(int x , int y , int (&spiral_arr)[300][300] , vector<string> clist,int length,int width)
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
				//printf("x : %d , y : %d i : %d , j %d , val %d\n",x - (150-length/2)+xcoord[i],y - (150-width/2)+ycoord[j],i,j,val);
				if ( val != -1)
					color_count[val] ++;
			}

	/*FOR(i,0,clist.size())
		printf("color count i %d val %d\n",i,color_count[i]);*/

	int min = 9999;
	int min_index=0,min_count=0;
	FOR(i,0,clist.size())
	{
		if ( color_count[i] < min)
		{
			min = color_count[i];
			min_index = i;
		}
		else if ( color_count[i] == min)
		{
			if ( total_count[i] < total_count[min_index])
				min_index = i;
		}
	}

	// more than one min index ? apply rule 2

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
			color_index = get_color(x,y,spiral_arr,colorList,length,width);
			spiral_arr[x][y] = color_index;

			//cout<<"color index "<<colorList[color_index]<<" ";
			//printf("x : %d , y : %d elen %d clen %d\n",x - (150-length/2),y - (150-width/2),elen,clen);

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
		/*FOR(i,0,length)
		{
			FOR(j,0,width)
			  printf("%2d ",spiral_arr[150-length/2+i][150-width/2+j]);
			cout<<endl;
		}*/
		return colorList[color_index];
	}

};
