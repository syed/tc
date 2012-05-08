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

#define IS_LEAP_YEAR(y) ( (y%4 == 0) && (y%100 !=0|| y%400==0) )

#define BOTH_LEAP_YEAR(a,b)  (IS_LEAP_YEAR(a) && IS_LEAP_YEAR(b))
#define BOTH_NOT_LEAP_YEAR(a,b)  ((!IS_LEAP_YEAR(a)) && (!IS_LEAP_YEAR(b)))

class CalendarRecycle {

	public: int useAgain(int year) {
		int diff=0;
		if ( IS_LEAP_YEAR(2014))
			cout<<"Leap year "<<2014<<endl;
		FOR(i,year+1,100000000)
		{
			if ( IS_LEAP_YEAR(i))
				diff+= 2;
			else
				diff+= 1;

			if (diff  % 7 == 0 && (BOTH_LEAP_YEAR(i,year) || (BOTH_NOT_LEAP_YEAR(i,year))))
				return i;
		}
		return -1;
	}

};
