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

class NumberGuesser {
	/* very nice problem. Here the trick is the difference of digits is
	 * a multiple of 9. So, the sum of the digits formed by the subtraction
	 * should also be multiple of 9
	 */

	public: int guess(string leftOver) {
		int sum = 0,i;
		FOR(i,0,leftOver.size())
			sum += leftOver[i] -'0';

		for(i=1;i<10;i++)
			if ( (i + sum)%9 == 0 )
				break;

		return i;
	}

};
