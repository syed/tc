#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

class BigCube {

	public: string largestCube(vector<string> range) {
		long long max_cube = -1;
		FOR(i, 0, range.size())
		{
			long long num1,num2;
			sscanf(range[i].c_str(),"%lld-%lld",&num1,&num2);
			int cbrt_start = fabs(cbrt(num1)) - 1;
			int cbrt_end = fabs(cbrt(num2)) + 1;

			//cout<<"cbrt start "<<cbrt_start<< " cbrt end "<<cbrt_end<<endl;
			for( long long j = cbrt_end ; j >= cbrt_start ; j-- )
			{
				long long j_cube = j*j*j ;

				if( j_cube >= num1 && j_cube <= num2 && j_cube > max_cube )
					max_cube = j_cube;
			}
		}
		if (max_cube== -1)
			return string();

		ostringstream out;
		out<<max_cube;
		return out.str();
	}

};
