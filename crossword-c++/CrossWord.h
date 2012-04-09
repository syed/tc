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

class CrossWord {

	public: int countWords(vector<string> board, int size) {
		int ret=0;
		FOR(i,0,board.size())
		{
			FOR(j,0,board[i].size())
			{
				int num_dots = 0;

				if ( board[i][j]== '.')
				{
					//cout<<"got dot "<<board[i][j]<<endl;
					while( board[i][j] == '.' && j < board[i].size())
					{
						num_dots++;
						j++;
						// cout <<"j "<< j << " size "<< board[i].size();
					}
				}

				if ( num_dots == size )
					ret++;
			}
		}
		return ret;
	}

};
