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

#define IS_TRIANGLE(a,b,c) ( a+b > c && b+c > a && c+a > b)
class Workshop {

	public: int pictureFrames(vector<int> pieces) {
		int num_t=0;
		FOR(i,0,pieces.size())
				FOR(j,i+1,pieces.size())
					FOR(k,j+1,pieces.size())
					{
						if ( j < pieces.size() && k< pieces.size())
						{
							int a = pieces[i] , b = pieces[j], c = pieces[k];
							if ( IS_TRIANGLE(a,b,c))
								num_t++;
						}
					}

		return num_t;
	}

};
