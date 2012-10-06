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

static inline chord make_chord(int f1,int f2, int f3)
{
	vector<int> freq;

	freq.push_back(f1);
	freq.push_back(f2);
	freq.push_back(f3);
	sort(freq.begin(),freq.end());

	vector<int> den;
	 den.push_back( freq[0]/gcd(freq[2],freq[0]));
	 den.push_back( freq[0]/gcd(freq[1],freq[0]));
	 den.push_back( freq[1]/gcd(freq[2],freq[1]));

	sort(den.begin(),den.end());

	chord c;
	c.freq= freq;
	c.den = den;
	if  ( freq[0] == 1960 && freq[1] == 2352 && freq[2] == 2940)
	{
		printf("F1 %d F2 %d F3 %d\n",freq[0],freq[1],freq[2]);
		printf("D1 %d D2 %d D3 %d\n",den[0],den[1],den[2]);
	}
	return c;
}
// a less than b ?
bool chord_cmp(chord a , chord b)
{
	if ( a.freq[0] == 1960 && a.freq[1] == 2352	 && a.freq[2] == 2490 )
		printf("Comparing this");
	for( int i =2 ;i>=0;i-- )
		if ( a.den[i] > b.den[i])
			return false;

	if ( a.den == b.den )
	{
		FOR(i,0,3)
			if ( a.freq[i] > b.freq[i])
				return false;
	}
	return true;
}
class Harmony {

	public: vector<int> mostHarmonious(vector<int> frequencies) {

		vector<chord> ch;
		FOR(i,0,frequencies.size())
			FOR(j,i+1,frequencies.size())
				FOR(k,j+1,frequencies.size())
				{
					printf("i:%d:%d j:%d:%d k:%d:%d\n",i,frequencies[i],j,frequencies[j],k,frequencies[k]);
					ch.push_back(make_chord(frequencies[i],frequencies[j],frequencies[k]));
				}


		chord min_c = ch[0];
		FOR(i,1,ch.size())
		{
			if ( ch[i].freq[0] == 1000 && ch[i].freq[1] == 2000 && ch[i].freq[2] == 3050 )
				printf (" ---- Here ----- at %d\n",i);
			if ( ch[i].freq[0] == 1960 && ch[i].freq[1] == 2352	 && ch[i].freq[2] == 2490 )
				printf (" ---- Here 2----- at %d\n",i);
			if  ( i == 39)
				printf("at 39\n");
			if ( chord_cmp( ch[i] , min_c))
				min_c = ch[i];
		}
		printf("%d:%d:%d %d:%d:%d\n", min_c.freq[0],min_c.freq[1],min_c.freq[2],min_c.den[0],min_c.den[1],min_c.den[2]);

		return min_c.freq;
	}

};
