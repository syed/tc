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

class GuessTheNumber {

	public: int noGuesses(int upper, int answer) {
		int lower = 1,guess=0,mid=-1;

		while ( mid != answer)
		{
			mid = ( upper+ lower)/2;
			guess ++;
			if ( mid < answer)
				lower= mid +1;
			if ( mid > answer)
				upper=mid -1;
			if ( mid == answer)
				break;
		}

		return guess;
	}

};
