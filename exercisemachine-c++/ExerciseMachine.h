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

/* It can also be solved as GCD(sec,100)-1. Gcd of a,b means a number that can divide both evenly.
 * now we have number of seconds and 100 as the percentage. at gcd both will divide evenly.
 * So it is a perfect percentage. We can get the pecentage as 100/gcd. every time we have
 * to increase the percentage by 100/gcd amount for every sec/gcd seconds.
 * So we want to find out for 100 how many times do we have to do this (100/(100/gcd)) = gcd .
 * Now remove  case where we put 100% so we have gcd-1
 */
class ExerciseMachine {

	public: int getPercentages(string time) {
		int hrs,mins,secs;
		char temp;
		istringstream in(time);
		in>>hrs>>temp>>mins>>temp>>secs;
		secs += (hrs)*60*60 + mins*60;

		int per=0;
		FOR(i,1,secs)
		{
			if( (100*i) % secs == 0 )
				per++;
		}
		return per;
	}

};
