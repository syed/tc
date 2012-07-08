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

#define SWAP_ROW(a,b,col,v) \
do{\
	char t = v[col][a];\
	v[col][a] = v[col][b];\
	v[col][b] = t;\
}while(0)

#define SWAP_COL(a,b,row,v) \
do{\
	char t = v[a][row];\
	v[a][row] = v[b][row];\
	v[b][row] = t;\
}while(0)

#define PRINT_VECTOR(v)\
do{\
	cout<<"-----------------"<<endl;\
	FOR(x,0,v.size())\
	{\
		FOR(y,0,v[0].size())\
		{\
			cout<<" "<<v[x][y];\
		}\
		cout<<endl;\
	}\
}while(0)
/* check if move is valid
 * 	move is valid if
 *	1) top two are same as this one
 *	2) bottom two are same as this one
 *	3) top and bottom are same as this one
 *
 *
 *	This applies to the row too
 */

bool is_valid_row(vector<string> board,int pos,int row)
{
	int sz=board[0].size();
	if ( sz<2 )
		return false;
	if (pos > 1 && board[row][pos] == board[row][pos-1] && board[row][pos-1] == board[row][pos-2]  )
		return true;
	if (pos > 0 && pos < sz -1  && board[row][pos] == board[row][pos-1] && board[row][pos-1] == board[row][pos+1]  )
		return true;
	if (pos >=0 && pos < sz - 2 && board[row][pos] == board[row][pos+1] && board[row][pos+1] == board[row][pos+2]  )
		return true;

	return false;
}

bool is_valid_col(vector<string> board,int pos,int col)
{
	//

	int sz=board.size();
	if ( sz<2 )
		return false;
	if (pos > 1 && board[pos][col] == board[pos-1][col] && board[pos-1][col] == board[pos-2][col])
		return true;
	if (pos > 0 && pos < sz -1  && board[pos][col] == board[pos-1][col] && board[pos-1][col] == board[pos+1][col])
			return true;
	if (pos >= 0 && pos < sz -2 && board[pos][col] == board[pos+1][col] && board[pos+1][col] == board[pos+2][col])
			return true;
	return false;
}


class Gems {

	public: int numMoves(vector<string> board) {
		int moves = 0 ;
		FOR(i,0,board.size())
		{
			FOR(j,0,board[0].size()-1)
			{
				vector<string> temp;
				temp=board;
				SWAP_ROW(j,j+1,i,temp);
				//PRINT_VECTOR(temp);
				if ( is_valid_col(temp,i,j) || is_valid_col(temp,i,j+1) )
						moves++;
				else if ( is_valid_row(temp,j,i) || is_valid_row(temp,j+1,i) )
						moves++;
			}

		}
		FOR(i,0,board[0].size())
		{
			FOR(j,0,board.size()-1)
			{
				vector<string> temp;
				temp=board;
				SWAP_COL(j,j+1,i,temp);
				if ( is_valid_col(temp,j,i) || is_valid_col(temp,j+1,i) )
						moves++;
				else if ( is_valid_row(temp,i,j) || is_valid_row(temp,i,j+1) )
						moves++;
			}

		}
		return moves;
	}
};
