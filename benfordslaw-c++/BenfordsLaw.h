#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

#define PROB(n) ( log10( 1 + 1/(double)n))
class BenfordsLaw {

	public: int questionableDigit(vector<int> transactions, int threshold) {
		vector<int> sums(11,0);
		int tot_num =0;
		FOR(i,0,transactions.size())
		{
			int num = transactions[i];
			int digit;
			while(num)
			{
				digit = num %10;
				num/=10;
			}
			tot_num++;
			sums[digit]++;
		}

		FOR( i, 1,10)
		{
			if( sums[i] >= threshold*tot_num*PROB(i) || sums[i] <= tot_num*PROB(i)/(double)threshold)
				return i;
		}

		return -1;
	}

};
