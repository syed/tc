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

class Swimmers {

	public: vector<int> getSwimTimes(vector<int> distances, vector<int> speeds, int current) {
		vector<int> res;
		double t_down,t_up;
		FOR(i,0,speeds.size())
		{
			if ( distances[i] == 0)
			{
				res.push_back(0);
				continue;
			}
			if (speeds[i]- current <= 0 )
			{
				res.push_back(-1);
			}
			else
			{
				t_down = (double)distances[i]/(double)(speeds[i]+ current);
				t_up = (double)distances[i]/(double)(speeds[i]- current);
				//cout<<"TIme "<< t_up+t_down<<endl;
				res.push_back((int)(t_down+t_up));
			}
		}
		return res;
	}

};
