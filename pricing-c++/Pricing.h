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
int max_price = 0 ;


int combinations(vector<int> v, int n , int r , int num , int count,vector<int> price)
{
	if( count == r )
	{
		int cur_price = 0;
		v.push_back(num-1);
		v.push_back(price.size());
		FOR(i,1,v.size()-1)
		{
			//cout<<"("<<price[v[i]]<<" * "<< v[i+1] - v[i]<<") +  " ;
			cur_price += price[v[i]] * ( v[i+1] - v[i] ) ;
		}
		//cout<< " = " <<cur_price<<endl;
		if ( cur_price > max_price )
			max_price = cur_price;
		return 0;
	}

	v.push_back(num-1);
	FOR(i,num,n)
		combinations(v,n,r,i+1,count+1,price);

}

class Pricing {

	public: int maxSales(vector<int> price) {
		vector<int> pos;
		if ( price.size() <= 4 )
		{
			int ret=0;
			FOR(i,0,price.size())
				ret+=price[i];
			return ret;
		}
		sort(price.begin(),price.end());
		combinations(pos,price.size(),4,0,0,price);
		return max_price;
	}

};
