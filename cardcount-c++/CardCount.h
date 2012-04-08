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

class CardCount {

	public: vector<string> dealHands(int numPlayers, string deck) {
		int num_cards = deck.size()/numPlayers;

		vector<string> final(numPlayers);
		FOR(i,0,num_cards)
			FOR(j,0,numPlayers)
				final[j].push_back(deck[i*numPlayers+j]);


		return final;
	}

};
