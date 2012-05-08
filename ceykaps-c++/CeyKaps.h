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

class CeyKaps {

	public: string decipher(string typed, vector<string> switches) {

		map<char,char> final_sw;
		map<char,char>::iterator it;
		istringstream in;
		string ret;
		FOR(i,0,typed.length())
		{
			char c = typed[i];
			FOR(j,0,switches.size())
			{
				if( c == switches[j][0])
					c = switches[j][2];
				else if ( c == switches[j][2])
					c = switches[j][0];
			}
			ret.push_back(c);
		}
		return ret;
	}

};
