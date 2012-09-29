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

#define SZ 10

void updateDir( int dx, int dy, vector<pair<int,int> >&dir )
{
	FOR(i,0 , dir.size()-1)
	{
		dir[i] = dir[i+1];
	}
	int sz = dir.size();

	dir[sz-1].first = dx;
	dir[sz-1].second = dy;
}

void updateCenti( vector<pair<int,int> > &centi ,vector<pair<int,int> > &dir, int x , int y , int d)
{
	int dx,dy;

	if ( d == 0 )
		dx = 1,dy=0 ;
	else
		dx= 0 ,dy = d;

	updateDir(dx,dy,dir);
	FOR(i,0,centi.size())
	{
		centi[i].first += dir[i].first;
		centi[i].second += dir[i].second;
	}
}

void print_snake(vector<string> pos, vector<pair<int,int> > centi, int d)
{
	int ht= pos.size(),wth=pos[0].size();
	FOR(i,0,centi.size())
	{
		if ( centi[i].first < ht)
			pos[centi[i].first][centi[i].second] = '~';
		printf("( %d,%d ) ", centi[i].first,centi[i].second);
	}
	printf("\nd %d \n",d);

	FOR(i,0,ht)
	{
		FOR(j,0,wth)
		{
			cout<<pos[i][j];
		}
		cout<<endl;
	}
	cout<<endl<<endl;
}

bool check_cycle( vector<pair<int,int> > centi,int ht)
{
	if ( centi[0].first >= ht)
		return true;
	return false;
}

bool is_empty( vector<string> screen,int x, int y, int d)
{
	int ht = screen.size();
	if( x >= ht )
		return true;
	else if ( screen[x][y+d] == '#' )
		return false;
	return true;
}
class Centipede {

	public: vector<string> simulate(vector<string> screen, int timeUnits) {
		vector< pair<int,int> > centi(10,make_pair(0,0));
		vector<pair<int,int> > dir(10,make_pair(0,0));


		FOR(i,0,10)
		{
			centi[i] = make_pair(0,i+1); // initial position of centipede
			dir[i] =  make_pair(0,1);
		}

		int x=0,y=10,d=1;
		vector<string> pos;
		int cycle_len=0;

		while(timeUnits)
		{

			if (is_empty(screen,x,y,d))
				updateCenti( centi, dir, x,y, d );
			else if(is_empty(screen,x+1,y,0))
			{
				d=d*-1;
				updateCenti(centi, dir,x+1,y,0 );
			}
			else
				d = d*-1;

			timeUnits--;
			cycle_len++;
			x = centi[centi.size()-1].first, y = centi[centi.size()-1].second;
			if ( check_cycle(centi,screen.size()))
			{
				cout<<"Reset"<<endl;
				FOR(i,0,centi.size())
				{
					centi[i] = make_pair(0,i+1); // initial position of centipede
					dir[i] =  make_pair(0,1);
				}
				x = 0,y=10,d=1;
				timeUnits = timeUnits % cycle_len;
				printf("New time units %d\n",timeUnits);
			}
			print_snake(screen,centi,d);
		}
		pos = screen ;
		FOR(i,0,centi.size())
			if ( centi[i].first < pos.size())
				pos[centi[i].first][centi[i].second] = 'x';

		return pos;
	}
};
