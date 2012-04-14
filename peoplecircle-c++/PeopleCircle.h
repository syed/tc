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

class PeopleCircle {

	public: string order(int nm, int nf, int k) {
		string ret(nm+nf, 'M');
		int i=k-1;
		int count=0;
		int pos=0;
		int rem=i;
#if 0 /* Behera Solution */
		while( count < nf )
		{
			if(rem!=0)
			{
				if(ret[pos] == 'F')
					pos++;
				else
				{
					rem--;
					pos++;
				}

			}
			else
			{
				while(ret[pos] == 'F')
				{
					pos++;
					if(pos==(nm+nf))
						pos=0;
				}
				ret[pos] = 'F';

				count++;
				rem=k-1;
				pos++;
			}
			if(pos==(nm+nf))
				pos=0;
		}
#endif /* end Behera Solution */

		count = 0;
		pos=ret.length()-1;
		while( count < nf )
		{
			for( int c = 0 ; c<k;)
			{
				pos = (pos + 1) % (nm+nf);
				if ( ret[pos] == 'M') c++;
			}

			ret[pos] = 'F';
			count ++;
		}
		return ret;
	}

};
