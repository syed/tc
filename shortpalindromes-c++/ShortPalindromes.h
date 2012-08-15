#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i < (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

map<string,string> dp;

int palindrome_len(string s)
{
	int start = 0 , end  = s.size()-1;
	while ( start < end )
	{
		if ( s[start] != s[end] )
			return start;
		start++,end--;
	}
	return s.size();
}

string min_palin(string s)
{
	//cout<<" got "<<s<<endl;
	if (dp.find(s) != dp.end())
		return dp[s];

	int pal_len  = palindrome_len (s);
	if( pal_len == (int)s.size())
	{
		//cout<<"ret "<<s<<endl;
		dp[s] = s;
		return s;
	}

	if ( pal_len )
	{
		string ret =  ( string(s.begin(),s.begin()+ pal_len ) +\
				min_palin(string(s.begin()+pal_len,s.end()-pal_len)) +\
					string(s.end()-pal_len , s.end()));
		dp[s] = ret;
		//cout<<"ret "<<ret<<endl;
		return ret;
	}

	string a = string(s.begin()+1,s.end());
	string b = string(s.begin(),s.end()-1);


	string ret_a  = string(s.begin(),s.begin() +1 ) + min_palin(a) +string(s.begin(),s.begin() +1 );
	string ret_b =	string(s.end()-1,s.end()) + min_palin(b) + string(s.end()-1,s.end());

	string ret = (ret_a.size() < ret_b.size() )? ret_a : ret_b;
	if ( ret_a.size() == ret_b.size())
		ret= (ret_a<ret_b) ? ret_a : ret_b;


	//cout<<"ret "<<ret<<endl;
	dp[s] = ret;
	return ret;
}
class ShortPalindromes {

	public: string shortest(string base) {

		string ret = min_palin(base);
		return ret;
	}
};
