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

bool is_magic(vector<int> num)
{
	int sum = num[0] + num[1] +  num[2];

	FOR(i,0,3) //row
	{
		int temp_sum=0;
		FOR(j,0,3)
			temp_sum += num[3*i+j];

		if ( temp_sum  != sum )
			return false;

		temp_sum = 0;
		FOR(j,0,3)
			temp_sum += num[3*j+i];

		if ( temp_sum  != sum )
			return false;
	}
	return true;
}
class MNS {

	public: int combos(vector<int> numbers) {
		sort(numbers.begin(),numbers.end());
		int count = 0;
		if ( is_magic(numbers))
			count++;
		while( next_permutation(numbers.begin(),numbers.end()))
		{
			if ( is_magic(numbers) )
				count++;
		}
		return count;
	}

};
