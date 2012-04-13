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

class ExerciseMachine {

	public: int getPercentages(string time) {
		int hrs,mins,secs;
		char temp;
		istringstream in(time);
		in>>hrs>>temp>>mins>>temp>>secs;
		secs += (hrs)*60*60 + mins*60;

		int per=0;
		FOR(i,1,secs)
		{
			if( (100*i) % secs == 0 )
				per++;
		}
		return per;
	}

};
