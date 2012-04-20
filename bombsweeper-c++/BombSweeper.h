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

#define LEFT(i,j) ((i>=len||j-1<0)? '.': board[i][j-1])
#define RIGHT(i,j) ((i>=len||j+1>=width)? '.': board[i][j+1])
#define UP(i,j) ((j>=width||i-1<0)? '.': board[i-1][j])
#define DOWN(i,j) ((j>=width||i+1>=len)? '.': board[i+1][j])


#define DIA_UP_LEFT(i,j) ((i-1<0||j-1<0)? '.': board[i-1][j-1])
#define DIA_DOWN_RIGHT(i,j) ((i+1>=len||j+1>=width)? '.': board[i+1][j+1])

#define DIA_UP_RIGHT(i,j) ((i-1<0||j+1>=width)? '.': board[i-1][j+1])
#define DIA_DOWN_LEFT(i,j) ((j-1<0||i+1>=len)? '.': board[i+1][j-1])


#define IS_GOOD(i,j) ( (LEFT(i,j) != 'B') && (RIGHT(i,j) != 'B')\
					  && (UP(i,j)!= 'B') && (DOWN(i,j) != 'B')\
					  && (DIA_UP_LEFT(i,j)!='B') && (DIA_UP_RIGHT(i,j)!='B')\
					  && (DIA_DOWN_LEFT(i,j)!='B') && (DIA_DOWN_RIGHT(i,j)!='B'))

#define IS_BAD(i,j) ( board[i][j] == 'B')


class BombSweeper {

	public: double winPercentage(vector<string> board) {
		int len = board.size();
		int width = board[0].size();
		int loss=0;int win=0;
		FOR(i,0,len)
			FOR(j,0,width)
			{
				if( IS_BAD(i,j))
					loss++;
				else if ( IS_GOOD(i,j))
					win++;
			}
		return ((win/(double)(win+loss))*100);
	}

};
