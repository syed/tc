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

class HourGlass {

	public: vector<int> measurable(int glass1, int glass2) {
		set<int> vals;
		vals.insert(glass1);
		vals.insert(glass2);
		FOR(i,1,11)
		{
			vals.insert(glass1*i);
			vals.insert(glass2*i);
		}
		if ( glass1 < glass2 )
		{
			int temp=glass1;
			glass1=glass2;
			glass2=temp;
		}

		if ( glass1 % glass2 != 0 )
		{

			int diff1 = (glass1 % glass2);
			int num2 = ((glass1/glass2) +1 ) * glass2;
			int diff2 = num2 - glass1;

			FOR(i,1,11)
				FOR(j,1,11)
					vals.insert(i*glass1+j*glass2);
			FOR(i,0,11)
			{
				vals.insert(glass1+diff1*i);
				vals.insert(glass1+diff1*i+glass2);
				vals.insert(num2+diff2*i);
				vals.insert(num2+diff2*i+glass1);
			}
		}

		vector<int> ret(vals.begin(),vals.end());

		sort(ret.begin(),ret.end());
		return vector<int>(ret.begin(),ret.begin()+10);
	}
};
