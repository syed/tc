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

class FixedPointTheorem {

	public: double cycleRange(double R) {
		double x=0.25;
		double max,min;
		for(int i=0;i<200000;i++)
			x = R*x*(1-x);

		max = min = x;
		for(int i=0;i<1000;i++)
		{
			x = R*x*(1-x);
			if ( max < x )
				max = x;
			if ( x < min )
				min = x;
		}
		return (max - min);
	}

};
