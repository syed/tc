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

#define NUM(c,i) ( i<0 ? 0 : c[i]-'0')

class BinaryCode {

	public: vector<string> decode(string q) {
		int prev ;
		string p;
		p+="0";

		FOR(i,0,q.size())
		{
			p.push_back((char)( NUM(q,i) - (NUM(p,i-1) + NUM(p,i))) + '0');
		}
		cout<<"first "<<p<<endl;
		p.clear();
		p+="1";
		FOR(i,0,q.size())
		{
			p.push_back((char)( NUM(q,i) - (NUM(p,i-1) + NUM(p,i))) + '0');
		}
		cout<<"Second"<<p<<endl;
	}

};
