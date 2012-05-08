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
#define INT_TO_STR(i,s) do{\
	ostringstream out;\
	out << i;\
	s = out.str();\
	}while(0)


class Animation {

	public: vector<string> animate(int speed, string init) {
		vector<string> ret;
		vector<int> pos(init.size(),-1);
		FOR(i,0,init.size())
			if ( init[i] != '.')
				pos[i] = i;

		string curr(init.size(),'.');
		bool over = true;
		FOR(i,0,pos.size())
			if ( pos[i] < init.size() &&  pos[i] >=0 )
			{
				curr[pos[i]] = 'X';
				over = false;
			}

		if ( ! over )
			ret.push_back(curr);

		while(1)
		{
			FOR(i,0,init.size())
			{
				if ( init[i] == 'R')
					pos[i] += speed;
				else if ( init[i] == 'L')
					pos[i] -= speed;
			}

//			FOR(i,0,pos.size())
//				cout<<"i "<<i<<" pos i "<<pos[i]<<endl;
			string curr(init.size(),'.');
			bool over = true;
			FOR(i,0,pos.size())
			{
				if ( pos[i] < init.size() &&  pos[i] >=0 )
				{
					curr[pos[i]] = 'X';
					over = false;
				}
			}
			ret.push_back(curr);
			if( over )
				break;

		}

		return ret;
	}

};
