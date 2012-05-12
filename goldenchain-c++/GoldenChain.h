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


class GoldenChain {

	public: int minCuts(vector<int> sections) {

		if ( sections.size() == 1 )
			return 1;

		sort(sections.rbegin(),sections.rend());
		int cuts = 0 ;

		while ( 1 )
		{
			if ( cuts + sections[sections.size()-1] >= sections.size())
				break;

			cuts+=sections[sections.size()-1];
			sections.pop_back();
			//cout<<" Cuts "<<cuts<<" Size "<<sections.size()<<endl;
		}
		int remaining = sections.size() - cuts;
		return cuts+ remaining;
	}

};
