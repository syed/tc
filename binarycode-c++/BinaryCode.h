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

#define N(s,i) ( i<0 ? 0 : s[i] - '0')
class BinaryCode {

	public: vector<string> decode(string m) {
		vector<string> ret;
		string out;
		out.push_back('0');
		FOR(i,0,m.size()-1)
		{
			if (((N(m,i) - ( N(out,i-1) + N(out,i))) == 0 )|| ((N(m,i) - ( N(out,i-1) + N(out,i))) == 1 ))
			{
				out.push_back((N(m,i) - ( N(out,i-1) + N(out,i))) + '0');
			}
			else
			{
				out.clear();
				out+="NONE";
				break;
			}
		}
		//verify
		int sz = m.size()-1;
		if ( N(m,sz) != N(out,sz-1) + N(out,sz) )
		{
			out.clear();
			out+="NONE";
		}
		ret.push_back(out);
		out.clear();
		out.push_back('1');
		FOR(i,0,m.size()-1)
		{
			if (((N(m,i) - ( N(out,i-1) + N(out,i))) == 0 )|| ((N(m,i) - ( N(out,i-1) + N(out,i))) == 1 ))
			{
				out.push_back((N(m,i) - ( N(out,i-1) + N(out,i))) + '0');
			}
			else
			{
				out.clear();
				out+="NONE";
				break;
			}
		}
		if ( N(m,sz) != N(out,sz-1) + N(out,sz) )
		{
			out.clear();
			out+="NONE";
		}
		ret.push_back(out);
		return ret;
	}

};
