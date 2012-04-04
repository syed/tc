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

/*  incrementing every time you see an 'X'
 *  and multiplying by 10 every time you see a '-'
 *  (except for the trailing '-'):
 */
class Quipu {

	public: int readKnots(string knots) {
		string::reverse_iterator i = knots.rbegin();
		int digit,number=0,base=1;
		while(i != knots.rend())
		{
			if (*i == '-')
			{
				i++;
				while ( *i == '-')
				{
					base = base*10;
					i++;
				}
			}
			if( *i == 'X')
			{
				digit = 0;
				while ( *i == 'X')
				{
					digit++;
					i++;
				}

				number = number + base*digit;
				base = base*10;
			}
		}
		return number;
	}

};
