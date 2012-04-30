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
#define INT_TO_STR(i,s) do{\
	ostringstream out;\
	out << i;\
	s = out.str();\
	}while(0)

int mod10(int v)
{
	if ( v>=0 )
		return v%10;

	return (10-((-v)%10))%10;
}

class RecurrenceRelation {

	public: int moduloTen(vector<int> coff, vector<int> init, int N) {
		int val,j;
		if ( N < init.size() )
			return mod10(init[N]);

		FOR(i,0,N-init.size()+1)
		{
			val = 0, j=0;
			FOR(j,0,init.size())
			{
				val += mod10((coff[j]) * init[j]);
			}
			//cout<<"val "<<val<<endl;
			init.erase(init.begin());
			init.push_back(val);
		}
		return mod10(val);
	}

};
