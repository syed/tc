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

class DivisorDigits {

	public: int howMany(int num) {
		int count=0;
		for ( int i=1; i<= num ; i*=10)
		{
			int digit = (num % (i*10))/i;
			if ( (digit != 0) && (num % digit) == 0 )
				count++;
		}
		return count;
	}

};
