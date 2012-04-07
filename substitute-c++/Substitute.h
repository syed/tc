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

class Substitute {

	public: int getValue(string key, string code) {
		map<char,int> code_map;
		int out=0;
		int val;
		FOR(i,0,26)
			code_map['A' + i] = -1;
		FOR(i,0,key.length()-1)
			code_map[key[i]] = i+1;

		code_map[key[key.length()-1]] = 0;

		FOR(i,0,code.length())
		{
			val =  code_map[code[i]];
			if ( val >=0 )
				out = out*10 + val;
		}

		return out;
	}

};
