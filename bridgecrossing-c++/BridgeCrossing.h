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

	//cout<<"inserting "<<e<<" to "<<#v<<endl;
#define INSERT(v,e) do{\
	v.push_back(e);\
	sort(v.begin(),v.end());\
	} while(0)

//	cout<<"removing "<<v[pos]<<" from "<<#v<<endl;
#define REMOVE(v,pos) do{\
	v.erase(v.begin()+pos);\
	sort(v.begin(),v.end());\
	} while(0)

#define PRINT_VEC(v) do{\
	cout<<#v<<":";\
	FOR(i,0,v.size())\
		cout<<" "<<v[i];\
	cout<<endl;\
	}while(0)

#define MIN(a,b) ((a)<(b)?a:b)

class BridgeCrossing {

	public: int minTime(vector<int> times) {
		sort(times.begin(),times.end());
		if ( times.size() <=2 )
			return times[times.size()-1];

		vector<int> a(0),b(times.begin(),times.end());
		int time=0;
		while(b.size()>3)
		{

			// two possible cases here
			// it is possible to transfer the heavy two using
			// the fastest one or we have to ship the 2nd fastest one
			// to the other side.
			// So if the faster one is able to do the job, we don't need
			// to keep the 2nd fastests
			// 2*fastest + slowest1 + slowest2 > fastest + slowest + 2*second_fastest


			int mina=999;
			int f1 = b[0],f2=b[1],s1=b[b.size()-1],s2=b[b.size()-2];
			if ( 2*f1 + s1+s2 > f1 + s1 + 2*f2 )
			{
				//use 2nd one
				time+=2*f2+f1+s1;
			}
			else
			{
				//use 1st one to transport heavy
				time +=2*f1 + s1+s2 ;
			}
			INSERT(a,b[b.size()-1]);
			INSERT(a,b[b.size()-2]);

			REMOVE(b,b.size()-1);
			REMOVE(b,b.size()-1);

			//PRINT_VEC(a);
			//PRINT_VEC(b);
		}
		if ( b.size() == 2 )
			time+= *max_element(b.begin(),b.end());
		else
		{
			time+= MIN(b[0] + b[1] + b[2], b[2] + 2*b[1]);
		}
		return time;
	}

};
