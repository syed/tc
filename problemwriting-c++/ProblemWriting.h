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
#define ERROR 4

#define IS_OP(c) ((c) == '+' || (c) == '-' || (c) == '*' || (c) == '/' )
#define IS_NUM(c)  ((c) >= '0' && (c) <= '9')

int validate(string s)
{
	int state=NUM;
	int i=0;
	int sz = s.size();

	if ( ! (IS_NUM(s[0])))
		return 0;
	i++;
	while(i<sz)
	{
		switch( state )
		{
		case NUM:
			if ( s[i] == '.')
				state = DOT_OP;
			else if (IS_OP(s[i]))
				state = OP;
			else
				state = ERROR;
			break;

		case DOT_OP:
			if ( s[i] == '.')
				state= DOT_OP;
			else if (IS_OP(s[i]))
				state = OP;
			else
				state = ERROR;

			break;
		case OP:
			if ( s[i] == '.')
				state = DOT_NUM;
			else if ( IS_NUM(s[i]))
				state = NUM;
			else
				state = ERROR;
			break;

		case DOT_NUM:
			if ( s[i] == '.')
				state= DOT_NUM;
			else if (IS_NUM(s[i]))
				state = NUM;
			else
				state = ERROR;

			break;

		case ERROR :
			return i-1;

		}
		i++;
	}

	if ( state == ERROR)
		return sz-1;
	else if ( state != NUM )
		return sz;

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
