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

/*
 *  a*b = lcm(a,b)*gcd(a,b)
 * ==> lcm(a,b) = ( a*b ) / gcd(a,b)
 * lcm( a0,a1.....an) = lcm( a0, lcm(a1,.....an))
 *
 */
#define NUM_PRIMES 9
class LCMRange {

	public: int lcm(int first, int last) {
		vector<int> list;
		FOR(i,first,last+1)
			list.push_back(i);
		int primes[] = { 2,3,5,7,11,13,17,19 };
		bool is_div=true;
		int lcm = 1;

		FOR(i,0,NUM_PRIMES)
		{
			is_div = true;
			while(is_div)
			{
				is_div=false;
				FOR(j,0,list.size())
				{
					if ( list[j] != 1 && list[j] % primes[i] == 0 )
					{
						is_div = true;
						list[j] /= primes[i];
					}

				}
				if( is_div )
					lcm *= primes[i];
			}
		}
		return lcm;
	}

};
