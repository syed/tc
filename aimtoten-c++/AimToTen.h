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

class AimToTen {

	public: int need(vector<int> marks) {
		/* simple average should be at least 9.5 */

		int sum=0,i, num = marks.size();
		FOR(i,0,num)
			sum+=marks[i];
		return (9.5*num - sum) >0 ? 2*(9.5*num - sum) : 0;
	}

};
