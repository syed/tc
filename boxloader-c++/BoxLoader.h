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

class BoxLoader {

	public: int mostItems(int boxX, int boxY, int boxZ, int itemX, int itemY, int itemZ) {
		int dim[3] = { itemX, itemY, itemZ };
		int max_items = 0;

		int o[6][3] = { {0,1,2},{0,2,1},
							 {1,0,2},{1,2,0},
							 {2,0,1},{2,1,0}};



		FOR(i,0,6)
		{
			int x = boxX/dim[o[i][0]];
			int y = boxY/dim[o[i][1]];
			int z = boxZ/dim[o[i][2]];

			if( x > 0 && y > 0 && z > 0)
			{
				if ( x*y*z > max_items)
					max_items = x*y*z;
			}
		}
		return max_items;
	}

};
