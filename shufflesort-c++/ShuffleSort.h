#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

/* Here we can see this as taking one card at a time and then shuffling the deck,
 * now if m are the min cards and n is the total cards, probability that we will
 * pick the min card p is m/n and prob of not picking the min card q is 1 - m/n.
 * let count(n) be the avg no of shuffles required. If we were picking card first
 * then shuffling, then
 *          count(n) = q*count(n) + p*count(n-1) 
 * but here we shuffle first so we change it like
 *          count(n) = 1 + q*count(n) + p*(count(n-1) - 1 )
 */

double count(vector<int> cards, int n )
{
    if ( n == 0 )
        return 1;
    int min_count = 0;

    while(cards[min_count] == cards[0])
       min_count++;
    
    double p = double(min_count)/double(n);
    double q = 1.0 - p;
    return double(n)/double(min_count) + count(vector<int>(cards.begin()+1,cards.end()),n-1) - 1;
}


class ShuffleSort {

	public: double shuffle(vector<int> cards) {
                sort(cards.begin(),cards.end());
                
		return count(cards,cards.size());
	}

};
