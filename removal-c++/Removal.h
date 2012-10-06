#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()


class Removal {

	public: int finalPos(int n, int k, vector<string> remove) {
		int sz = remove.size();
		int st[sz],end[sz];
		FOR(i,0,sz)
			sscanf(remove[i].c_str(),"%d-%d",&st[i],&end[i]);


		int diff = 0 ;
		for(int i = sz-1 ; i >=0 ;i--)
		{
			if ( k >= st[i])
				k += end[i] - st[i] + 1;
		}

		if ( k > n || k < 1 )
			k = -1;
		return k;
	}

};
