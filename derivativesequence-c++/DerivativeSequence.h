#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

class DerivativeSequence {

	public: vector<int> derSeq(vector<int> a, int n) {
		vector<int> prev = vector<int>(a.size(), 0);
		prev = a;
		while(n)
		{
			a = prev;
			FOR(i,0, a.size()-1)
				a[i] = a[i+1] - a[i];

			prev = vector<int>(a.begin(),a.end()-1);
			n--;
		}
	return prev;
	}
};
