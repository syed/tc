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

#define IS_FIXED_VOWEL(s,i) ( s[i] == 'A' || s[i] == 'E' || s[i] == 'O' || s[i] == 'U'|| s[i] == 'I')
#define IS_VOWEL(s,i)  ( IS_FIXED_VOWEL(s,i) || (s[i] == 'Y' && ( s[i-1] != ' ' && (!IS_FIXED_VOWEL(s,i-1)))))

class WordForm {

	public: string getSequence(string word) {

		FORIT(i,word)
				(*i) = toupper(*i);

		word = " " + word;

		char prev='Z';
		string ret;
		//cout <<word<<endl;
		FOR(i,1,word.size())
		{
			char cur= IS_VOWEL(word,i)?'V':'C';
			//cout <<"word "<<word[i]<<" val "<<cur<<endl;
			if ( word[i] == 'Y' && prev == 'V')
				cur='C';

			if ( prev != cur )
			{
				ret.push_back(cur);
				prev = cur;
			}
		}
		return ret;
	}

};
