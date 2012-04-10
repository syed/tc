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

class RGBColor {

	public: vector<int> getComplement(vector<int> rgb) {
		vector<int> comp;

		FOR(i,0,rgb.size())
			comp.push_back(255-rgb[i]);

		bool diff_good = false;
		FOR(i,0,rgb.size())
		{
			if ( abs( comp[i] - rgb[i]) >= 32 )
				diff_good = true;
		}
		if ( ! diff_good)
		{
			comp.clear();
			FOR(i,0,rgb.size())
			{
				if ( rgb[i] + 128 <= 255 )
					comp.push_back( rgb[i] + 128 );
				else
					comp.push_back( rgb[i] - 128 );
			}
		}
		return comp;
	}

};
