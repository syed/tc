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


class Cubism {

	public: int lines(vector<string> lattice, string color) {

		char cube[4][4][4];
		FOR(i,0,4)
		{
			FOR(j,0,4)
			{
				FOR(k,0,4)
				{
					cube[i][j][k] = lattice[i][4*j + k];
					//cout<<"(i,j,k,v) "<<i<<j<<k<<lattice[i][4*j+k]<<endl;
				}
			}
		}
		char color_match;

		if (color == "black")
			color_match='B';
		else
			color_match = 'W';

		int tot_count = 0;
		/* total horizontal and vertial lines in all faces
		 * ( 4h + 4v + 4(up-down) ) * 4 faces = 48 lines
		 * now total diagonal lines in a face = 2 ( the X mark )
		 * we can go top-down left-right front-back
		 * ( 2*3 ) * 4 faces = 24 lines
		 * now we are left with four major diagonals connecting the
		 * opposite cornors
		 * total = 48 + 24 + 4 = 76
		 */

		//rows & cols
		FOR(i,0,4)
		{
			FOR(j,0,4)
			{
				int counts[3] = {0,0,0};
				FOR(k,0,4)
				{
					if ( cube[i][j][k] == color_match)
						counts[0]++;
					if ( cube[i][k][j] == color_match)
						counts[1]++;
					if ( cube[k][j][i] == color_match)
						counts[2]++;
				}
				FOR(z,0,3)
				{
					if( counts[z] == 4)
						tot_count++;
				}
			}
		}

		// face diagonals
		FOR(i,0,4)
		{
			int diag_counts[6] = {0,0,0,0,0,0};
			FOR(j,0,4)
			{
				if ( cube[i][j][j] == color_match)
					diag_counts[0]++;
				if ( cube[i][3-j][j] == color_match)
					diag_counts[1]++;
				if ( cube[j][j][i] == color_match)
					diag_counts[2]++;
				if ( cube[3-j][j][i] == color_match)
					diag_counts[3]++;
				if ( cube[j][i][j] == color_match)
					diag_counts[4]++;
				if ( cube[3-j][i][j] == color_match)
					diag_counts[5]++;
			}
			FOR(z,0,6)
			{
				if( diag_counts[z] == 4)
					tot_count++;
			}
		}

		// major diagonals
		int major_diag_counts[4] = { 0,0,0,0};
		FOR(i,0,4)
		{
			if ( cube[i][i][i] == color_match)
				major_diag_counts[0]++;
			if ( cube[3-i][3-i][i] == color_match)
				major_diag_counts[1]++;
			if ( cube[i][3-i][3-i] == color_match)
				major_diag_counts[2]++;
			if ( cube[3-i][i][3-i] == color_match)
				major_diag_counts[3]++;
		}
		FOR(z,0,4)
		{
			if( major_diag_counts[z] == 4)
				tot_count++;
		}
		return tot_count;
	}

};
