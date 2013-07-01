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

class ColorfulTilesEasy {

	public: int theMin(string room) {
		int min = 0;
		int i=0;

		for(; i< room.size(); i++)
		{
			int num_con = 0;
			//cout << " i "<<i << " room i "<< room[i]<<endl;
			char cur_col = room[i];
			for( int j = i+1; j < room.size(); j++)
			{
				//cout<<"room j "<<room[j]<<endl;
				if( room[j] == cur_col)
				{
					num_con += 1;
					i++;
				}
				else
					break;
			}
			min += (num_con+1)/2;
		}
		return min;
	}

};
