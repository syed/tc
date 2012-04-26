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
#define INT_TO_STR(i,s) do{\
	ostringstream out;\
	out << i;\
	s = out.str();\
	}while(0)


class PartySeats {

	public: vector<string> seating(vector<string> attendees) {
		vector<string> boys,girls,ret;

		FOR(i,0,attendees.size())
		{
			int pos = attendees[i].find(' ');
			string name = attendees[i].substr(0,pos);
			string gender = attendees[i].substr(pos+1);

			//cout<<"Name "<<name<<" gender "<<gender<<endl;
			if ( gender == "boy")
				boys.push_back(name);
			else
				girls.push_back(name);
		}

		if ( boys.size() != girls.size())
			return ret;
		if ( boys.size() < 2)
			return ret;
		if ( boys.size() % 2 !=0)//no odded
			return ret;


		sort(ISEQ(boys));
		sort(ISEQ(girls));

		FOR(i,0,girls.size())
		{
			if ( i<girls.size()/2 )
			{
				ret.push_back(girls[i]);
				ret.push_back(boys[i]);
			}
			else
			{
				ret.push_back(boys[i]);
				ret.push_back(girls[i]);
			}
		}

		ret.insert(ret.begin(),"HOST");
		ret.insert(ret.begin() + ret.size()/2 +1,"HOSTESS");
		return ret;
	}

};
