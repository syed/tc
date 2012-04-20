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

class SuperRot {

	public: string decoder(string message) {
		string ret;

		FOR(i,0,message.size())
		{
			char c = message[i];
			if ( c >= 'A' && c <='Z')
			{
				//capital
				if ( c < 'N')
					c+= ('N' - 'A');
				else
					c-= ('N' - 'A');
			}
			else if ( c >='a' && c<='z')
			{
				if ( c < 'n')
					c+= ('n' - 'a');
				else
					c-= ('n' - 'a');
			}
			else if ( c >='0' && c<='9')
			{
				//digit
				if( c<'5')
					c += 5;
				else
					c -= 5;
			}
			ret.push_back(c);

		}
		return ret;
	}

};
