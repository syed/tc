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

<<<<<<< HEAD
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

=======
#define NUM(c) (c - '0')

#define IS_DIGIT(n) ((n==0)||(n==1))

class BinaryCode {

	public: string my_decode(string p , string q)
	{
		int len = q.length();
		if ( len == 1 )
		{
			if ( p[0] == q[0])
				return p;

			return "NONE";
		}

		if ( IS_DIGIT( q[0] - p[0] ))
			p.push_back('0' + (q[0] - p[0]));
		else
			return "NONE";

		FOR( i , 1 , q.length()-1)
		{
			if ( IS_DIGIT( (NUM(q[i]) - ( NUM(p[i-1]) + NUM(p[i])) )))
					p.push_back('0' + (NUM(q[i]) - ( NUM(p[i-1]) + NUM(p[i]))));
			else
					return "NONE";
		}
		if ( NUM(q[len-1]) != NUM(p[len-1]) + NUM(p[len-2]))
			return "NONE";

		return p;
	}

	public: vector<string> decode(string q) {
		string p;
		vector<string> ret;
		p.push_back('0');
		ret.push_back(my_decode(p,q));
		p.clear();
		p.push_back('1');
		ret.push_back(my_decode(p,q));
		return ret;
	}
>>>>>>> d9fe0dd53eb3740af5116af4969ce65a284b786a
};
