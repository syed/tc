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

class TireRotation {

	public: int getCycle(string initial, string current) {

		FOR(i,1,5)
		{
			if (initial==current)
				return i;

			char temp1,temp2;
			temp1=current[0];
			temp2=current[1];
			current[0]=current[2];
			current[1]=current[3];
			current[2]=temp2;
			current[3]=temp1;

			//cout<<current<<endl;
		}
		return -1;

	}

};
