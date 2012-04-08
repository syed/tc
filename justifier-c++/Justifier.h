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

class Justifier {

	public: vector<string> justify(vector<string> textIn) {
		int max_len = 0 ;
		FOR(i,0,textIn.size())
		{
			if ( textIn[i].length()>max_len)
				max_len = textIn[i].length();
		}
		vector<string> ret;

		string newone;
		FOR(i,0,textIn.size())
		{
			newone.clear();
			newone.append(max_len - textIn[i].length(),' ');
			newone.append(textIn[i]);

			//cout<<" noew one "<< newone<<endl;
			ret.push_back(newone);
		}
		return ret;
	}

};
