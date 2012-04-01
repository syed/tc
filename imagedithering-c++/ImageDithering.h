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

class ImageDithering {

	public: int count(string dithered, vector<string> screen) {
		/*Char count */
		int n=0;
		FOR(i,0,screen.size())
			FOR(j,0,screen[i].length())
				if ( dithered.find(screen[i][j]) != string::npos )
					n++;
		return n;
	}

};
