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

class ProgressBar {

	public: string showProgress(vector<int> taskTimes, int tasksCompleted) {
		int tot=0,comp=0;
		FOR(i,0,taskTimes.size())
		{
			tot+=taskTimes[i];
			if ( i< tasksCompleted)
				comp+=taskTimes[i];
		}
		string bar;
		int avg = (20*comp)/tot;
		FOR(i,0,20)
		{
			if(i<avg)
				bar.push_back('#');
			else
				bar.push_back('.');
		}
		return bar;
	}
};
