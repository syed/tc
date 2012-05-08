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

#define N(x) (x-'0')

#define TIMESTAMP(s) (3600*(10* N(s[0]) + N(s[1])) + 60*(10*N(s[3]) + N(s[4])) + (10* N(s[6]) + N(s[7])))

#define OVT_ST1 (TIMESTAMP("18:00:00"))
#define OVT_ST2 (TIMESTAMP("00:00:00"))


#define OVT_E1 (TIMESTAMP("23:59:59"))
#define OVT_E2 (TIMESTAMP("05:59:59"))

#define MIDNIGHT (TIMESTAMP("23:59:59"))

#define IS_OVERTIME(t) ((t>= OVT_ST1 && t<= OVT_E1) || (t>= OVT_ST2 && t<= OVT_E2))

class Salary {

	public: int howMuch(vector<string> arrival, vector<string> departure, int wage) {
		long long overtime_sec=0;
		long long normal_sec=0;
#if 0 /*GIVEUP see radeye's solution */
		FOR(i,0,arrival.size())
		{
			int avl = TIMESTAMP(arrival[i]);
			int dpt = TIMESTAMP(departure[i]);
			cout<<"arrival "<<arrival[i]<<" int "<<avl<<"departure "<<departure[i]<<" int "<<dpt<<endl;

			if (  dpt > avl )
			{
				if ( avl < OVT_ST1)
				{
					if ( dpt > OVT_E1 )
					{
						sum += (OVT_ST1 - avl)*1.5*wage;
						avl = OUT_ST1;
					}
					else
					{
						sum += (dpt - avl)*1.5*wage;
						avl = dpt;
					}
				}
				if ( dpt > OVT_E1)
				}
				else
				{
					cout<<"ERROR"<<endl;
				}

			}
			else
			{
				cout<<"Not yet impl"<<endl;
			}
		}
		cout<<"Sum "<<sum<<endl;
#endif

		FOR(i,0,arrival.size())
		{
			int avl = TIMESTAMP(arrival[i]);
			int dpt = TIMESTAMP(departure[i]);
			for(int j=avl;j!=dpt;j=(j+1)%(MIDNIGHT+1))
			{
				if ( IS_OVERTIME(j) )
					overtime_sec++;
				else
					normal_sec++;
				//cout <<" j" << j << endl;
			}
		}

		//cout<<"Overtime "<< overtime_sec/3600 <<" min " endl;
		return ((3*overtime_sec*wage + 2*normal_sec*wage)/7200);
	}

};
