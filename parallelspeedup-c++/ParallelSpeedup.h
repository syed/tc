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
#define INT_TO_STR(i,s) do{\
	ostringstream out;\
	out << i;\
	s = out.str();\
	}while(0)

int nc2(int n)
{
	return (n*(n-1))/2;
}

class ParallelSpeedup {

	public: int numProcessors(int k, int overhead) {
		int min_p = 1;
		int min_time = k;
		FOR(i,2,k+1)
		{
			int ov = nc2(i)*overhead;
			if ( ov > int(k+i-1/i))
				break;

			if ( ov+int((k+i-1)/i) < min_time)
			{
				min_time = ov + int((k+i-1)/i) ;
				min_p = i;
			}

		}
		return min_p;
	}

};
