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
		FOR(i,0,words.size())
		{
			FOR(j,0,words.size())
			{
				if(i!=j && (words[j].compare(0,words[i].length(),words[i]) == 0 ))
				{
					out<<"No, "<<i;
					return out.str();
				}
			}
		}
		return "Yes";
	}

};
