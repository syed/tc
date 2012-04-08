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

int gcd(int a,int b)
{
	if( b == 0)
		return a;
	return gcd( b, a %b );
}

int lcm( int a , int b)
{
	int l_gcd;
	if ( a > b)
		l_gcd = gcd( a,b);
	else
		l_gcd = gcd(b,a);
	//cout<<"Got gcd of " << a <<" , "<< b << " "<< l_gcd;
	return (a*b/l_gcd);
}

class Inchworm {

	public: int lunchtime(int branch, int rest, int leaf) {
		//return branch;
		return ( branch/lcm(rest,leaf)+1 );

	}

};
