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

int check_wb( string cards, string ans)
{
	int count = 0;
	for ( int i=0; i< cards.size(); i++)
	{
		if ( cards[i]  != ans[i])
			count++;
	}
	return count;
}

class BlackAndWhiteSolitaire {

	public: int minimumTurns(string cardFront) {
		string ans1,ans2;
		for( int i = 0; i< cardFront.size(); i++ )
		{
			ans1 += (i%2 == 0) ? "W": "B";
			ans2 += (i%2 != 0) ? "W": "B";
		}

		return min( check_wb(cardFront, ans1), check_wb(cardFront, ans2));
	}

};
