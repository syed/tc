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

class CCipher {

	public: string decode(string cipherText, int shift) {
		/* (char)((((c[i]-'A')+26-shift)%26)+'A')
		 * this is a better solution. If it is negative
		 * it wont do anything if it is positive it has
		 * an effect of subtracting 26 so adding of 26
		 * before modulus does not cause harm
		 * see editorial for more
		 */

		ostringstream out;
		FOR(i,0,cipherText.length())
		{
			char dec_ch = cipherText[i] - shift;
			if( dec_ch < 'A')
				dec_ch = dec_ch + 26;

			out<< dec_ch;
		}
		return out.str();

	}

};
