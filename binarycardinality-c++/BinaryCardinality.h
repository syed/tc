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

int bin_cardinality(int n)
{
	int card=0;
	while(n)
	{
		if (n%2 == 1)
			card++;
		n/=2;
	}
	return card;
}

class BinaryCardinality {

	public: vector<int> arrange(vector<int> numbers) {
		vector<pair<int,int> > list;
		FOR(i,0,numbers.size())
		{
			pair<int,int> p;
			p.first = bin_cardinality(numbers[i]);
			//cout<<"card of "<<numbers[i]<< "  "<< bin_cardinality(numbers[i])<<endl;
			p.second = numbers[i];
			list.push_back(p);
		}
		sort(list.begin(),list.end());
		vector<int> ret;
		FOR(i,0,list.size())
		{
			//cout<<"card "<<list[i].first<<" num "<<list[i].second<<endl;
			ret.push_back(list[i].second);
		}

		return ret;

	}

};
