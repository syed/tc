#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

typedef struct chord_t {
	vector<int> freq;
	vector<int> den;
}chord;

int gcd(int a,int b)
{
	if ( b == 0 )
		return a;

	return (gcd( b , a % b ));
}

static inline void make_chord(int f1,int f2, int f3, chord &c)
{
	c.freq.clear();
	c.den.clear();

	c.freq.push_back(f1);
	c.freq.push_back(f2);
	c.freq.push_back(f3);
	sort(c.freq.begin(),c.freq.end());

	c.den.push_back( c.freq[0]/gcd(c.freq[2],c.freq[0]));
	c.den.push_back( c.freq[0]/gcd(c.freq[1],c.freq[0]));
	c.den.push_back( c.freq[1]/gcd(c.freq[2],c.freq[1]));

	sort(c.den.rbegin(),c.den.rend());
}
// a less than b ?
bool chord_cmp(chord a , chord b)
{
		bool eq=true;
		FOR(i,0,3)
			if ( a.den[i] < b.den[i] && eq)
				return true;
			else if ( a.den[i] == b.den[i])
				eq = true;
			else
				eq = false;



	if ( a.den == b.den )
	{
		eq = true;
		FOR(i,0,3)
			if ( a.freq[i] < b.freq[i] && eq )
				return true;
			else if ( a.freq[i] == b.freq[i])
				eq = true;
			else
				eq = false;
	}
	return false;
}

class Harmony {

	public: vector<int> mostHarmonious(vector<int> frequencies) {

		vector<chord> ch;
		chord min_c;
		make_chord(1,999999999,123456, min_c);
		FOR(i,0,frequencies.size())
			FOR(j,i+1,frequencies.size())
				FOR(k,j+1,frequencies.size())
				{
					chord tmp;
					//printf("i:%d:%d j:%d:%d k:%d:%d\n",i,frequencies[i],j,frequencies[j],k,frequencies[k]);
					make_chord(frequencies[i],frequencies[j],frequencies[k],tmp);
					if ( chord_cmp(tmp,min_c))
						min_c = tmp;
				}
		return min_c.freq;
	}

};
