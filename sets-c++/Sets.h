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

class Sets {

	public: vector<int> operate(vector<int> A, vector<int> B, string operation) {
		set<int> s1(A.begin(),A.end()) , s2(B.begin(),B.end());
		vector<int> ret;

		if ( operation == "UNION")
		{
			FORIT(i,s2)
				s1.insert(*i);

			ret.assign(s1.begin(),s1.end());
		}
		if ( operation == "SYMMETRIC DIFFERENCE")
		{
			set<int> s3(s1.begin(),s1.end());
			s3.insert(s2.begin(),s2.end());

			FORIT(i,s1)
				FORIT(j,s2)
					if( *j == *i )
					{
						s3.erase(int(*i));
					}

			ret.assign(s3.begin(),s3.end());
		}
		if ( operation == "INTERSECTION")
		{
			FORIT(i,s1)
				FORIT(j,s2)
					if( *j == *i )
					{
						ret.push_back(int(*i));
					}
		}

		sort(ret.begin(),ret.end());

		return ret;
	}

};
