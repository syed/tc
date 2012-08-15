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



class ElectionFraudDiv2 {

	public: string IsFraudulent(vector<int> percentages) {
		FOR(i,0,percentages.size())
			percentages[i] *=100;

		long long int min_sum=0,max_sum=0;
		FOR(i,0,percentages.size())
		{
			if(percentages[i]>=100)
				min_sum += ( percentages[i] - 50 );
		}
		FOR(i,0,percentages.size())
		{
			if(percentages[i]<10000)
				max_sum += ( percentages[i] + 49 );
			else
				max_sum += 10000;
		}
		//cout<<"min : "<<min_sum<<" max_sum : "<<max_sum<<endl;
		if ( min_sum <= 10000 && max_sum >= 10000)
			return "NO";

		return "YES";
	}
};
