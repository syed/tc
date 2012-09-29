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


class BoardSplitting {

	public: int minimumCuts(int dl, int dc, int al) {

		if ( dl % al == 0 )
			return 0;

		int total_cuts = 0 ;
		if ( dl > al )
		{
			int num = dl/al;
			int remain = dl % al;
			int cuts = (al%remain)?(al/remain) : (al/remain) -1 ; //for 1 block

			total_cuts = dc*cuts/(cuts+1);

			if ( dc*cuts % al != 0 )
				total_cuts ++;
		}
		else if ( al > dl )
		{
			int num = al/dl;
			int remain = al % dl;
			int cuts = num -1 ; //for 1 block

			total_cuts = dc*cuts/(cuts+1);
			if ( dc*cuts % dl != 0 )
				total_cuts ++;
		}
		return total_cuts;
	}

};
