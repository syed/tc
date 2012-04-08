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

class RPG {

	public: vector<int> dieRolls(vector<string> dice) {
		vector<int> res;
		int min=0,max=0;
		double avg=0.0;
		FOR(i,0,dice.size())
		{
			istringstream in(dice[i]);
			int times,size;
			char temp ;
			in>>times>>temp>>size;
			min += times;
			max += times*size;
			avg += (times*(double)(1+size)/2);
		}
		res.push_back(min);
		res.push_back(max);
		res.push_back((int)avg);
		return res;
	}

};
