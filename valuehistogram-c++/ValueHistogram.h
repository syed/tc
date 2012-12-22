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

#define FOR(i,s,e) for (int i = int(s); i < int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()


class ValueHistogram {

	public: vector<string> build(vector<int> values) {
		vector<int> count(10,0);
		FOR(i,0,values.size())
			count[values[i]]++;

		int ht = *max_element(count.begin(),count.end()) + 1;
		vector<string> ret;
		FOR(i,0,ht)
		{
			string str(10,'.');
			FOR(j,0,count.size())
			{
				if ( count[j])
				{
					str[j] = 'X';
					count[j]--;
				}
			}
			ret.push_back(str);
		}
		return vector<string> (ret.rbegin(),ret.rend());
	}

};
