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


class Books {

	public: int sortMoves(vector<string> titles) {

		int lcs[titles.size()];

		FOR(i,0,titles.size())
			lcs[i] = 1;
		int max_lcs = 1;
		FOR(i,0,titles.size())
		{
			FOR(j,i+1,titles.size())
			{
				if ( titles[j] >= titles[i] && lcs[j] < lcs[i] + 1)
					lcs[j] = lcs[i] + 1;
				if ( lcs[j] > max_lcs)
					max_lcs = lcs[j];
			}
		}
		//cout<<"lcs "<<max_lcs<<endl;
		return titles.size() - max_lcs;
	}

};
