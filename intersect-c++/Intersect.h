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

#define LIES(p,p1,p2) (p>=p1 && p<=p2)

#define SWAP(p1,p2) \
				do{\
					int temp=p2;\
					p2=p1;\
					p1=temp;\
				}while(0)


class Intersect {

	public: int area(vector<int> x, vector<int> y) {
		vector<int> ix,iy;
		int pos=0;
		FOR(i,0,y.size())
		{
			bool between = true;
			int p = y[i];
			for(int j=0;j<int(y.size());j+=2)
			{
				if ( j== i || j+1 == i)
					continue;
				int p1= y[j], p2=y[j+1];
				if(p1>p2)
					SWAP(p1,p2);

				if (!LIES(p,p1,p2))
					between = false;

			}
			if ( between )
			{
				//cout<<"Between y"<<p<<endl;
				iy.push_back(p);
				pos++;
			}
		}
		pos=0;
		if ( iy.size() == 0)
		{
			iy.push_back(0);
			iy.push_back(0);
		}
		FOR(i,0,x.size())
		{
			bool between = true;
			int p = x[i];
			for(int j=0;j<int(x.size());j+=2)
			{
				if ( j== i || j+1 == i)
					continue;
				int p1= x[j], p2=x[j+1];
				if(p1>p2)
					SWAP(p1,p2);

				if (!LIES(p,p1,p2))
					between = false;
			}
			if ( between )
			{
				ix.push_back(p) ;
				//cout<<"Between x"<<p<<endl;
			}
		}
		if ( ix.size() == 0)
		{
			ix.push_back(0);
			ix.push_back(0);
		}
		int area =  abs(ix[0]-ix[1])* abs(iy[0] - iy[1]);
		cout <<"area "<<area<<endl;
		return (area);
	}

};
