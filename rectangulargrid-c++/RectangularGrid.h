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

class RectangularGrid {

	public: long long countRectangles(int width, int height) {
		long long ways=0;
		FOR(i,0,width)
		{
				FOR(j,0,height)
				{
					if ( i!=j )
						ways+= ( (width+1) - (i+1)) * ( (height +1) - (j+1) );
				}
		}
		cout<<"Wasy"<<ways;
		return ways;
	}

};
