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

class PrefixCode {

	public: string isOne(vector<string> words) {

		ostringstream out;
		int cur_min = 9999999 ;
		bool match = false;
		FOR(i,0,words.size())
		{
			FOR(j,0,words.size())
			{
				if(i!=j && (words[i].compare(0,words[j].length(),words[j]) == 0 ) && j < cur_min)
				{
					cur_min = j;
					match = true;
				}
			}
		}
		if ( match )
		{
			out<<"No, "<<cur_min;
			return out.str();
		}
		return "Yes";
	}

};
