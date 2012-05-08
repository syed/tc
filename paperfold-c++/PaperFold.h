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

#define IS_FIT(l,w,bl,bw) ((max(l,w) <= max(bl,bw)) && (min(l,w) <= min(bl,bw)))

int rec(double l,double w,double bl,double bw,int count)
{
	if( count > 8)
		return 100;
	if ( IS_FIT(l,w,bl,bw))
		return count;

	return min( rec(l/2,w,bl,bw,count+1) , rec(l,w/2,bl,bw,count+1));
}

class PaperFold {

	public: int numFolds(vector<int> paper, vector<int> box) {
		double l=paper[0],w=paper[1],bl=box[0],bw=box[1];
		int ret;
		ret = rec(l,w,bl,bw,0);
		if (ret <= 8)
			return ret;
		return -1;
	}

};
