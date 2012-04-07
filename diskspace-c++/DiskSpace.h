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

class DiskSpace {

public:
	int minDrives(vector<int> used, vector<int> total) {
		int tot_used = 0;
		sort(total.begin(), total.end());
		reverse(total.begin(), total.end());

		/*		FOR(i,0,total.size())
		 cout<<"total: "<<total[i]<<endl;
		 FOR(i,0,total.size())
		 cout<<"used: "<<used[i]<<endl;
		 */
		int num_hd = 0;

		FOR(i,0,used.size())
			tot_used += used[i];

		int i = 0;
		//cout<< "Tot used : "<< tot_used<<endl;
		while (tot_used > 0) {
			tot_used -= total[i];
			//cout<< "Tot used : "<< tot_used<<endl;
			num_hd++;
			i++;
		}
		return num_hd;
	}

};
