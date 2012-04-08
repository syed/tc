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

class StairClimb {

	public: int stridesTaken(vector<int> flights, int stairsPerStride) {
		int strides=0;
		FOR(i,0,flights.size())
		{
			strides += flights[i]/stairsPerStride;
			if ( flights[i]%stairsPerStride != 0)
				strides+=1;
			//turn at landing
			strides+=2;
		}
		//remove last
		strides -=2;
		return strides;
	}

};
