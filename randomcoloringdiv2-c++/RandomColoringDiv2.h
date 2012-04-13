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

class RandomColoringDiv2 {

	public: int getCount(int maxR, int maxG, int maxB, int startR, int startG, int startB, int d1, int d2) {
		int ways =0;
		FOR(i,0,maxR)
				FOR(j,0,maxG)
					FOR(k,0,maxB)
					{
						//cout <<"RGB ("<<i<<","<<j<<","<<k<<") d1 d2 " << d1 << ","<<d2<<endl;

						if ( (abs(i-startR) <= d2 && abs(j-startG)<=d2 && abs(k-startB)<=d2)&& (abs(i-startR) >= d1 || abs(j-startG)>=d1 || abs(k-startB)>=d1) )
									ways++;

					}


	return ways;
	}

};
