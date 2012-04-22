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

class StringTrain {

	public: string buildTrain(vector<string> cars) {
		string train(cars[0]);
		string common ;
		FOR(i,1,cars.size())
		{
			int train_sz  = train.size();
			int cpos = -1;
			common.clear();

			for(int j=1; j< int(train.size()) && j< int(cars[i].size()) ; j++)
			{
				if ( cars[i].substr(0,j) == train.substr(train_sz-j,j))
				{
					common = cars[i].substr(0,j);
					cpos = j;
				}
			}
			//cout<<"Common string "<<common<<endl;
			if ( cpos != -1 && common.size() < cars[i].size())
				train = train + cars[i].substr(cpos);

			//cout<<"Train "<<train<<endl;

		}
		map<char,int> seen;
		string ret1;
		string ret2;
		INT_TO_STR(train.size(), ret1);
		ret1.push_back(' ');

		for(int i=train.size()-1;i>=0;i--)
		{
			if ( seen[train[i]])
				continue;
			ret2.push_back(train[i]);
			seen[train[i]] = 1;
		}
		return ret1 + string(ret2.rbegin(),ret2.rend());
	}

};
