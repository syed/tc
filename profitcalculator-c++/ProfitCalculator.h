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

class ProfitCalculator {

	public: int percent(vector<string> items) {
		double cp,sp;
		int margin;
		double t_sp,t_cp;
		t_sp = t_cp = 0;
		FOR(i,0,items.size())
		{
			istringstream input(items[i]);
			input>>sp>>cp;
			t_sp+=sp;
			t_cp+=cp;
		}

		margin= ((t_sp-t_cp)/t_sp)*100;
		return margin;
	}

};
