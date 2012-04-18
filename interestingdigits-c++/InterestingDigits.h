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

class InterestingDigits {

	public:  int sum_of_digits(int num,int base)
	{
		ostringstream out;
		int sum =0;
		out<<num;

		while ( num )
		{
			sum += num%base;
			num = num/base;
		}

		return sum;
	}
	public: vector<int> digits(int base) {
		vector<int> ret;
		int j=2;
		FOR( i, 2,base)
		{
			bool fail = false;
			for(j=2;j*i<base*base*base;j++)
			{
				if ( sum_of_digits(j*i, base) % i != 0 )
				{
					fail = true;
					break;
				}

			}
			if ( !fail )
				ret.push_back(i);
		}
		return ret;
	}
};
