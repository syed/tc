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

class PaternityTest {

	public: vector<int> possibleFathers(string child, string mother, vector<string> men) {

		string remain;
		FOR(i,0,child.size())
		{
			bool match=false;
			FOR(j,0,mother.size())
				if ( child[i] == mother[j])
					match = true;

			if ( !match )
				remain.push_back(child[i]);
		}
		int sz = child.size();
		vector<int> ret;
		FOR(i,0,men.size())
		{
			bool bad = false;
			int of=0,om=0;
			FOR(j,0,child.size())
			{
				if( child[j] == men[i][j])
					of++;
				else if ( child[j] == mother[j])
					om++;
				else
				{
					bad = true;
					break;
				}
			}
			if ( !bad && of >= sz/2 )
				ret.push_back(i);
		}

		return ret;
	}

};
