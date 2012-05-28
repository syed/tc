#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

#define RET_LARGE "dotForm must contain between 1 and 25 characters, inclusive."

#define NUM 0
#define DOT_OP 1
#define DOT_NUM 2
#define OP 3


int validate(string s)
{
	int state=NUM;
	int i=0;
	int sz = s.size();
	bool op_seen = false;
	while(i<sz)
	{
		switch( state )
		{
		case NUM:
			while( i<sz && s[i] >= '0' && s[i] <= '9' )
				i++;
			if ( i<sz )
				state = DOT_OP;

			break;
		case DOT_OP:
			while(i<sz && s[i] == '.')
				i++;
			if ( i<sz && ( s[i] == '+' || s[i] == '-' ||s[i] == '*' ||s[i] == '/' ))
				state=OP;
			else
				return i;
			break;

		case DOT_NUM:
			while(i<sz && s[i] == '.')
				i++;
			if ( i<sz && ( s[i] >= '0' && s[i] <= '9'))
				state=NUM;
			else
				return i;
			break;

		case OP:
			op_seen = true;
			i++;
			if ( i<sz && ! ( s[i] == '.' || ( s[i] >= '0' && s[i] <= '9' )))
				return i;
			if ( i<sz && s[i] == '.')
				state = DOT_NUM;
			else
				state=NUM;

			break;
		}
	}
	if ( ! op_seen)
		return i;
	return -1;
}

class ProblemWriting {

	public: string myCheckData(string df) {
		if ( df.size()<1 || df.size()>25 )
			return RET_LARGE;
		int err_pos=-1;

		err_pos = validate(df);

		if ( err_pos >= 0 )
		{
			char *ret_str = new char[50];
			sprintf(ret_str, "dotForm is not in dot notation, check character %d." , err_pos );
			return (string(ret_str));
		}
		return string();
	}

};
